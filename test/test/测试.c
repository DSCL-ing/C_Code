#include<stdio.h>
#include<stdarg.h>

/*
micro:
    __FILE__ :  当前代码所在文件
    __LINE__ :  第几行
   */

   //2. 
#define LOG(fmt,...) printf("[%s:%d]" fmt,__FILE__,__LINE__,__VA_ARGS__);
/*
   1.fmt是个字符串,字符串和字符串能够拼接
 */

int main()
{
    //1.引入
    //printf("[%s:%d] %s %d\n",__FILE__,__LINE__,"测试",999) ;
    LOG("hello");


    return 0;

}