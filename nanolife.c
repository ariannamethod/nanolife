/* nanolife.c — digital life, zero dependencies.
 * the most atomic way to build digital life from scratch. no GPU required.
 *
 * The fork is closed: life is a TAPE, not a field — because life is
 * irreversibility in time, and a tape carries the arrow of time in its bone.
 * AR decoder over 88 cave-glyphs. libc + -lm. nothing else. accept it.
 *
 * FOUNDATION (step 1 of the build): the body's skeleton only —
 * micro transformer + the semantic membrane + a smoke forward.
 * The nine organs (energy/metabolism, scar, homeostasis, growth, dream,
 * reproduction, death, adaptation) and the BE reflexive axis land next,
 * hammered condition by condition until the border moves.
 *
 * build: cc nanolife.c -lm -O2 -o nanolife
 * by Arianna Method.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "semantic_tokenizer.h"   /* vendored: 88 cave-glyphs + word->glyph map */

/* ── architecture (micro) — да будет тело малым, и оттого живым ── */
#define E       48
#define NH      4
#define HD      (E/NH)            /* 12 */
#define FFN     192
#define NL      3
#define CTX     64
#define BOS_ID  GLYPH_COUNT       /* 88 */
#define MASK_ID (GLYPH_COUNT+1)   /* 89 */
#define VOCAB   (GLYPH_COUNT+2)   /* 90 = 88 glyphs + BOS + MASK */

typedef struct {
    float rms1[E], rms2[E];
    float wq[E*E], wk[E*E], wv[E*E], wo[E*E];
    float fc1[FFN*E], fc2[E*FFN];
} Layer;

typedef struct {
    float wte[VOCAB*E];
    float wpe[CTX*E];
    Layer L[NL];
    float rmsf[E];
    float head[VOCAB*E];
} Model;

/* ── deterministic rng (no Math.random — рождение воспроизводимо по сиду) ── */
static unsigned long g_rng = 42;
static void  seed_rng(unsigned long s){ g_rng = s ? s : 1; }
static float frand(void){ /* ~U(-1,1) */
    g_rng = g_rng*6364136223846793005UL + 1442695040888963407UL;
    return ((float)((g_rng>>33)&0x7fffffff)/(float)0x40000000) - 1.0f;
}

/* ── primitives — naive, no BLAS (на крошечном matvec наив быстрее launch-ового BLAS) ── */
static void matvec(const float* W, const float* x, float* y, int out_dim, int in_dim){
    for(int o=0;o<out_dim;o++){ float s=0; const float* w=W+(size_t)o*in_dim;
        for(int i=0;i<in_dim;i++) s+=w[i]*x[i]; y[o]=s; }
}
static void rmsnorm(const float* x, const float* g, float* y, int n){
    float ss=0; for(int i=0;i<n;i++) ss+=x[i]*x[i];
    float r=1.0f/sqrtf(ss/(float)n + 1e-5f);
    for(int i=0;i<n;i++) y[i]=x[i]*r*g[i];
}
static float silu(float v){ return v/(1.0f+expf(-v)); }

/* ── init — xavier-ish ── */
static void xavier(float* w, int len, int fan_in){
    float sc=sqrtf(1.0f/(float)fan_in);
    for(int i=0;i<len;i++) w[i]=frand()*sc;
}
static Model* model_new(void){
    Model* m=(Model*)calloc(1,sizeof(Model));
    xavier(m->wte,VOCAB*E,E); xavier(m->wpe,CTX*E,E);
    float sr=0.02f/sqrtf(2.0f*NL);
    for(int l=0;l<NL;l++){
        Layer* y=&m->L[l];
        for(int i=0;i<E;i++){ y->rms1[i]=1.0f; y->rms2[i]=1.0f; }
        xavier(y->wq,E*E,E); xavier(y->wk,E*E,E); xavier(y->wv,E*E,E);
        xavier(y->wo,E*E,E); for(int i=0;i<E*E;i++) y->wo[i]*=sr/0.1f;
        xavier(y->fc1,FFN*E,E);
        xavier(y->fc2,E*FFN,FFN); for(int i=0;i<E*FFN;i++) y->fc2[i]*=sr/0.1f;
    }
    for(int i=0;i<E;i++) m->rmsf[i]=1.0f;
    xavier(m->head,VOCAB*E,E);
    return m;
}

