#include <stdio.h>


int main()
{
    int a[4] = {1,2,3,4};
    int *p = &a+1;
    printf("%d \n",p[-1]);
    return 0;
}
