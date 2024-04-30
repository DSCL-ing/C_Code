#include<stdio.h>


int main()
{
    char c = 0;
    printf("sizeof(c): %d\n", sizeof(c)); //1
    printf("sizeof(c): %d\n", sizeof(~c)); //4
    printf("sizeof(c): %d\n", sizeof(c << 1)); //4
    printf("sizeof(c): %d\n", sizeof(c >> 1)); //4
    return 0;
}
