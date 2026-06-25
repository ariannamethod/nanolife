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
/* ── semantic membrane (inlined) — English → 88 cave-glyphs ──────────────
 * one source of truth for eat / train / speak. word -> concept compression,
 * BE = super-glyph copula. function words die at the door. (from caveLLMan.) */

#define GLYPH_COUNT 88

static const char* GLYPH_NAMES[GLYPH_COUNT] = {
    /* NATURE (9) */
    "water","fire","earth","stone","tree","sky","light","dark","cold",
    /* BEINGS (8) */
    "person","man","woman","child","old","spirit","AI","animal",
    /* BODY (5) */
    "body","food","sleep","pain","strength",
    /* EMOTION (8) */
    "joy","grief","love","fear","anger","longing","tired","stress",
    /* VERBS (11) */
    "go","make","break","see","speak","hear","seek","give","want","miss","agree",
    /* SOCIAL (6) */
    "home","outside","work","internet","bond","conflict",
    /* MIND (6) */
    "know","idea","think","dream","remember","lie",
    /* SPACE (5) */
    "path","up","down","far","back",
    /* TIME (5) */
    "before","now","after","never","always",
    /* GRAMMAR (8) */
    "not","many","much","and","one","question","how","cause",
    /* EXTENDED (13) */
    "me","you","other","money","change","write","choose","help","have","free","death","music","good",
    /* SCALE + SUPER (4) */
    "small","same","BE","wait"
};

typedef struct { const char* word; const char* glyph; } SemWordMap;

