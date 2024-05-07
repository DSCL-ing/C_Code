#include <stdio.h>


#define N 100 

void func()
{
    printf("%d\n", N);
}

int main()
{
    printf("%d\n", N);
#undef N
    func();
    return 0;
}
