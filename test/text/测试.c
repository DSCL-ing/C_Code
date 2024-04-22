#include<stdio.h>

struct data
{
    int num;
    int arr[0];
};

void fun()
{

    int a = 10;
    int b = 20;
    int arr[5] = {1,2,3,4,5};
    printf("%p\n",a);
    printf("%p\n",b);
    printf("%p\n",&arr);
    printf("%p\n",arr[1]);
    printf("%p\n",arr[2]);
}

int main()
{
fun();
    return 0;
}
