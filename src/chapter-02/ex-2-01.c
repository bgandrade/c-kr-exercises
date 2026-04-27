#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned char computed_uchar_max = (unsigned char)~0U;
    unsigned short computed_ushort_max = (unsigned short)~0U;
    unsigned int computed_uint_max = ~0U;
    unsigned long computed_ulong_max = ~0UL;
    unsigned long long computed_ullong_max = ~0ULL;

    int computed_char_min;
    int computed_char_max;
    signed char computed_schar_max = (signed char)(computed_uchar_max >> 1);
    signed char computed_schar_min = (signed char)(-computed_schar_max - 1);
    short computed_short_max = (short)(computed_ushort_max >> 1);
    short computed_short_min = (short)(-computed_short_max - 1);
    int computed_int_max = (int)(computed_uint_max >> 1);
    int computed_int_min = -computed_int_max - 1;
    long computed_long_max = (long)(computed_ulong_max >> 1);
    long computed_long_min = -computed_long_max - 1L;
    long long computed_llong_max = (long long)(computed_ullong_max >> 1);
    long long computed_llong_min = -computed_llong_max - 1LL;

    if ((char)-1 < 0) {
        computed_char_min = computed_schar_min;
        computed_char_max = computed_schar_max;
    } else {
        computed_char_min = 0;
        computed_char_max = computed_uchar_max;
    }

    printf("Ranges from standard headers:\n");
    printf("Signed ranges:\n");
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("long min: %ld\n", LONG_MIN);
    printf("long max: %ld\n", LONG_MAX);
    printf("long long min: %lld\n", LLONG_MIN);
    printf("long long max: %lld\n", LLONG_MAX);
    printf("Unsigned ranges:\n");
    printf("char max: %u\n", UCHAR_MAX);
    printf("short max: %u\n", USHRT_MAX);
    printf("int max: %u\n", UINT_MAX);
    printf("long max: %lu\n", ULONG_MAX);
    printf("long long max: %llu\n", ULLONG_MAX);

    printf("\nComputed ranges:\n");
    printf("Signed ranges:\n");
    printf("char min: %d\n", computed_char_min);
    printf("char max: %d\n", computed_char_max);
    printf("short min: %d\n", computed_short_min);
    printf("short max: %d\n", computed_short_max);
    printf("int min: %d\n", computed_int_min);
    printf("int max: %d\n", computed_int_max);
    printf("long min: %ld\n", computed_long_min);
    printf("long max: %ld\n", computed_long_max);
    printf("long long min: %lld\n", computed_llong_min);
    printf("long long max: %lld\n", computed_llong_max);
    printf("Unsigned ranges:\n");
    printf("char max: %u\n", (unsigned int)computed_uchar_max);
    printf("short max: %u\n", (unsigned int)computed_ushort_max);
    printf("int max: %u\n", computed_uint_max);
    printf("long max: %lu\n", computed_ulong_max);
    printf("long long max: %llu\n", computed_ullong_max);

    return 0;
}
