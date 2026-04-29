#include <stdio.h>
#include <ctype.h>

int htoi(const char s[])
{
    int i = 0;
    int n = 0;

    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
        i += 2;

    while (isxdigit((unsigned char)s[i]))
    {
        int c = toupper((unsigned char)s[i]);
        int digit;

        if (c >= '0' && c <= '9')
            digit = c - '0';
        else
            digit = c - 'A' + 10;

        n = 16 * n + digit;
        ++i;
    }

    return n;
}

int main(void)
{
    printf("%d", htoi("FF"));

    return 0;
}
