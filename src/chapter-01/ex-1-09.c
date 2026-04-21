#include <stdio.h>

int main(void)
{
    int c, lastc = EOF;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && lastc == ' ')
            continue;

        putchar(c);
        lastc = c;
    }

    return 0;
}
