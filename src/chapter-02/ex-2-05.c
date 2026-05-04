#include <stdio.h>

#define UCHAR_LIMIT 256

int any(char s1[], char s2[])
{
    int read;

    int present[UCHAR_LIMIT] = {0};

    read = 0;
    while (s2[read] != '\0')
    {
        present[(unsigned char)s2[read++]] = 1;
    }

    for (read = 0; s1[read] != '\0'; read++)
    {
        if (present[(unsigned char)s1[read]])
            return read;
    }
    return -1;
}

int main(void)
{
    char str1[] = "Sphinx of black quartz, judge my vow.";
    char str2[] = "aeiou";

    int index = any(str1, str2);
    printf("%d", index);

    return 0;
}
