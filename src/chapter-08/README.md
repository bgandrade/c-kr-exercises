# Chapter 08

**Title:** The UNIX System Interface

**Exercises:** 8

## Exercises

- [ ] `8-01` - Rewrite the program `cat` from Chapter 7 using `read`, `write`, `open`, and `close` instead of their standard library equivalents. Perform experiments to determine the relative speeds of the two versions.
- [ ] `8-02` - Rewrite `fopen` and `_fillbuf` with fields instead of explicit bit operations. Compare code size and execution speed.
- [ ] `8-03` - Design and write `_flushbuf`, `fflush`, and `fclose`.
- [ ] `8-04` - The standard library function `fseek` is not much more difficult than `lseek`. Write `fseek` for the library shown in this chapter.
- [ ] `8-05` - Modify the `fsize` program to print the other information contained in the inode entry.
- [ ] `8-06` - The standard library function `calloc(n, size)` returns a pointer to `n` objects of size `size`, with the storage initialized to zero. Write `calloc`, by calling `malloc` or by modifying it.
- [ ] `8-07` - `malloc` accepts a size request without checking its plausibility; `free` believes that the block it is asked to free contains a valid size field. Improve these routines so they take more precautions against errors.
- [ ] `8-08` - Write a routine `bfree(p, n)` that will free an arbitrary block `p` of `n` characters into the free list maintained by `malloc` and `free`.

## Notes

- I will create each solution file only when I start that exercise, using names like `ex-8-01.c`.
- I will use this checklist to track progress and mark an item only after the exercise is finished.
