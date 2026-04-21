#include <stdio.h>

#define IN 1
#define OUT 0

/*
 * Some quick tests for the word count program:
 * - empty input
 * - input with only blanks, tabs, and newlines
 * - one word
 * - multiple words separated by one blank
 * - multiple words separated by many blanks
 * - words separated by tabs
 * - words separated by newlines
 * - input ending without a final newline
 *
 * These usually catch bugs, since the program relies on switching between
 * OUT and IN states.
 */

int main(void)
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
