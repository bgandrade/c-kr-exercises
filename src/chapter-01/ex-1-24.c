#include <stdio.h>

#define NORMAL 0
#define SLASH 1
#define IN_COMMENT 2
#define COMMENT_STAR 3
#define IN_STRING 4
#define STRING_ESCAPE 5
#define IN_CHAR 6
#define CHAR_ESCAPE 7

#define MAXSTACK 1000

char stack[MAXSTACK];
int stack_line[MAXSTACK];
int top = 0;
int errors = 0;

int process_normal(int c, int line);
void push(int c, int line);
void pop(int c, int line);
int opening(int c);
int closing(int c);
int matches(int open, int close);
char expected_close(int open);

/* check a C program for rudimentary syntax errors */
int main(void)
{
    int c, state, line, current_line, quote_line, comment_line;

    state = NORMAL;
    line = 1;
    quote_line = comment_line = 0;

    while ((c = getchar()) != EOF)
    {
        current_line = line;

        switch (state)
        {
        case NORMAL:
            if (c == '"' || c == '\'')
                quote_line = current_line;
            state = process_normal(c, current_line);
            break;

        case SLASH:
            if (c == '*')
            {
                state = IN_COMMENT;
                comment_line = current_line;
            }
            else
            {
                if (c == '"' || c == '\'')
                    quote_line = current_line;
                state = process_normal(c, current_line);
            }
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
            if (c == '\\')
                state = STRING_ESCAPE;
            else if (c == '"')
                state = NORMAL;
            else if (c == '\n')
            {
                printf("line %d: newline in string constant\n", current_line);
                ++errors;
                state = NORMAL;
            }
            break;

        case STRING_ESCAPE:
            state = IN_STRING;
            break;

        case IN_CHAR:
            if (c == '\\')
                state = CHAR_ESCAPE;
            else if (c == '\'')
                state = NORMAL;
            else if (c == '\n')
            {
                printf("line %d: newline in character constant\n", current_line);
                ++errors;
                state = NORMAL;
            }
            break;

        case CHAR_ESCAPE:
            state = IN_CHAR;
            break;
        }

        if (c == '\n')
            ++line;
    }

    if (state == IN_COMMENT || state == COMMENT_STAR)
    {
        printf("line %d: unclosed comment\n", comment_line);
        ++errors;
    }
    else if (state == IN_STRING || state == STRING_ESCAPE)
    {
        printf("line %d: unclosed string constant\n", quote_line);
        ++errors;
    }
    else if (state == IN_CHAR || state == CHAR_ESCAPE)
    {
        printf("line %d: unclosed character constant\n", quote_line);
        ++errors;
    }

    while (top > 0)
    {
        --top;
        printf("line %d: unclosed %c, expected %c\n",
               stack_line[top], stack[top], expected_close(stack[top]));
        ++errors;
    }

    if (errors == 0)
        printf("no rudimentary syntax errors found\n");

    return 0;
}

int process_normal(int c, int line)
{
    if (c == '/')
        return SLASH;
    else if (c == '"')
        return IN_STRING;
    else if (c == '\'')
        return IN_CHAR;
    else if (opening(c))
        push(c, line);
    else if (closing(c))
        pop(c, line);

    return NORMAL;
}

void push(int c, int line)
{
    if (top >= MAXSTACK)
    {
        printf("line %d: too many nested delimiters\n", line);
        ++errors;
    }
    else
    {
        stack[top] = c;
        stack_line[top] = line;
        ++top;
    }
}

void pop(int c, int line)
{
    int open;

    if (top == 0)
    {
        printf("line %d: unmatched %c\n", line, c);
        ++errors;
    }
    else
    {
        open = stack[top - 1];
        --top;
        if (!matches(open, c))
        {
            printf("line %d: found %c, expected %c for %c opened on line %d\n",
                   line, c, expected_close(open), open, stack_line[top]);
            ++errors;
        }
    }
}

int opening(int c)
{
    return c == '(' || c == '[' || c == '{';
}

int closing(int c)
{
    return c == ')' || c == ']' || c == '}';
}

int matches(int open, int close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

char expected_close(int open)
{
    if (open == '(')
        return ')';
    else if (open == '[')
        return ']';
    else
        return '}';
}
