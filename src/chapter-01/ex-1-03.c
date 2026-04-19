#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    puts("fahr   celsius");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f %9.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
