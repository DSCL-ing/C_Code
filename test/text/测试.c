#include<stdio.h>

void fun()
{
}

union un
{
    int i;
    char a[4];
};

int main()
{
    union un x;
    x.a[0] = 0x78;
    x.a[1] = 0x56;
    x.a[2] = 0x34;
    x.a[3] = 0x12;
    printf("0x%x\n",x.i); //vs:0x12345678
    return 0;
}
