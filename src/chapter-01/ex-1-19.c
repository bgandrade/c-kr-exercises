#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char str[]);

/* reverse each input line */
int main(void)
{
    char line[MAXLINE]; /* current input line */

    while (get_line(line, MAXLINE) > 0)
    {
        reverse(line);
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

/* reverse: reverse the string, keeping the newline at the end */
void reverse(char str[])
{
    int c, i, j;

    for (j = 0; str[j] != '\n' && str[j] != '\0'; ++j)
        ;

    --j;

    for (i = 0; i < j; ++i, --j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
