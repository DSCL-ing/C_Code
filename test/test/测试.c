#include<stdio.h>
#include<math.h>

int main()
{
    int a = -2.9;
    int b = 12.9;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%f\n",trunc(b));
    printf("%d\n",trunc(b)); 
    printf("%d\n",(int)trunc(b));
    return 0;
}
