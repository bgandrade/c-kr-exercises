#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float min, max, step;
    min = -50;
    max = 100;
    step = 5;
    celsius = min;
    puts("celsius   fahr");
    while (celsius <= max)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%7.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
