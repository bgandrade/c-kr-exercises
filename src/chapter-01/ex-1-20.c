#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TAB_WIDTH 4

char line[MAXLINE];      /* current input line */
char detabbed[MAXLINE];  /* line with tabs replaced by blanks */
int get_line(void);
void detab(void);

/* replace tabs with blanks in each input line */
int main(void)
{
    while ((get_line()) > 0)
    {
        detab();
        printf("%s", detabbed);
    }

    return 0;
}

/* get_line: read a line into the global line buffer */
int get_line(void)
{
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* detab: replace tabs with blanks up to the next tab stop */
void detab(void)
{
    int i = 0, col = 0;
    int spaces;

    while (line[i] != '\0')
    {
        if (line[i] == '\t')
        {
            spaces = TAB_WIDTH - (col % TAB_WIDTH);
            while (spaces > 0)
            {
                detabbed[col] = ' ';
                ++col;
                --spaces;
            }
        }
        else
        {
            detabbed[col] = line[i];
            ++col;
        }
        ++i;
    }
    detabbed[col] = '\0';
}