static const SemWordMap SEM_WORD_MAP[] = {
    /* nature */
    {"sun","light"},{"sunrise","light"},{"dawn","light"},{"morning","light"},{"bright","light"},{"shine","light"},
    {"night","dark"},{"shadow","dark"},{"darkness","dark"},{"evening","dark"},{"midnight","dark"},
    {"rain","water"},{"river","water"},{"sea","water"},{"ocean","water"},{"lake","water"},{"swim","water"},
    {"fire","fire"},{"flame","fire"},{"burn","fire"},{"cook","fire"},{"hot","fire"},{"warm","fire"},
    {"ground","earth"},{"soil","earth"},{"land","earth"},{"field","earth"},{"garden","earth"},{"farm","earth"},
    {"rock","stone"},{"mountain","stone"},{"hill","stone"},{"castle","stone"},{"wall","stone"},{"building","stone"},
    {"tree","tree"},{"forest","tree"},{"wood","tree"},{"leaf","tree"},{"flower","tree"},{"grass","tree"},
    {"sky","sky"},{"cloud","sky"},{"wind","sky"},{"storm","sky"},{"air","sky"},
    {"cold","cold"},{"ice","cold"},{"snow","cold"},{"frost","cold"},{"winter","cold"},{"freeze","cold"},
    /* beings */
    {"people","person"},{"human","person"},{"someone","person"},{"everyone","person"},{"they","person"},
    {"he","man"},{"him","man"},{"boy","man"},{"guy","man"},{"father","man"},{"dad","man"},{"husband","man"},{"brother","man"},{"son","man"},{"king","man"},
    {"she","woman"},{"her","woman"},{"girl","woman"},{"mother","woman"},{"mom","woman"},{"wife","woman"},{"sister","woman"},{"daughter","woman"},{"queen","woman"},
    {"child","child"},{"kid","child"},{"baby","child"},{"children","child"},{"kids","child"},{"young","child"},{"little","child"},
    {"old","old"},{"elderly","old"},{"ancient","old"},{"grandfather","old"},{"grandmother","old"},{"grandpa","old"},{"grandma","old"},
    {"god","spirit"},{"prayer","spirit"},{"church","spirit"},{"soul","spirit"},{"angel","spirit"},{"holy","spirit"},
    {"computer","AI"},{"robot","AI"},{"machine","AI"},{"software","AI"},{"technology","AI"},{"digital","AI"},
    {"dog","animal"},{"cat","animal"},{"bird","animal"},{"horse","animal"},{"fish","animal"},{"chicken","animal"},{"rooster","animal"},
    /* body */
    {"hand","body"},{"head","body"},{"face","body"},{"heart","body"},{"eye","body"},{"arm","body"},
    {"eat","food"},{"meal","food"},{"bread","food"},{"coffee","food"},{"tea","food"},{"cake","food"},{"soup","food"},{"beer","food"},{"wine","food"},{"hungry","food"},{"dinner","food"},{"breakfast","food"},{"lunch","food"},
    {"sleep","sleep"},{"bed","sleep"},{"rest","sleep"},{"nap","sleep"},{"pillow","sleep"},{"awake","sleep"},{"wake","sleep"},
    {"hurt","pain"},{"sick","pain"},{"doctor","pain"},{"hospital","pain"},{"medicine","pain"},{"wound","pain"},{"fever","pain"},
    {"strong","strength"},{"power","strength"},{"run","strength"},{"exercise","strength"},{"fight","strength"},{"sport","strength"},
    /* emotion */
    {"happy","joy"},{"smile","joy"},{"laugh","joy"},{"celebrate","joy"},{"dance","joy"},{"fun","joy"},{"enjoy","joy"},
    {"sad","grief"},{"cry","grief"},{"mourn","grief"},{"sorrow","grief"},{"funeral","grief"},{"tears","grief"},
    {"love","love"},{"kiss","love"},{"hug","love"},{"romance","love"},{"wedding","love"},{"marry","love"},
    {"afraid","fear"},{"scared","fear"},{"panic","fear"},{"worry","fear"},{"nightmare","fear"},{"danger","fear"},
    {"angry","anger"},{"mad","anger"},{"rage","anger"},{"hate","anger"},{"yell","anger"},{"shout","anger"},
    {"miss","longing"},{"yearn","longing"},{"homesick","longing"},{"nostalgia","longing"},
    {"tired","tired"},{"exhausted","tired"},{"weary","tired"},{"sleepy","tired"},{"bored","tired"},
    {"stress","stress"},{"pressure","stress"},{"overwhelm","stress"},{"busy","stress"},{"rush","stress"},
    /* verbs */
    {"go","go"},{"walk","go"},{"move","go"},{"travel","go"},{"drive","go"},{"leave","go"},{"arrive","go"},{"come","go"},{"ran","go"},{"went","go"},{"walked","go"},
    {"make","make"},{"build","make"},{"create","make"},{"produce","make"},{"craft","make"},
    {"break","break"},{"destroy","break"},{"smash","break"},{"crash","break"},{"tear","break"},
    {"see","see"},{"look","see"},{"watch","see"},{"read","see"},{"notice","see"},{"found","see"},{"saw","see"},
    {"speak","speak"},{"say","speak"},{"tell","speak"},{"talk","speak"},{"call","speak"},{"sing","speak"},{"said","speak"},{"told","speak"},
    {"hear","hear"},{"listen","hear"},{"sound","hear"},{"music","hear"},{"song","hear"},
    {"seek","seek"},{"search","seek"},{"hunt","seek"},{"explore","seek"},
    {"give","give"},{"share","give"},{"offer","give"},{"send","give"},{"gave","give"},
    {"want","want"},{"wish","want"},{"desire","want"},{"need","want"},{"hope","want"},
    {"miss","miss"},{"lost","miss"},{"gone","miss"},{"absent","miss"},{"lonely","miss"},
    {"agree","agree"},{"yes","agree"},{"accept","agree"},{"nod","agree"},{"peace","agree"},
    /* social */
    {"home","home"},{"house","home"},{"room","home"},{"door","home"},{"kitchen","home"},{"window","home"},{"roof","home"},
    {"outside","outside"},{"nature","outside"},{"park","outside"},{"beach","outside"},{"city","outside"},{"market","outside"},{"shop","outside"},{"street","outside"},
    {"work","work"},{"job","work"},{"office","work"},{"business","work"},{"career","work"},
    {"internet","internet"},{"online","internet"},{"email","internet"},{"phone","internet"},{"website","internet"},
    {"friend","bond"},{"family","bond"},{"together","bond"},{"team","bond"},{"community","bond"},
    {"war","conflict"},{"battle","conflict"},{"attack","conflict"},{"argue","conflict"},{"enemy","conflict"},
    /* mind */
    {"know","know"},{"learn","know"},{"study","know"},{"school","know"},{"book","know"},{"understand","know"},{"knew","know"},{"taught","know"},
    {"idea","idea"},{"plan","idea"},{"concept","idea"},{"solution","idea"},{"invention","idea"},
    {"think","think"},{"thought","think"},{"consider","think"},{"wonder","think"},{"mind","think"},{"decide","think"},
    {"dream","dream"},{"imagine","dream"},{"fantasy","dream"},{"story","dream"},{"wish","dream"},
    {"remember","remember"},{"memory","remember"},{"past","remember"},{"history","remember"},{"forgot","remember"},
    {"lie","lie"},{"cheat","lie"},{"fake","lie"},{"trick","lie"},{"pretend","lie"},
    /* space */
    {"road","path"},{"street","path"},{"way","path"},{"direction","path"},{"trail","path"},
    {"up","up"},{"rise","up"},{"climb","up"},{"above","up"},{"high","up"},{"tall","up"},{"top","up"},
    {"down","down"},{"fall","down"},{"drop","down"},{"below","down"},{"low","down"},{"fell","down"},
    {"far","far"},{"distant","far"},{"away","far"},{"abroad","far"},{"remote","far"},
    {"back","back"},{"return","back"},{"behind","back"},{"again","back"},
    /* time */
    {"before","before"},{"earlier","before"},{"yesterday","before"},{"once","before"},{"ago","before"},
    {"now","now"},{"today","now"},{"moment","now"},{"current","now"},
    {"after","after"},{"later","after"},{"tomorrow","after"},{"soon","after"},{"next","after"},{"then","after"},
    {"never","never"},{"no","never"},{"nothing","never"},{"nobody","never"},{"stop","never"},
    {"always","always"},{"forever","always"},{"every","always"},{"daily","always"},{"constant","always"},
    /* grammar */
    {"not","not"},{"don't","not"},{"can't","not"},{"won't","not"},{"bad","not"},{"wrong","not"},
    {"many","many"},{"much","many"},{"lots","many"},{"several","many"},{"huge","many"},{"thousand","many"},
    {"very","much"},{"really","much"},{"extremely","much"},{"quite","much"},
    {"and","and"},{"also","and"},{"with","and"},{"both","and"},{"plus","and"},
    {"one","one"},{"single","one"},{"alone","one"},{"only","one"},{"first","one"},
    {"question","question"},{"ask","question"},{"why","question"},{"what","question"},{"curious","question"},
    {"how","how"},{"method","how"},{"way","how"},{"step","how"},
    {"because","cause"},{"reason","cause"},{"therefore","cause"},{"result","cause"},
    /* extended */
    {"i","me"},{"my","me"},{"myself","me"},
    {"you","you"},{"your","you"},{"yourself","you"},
    {"other","other"},{"another","other"},{"different","other"},{"new","other"},{"strange","other"},
    {"money","money"},{"dollar","money"},{"pay","money"},{"buy","money"},{"sell","money"},{"rich","money"},{"poor","money"},{"price","money"},
    {"change","change"},{"transform","change"},{"grow","change"},{"develop","change"},{"evolve","change"},
    {"write","write"},{"pen","write"},{"paper","write"},{"letter","write"},{"note","write"},{"wrote","write"},{"poem","write"},{"code","write"},
    {"choose","choose"},{"pick","choose"},{"decide","choose"},{"select","choose"},{"vote","choose"},
    {"help","help"},{"assist","help"},{"support","help"},{"save","help"},{"protect","help"},
    {"have","have"},{"own","have"},{"keep","have"},{"hold","have"},{"got","have"},{"had","have"},
    {"free","free"},{"freedom","free"},{"liberty","free"},{"escape","free"},{"open","free"},
    {"death","death"},{"die","death"},{"dead","death"},{"kill","death"},{"grave","death"},{"died","death"},
    {"music","music"},{"song","music"},{"melody","music"},{"guitar","music"},{"piano","music"},{"drum","music"},{"sang","music"},{"singing","music"},
    {"good","good"},{"great","good"},{"nice","good"},{"kind","good"},{"beautiful","good"},{"wonderful","good"},{"fine","good"},
    /* super */
    {"small","small"},{"tiny","small"},{"little","small"},{"short","small"},{"few","small"},
    {"same","same"},{"equal","same"},{"similar","same"},{"identical","same"},
    {"is","BE"},{"am","BE"},{"are","BE"},{"was","BE"},{"were","BE"},{"being","BE"},{"become","BE"},{"feel","BE"},
    {"wait","wait"},{"patience","wait"},{"pause","wait"},{"delay","wait"},{"stay","wait"},
    {NULL, NULL}
};

