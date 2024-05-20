#include <stdio.h>
#include <stdarg.h>

FindMax(int num, ...)
{
    va_list arg;
    va_start(arg, num);
    int max = 0;
    max = va_arg(arg, int);
    for (int i = 0; i < num - 1; i++)
    {
        int cur = va_arg(arg, int);
        if (cur > max)
        {
            max = cur;
        }
    }
    va_end(arg);

    return max;
}

int main()
{
#if defined(_INC_STDARG)
#pragma message("included stdarg.h")
#else
#pragma message("no included stdarg.h");
#endif

    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    char e = 'e';
    int max = FindMax(5, a, b, c, d, e);
    printf("max = %d\n", max);
    return 0;
}