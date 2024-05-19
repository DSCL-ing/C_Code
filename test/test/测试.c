#include <stdio.h>
#include<stdarg.h>

FindMax(int num, ...)
{
    va_list arg;
    va_start(arg,num);
    int max = 0;
    max = va_arg(arg,int);
    for()

    return;
}

int main()
{
#if defined(_INC_STDARG)
    #pragma message("included stdarg.h");
#else
    #pragma message("no included stdarg.h");
#endif

     
    return 0;
}
