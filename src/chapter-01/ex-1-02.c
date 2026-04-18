#include <stdio.h>

int main(void)
{
    printf("hello,\\c");
    printf("world");
    printf("\n");

    return 0;
}

// We know that \c causes a compilation error, so I left it as \ only so it doesn’t prevent compilation if someone tries