#include<stdio.h>

int main()
{
#if 1
    int a = 10;
    int b = 20;

    char c = 'abcd';
    printf("%c",c);
#endif

#if 0
    printf("%d\n",sizeof(1));  //4
    printf("%d\n",sizeof("1"));//2
    printf("%d\n",sizeof('abc'));//4
    char c = 'abcd';
    printf("%d\n",sizeof(c));  //1
#endif

    return 0;
}
