# Makefiles & Static Libraries

> A complete reference for everything you need to understand about `make`, Makefiles, and library compilation in C.

---

## Table of Contents

1. [What is `make`?](#1-what-is-make)
2. [Make vs Shell Script](#2-make-vs-shell-script)
3. [Makefile Structure](#3-makefile-structure)
4. [Targets & Dependencies](#4-targets--dependencies)
5. [Compiler Flags](#5-compiler-flags)
6. [Timestamp Checking & Incremental Compilation](#6-timestamp-checking--incremental-compilation)
7. [Dependency Tracking](#7-dependency-tracking)
8. [Static Libraries](#8-static-libraries)
9. [Shared Libraries — Basics](#9-shared-libraries--basics)
10. [Project Compilation Automation](#10-project-compilation-automation)
11. [Common Pitfalls](#11-common-pitfalls)
12. [Quick Reference](#12-quick-reference)

---

## 1. What is `make`?

`make` is a build automation tool. You describe **what** needs to be built and **how**, and `make` figures out what actually needs to run based on what has changed.

You write those instructions in a file called `Makefile` (capital M, no extension).

```bash
make          # runs the default (first) rule
make clean    # runs the "clean" rule
make re       # runs the "re" rule
```

---

## 2. Make vs Shell Script

Both can compile your project. Here's why `make` is better:

| | Shell Script | Makefile |
|---|---|---|
| Recompiles everything? | **Always** — even unchanged files | **Only what changed** |
| Tracks dependencies? | No — you write it manually | Yes — built-in |
| Readable build logic? | Gets messy fast | Clean, declarative |
| Standard in C projects? | No | **Yes** |

A shell script runs top-to-bottom blindly. `make` is **smart** — it checks timestamps and skips work that's already done.

```bash
# shell script — always recompiles everything
cc -Wall ft_strlen.c ft_putchar.c ft_swap.c -o libft

# make — only recompiles ft_strlen.c if it changed
make
```

---

## 3. Makefile Structure

A Makefile is made of **variables** and **rules**.

```makefile
# --- Variables ---
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
NAME    = libft.a

SRCS    = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
          srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS    = $(SRCS:.c=.o)

# --- Rules ---
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes/ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

> **Critical:** recipe lines (the commands) must be indented with a **tab character**, not spaces. Make will refuse to run otherwise.

---

## 4. Targets & Dependencies

### The rule syntax

```makefile
target: dependency1 dependency2
	command to build target
```

- **target** — the file you want to produce, or a label for an action
- **dependencies** (also called prerequisites) — files that must exist and be up-to-date before the target is built
- **recipe** — the shell command(s) to run

### Example chain

```makefile
libft.a: srcs/ft_strlen.o srcs/ft_putchar.o
	ar rcs libft.a srcs/ft_strlen.o srcs/ft_putchar.o

srcs/ft_strlen.o: srcs/ft_strlen.c includes/ft.h
	cc -Wall -Wextra -Werror -I includes/ -c srcs/ft_strlen.c -o srcs/ft_strlen.o
```

`make` reads this as: *"to build `libft.a`, I first need the `.o` files. To build each `.o`, I need its `.c` and the header."*

### Automatic variables

Inside a recipe, these shortcuts are available:

| Variable | Meaning |
|----------|---------|
| `$@` | The target name |
| `$<` | The first dependency |
| `$^` | All dependencies |

```makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#                      ↑       ↑
#               the .c file   the .o file
```

### .PHONY targets

Some targets are not real files — they're just labels for actions (`clean`, `all`, `re`).

```makefile
.PHONY: all clean fclean re
```

Without `.PHONY`: if a file named `clean` ever exists in your directory, `make clean` would do nothing (it would see the file and think the target is already up to date). `.PHONY` prevents this.

---

## 5. Compiler Flags

```makefile
CFLAGS = -Wall -Wextra -Werror
```

| Flag | Meaning |
|------|---------|
| `-Wall` | Enable all common warnings |
| `-Wextra` | Enable extra warnings beyond `-Wall` |
| `-Werror` | Treat every warning as an error — code won't compile with warnings |
| `-I includes/` | Tell the compiler where to find header files |
| `-c` | Compile only — produce a `.o`, don't link yet |

The order matters at 42: always `-Wall -Wextra -Werror` in that sequence.

---

## 6. Timestamp Checking & Incremental Compilation

This is the core of what makes `make` smart.

Every file on your system has a **last modified timestamp**. `make` compares timestamps between a target and its dependencies:

```
if dependency is NEWER than target:
    → rerun the recipe (recompile)
else:
    → skip (already up to date)
```

### Example

You have these files:

```
srcs/ft_strlen.c    → last modified: 10:00
srcs/ft_strlen.o    → last modified: 10:05
```

Running `make` → **skips** `ft_strlen.o`, it's already newer than the source.

You then edit `ft_strlen.c` (now 10:10):

```
srcs/ft_strlen.c    → last modified: 10:10
srcs/ft_strlen.o    → last modified: 10:05
```

Running `make` again → **recompiles** only `ft_strlen.o`.

This is **incremental compilation** — only the changed pieces get rebuilt. On large projects this saves enormous amounts of time.

---

## 7. Dependency Tracking

Dependencies tell `make` the full chain of what depends on what.

```makefile
srcs/ft_strlen.o: srcs/ft_strlen.c includes/ft.h
```

This means: rebuild `ft_strlen.o` if **either** `ft_strlen.c` **or** `ft.h` changes.

This matters because if you update a header (`ft.h`), every `.o` that includes it must be recompiled — even if the `.c` files themselves didn't change. Without this dependency, your build would be stale and potentially broken silently.

### The dependency graph

```
libft.a
├── srcs/ft_putchar.o  ←  srcs/ft_putchar.c + includes/ft.h
├── srcs/ft_swap.o     ←  srcs/ft_swap.c    + includes/ft.h
├── srcs/ft_putstr.o   ←  srcs/ft_putstr.c  + includes/ft.h
├── srcs/ft_strlen.o   ←  srcs/ft_strlen.c  + includes/ft.h
└── srcs/ft_strcmp.o   ←  srcs/ft_strcmp.c  + includes/ft.h
```

`make` walks this graph and rebuilds only what's necessary.

---

## 8. Static Libraries

### What is a static library?

A static library (`.a` file) is an **archive of compiled object files** bundled together. When you link against it, the relevant code gets **copied directly into your final binary** at compile time.

```
ft_strlen.o ─┐
ft_putchar.o ─┤
ft_swap.o    ─┼──→  ar rcs  ──→  libft.a
ft_putstr.o  ─┤
ft_strcmp.o  ─┘
```

### Creating one

```makefile
libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)
```

`ar` = archiver tool  
`r` = insert/replace files in archive  
`c` = create archive if it doesn't exist  
`s` = write an index (symbol table) — makes linking faster

### Using a static library

```bash
cc main.c -L. -lft -I includes/ -o my_program
#          ↑    ↑
#    look here  link libft.a
```

`-L.` = look for libraries in current directory  
`-lft` = link `libft.a` (drop the `lib` prefix and `.a`)

### Key property — static

At link time, the needed code from `libft.a` is **baked into the binary**. The `.a` file is no longer needed to run the program. Distribute just the binary and it works standalone.

---

## 9. Shared Libraries — Basics

A shared library (`.so` on Linux, `.dylib` on macOS) works differently from a static one.

| | Static (`.a`) | Shared (`.so`) |
|---|---|---|
| Code copied into binary? | **Yes** — at link time | **No** — loaded at runtime |
| Binary size | Larger | Smaller |
| Library needed to run? | No | **Yes** — must be present |
| Update library without recompiling? | No | **Yes** |

### Creating a shared library

```bash
cc -Wall -Wextra -Werror -fPIC -c ft_strlen.c -o ft_strlen.o
#                         ↑
#              Position-Independent Code — required for shared libs

cc -shared -o libft.so ft_strlen.o ft_putchar.o ...
```

### When to use which

- **Static** → simpler, self-contained binaries. Used at 42.
- **Shared** → system libraries (`libc.so`, `libm.so`) — shared across all programs, saving RAM and disk.

---

## 10. Project Compilation Automation

Here's how a full build flows step by step:

```
make all
  │
  ├─ needs libft.a
  │     │
  │     ├─ needs srcs/ft_strlen.o  → compile ft_strlen.c  ✓
  │     ├─ needs srcs/ft_putchar.o → compile ft_putchar.c ✓
  │     ├─ needs srcs/ft_swap.o    → compile ft_swap.c    ✓
  │     ├─ needs srcs/ft_putstr.o  → compile ft_putstr.c  ✓
  │     └─ needs srcs/ft_strcmp.o  → compile ft_strcmp.c  ✓
  │
  └─ ar rcs libft.a *.o  →  libft.a created ✓
```

Second run with no changes:

```
make all
  └─ libft.a is up to date. Nothing to be done.
```

Edit only `ft_strlen.c`, then run again:

```
make all
  └─ needs libft.a
        ├─ ft_strlen.o is outdated → recompile ft_strlen.c only
        └─ ar rcs libft.a *.o  →  libft.a updated
```

This is the power of `make` — **automatic, minimal rebuilds**.

---

## 11. Common Pitfalls

- **Spaces instead of tabs** before recipes → `Makefile:N: *** missing separator. Stop.`
- **Forgetting `-I includes/`** → `fatal error: ft.h: No such file or directory`
- **Not listing `.PHONY`** → if a file named `clean` exists, `make clean` silently does nothing
- **No header in dependencies** → editing `ft.h` won't trigger recompilation of `.o` files
- **Linking instead of compiling** → forgetting `-c` flag produces an executable instead of a `.o`

---

## 12. Quick Reference

```bash
make              # build (runs 'all' rule)
make all          # same as above
make libft.a      # build the library directly
make clean        # remove .o files
make fclean       # remove .o files + libft.a
make re           # full rebuild from scratch
```

### Compilation pipeline

```
source.c  →  (cc -c)  →  source.o  →  (ar rcs)  →  libft.a
```

### Key Makefile variables

```makefile
CC     = cc                          # compiler
CFLAGS = -Wall -Wextra -Werror       # flags
AR     = ar rcs                      # archiver
NAME   = libft.a                     # output library
SRCS   = srcs/ft_putchar.c ...       # source files
OBJS   = $(SRCS:.c=.o)              # object files (auto-derived)
```
