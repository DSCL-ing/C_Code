#include <stdio.h>


int Add(int a, int b)
{
    return a+b;
}

int main()
{
    int x = 0xA;
    int y = 0xB;
    int z = 0;
    z = Add(x,y);
    return 0;
}
