
#define _CRT_SECURE_NO_WARNINGS 
#include<math.h>
#include<stdio.h>
//#pragma warning(disable:4996)

int main()
{
    int n = 0 ;
    scanf("%d",&n);
    switch (n)
    {
        int a = 1;
        case 1:
        printf("%d\n",a);
        case 2:
        case 3:
        case 4:
        case 5:
            puts("周内");
            break;
        case 6:
            puts("周六");
            break;
        case 7:
            puts("周日");
            break;
        default:
            break;
    }
    return 0;
}
