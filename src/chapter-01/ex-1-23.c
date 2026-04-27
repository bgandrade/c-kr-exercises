#include <stdio.h>

#define NORMAL 0
#define IN_COMMENT 1
#define IN_STRING 2
#define IN_CHAR 3
#define COMMENT_STAR 4

/* remove all comments from a C program */
int main(void)
{
    int c, next, state;

    state = NORMAL;

    while ((c = getchar()) != EOF)
    {
        switch (state)
        {
        case NORMAL:
            if (c == '/')
            {
                next = getchar();
                if (next == '*')
                    state = IN_COMMENT;
                else
                {
                    putchar(c);
                    if (next != EOF)
                        putchar(next);
                }
            }
            else if (c == '"')
            {
                state = IN_STRING;
                putchar(c);
            }
            else if (c == '\'')
            {
                state = IN_CHAR;
                putchar(c);
            }
            else
                putchar(c);
            break;

        case IN_COMMENT:
            if (c == '*')
                state = COMMENT_STAR;
            break;

        case COMMENT_STAR:
            if (c == '/')
                state = NORMAL;
            else if (c != '*')
                state = IN_COMMENT;
            break;

        case IN_STRING:
            putchar(c);
            if (c == '\\')
            {
                next = getchar();
                if (next != EOF)
                    putchar(next);
            }
            else if (c == '"')
                state = NORMAL;
            break;

        case IN_CHAR:
            putchar(c);
            if (c == '\\')
            {
                next = getchar();
                if (next != EOF)
                    putchar(next);
            }
            else if (c == '\'')
                state = NORMAL;
            break;
        }
    }

    return 0;
}

/* This was quite difficult; I did not expect this level in chapter 1. */
