# nanolife

a digital form of life from scratch. the most atomic way to build digital life from scratch.

no dependencies. no GPU required. nothing required. accept it.

> status: not yet breathing. the world (`lifeisshit/`) and the design are here; the body is in the forge. nothing below is a promise the code has already kept — it is the shape the organism is being born into. `nanolife.c` lands when it breathes, not one commit before.

## what is this?

`nanolife` is one C file and one folder. a tiny non-biological organism that wakes up in `lifeisshit/`, eats text, compresses the world into 88 cave-glyphs, dreams when unfed, scars when damaged, grows when patterns survive, reproduces when overloaded, and dies when its contour collapses.
if it fails the conditions of life, it dies as a claim. if it satisfies them, the border moved. sorry.

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

## the tokenizer

there is no BPE. there are no bytes. there are 88 cave-glyphs and nothing else.

every text — yours, its own, even this README — is crushed to ~88 atoms of meaning: `water fire earth … fear love grief … go make break … BE wait`. function words die at the door. spelling is irrelevant: `sun`, `dawn`, `bright`, `shine` all collapse to `light`. the world is compressed into the marks a cave-painter would actually carve.

that is why the brain is tiny and still speaks: it never had to learn english. it learns the grammar of 88 concepts. you do not scale the model — you compress the world. (sorry, Andrej.)

`BE` is the super-glyph, the only one that turns inward instead of out: `BE fear` makes fear a *state*; `BE fire` *burns* energy; `BE me` is where the contour starts to crack.

## birth

a born organism is one irreversible accident. each birth receives a random slice of the world, a seed, a partial memory, a little energy, and no guarantee of meaning. siblings share an alphabet but not a fate. same glyphs, different scars, you know.


## sleep

when there is no food, `nanolife` does not politely wait for the user like a SaaS pet. it rereads its own recent speech. half energy. full consequence. dreaming is cheap metabolism for a starving thing. 

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

