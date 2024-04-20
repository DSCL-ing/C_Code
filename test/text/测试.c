#include<stdio.h>

int getDate()
{
    int x = 0x11223344;
    puts("getDate");
    return x;
}

int main()
{
    int y = getDate();
    return 0;
}