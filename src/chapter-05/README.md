# Chapter 05

**Title:** Pointers and Arrays

**Exercises:** 20

## Exercises

- [ ] `5-01` - As written, `getint` treats a `+` or `-` not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.
- [ ] `5-02` - Write `getfloat`, the floating-point analog of `getint`. What type does `getfloat` return as its function value?
- [ ] `5-03` - Write a pointer version of the function `strcat` that we showed in Chapter 2: `strcat(s, t)` copies the string `t` to the end of `s`.
- [ ] `5-04` - Write the function `strend(s, t)`, which returns `1` if the string `t` occurs at the end of the string `s`, and `0` otherwise.
- [ ] `5-05` - Write versions of the library functions `strncpy`, `strncat`, and `strncmp`, which operate on at most the first `n` characters of their argument strings. For example, `strncpy(s, t, n)` copies at most `n` characters of `t` to `s`. Full descriptions are in Appendix B.
- [ ] `5-06` - Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include `getline`, `atoi`, `itoa`, and their variants, `reverse`, `strindex`, and `getop`.
- [ ] `5-07` - Rewrite `readlines` to store lines in an array supplied by `main`, rather than calling `alloc` to maintain storage. How much faster is the program?
- [ ] `5-08` - There is no error checking in `day_of_year` or `month_day`. Remedy this defect.
- [ ] `5-09` - Rewrite the routines `day_of_year` and `month_day` with pointers instead of indexing.
- [ ] `5-10` - Write the program `expr`, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example, `expr 2 3 4 + *` evaluates the expression `2 * (3 + 4)`.
- [ ] `5-11` - Modify the programs `entab` and `detab` to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
- [ ] `5-12` - Extend `entab` and `detab` to accept the shorthand `entab -m +n` to mean tab stops every `n` columns, starting at column `m`. Choose convenient default behavior.
- [ ] `5-13` - Write the program `tail`, which prints the last `n` lines of its input. By default, `n` is `10`. Let the program behave rationally no matter how unreasonable the input or the value of `n`. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program, not in a two-dimensional array of fixed size.
- [ ] `5-14` - Modify the sort program to handle a `-r` flag, which indicates sorting in reverse order. Be sure that `-r` works with `-n`.
- [ ] `5-15` - Add the option `-f` to fold upper and lower case together, so that case distinctions are not made during sorting; for example, `a` and `A` compare equal.
- [ ] `5-16` - Add the `-d` option, which makes the sort program compare only letters, numbers, and blanks. Make sure it works in conjunction with `-f`.
- [ ] `5-17` - Add a field-searching capability, so sorting may be done on fields within lines, each field sorted according to an independent set of options. The index for the Unix `sort` command may be a useful guide.
- [ ] `5-18` - Make `dcl` recover from input errors.
- [ ] `5-19` - Modify `undcl` so that it does not add redundant parentheses to declarations.
- [ ] `5-20` - Expand `dcl` to handle declarations with function argument types, qualifiers like `const`, and so on.

## Notes

- I will create each solution file only when I start that exercise, using names like `ex-5-01.c`.
- I will use this checklist to track progress and mark an item only after the exercise is finished.
