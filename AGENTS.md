# Mario Party 5 Decompilation

Matching decompilation of Mario Party 5 targeting the USA Release build (`GP5E01_00`).
The goal is to produce C (some files C++) source that compiles to byte-identical object code against the
original retail binary using the original C88 MWCC compiler.

## Build & Verify

```sh
python configure.py    # generate build.ninja + objdiff.json (run after config changes)
ninja all_source       # build all objects
ninja                  # build all objects, hash check and progress report
ninja baseline         # generates baseline report for regression checking
ninja changes          # check for regressions after code changes (empty = no regressions)
```

## Project Layout

```
src/                   C/C++ source
include/               Headers
config/GP5E01_00/      Symbol addresses, section splits
  symbols.txt          Symbol names -> addresses
  splits.txt           Memory layout / section boundaries
orig/                  Original game files
tools/                 Build system, agent tooling and other scripts
objdiff.json           Generated build/diff configuration
```

## Sub-Agent Usage

Sub-agents are allowed only for **read-only exploration** tasks such as:

- searching the codebase for symbols, call sites
- inspecting decomp output or assembly
- summarizing findings that help the main worker decide what to change

Sub-agents must **not** write or edit code files, headers, configs, or other repository files.
All persistent file changes, decomp implementations, scaffolding, and follow-up fixes must be
done by the main worker after reviewing the read-only findings.

## Forbidden Changes

Do **not** edit or otherwise touch the comparison and configuration inputs that define the
project's match metrics:

- `config/GP5E01_00/symbols.txt`
- `config/GP5E01_00/splits.txt`
- `configure.py`

Treat these files as read-only unless the user explicitly asks for a task that is specifically
about maintaining that infrastructure.

Do **not** try to cheat objdiff, progress, or match metrics in any way. The goal is to improve
the real decompilation output, not to manipulate the comparison setup, hide mismatches, or make
progress numbers look better without actually matching the original code.

**Never** copy, overwrite, or symlink a compiled source `.o` file into `build/GP5E01_00/obj/`.
The `obj/` directory contains the **original reference objects** extracted from the retail
binary. Replacing them with your own compiled output will make objdiff
compare your code against itself, producing a false 100% match. If the `obj/` file is
accidentally corrupted, regenerate it with:

```sh
rm build/GP5E01_00/config.json
ninja build/GP5E01_00/config.json   # re-splits from the original ELF
```

## Tooling

### decomp.sh — Decompile a file

Get a decompilation baseline using m2c.

```sh
./tools/decomp.sh ./build/GP5E01_00/m507dll/asm/REL/m507dll/m507.s dummy_ctx_base.c /tmp/output.c
```

### decomp-diff.py — Diff & symbol overview

Overview mode lists all symbols in a translation unit with match status:

```sh
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507 -s nonmatching -t function
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507 -s missing -t function
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507 --search RemoveIOWin
```

Filters: `-t function,object` (type), `-s missing|matching|nonmatching|extra` (status),
`--section .text`, `--search <pattern>` (fuzzy name match)..

Diff mode shows side-by-side instruction comparison:

```sh
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507 -d DistributeOneMessage
python tools/decomp-diff.py -u m507dll/REL/m507dll/m507 -d FindIOWin -C 5
```

Mismatched args are wrapped in `{}`. Matching runs are collapsed (control with `-C <n>` context lines, `--no-collapse`). Left = original, right = decomp.

### decomp-status.py — Project-wide progress

```sh
python tools/decomp-status.py                       # all categories
python tools/decomp-status.py --category modules    # filter modules (only thing we want to match)
python tools/decomp-status.py --unit m507dll/REL/m507dll/m507
python tools/decomp-status.py --json                # machine-readable
```

## Matching Philosophy

When asked to decompile a C/C++ board/minigame, start by looking up `configure.py` for the source file paths that make up that translation unit. Then run `tools/decomp.sh` which decompiles the whole file, adding a line comment onto every single line to make sure you can work function by function.

Your goal is to match the data and functions to 100%. You are only asked to decompile RELs.

