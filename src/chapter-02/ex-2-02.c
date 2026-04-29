#include <stdio.h>
#define SIZE 1000

int main(void)
{

    int i, c;
    char s[SIZE];

    for (i = 0;; ++i)
    {
        if (i >= SIZE - 1)
            break;

        c = getchar();

        if (c == EOF)
            break;

        if (c == '\n')
            break;

        s[i] = c;
    }

    s[i] = '\0';
    puts(s);

    return 0;
}
