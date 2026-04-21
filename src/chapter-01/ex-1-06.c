#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
        printf("c != EOF: %d\n", c != EOF);
    printf("c != EOF: %d\n", c != EOF);
    return 0;
}

// You can test it in the terminal with: printf 'abc' | make run EX=ex-1-06