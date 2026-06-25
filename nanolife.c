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

/* ── Phase A: the mortal clock (Vera's order) ── */
#define RENT    0.001f            /* rent on existing — the arrow of time */
#define E_BORN  1.0f              /* energy at birth */

/* ── Phase A step 2: metabolism — living Hebbian-V plasticity (the fuel) ── */
#define RANK           4          /* low-rank Hebbian LoRA (canon cavellman.c:43) */
#define HEBBIAN_LR     0.001f     /* canon cavellman.c:423 */
#define HEBBIAN_DECAY  0.9999f    /* canon cavellman.c:424 */
#define PASSIVE_SIGNAL 0.3f       /* reading the world = passive (cavellman.c:654) */
#define DIGEST_YIELD   80.0f      /* energy per unit |ΔB_v| — calibrated: avg dB~2e-5, break-even~50 */
#define BE_GAIN        3.0f       /* BE turns the next glyph's charge inward, amplified */
#define BE_INTENSITY   2.0f       /* BE intensifies the glyph's metabolic nature (becoming costs) */

/* ── Phase A step 4: scar — permanent wounds (never decay) ── */
#define SCAR_RATE   0.01f         /* how fast an agitating glyph wounds itself */
#define SCAR_RENT   0.5f          /* total scar raises rent — a wounded organism burns faster */
#define ACHE        0.05f         /* a scarred glyph aches on contact — the wound returns */

/* ── Phase A step 5: dream — self-ingestion when starving (Klaus's meta-loop) ── */
#define DREAM_THRESH 0.6f         /* dream only when hungry (energy below this) */
#define DREAM_FRAC   0.5f         /* a dream is half-metabolism — cheaper than real food */
#define DREAM_DECAY  50.0f        /* dream yield decays with the streak — no immortality on dreams */

