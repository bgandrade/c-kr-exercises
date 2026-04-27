# Chapter 02

**Title:** Types, Operators, and Expressions

**Exercises:** 10

## Exercises

- [x] `2-01` - Write a program to determine the ranges of `char`, `short`, `int`, and `long` variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
- [ ] `2-02` - Write a loop equivalent to the `for` loop above without using `&&` or `||`.
- [ ] `2-03` - Write the function `htoi(s)`, which converts a string of hexadecimal digits, including an optional `0x` or `0X`, into its equivalent integer value.
- [ ] `2-04` - Write an alternate version of `squeeze(s1, s2)` that deletes each character in `s1` that matches any character in the string `s2`.
- [ ] `2-05` - Write the function `any(s1, s2)`, which returns the first location in the string `s1` where any character from the string `s2` occurs, or `-1` if `s1` contains no characters from `s2`.
- [ ] `2-06` - Write a function `setbits(x, p, n, y)` that returns `x` with the `n` bits that begin at position `p` set to the rightmost `n` bits of `y`, leaving the other bits unchanged.
- [ ] `2-07` - Write a function `invert(x, p, n)` that returns `x` with the `n` bits that begin at position `p` inverted, leaving the others unchanged.
- [ ] `2-08` - Write a function `rightrot(x, n)` that returns the value of the integer `x` rotated to the right by `n` bit positions.
- [ ] `2-09` - In a two's complement number system, `x &= (x - 1)` deletes the rightmost `1` bit in `x`. Explain why. Use this observation to write a faster version of `bitcount`.
- [ ] `2-10` - Rewrite the function `lower`, which converts upper case letters to lower case, with a conditional expression instead of `if-else`.

## Notes

- I will create each solution file only when I start that exercise, using names like `ex-2-01.c`.
- I will use this checklist to track progress and mark an item only after the exercise is finished.
