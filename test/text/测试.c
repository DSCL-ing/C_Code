#include<stdio.h>

void fun()
{
}

enum color
{
    A ,
    B ,
    C = 0,
    D
};

enum e{};

int main()
{
    int a = 1;
    int b = 2;
    enum color c =a;
    c = b;
    printf("%d\n",A);
    printf("%d\n",B);
    printf("%d\n",C);
    printf("%d\n",D);
    printf("%d\n",sizeof(enum e));
    return 0;
}
