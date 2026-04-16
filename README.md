# K&R C Exercises

This repository contains my solutions to the exercises from *The C Programming Language, Second Edition* by Brian W. Kernighan and Dennis M. Ritchie.

## Goals

- Work through every exercise in the book in order.
- Use the book as a structured review of core C concepts.
- Revisit a classic text to strengthen my understanding of idiomatic C.
- Compare the book's style with modern compiler warnings and build practices.
- Keep the repository easy to navigate and easy to build.
- Track my progress over time as I deepen my C fundamentals.

## Progress

- [ ] [Chapter 01 - A Tutorial Introduction](src/chapter-01/README.md)
- [ ] [Chapter 02 - Types, Operators, and Expressions](src/chapter-02/README.md)
- [ ] [Chapter 03 - Control Flow](src/chapter-03/README.md)
- [ ] [Chapter 04 - Functions and Program Structure](src/chapter-04/README.md)
- [ ] [Chapter 05 - Pointers and Arrays](src/chapter-05/README.md)
- [ ] [Chapter 06 - Structures](src/chapter-06/README.md)
- [ ] [Chapter 07 - Input and Output](src/chapter-07/README.md)
- [ ] [Chapter 08 - The UNIX System Interface](src/chapter-08/README.md)

## Repository Layout

```text
.
├── Makefile
├── README.md
├── bin/
└── src/
    ├── chapter-01/
    ├── chapter-02/
    ├── chapter-03/
    ├── chapter-04/
    ├── chapter-05/
    ├── chapter-06/
    ├── chapter-07/
    └── chapter-08/
```

Each exercise lives in its own source file and follows this naming convention:

- `src/chapter-01/ex-1-01.c`
- `src/chapter-05/ex-5-13.c`
- `src/chapter-08/ex-8-04.c`

## Build Conventions

- C standard: `C99`, close enough to the book's style while still being practical on modern compilers.
- Warnings: `-Wall -Wextra -Werror -pedantic`
- Build output: `bin/`

## Usage

List all available exercises:

```sh
make list
```

Build a specific exercise by target name:

```sh
make ex-1-01
```

Run a specific exercise:

```sh
make run EX=ex-1-01
```

Remove compiled artifacts:

```sh
make clean
```