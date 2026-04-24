#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

/* print the longest input line */
int main(void)
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 80)
        {
            fputs(line, stdout);
        }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim - 1)
            s[i] = c;
    }

    if (c == '\n')
    {
        if (i < lim - 1)
            s[i] = c;
        ++i;
    }
    if (i < lim - 1)
        s[i] = '\0';
    else
    {
        s[lim - 1] = '\0';
    }

    return i;
}
