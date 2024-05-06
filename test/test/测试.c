#include<stdio.h>
#include<math.h>

#define INIT_VALUE(a,b) a = 0; b = 0;

int main()
{
    int a = 10;
    int b = 20;
    printf("before a = %d, b = %d\n",a,b);
    int flag = 0;
    scanf("%d",&flag);
    if(flag)
        INIT_VALUE(a,b);
    return 0;
}
