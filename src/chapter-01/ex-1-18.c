#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int trimline(char str[]);

/* remove trailing blanks and tabs, and skip blank lines */
int main(void)
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    while (get_line(line, MAXLINE) > 0)
    {
        len = trimline(line);
        if (len > 0)
            printf("%s", line);
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/* trimline: remove trailing blanks and tabs, return the new length */
int trimline(char str[])
{
    int i = 0;
    int has_newline;

    while (str[i] != '\n' && str[i] != '\0')
        ++i;

    has_newline = (str[i] == '\n');

    --i;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
        --i;

    if (i >= 0)
    {
        if (has_newline)
        {
            str[i + 1] = '\n';
            str[i + 2] = '\0';
        }
        else
        {
            str[i + 1] = '\0';
        }

        return i + 1;
    }

    str[0] = '\0';
    return 0;
}
