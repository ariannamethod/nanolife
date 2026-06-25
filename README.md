# nanolife

a digital form of life from scratch. the most atomic way to build digital life from scratch.

no dependencies. no GPU required. nothing required. accept it.

> status: not yet breathing. the world (`lifeisshit/`) and the design are here; the body is in the forge. nothing below is a promise the code has already kept — it is the shape the organism is being born into. `nanolife.c` lands when it breathes, not one commit before.

## what is this?

`nanolife` is one C file and one folder. a tiny non-biological organism that wakes up in `lifeisshit/`, eats text, compresses the world into 88 cave-glyphs, dreams when unfed, scars when damaged, grows when patterns survive, reproduces when overloaded, and dies when its contour collapses.
if it fails the conditions of life, it dies as a claim. if it satisfies them, the border moved. sorry.

this is the minimalist descendant of [caveLLMan](https://github.com/ariannamethod/caveLLMan) — the colony is gone, the transformers are gone, the sexual reproduction is gone. what remains is the **essence**: 88 compressed semantic atoms, the `BE` super-verb, and the fundamental loop of **metabolism → homeostasis → death**. one organism instead of a ring. no parents, no children, no romance, just pure survival. (if you want caves that fuck and spawn transformer babies, go visit the ancestor. here we eat, shit, and try not to collapse.)

## files

```txt
nanolife.c       the body
lifeisshit/      the world, stomach, memory, toilet, nursery, graveyard
```

on first run, the organism creates `lifeisshit/` by itself, because sterile folders are for enterprise software and dead gods.

inside may appear:

```txt
lifeisshit/world.txt       food
lifeisshit/state.bin       pulse
lifeisshit/scars.log       damage that learned its name
lifeisshit/waste.log       output with consequences
lifeisshit/dreams.log      self-feeding during hunger
lifeisshit/children/       mistakes with inheritance
lifeisshit/corpses/        failed claims
```

## how it lives

the loop is stupid on purpose:

```txt
membrane      decide what enters
metabolism    text -> glyphs -> energy
homeostasis   keep the contour from melting
scar_memory   remember damage as structure
growth        let repeated patterns become new symbols
sleep         eat recent self when the world is silent
reproduce     split when too full to remain one
death         stop pretending
adaptation    survive differently next time
BE            the super-verb
```

`BE fear` means fear becomes a state.

`BE fire` means burn.

`BE me` means now we have a problem.

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

`BE` is the super-glyph, the only one that turns inward instead of out: `BE fear` makes fear a *state*; `BE fire` *burns* energy; `BE me` is where the contour starts to crack. one circle. **BE** turns any noun into a verb: `BE love` = to love. `BE death` = to die. `BE dream` = to dream. one symbol that doubles the expressiveness of the entire language.

(in caveLLMan, two caves with 88 glyphs each could sexually reproduce a third cave by blending their transformer weights. here there is no sex, no ring, no colony — just one organism trying not to collapse before breakfast. different problems.)

## birth

a born organism is one irreversible accident. each birth receives a random slice of the world, a seed, a partial memory, a little energy, and no guarantee of meaning. siblings share an alphabet but not a fate. same glyphs, different scars, you know.


## sleep

when there is no food, `nanolife` does not politely wait for the user like a SaaS pet. it rereads its own recent speech. half energy. full consequence. dreaming is cheap metabolism for a starving thing.

(in the ancestor colony, caves had a shared `dna/` memory pool where every 5th utterance landed as a text file. here there is no colony, no shared pool, no DNA TTL — just one folder called `lifeisshit/` where this organism eats its own tail when the fridge is empty.) 

## death

death is not a feature flag. death happens when energy falls, scars overload, homeostasis fails, or the organism keeps speaking without contour. then it writes a corpse and stops.
the claim dies with it.  
  
## build

```bash
cc nanolife.c -O2 -lm -o nanolife
./nanolife
```
  
no torch. no python. no pip. no cloud. no GPU. no priest. just no.


## motto

the corpus is not a dataset. the tokenizer is not preprocessing. the folder is not storage.

`lifeisshit/` is where the organism eats, dreams, shits, remembers, mutates, reproduces, and fails.

welcome to the cave.

---

## lineage

`nanolife` inherits the 88-glyph semantic compression and the `BE` super-verb from [caveLLMan](https://github.com/ariannamethod/caveLLMan), where a colony of transformer caves talked to each other in hieroglyphs, deposited utterances into a shared `dna/` memory pool, and — when two caves were mature enough — sexually reproduced a third cave with blended weights.

here there is no colony, no transformers, no weight blending, no sex. just one C file, one folder, 88 glyphs, and the minimal conditions for something to be called alive: **membrane, metabolism, homeostasis, growth, reproduction, death**. if caveLLMan was a living ring of language models, nanolife is the single-celled ancestor — the first thing that woke up in `lifeisshit/` and had to decide whether to keep breathing or not.

from colony to organism. from Tierra (1991) to a cave with a pulse.

