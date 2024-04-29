#include<stdio.h>


int show()
{
    printf("aaaaaaa");
    return 1;
}

int main()
{
#if 1
   int flag = 0;
   scanf("%d",&flag);
   flag && show();  //使用短路实现的if语句效果
   //如果表达式左边为假,则表达式右边不再执行,这样的语句就称为短路.

   scanf("%d",&flag);
   flag || show();  //使用短路实现的if not语句

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