A common pattern the developers used is passing around a struct called `OMOBJ` and assigning custom data to its `data` field. The first thing you should do is track down how these are allocated/assigned and create structs for the data using the M<minigame number>Struct<index> for minigames, for example M501Struct2, or MB<board number>Struct<index> for boards. Once you've created the empty structs, annotate - functions that receive OMOBJ - (using a comment) what struct their data corresponds to. The objFunc field will help you in the process. Sometimes `OMOBJ` is saved into global variables.

This game contains lots of places where regular functions get inlined, but it's restricted in the direction: the inlined function has to be _defined_ above the caller. It would be a good idea to start by recognizing huge inlined code chunks and annotating them call-sites using comments to avoid extra work later. 

Then you should go through every function in the translation unit, get the functions to compile and match them to 100% according to objdiff. You should fill up the structs in the process using correct data types, offsets and sizes. Raw pointer math to access members isn't allowed. 

If you are struggling with types, you can run `tools/decomp.sh` passing the file you're working on as a context instead of the dummy one. The file has to be in a compilable state when you do this. A tip for dealing with globals with `/* unable to generate initializer: unknown type */`: you should figure out the type by the code usage, _declare_ the global and rerun decomp.sh passing the file as the context. If none of this works and you have to figure out data, you should check the asm file.

You need to create and maintain a header file per REL if its source files have to share declarations (structs, data or functions) between each other. One way you can see this for functions is that m2c emits a declaration with the comment `/* extern */`, for example `fn_1_7720(s32 *); /* extern */`.

m2c generates forward declarations of functions, but lots of types are unknown by default. You'll have to figure them out and update them yourself.

Try really hard to use string and floating point constants on the spot instead of having them as global variables, to the point that you should remove global strings generated by m2c if they are not necessary to match the file.

Be aware that it in order to match a function, it might be rarely necessary to not have all the includes, resulting in calls of implicitly declared functions. In case you must absolutely "remove" an include, put the include statement inside an `#ifndef __MWERKS__ ... #endif` guard. Other than that don't come up with weird macros for this.

Really try to make stack and global arrays have the correct size. If you absolutely don't find any way to fit an access into the array's bounds without breaking matching status, leave a comment about the bug.

Instead of casting function pointers to functions whose signature we are not sure about, try to change the function's signature if that still matches. For example don't cast a function to `OMOBJFUNC` if you can make it take an `OMOBJ*` as an argument.

Never dismiss a diff as "close enough" or "just register allocation." Every mismatched
instruction is a signal that the source doesn't perfectly represent the original. Even
the most stubborn mismatches can be resolved through careful analysis, lateral thinking, and
creative source-level permutations. It may take 10 iterations or 100, but the ultimate goal
is to perfectly match the original code.

Matching can be tricky — be patient and methodical. Try many different ways of writing the same thing. Look for patterns elsewhere in the codebase. Only move on when you've exhausted concrete ideas, not when the match percentage is "high enough." When resolving issues, keep in mind that the overall matching percentage is not a clean indicator of whether a change was successful or not, as something that fixes a spot can lead to register swaps that dunk the percentage. You should consider this before discarding potential fixes too early.

### Compiler behavior

The game was compiled using no optimizations other than inlining and jumptables for switch statements. On PowerPC this means that unless the function is too large and there are no free registers left: the stack is only used for arrays, structs, variables that are only written to and never read from, the result of ternaries, and temporaries/return values of inlined functions.

The m2c output can often be missing case labels in switch statements which are necessary to match the function.

### Always **humanize** code

Most importantly: write code that a human would write. The original code was written by humans, so the closer your source is
to natural C/C++, the more likely it is to match.

Use `NULL` instead of `0` when dealing with pointers.

DON'T ADD EXPLANATIVE TO THE CODE WHEN DECOMPILING other than the objdata and inline usage which you should also get rid of by the end and the ones that this file explicitly told you about.  

DON'T LABEL things on your own, keep the original variable and member names.

### Final stages
m2c auto-generates lots of struct definitions which are the same, you should get rid of the unnecessary/duplicate ones.

To match the data, especially string constants, it's important that they occur in the correct order.

To link an object file, it's necessary that the functions are in the correct order. m2c does this by default, so you shouldn't mess it up accidentally. 

Stop the decompilation process if 98% matching has been reached and no significant progress has been made in a while. Before you stop completely, verify that the code fulfills our guides.
