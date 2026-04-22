#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LEN 10

int main(void)
{
    int c, length, state, max;
    int lengths[MAX_WORD_LEN + 1] = {0};

    state = OUT;
    length = max = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                state = OUT;
                length = length > MAX_WORD_LEN ? MAX_WORD_LEN : length;
                ++lengths[length];
            }
        }
        else if (state == IN)
            ++length;
        else
        {
            state = IN;
            length = 1;
        }
    }
    if (state == IN)
    {
        length = length > MAX_WORD_LEN ? MAX_WORD_LEN : length;
        ++lengths[length];
    }

    printf("Horizontal histogram\n");
    for (int i = 1; i <= MAX_WORD_LEN; ++i)
    {
        if (i == MAX_WORD_LEN)
            printf("Length %2d+: %2d word(s) | ", i, lengths[i]);
        else
            printf("Length %2d : %2d word(s) | ", i, lengths[i]);
        for (int j = 1; j <= lengths[i]; ++j)
            putchar('#');
        putchar('\n');
    }

    printf("\n\n\n");
    printf("Vertical histogram\n");

    for (int i = 0; i <= MAX_WORD_LEN; ++i)
        max = lengths[i] > max ? lengths[i] : max;

    while (max > 0)
    {
        printf("%2d", max);
        for (int i = 1; i <= MAX_WORD_LEN; ++i)
        {
            if (lengths[i] >= max)
                printf("  #");
            else
                printf("   ");
        }
        --max;
        putchar('\n');
    }
    printf("  ");
    for (int i = 1; i <= MAX_WORD_LEN; ++i)
        i == MAX_WORD_LEN ? printf("%3d+", i) : printf("%3d", i);
    putchar('\n');

    return 0;
}
