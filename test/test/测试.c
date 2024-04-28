#include<stdio.h>

int main()
{
#if 0
    int a = 10;
    int b = 20;

    char c = 'abc';
    printf("%c",c);
#endif

    printf("%d\n",sizeof(1));  //4
    printf("%d\n",sizeof("1"));//2
    printf("%d\n",sizeof('1'));//4
    char c = '1';
    printf("%d\n",sizeof(c));  //1

    return 0;
}
