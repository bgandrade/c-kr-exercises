/*
 * K&R 2, Exercise 1-01
 * Summary: Run the classic hello-world program and observe the diagnostics produced when parts are removed.
 */
#include <stdio.h>

int main(void)
{
    printf("hello, ");
    printf("world");
    printf("\n");

    return 0;
}

// It may seem silly to write a hello world, but it’s there