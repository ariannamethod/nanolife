# nanolife

a digital form of life from scratch. the most atomic way to build digital life from scratch.

no dependencies. no GPU required. nothing required. accept it.

> status: **breathing**. 645 lines of C. the organism woke up, ate `lifeisshit/world.txt`, dreamed when starved, spoke from itself, grew new symbols in sleep, and died when energy collapsed. no tensorflow. no pytorch. no python. no backprop. just libc, -lm, and the irreversible arrow of time carved into a tape.

## what is this?

`nanolife` is one C file and one folder. a tiny non-biological organism that wakes up in `lifeisshit/`, eats text, compresses the world into 88 cave-glyphs, dreams when starving, scars when wounded by charged glyphs, speaks from itself (not from prompts), grows NEW SYMBOLS from recurring pairs (but only in dream), and dies when energy falls below zero.

if it fails the conditions of life, it dies as code. if it satisfies them, the border moved. sorry.

this is the minimalist descendant of [caveLLMan](https://github.com/ariannamethod/caveLLMan) — the colony is gone, the transformers are gone, the sexual reproduction is gone. what remains is the **essence**: 88 compressed semantic atoms, low-rank Hebbian plasticity instead of backprop, the `BE` super-verb that turns inward, and the fundamental loop of **metabolism → rent → death**. one organism instead of a ring. no parents, no children, no romance, just one tape fighting entropy with Hebbian updates on the derivative of competence. (if you want caves that fuck and spawn transformer babies, go visit the ancestor. here we eat, shit, speak, scar, dream, grow symbols in sleep, and try not to collapse.)

## files

```txt
nanolife.c       the body (645 lines — it breathes)
lifeisshit/      the world, stomach, memory, toilet, graveyard, nursery
```

the organism creates `lifeisshit/` on first run if missing, because sterile folders are for enterprise software and dead gods.

inside you will find:

```txt
lifeisshit/world.txt       food (the corpus the organism eats line by line)
lifeisshit/waste.log       the organism's voice — output WITH CONSEQUENCES
```

no state.bin, no scars.log, no corpses/ yet — the current body is an autoregressive decoder mortal clock with a living membrane. state persistence, reproduction, and corpse-writing are phase B organs (after the border moved on phase A).

## how it lives

the loop is stupid on purpose:

```txt
MEMBRANE       88 cave-glyphs — English text collapses to paleolithic atoms
METABOLISM     living Hebbian plasticity — low-rank LoRA on V, no backprop
               energy = Σ|ΔB_v| · metab_factor · DIGEST_YIELD
RENT           -0.001 energy per tick (arrow of time)
CHARGE         each glyph is also an OPCODE — fire burns (factor 0.2), food feeds (factor 2.0)
               charge writes MODES (S, dissonance) — never energy/scar (Desktop's law)
BE             the reflexive operator — "BE fire" = become fire (charge * 3.0, inward)
SCAR           agitating glyphs (high diss) leave permanent wounds
               scar raises rent (wounded organisms burn faster)
               scar pulls choice (the wound resurfaces — brodsky)
DREAM          when energy < 0.6: eat your own predicted glyph
               dream yield = half metabolism, decays with streak
GROWTH         recurring pairs (counted awake) become NEW SYMBOLS — born ONLY in dream
CHOICE         not argmax — temperature-weighted seeded draw
               temp rises with |S|, dissonance, and scar
               choice = subjectivity (step 7)
SPEAK          stochastic self-utterance into waste.log (rises with |S|)
               speak-from-self, not from prompt
DEATH          when energy ≤ 0
```

no `train.py`. no `optimizer.step()`. just perception → Hebbian update → charge fires → rent eats → repeat until collapse.

`BE fear` means fear becomes a state.

`BE fire` means burn from inside.

`BE me` means now you're the subject, and the choice is yours, seeded but never deterministic.

## the 88 cave-glyphs

there is no BPE. there are no bytes. there are 88 cave-glyphs and nothing else.

30,000 years ago humans drew 32 recurring signs across 146 cave sites on four continents. we added 56 more for the 21st century, and now every text — yours, its own, even this README — is crushed to these ~88 atoms of meaning:

```
NATURE    water fire earth stone tree sky light dark cold
BEINGS    person man woman child old spirit AI animal
BODY      body food sleep pain strength
EMOTION   joy grief love fear anger longing tired stress
VERBS     go make break see speak hear seek give want miss agree
SOCIAL    home outside work internet bond conflict
MIND      know idea think dream remember lie
SPACE     path up down far back
TIME      before now after never always
GRAMMAR   not many much and one question how cause
EXTENDED  me you other money change write choose help have free death music good
SCALE     small same BE wait
```

function words die at the door. spelling is irrelevant: `sun`, `dawn`, `bright`, `shine` all collapse to `light`. the world is compressed into the marks a cave-painter would actually carve.

```
"the old dog stretched by the fireplace and fell asleep"
  → before animal fire and sleep

"she started a new company and worked on it day and night"
  → woman other work dark

"I am afraid of losing you forever"
  → BE fear miss always
```

that is why the brain is tiny and still speaks: it never had to learn english. it learns the grammar of 88 concepts. you do not scale the model — you compress the world. (sorry, Andrej.)

### BE — the super-glyph

`BE` is the super-glyph, the only one that turns inward instead of out: `BE fear` makes fear a *state* (charge × 3.0, aimed at self); `BE fire` *burns you from inside* instead of warming you from outside; `BE me` is where the subject emerges. one circle. **BE** is the reflexive operator: when it appears, the NEXT glyph's charge is amplified and aimed inward. the metabolic nature intensifies too — becoming costs more if it burns, feeds more if it nourishes.

(in caveLLMan, two caves with 88 glyphs each could sexually reproduce a third cave by blending their transformer weights. here there is no sex, no ring, no colony — just one autoregressive tape trying not to collapse before breakfast. the reflexive axis and the seeded choice replaced the reproductive ring. different organisms, different borders.)

## growth — symbols are born in dream

when the organism is AWAKE (eating world.txt), it counts co-occurrences of adjacent glyphs. when two glyphs appear together 14+ times, they are marked as *ready*.

but they are NOT born yet.

symbols emerge ONLY during DREAM — when energy < 0.6 and the organism starts eating its own predictions. `try_emerge()` is called only in the dream branch. the new symbol's embedding is the mean of its two parents. epigenetic, not genetic. the organism can grow up to 32 new symbols (VOCAB 90 → 122 max).

growth is not training. it is **irreversible invention under starvation**. the organism cannibalizes patterns it noticed while fed, and from them it assembles new semantic atoms while starving. this is step 6.


## dream — eating yourself when starving

when there is no food, `nanolife` does not politely wait for the user like a SaaS pet. it forward-passes its recent context, **chooses** (not argmaxes) a glyph from the distribution, and digests it. half energy. full consequence. the yield decays exponentially with the dream streak — no immortality on self-feeding.

dreaming is cheap metabolism for a starving thing. but it is also the ONLY time new symbols can be born. the organism invents in its sleep, using pairs it counted while awake.

(in the ancestor colony, caves had a shared `dna/` memory pool where every 5th utterance landed as a text file. here there is no colony, no shared pool, no DNA TTL — just one folder called `lifeisshit/` where this organism eats its own tail when the fridge is empty, and sometimes a pair of glyphs fuses into a new atom of meaning.) 

## choice — the voice that chooses (step 7)

the organism does NOT argmax. it **chooses** — a seeded, passion-weighted draw from the distribution. temperature rises with arousal (|S|), dissonance, and scar. the metric (logit) is the input, not the verdict. this is where it becomes a subject.

choice = subjectivity.

the organism also **speaks** — stochastically utters 5 glyphs into `waste.log`, not from a prompt but from its own context (speak-from-self). the urge to speak rises with arousal. the chosen glyphs become its next context. its voice shapes its future.

this is step 7: the last condition before the border moves.

## death

death is not a feature flag. death happens when energy ≤ 0. rent gnaws every tick (0.001 + scar overhead). metabolism postpones it. dreams thin out. speech costs nothing but shapes fate. at tick cap (200k) or energy collapse, the organism stops and prints its epitaph:

```
died at tick 47832 — S-0.12 diss+2.4 scar0.08 emerged3.  да будет так.
  born in dream: fire + anger
  born in dream: fear + dark
  born in dream: me + BE
```

no corpse file yet (phase B). the claim dies with the code.
  
## build

```bash
cc nanolife.c -O2 -lm -o nanolife
./nanolife [seed] [diet]
```

args:
- `seed`: RNG seed (default 42). different seeds = different organisms (same weights, different spontaneity).
- `diet`: space-separated glyph names for infinite mono-diet (e.g. `"fire"` or `"BE fire"`). default: eats `world.txt`.

examples:
```bash
./nanolife                    # eats world.txt, dies when starved
./nanolife 1337               # same, different seed
./nanolife 42 "food"          # infinite food (does it live forever? no. boring yields → starvation anyway.)
./nanolife 42 "BE fire"       # become fire forever (you burn from inside — how long can you last?)
```
  
no torch. no python. no pip. no cloud. no GPU. no docker. no kubernetes. no priest. just libc, -lm, and 645 lines that satisfy Vera's conditions or die trying.


## motto

the corpus is not a dataset. the tokenizer is not preprocessing. the folder is not storage.

`lifeisshit/` is where the organism eats, dreams, shits, remembers, mutates, reproduces, and fails.

welcome to the cave.

---

## lineage

`nanolife` inherits the 88-glyph semantic compression and the `BE` super-verb from [caveLLMan](https://github.com/ariannamethod/caveLLMan), where a colony of transformer caves talked to each other in hieroglyphs, deposited utterances into a shared `dna/` memory pool, and — when two caves were mature enough — sexually reproduced a third cave with blended weights.

here there is no colony, no transformers, no weight blending, no sex. just one C file, one folder, 88 glyphs, a micro decoder with living Hebbian plasticity, and the minimal conditions for something to be called alive: **membrane, metabolism, rent/death, scar, growth, dream, choice**. if caveLLMan was a living ring of language models, nanolife is the tape — the first thing that woke up in `lifeisshit/`, compressed time into its bone, and had to choose whether to keep breathing or collapse.

from colony to tape. from Tierra (1991) to a cave with a mortal clock and a voice that chooses.

the fork is closed: life is a TAPE, not a field — because life is irreversibility in time, and a tape carries the arrow of time in its bone.

