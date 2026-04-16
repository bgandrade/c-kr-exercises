# Chapter 04

**Title:** Functions and Program Structure

**Exercises:** 14

## Exercises

- [ ] `4-01` - Write the function `strrindex(s, t)`, which returns the position of the rightmost occurrence of `t` in `s`, or `-1` if there is none.
- [ ] `4-02` - Extend `atof` to handle scientific notation of the form `123.45e-6`, where a floating-point number may be followed by `e` or `E` and an optionally signed exponent.
- [ ] `4-03` - Given the basic framework, extend the calculator to handle more of the operators and functions. Add the modulus operator `%` and provisions for negative numbers.
- [ ] `4-04` - Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
- [ ] `4-05` - Add access to library functions like `sin`, `exp`, and `pow`. See `<math.h>` in Appendix B, Section 4.
- [ ] `4-06` - Add commands for handling variables. It is easy to provide twenty-six variables with single-letter names. Add a variable for the most recently printed value.
- [ ] `4-07` - Write a routine `ungets(s)` that will push back an entire string onto the input. Should `ungets` know about `buf` and `bufp`, or should it just use `ungetch`?
- [ ] `4-08` - Suppose that there will never be more than one character of pushback. Modify `getch` and `ungetch` accordingly.
- [ ] `4-09` - Our `getch` and `ungetch` do not handle a pushed-back `EOF` correctly. Decide what their properties ought to be if an `EOF` is pushed back, then implement your design.
- [ ] `4-10` - An alternate organization uses `getline` to read an entire input line; this makes `getch` and `ungetch` unnecessary. Revise the calculator to use this approach.
- [ ] `4-11` - Modify `getop` so that it does not need to use `ungetch`. Hint: use an internal `static` variable.
- [ ] `4-12` - Adapt the ideas of `printd` to write a recursive version of `itoa`; that is, convert an integer into a string by calling a recursive routine.
- [ ] `4-13` - Write a recursive version of the function `reverse(s)`, which reverses the string in place.
- [ ] `4-14` - Define a macro `swap(t, x, y)` that interchanges two arguments of type `t`. Use a block structure so that the macro behaves syntactically like a function call.

## Notes

- I will create each solution file only when I start that exercise, using names like `ex-4-01.c`.
- I will use this checklist to track progress and mark an item only after the exercise is finished.