typedef struct {
    float rms1[E], rms2[E];
    float wq[E*E], wk[E*E], wv[E*E], wo[E*E];
    float fc1[FFN*E], fc2[E*FFN];
    float heb_A_v[E*RANK], heb_B_v[RANK*E]; /* living Hebbian LoRA on V — runtime δ */
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
static float gauss(float mu, float sigma){ /* Box-Muller on frand — deterministic by seed */
    float u1=(frand()+1.0f)*0.5f, u2=(frand()+1.0f)*0.5f;
    if(u1<1e-7f) u1=1e-7f;
    return mu + sigma*sqrtf(-2.0f*logf(u1))*cosf(6.2831853f*u2);
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

/* ── Hebbian LoRA (vendored byte-faithful from caveLLMan, no backprop) ──
 * apply: out += B @ (A @ x).  cavellman.c:511  (A:[dim×rank], B:[rank×dim]). */
static void apply_hebbian_lora(float* out, const float* A, const float* B,
                               const float* x, int dim, int rank){
    float proj[RANK];
    for(int r=0;r<rank;r++){ float s=0;
        for(int j=0;j<dim;j++) s+=A[j*rank+r]*x[j]; proj[r]=s; }
    for(int i=0;i<dim;i++){ float s=0;
        for(int r=0;r<rank;r++) s+=B[r*dim+i]*proj[r]; out[i]+=s; }
}
/* update (the δ in θ=ε+γ+αδ): A += lr·signal·(x ⊗ Bᵀdy); B += lr·signal·(Aᵀx ⊗ dy);
 * then weight decay.  notorch.c:2683, naive path verbatim — stack, ASan-clean. */
static void nt_hebbian_step(float* A, float* B, int out_dim, int in_dim, int rank,
                            const float* x, const float* dy, float signal,
                            float lr, float decay){
    if(!A||!B||!x||!dy) return;
    float proj[RANK];
    for(int r=0;r<rank;r++){ float s=0;
        for(int j=0;j<out_dim;j++) s+=B[r*out_dim+j]*dy[j]; proj[r]=s; }
    float alpha=lr*signal;
    for(int i=0;i<in_dim;i++)
        for(int r=0;r<rank;r++) A[i*rank+r]+=alpha*x[i]*proj[r];
    float proj2[RANK];
    for(int r=0;r<rank;r++){ float s=0;
        for(int i=0;i<in_dim;i++) s+=A[i*rank+r]*x[i]; proj2[r]=s; }
    for(int r=0;r<rank;r++)
        for(int j=0;j<out_dim;j++) B[r*out_dim+j]+=alpha*proj2[r]*dy[j];
    if(decay>0.0f&&decay<1.0f){
        for(int i=0;i<in_dim*rank;i++) A[i]*=decay;
        for(int i=0;i<rank*out_dim;i++) B[i]*=decay;
    }
}

/* ── glyph charge: the SECOND signal — each glyph is also an opcode ───────
 * a glyph acts on the organism two ways: slow (weights/Hebbian, via forward)
 * and fast (this charge — a direct somatic reflex, like a cat flinching from
 * fire). INVARIANT (Desktop's law): the charge writes only MODES (S, dissonance)
 * — never energy/scar/contour. a burning glyph costs energy ONLY through
 * metabolism (metab_factor<1), never by a direct write. modes bend behaviour;
 * the price of life is always paid by organs, never cheated. */
typedef struct { float S, dissonance; } Modes;
typedef struct { float mode_dS, mode_dDiss, metab_factor; } GlyphCharge;
static GlyphCharge charge[VOCAB];
static int BE_ID = -1;            /* the BE operator's glyph id (set in charges_init) */

static void charges_init(void){
    for(int i=0;i<VOCAB;i++){ charge[i].mode_dS=0.0f; charge[i].mode_dDiss=0.0f; charge[i].metab_factor=1.0f; }
    /* {glyph, dS, dDiss, metab_factor}: catabolic = burn (factor<1) / anabolic = feed (factor>1) */
    static const struct { const char* g; float dS, dDiss, f; } spec[] = {
        {"fire",   +0.05f, +0.10f, 0.2f}, {"anger",   +0.04f, +0.15f, 0.3f},
        {"stress", -0.02f, +0.20f, 0.3f}, {"conflict",-0.03f, +0.15f, 0.4f},
        {"pain",   -0.05f, +0.20f, 0.4f}, {"fear",    -0.06f, +0.18f, 0.5f},
        {"death",  -0.10f, +0.10f, 0.1f},
        {"food",   +0.02f, -0.10f, 2.0f}, {"water",   +0.01f, -0.08f, 1.8f},
        {"sleep",  -0.01f, -0.15f, 1.5f}, {"joy",     +0.06f, -0.12f, 1.6f},
        {"love",   +0.08f, -0.15f, 1.7f}, {"music",   +0.05f, -0.10f, 1.4f},
        {"good",   +0.04f, -0.08f, 1.3f}, {"me",      +0.03f,  0.00f, 1.0f},
        {NULL,0,0,0}
    };
    for(int i=0; spec[i].g; i++){ int id=semtok_find_glyph(spec[i].g);
        if(id>=0){ charge[id].mode_dS=spec[i].dS; charge[id].mode_dDiss=spec[i].dDiss; charge[id].metab_factor=spec[i].f; } }
    BE_ID = semtok_find_glyph("BE");
}
/* the charge fires here — Modes* only in scope, no life-scalar pointer (invariant by type) */
static void charge_apply(Modes* mo, int glyph){
    if(glyph<0||glyph>=VOCAB) return;
    mo->S          = tanhf(mo->S + charge[glyph].mode_dS);
    mo->dissonance = mo->dissonance + charge[glyph].mode_dDiss;
}
/* BE — the reflexive operator: the charge of the glyph AFTER be is turned inward, on
 * the self, amplified (BE_GAIN). "BE fire" = become fire, not eat it. Klaus's meta-loop
 * made atomic; haiku's speak-from-self. Invariant holds — still modes only. */
static void charge_apply_reflexive(Modes* mo, int glyph){
    if(glyph<0||glyph>=VOCAB) return;
    mo->S          = tanhf(mo->S + BE_GAIN*charge[glyph].mode_dS);
    mo->dissonance = mo->dissonance + BE_GAIN*charge[glyph].mode_dDiss;
}

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
        /* seed Hebbian A_v ~ N(0,1e-3): unlock the zero-lock fixed point (both
         * factors zero → ΔB≡0 forever). B_v stays 0 from calloc. */
        for(int i=0;i<E*RANK;i++) y->heb_A_v[i]=gauss(0.0f,1e-3f);
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
                              matvec(y->wv,xn[t],v[t],E,E);
                              apply_hebbian_lora(v[t],y->heb_A_v,y->heb_B_v,xn[t],E,RANK); }
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

/* digest a line: perceive it (forward), learn it into the living V-adapters
 * (Hebbian, no backprop), and let each glyph's somatic charge fire. returns the
 * metabolic yield = Σ over glyphs of (Σ|ΔB_v| · metab_factor): how much the
 * organism CHANGED on eating, scaled by whether the glyph feeds or burns. (Yield
 * on the derivative of competence kills immortality on a mastered corpus.)
 * INVARIANT: the charge writes modes only (charge_apply); energy/scar are never
 * touched here — a burning glyph costs energy THROUGH a low metab_factor, never
 * by a direct write. */
static float digest(Model* m, Modes* mo, float* scar, const int* glyphs, int n){
    static float logits[VOCAB];
    forward(m,glyphs,n,logits);          /* perception, modulated by current adapters */
    static float before[RANK*E];
    float yield=0.0f;
    int be_armed=0;
    for(int g=0;g<n;g++){
        int id=glyphs[g];
        if(id<0||id>=VOCAB) continue;
        const float* x_emb=m->wte+(size_t)id*E;       /* x = dy = the glyph's embedding */
        float dB=0.0f;
        for(int l=0;l<NL;l++){
            Layer* y=&m->L[l];
            memcpy(before,y->heb_B_v,sizeof(before));
            nt_hebbian_step(y->heb_A_v,y->heb_B_v,E,E,RANK,
                            x_emb,x_emb,PASSIVE_SIGNAL,HEBBIAN_LR,HEBBIAN_DECAY);
            for(int i=0;i<RANK*E;i++) dB+=fabsf(y->heb_B_v[i]-before[i]);
        }
        float f=charge[id].metab_factor;
        if(id==BE_ID){                                /* the operator is not a meal — arms reflexivity, yields nothing */
            be_armed=1; (void)f;
        } else if(be_armed){                          /* "BE X": become X — charge turned inward, amplified */
            charge_apply_reflexive(mo,id);
            yield += dB * (1.0f + BE_INTENSITY*(f-1.0f)); /* becoming intensifies the metabolic nature */
            be_armed=0;
        } else {                                      /* plain X: charge acts outward */
            charge_apply(mo,id);
            yield += dB*f;                            /* cost/gain paid through metabolism */
        }
        if(id!=BE_ID){                                /* scar: agitating glyphs leave permanent wounds */
            scar[id] += SCAR_RATE * fmaxf(0.0f, charge[id].mode_dDiss);
            mo->dissonance += ACHE * scar[id];        /* the word hurts, therefore it returns (brodsky) */
        }
    }
    return yield;
}

static const char* glyph_name(int id){
    if(id<GLYPH_COUNT) return GLYPH_NAMES[id];
    if(id==BOS_ID) return "BOS";
    return "MASK";
}

/* ── main — Phase A step 3a: the breathing clock with a second signal ──
 * usage: ./nanolife [seed] [diet-glyph]
 *   no diet  -> eats lifeisshit/world.txt line by line, then starves.
 *   diet     -> an infinite mono-glyph diet (e.g. fire / food) for A/B: does
 *               the charge bend life differently at the SAME weights? */
static void recent_push(int* recent, int* rn, int g){  /* ring of last glyphs — the dream's context */
    if(*rn < CTX) recent[(*rn)++]=g;
    else { memmove(recent, recent+1, (CTX-1)*sizeof(int)); recent[CTX-1]=g; }
}
int main(int argc, char** argv){
    unsigned long seed = argc>1 ? strtoul(argv[1],NULL,10) : 42UL;
    seed_rng(seed);
    charges_init();
    Model* m=model_new();
    long params=(long)(sizeof(Model)/sizeof(float));
    /* optional diet: space-separated exact glyph names, e.g. "fire" or "BE fire" */
    int diet_glyphs[CTX]; int diet_n=0;
    if(argc>2){
        char dbuf[256]; strncpy(dbuf,argv[2],255); dbuf[255]='\0';
        char* tk=strtok(dbuf," ");
        while(tk && diet_n<CTX){ int gid=semtok_find_glyph(tk); if(gid>=0) diet_glyphs[diet_n++]=gid; tk=strtok(NULL," "); }
    }
    int diet_mode = diet_n>0;

    printf("nanolife — a mortal clock that can eat.  seed=%lu  diet=%s\n",
           seed, (diet_mode? argv[2] : "world"));
    printf("  params=%ld  vocab=%d  E=%d L=%d H=%d ctx=%d  yield=%.1f rent=%.4f\n",
           params,VOCAB,E,NL,NH,CTX,(double)DIGEST_YIELD,(double)RENT);

    /* birth: one perception of the world through the membrane */
    { int t[CTX]; int bn=semtok_line("the sun is fire and i feel fear in the dark",t,CTX);
      if(bn<1){ t[0]=BOS_ID; bn=1; }
      printf("  first breath:"); for(int i=0;i<bn;i++) printf(" %s",glyph_name(t[i])); printf("\n\n"); }

    FILE* food = diet_mode ? NULL : fopen("lifeisshit/world.txt","r");
    if(!diet_mode && !food){ printf("  no world to eat (lifeisshit/world.txt). да будет так.\n"); free(m); return 1; }

    /* rent gnaws every tick; a glyph that MOVES the V-adapters (|ΔB_v|), scaled
     * by its metab_factor (fire burns, food feeds), postpones death. one scalar
     * carries metabolism and death; modes (S, dissonance) ride the second signal. */
    Modes mo = {0.0f, 0.0f};
    static float scar[VOCAB]; for(int i=0;i<VOCAB;i++) scar[i]=0.0f; /* permanent wounds (never decay) */
    int   scar_on = (getenv("NL_NOSCAR")==NULL);  /* A/B toggle: NL_NOSCAR=1 lifts the wound's weight */
    int   dream_on = (getenv("NL_NODREAM")==NULL);/* A/B toggle: NL_NODREAM=1 forbids self-feeding */
    float scar_total=0.0f;
    int   recent[CTX]; int recent_n=0;            /* ring of last glyphs — the dream's context */
    long  dream_streak=0;
    float energy=E_BORN;
    long  tick=0;
    char  line[4096];
    int   glyphs[CTX];
    int   fed=1;
    while(energy>0.0f && tick<200000){          /* cap = falsification guard: it MUST die */
        tick++;
        energy -= RENT * (1.0f + (scar_on? SCAR_RENT*scar_total : 0.0f)); /* wounds make rent heavier */
        float yield=0.0f;
        int   dreaming=0;
        if(diet_mode){
            yield=digest(m,&mo,scar,diet_glyphs,diet_n);
            for(int i=0;i<diet_n;i++) recent_push(recent,&recent_n,diet_glyphs[i]);
            dream_streak=0;
        } else if(fed && fgets(line,sizeof(line),food)){
            int n=semtok_line(line,glyphs,CTX);
            if(n>=1){ yield=digest(m,&mo,scar,glyphs,n);
                for(int i=0;i<n;i++) recent_push(recent,&recent_n,glyphs[i]); dream_streak=0; }
        } else {                                 /* corpus exhausted -> starvation, or dream */
            fed=0;
            if(dream_on && energy<DREAM_THRESH && recent_n>0){  /* eat your own predicted glyph */
                static float dl[VOCAB]; forward(m,recent,recent_n,dl);
                int dg=0; for(int i=1;i<VOCAB;i++) if(dl[i]>dl[dg]) dg=i;
                float dy=digest(m,&mo,scar,&dg,1);
                yield = dy * DREAM_FRAC * expf(-(float)dream_streak/DREAM_DECAY); /* dreams thin out */
                recent_push(recent,&recent_n,dg);
                dream_streak++; dreaming=1;
            }
        }
        energy += DIGEST_YIELD*yield;
        scar_total=0.0f; for(int i=0;i<VOCAB;i++) scar_total+=scar[i];
        if(tick<=30 || tick%100==0)
            printf("  t%-6ld E%+.5f  S%+.3f  diss%+.3f  scar%.3f  y %.2e  %s\n",
                   tick,energy,(double)mo.S,(double)mo.dissonance,(double)scar_total,yield,
                   (dreaming?"DREAM":(diet_mode?"diet":(fed?"eat":"STARVE"))));
    }
    if(energy>0.0f)
        printf("\n  STILL ALIVE at tick %ld (cap) — immortality hole, investigate.\n",tick);
    else
        printf("\n  died at tick %ld — S%+.3f diss%+.3f scar%.3f.  да будет так.\n",
               tick,(double)mo.S,(double)mo.dissonance,(double)scar_total);
    if(food) fclose(food);
    free(m);
    return 0;
}
