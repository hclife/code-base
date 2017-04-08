/* limits.c: Illustrates integral limits */
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char: %lu [%d, %d]\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short: %lu [%d, %d]\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int: %lu [%d, %d]\n", sizeof(int), INT_MIN,  INT_MAX);
    printf("long: %lu [%ld, %ld]\n", sizeof(long), LONG_MIN, LONG_MAX);
    //printf("long long: %lu\n", sizeof(long long));

    return 0;
}