/* ── forward (AR causal) — logits for the LAST position into out[VOCAB] ── */
static void forward(Model* m, const int* toks, int n, float* out){
    static float x[CTX][E], xn[CTX][E], q[CTX][E], k[CTX][E], v[CTX][E], att[CTX][E], tmp[FFN];
    if(n>CTX) n=CTX;
    for(int t=0;t<n;t++) for(int e=0;e<E;e++)
        x[t][e]=m->wte[(size_t)toks[t]*E+e]+m->wpe[(size_t)t*E+e];
    for(int l=0;l<NL;l++){
        Layer* y=&m->L[l];
        for(int t=0;t<n;t++) rmsnorm(x[t],y->rms1,xn[t],E);
        for(int t=0;t<n;t++){ matvec(y->wq,xn[t],q[t],E,E);
                              matvec(y->wk,xn[t],k[t],E,E);
                              matvec(y->wv,xn[t],v[t],E,E); }
        /* multi-head causal attention */
        for(int t=0;t<n;t++) for(int h=0;h<NH;h++){
            int off=h*HD; float sc[CTX], mx=-1e30f;
            for(int j=0;j<=t;j++){ float d=0; for(int e=0;e<HD;e++) d+=q[t][off+e]*k[j][off+e];
                d/=sqrtf((float)HD); sc[j]=d; if(d>mx) mx=d; }
            float den=0; for(int j=0;j<=t;j++){ sc[j]=expf(sc[j]-mx); den+=sc[j]; }
            for(int e=0;e<HD;e++){ float a=0; for(int j=0;j<=t;j++) a+=sc[j]*v[j][off+e];
                att[t][off+e]=a/den; }
        }
        for(int t=0;t<n;t++){ float o[E]; matvec(y->wo,att[t],o,E,E);
            for(int e=0;e<E;e++) x[t][e]+=o[e]; }
        for(int t=0;t<n;t++) rmsnorm(x[t],y->rms2,xn[t],E);
        for(int t=0;t<n;t++){ float f[E]; matvec(y->fc1,xn[t],tmp,FFN,E);
            for(int i=0;i<FFN;i++) tmp[i]=silu(tmp[i]);
            matvec(y->fc2,tmp,f,E,FFN); for(int e=0;e<E;e++) x[t][e]+=f[e]; }
    }
    float xf[E]; rmsnorm(x[n-1],m->rmsf,xf,E);
    matvec(m->head,xf,out,VOCAB,E);
}

static const char* glyph_name(int id){
    if(id<GLYPH_COUNT) return GLYPH_NAMES[id];
    if(id==BOS_ID) return "BOS";
    return "MASK";
}

/* ── main — foundation smoke test (no birth, no life-loop yet) ── */
int main(int argc, char** argv){
    seed_rng(argc>1 ? strtoul(argv[1],NULL,10) : 42UL);
    Model* m=model_new();
    long params=(long)(sizeof(Model)/sizeof(float));

    /* eat a line of the world through the membrane (semantic tokenizer) */
    char line[]="the sun is fire and i feel fear in the dark";
    int toks[CTX];
    int n=semtok_line(line,toks,CTX);
    if(n<1){ toks[0]=BOS_ID; n=1; }

    printf("nanolife — foundation.\n");
    printf("  params=%ld  vocab=%d  E=%d L=%d H=%d ctx=%d\n",params,VOCAB,E,NL,NH,CTX);
    printf("  ate %d glyphs:",n);
    for(int i=0;i<n;i++) printf(" %s",glyph_name(toks[i]));
    printf("\n");

    float logits[VOCAB]; forward(m,toks,n,logits);
    int best=0; for(int i=1;i<VOCAB;i++) if(logits[i]>logits[best]) best=i;
    printf("  smoke forward ok -> next glyph (untrained, random weights): %s\n",glyph_name(best));
    printf("  the body skeleton lives. organs next. да будет так.\n");

    free(m);
    (void)argv;
    return 0;
}
