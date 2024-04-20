
#define _CRT_SECURE_NO_WARNINGS 
#include<math.h>
#include<stdio.h>
//#pragma warning(disable:4996)


double arr[10];
int main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%p ",arr+i);
    }
    puts("");
    for (int i = 0; i < 10; i++)
    {
        printf("%f ",*(arr+i));
    }
    return 0;
}

