#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define COLUMN_WIDTH 80
#define TAB_WIDTH 4

int get_line(char line[]);
void fold(char from[], char to[]);

/* fold long input lines into shorter lines */
int main(void)
{
    char line[MAXLINE];
    char folded[MAXLINE * 2];
    int length;

    while ((length = get_line(line)) > 0)
    {
        fold(line, folded);
        printf("%s", folded);
    }

    return 0;
}

/* get_line: read a line into line, return length */
int get_line(char line[])
{
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* fold: break long lines after the last blank before COLUMN_WIDTH */
void fold(char from[], char to[])
{
    int i, j, column, last_breakpoint;
    i = j = column = 0;
    last_breakpoint = -1;

    while (from[i] != '\0')
    {
        to[j] = from[i];

        if (from[i] == '\n')
        {
            column = 0;
            last_breakpoint = -1;
        }
        else
        {
            if (from[i] == ' ' || from[i] == '\t')
                last_breakpoint = j;

            if (from[i] == '\t')
                column = column + (TAB_WIDTH - column % TAB_WIDTH);
            else
                ++column;

            if (column >= COLUMN_WIDTH && from[i + 1] != '\0' && from[i + 1] != '\n')
            {
                if (last_breakpoint >= 0)
                {
                    to[last_breakpoint] = '\n';
                    column = j - last_breakpoint;
                    last_breakpoint = -1;
                }
                else
                {
                    ++j;
                    to[j] = '\n';
                    column = 0;
                }
            }
        }

        ++i;
        ++j;
    }

    to[j] = '\0';
}