static const char* SEM_STOP_WORDS[] = {
    "the","a","an","to","of","in","for","on","at","by","from","about","into",
    "through","during","above","between","out","off","over","under","again",
    "further","here","there","when","where","all","each","both","few","more",
    "most","some","such","so","than","too","just","but","if","or","while","as",
    "until","that","this","these","those","it","its","itself","which","who","whom",
    NULL
};

static int semtok_is_stop_word(const char* w){
    for(int i=0; SEM_STOP_WORDS[i]; i++)
        if(strcmp(w,SEM_STOP_WORDS[i])==0) return 1;
    return 0;
}
/* glyph id 0..87 by name; -1 if not a base glyph */
static int semtok_find_glyph(const char* name){
    for(int i=0;i<GLYPH_COUNT;i++)
        if(strcmp(name,GLYPH_NAMES[i])==0) return i;
    return -1;
}
/* one word -> glyph id, -1 if unknown or stop-word */
static int semtok_word(const char* word){
    int id=semtok_find_glyph(word);
    if(id>=0) return id;
    for(int i=0; SEM_WORD_MAP[i].word; i++)
        if(strcmp(word,SEM_WORD_MAP[i].word)==0)
            return semtok_find_glyph(SEM_WORD_MAP[i].glyph);
    return -1;
}
/* a line of English -> glyph ids; lowercases, strips punctuation, drops stop
 * words and unmapped words, suppresses consecutive dups. returns count. */
static int semtok_line(const char* line, int* out, int max_tokens){
    char buf[4096];
    strncpy(buf,line,4095); buf[4095]='\0';
    for(int i=0;buf[i];i++) if(buf[i]>='A'&&buf[i]<='Z') buf[i]+=32;
    for(int i=0;buf[i];i++){ unsigned char c=(unsigned char)buf[i];
        if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c==' '||c=='\''||c=='-')) buf[i]=' '; }
    int n=0, last_id=-1;
    char* tok=strtok(buf," \t\n");
    while(tok && n<max_tokens){
        if(*tok=='\0'||semtok_is_stop_word(tok)){ tok=strtok(NULL," \t\n"); continue; }
        int id=semtok_word(tok);
        if(id>=0 && id!=last_id){ out[n++]=id; last_id=id; }
        tok=strtok(NULL," \t\n");
    }
    return n;
}

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
