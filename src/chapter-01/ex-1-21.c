#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TAB_WIDTH 4

char line[MAXLINE];     /* current input line */
char entabbed[MAXLINE]; /* line with blanks replaced by tabs and blanks */
int get_line(void);
void entab(void);

/* replace strings of blanks with tabs and blanks in each input line */
int main(void)
{
    while ((get_line()) > 0)
    {
        entab();
        printf("%s", entabbed);
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

/* entab: replace blanks with the minimum number of tabs and blanks */
void entab(void)
{
    int i, j, column, spaces;
    i = j = column = spaces = 0;

    while (line[i] != '\0')
    {
        if (line[i] == ' ')
        {
            ++spaces;
            ++column;
            if (column % TAB_WIDTH == 0)
            {
                if (spaces == 1)
                    entabbed[j] = ' ';
                else
                    entabbed[j] = '\t';
                ++j;
                spaces = 0;
            }
        }
        else
        {
            while (spaces > 0)
            {
                entabbed[j] = ' ';
                ++j;
                --spaces;
            }
            entabbed[j] = line[i];
            j++;
            ++column;
        }
        ++i;
    }
    while (spaces > 0)
    {
        entabbed[j] = ' ';
        ++j;
        --spaces;
    }

    entabbed[j] = '\0';
}
