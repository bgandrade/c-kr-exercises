#include <stdio.h>

int main(void)
{
    int c, nl, tab, blank;
    nl = tab = blank = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++blank;
        else if (c == '\t')
            ++tab;
        else if (c == '\n')
            ++nl;

    printf("blanks: %d\n", blank);
    printf("tabs: %d\n", tab);
    printf("newlines: %d\n", nl);

    return 0;
}

// try it in the terminal: printf "Noite calma\nvento antigo\n\tverso leve\n\tna janela" | make run EX=ex-1-08
