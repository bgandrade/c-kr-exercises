#include <stdio.h>

#define UCHAR_LIMIT 256

void squeeze(char s1[], char s2[])
{
    int read, write;

    int remove[UCHAR_LIMIT] = {0};

    read = 0;
    while (s2[read] != '\0')
    {
        remove[(unsigned char)s2[read++]] = 1;
    }

    for (read = write = 0; s1[read] != '\0'; read++)
    {
        if (!remove[(unsigned char)s1[read]])
            s1[write++] = s1[read];
    }
    s1[write] = '\0';
}

int main(void)
{
    char str1[] = "The quick brown fox jumps over 13 lazy dogs!";
    char str2[] = "aeiou 123!";

    squeeze(str1, str2);
    puts(str1);

    return 0;
}
