#include <stdio.h>
#define ASCII_LIMIT 127

int main(void)
{
    int c;
    int counts[128] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= 0 && c <= ASCII_LIMIT)
            counts[c]++;
    }
    printf("Horizontal histogram\n");
    for (int i = 1; i <= ASCII_LIMIT; ++i)
    {
        printf("ASCII %3d: %3d character(s) | ", i, counts[i]);
        for (int j = 1; j <= counts[i]; ++j)
            putchar('#');
        putchar('\n');
    }
    return 0;
}
