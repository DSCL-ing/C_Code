#include<stdio.h>

// 0|0 = 0 ; 0|1 = 1  //  规律:任何数或0结果都是它本身      //用途:
// 1|0 = 1 ; 1|1 = 1  //  规律:任何数或1,结果都是被设置为1  //用途:特定 比特位 置1
// 组合用途:让特定比特位置1,其他位不变

// 0&0 = 0 ; 0&1 = 0; //  规律:任何书与0,结果都是被设置成0  //用途:特定比特位置0
// 1&0 = 0 ; 1&1 = 1; //  规律:任何书与1,结果都是它本身     //用途:获取特定比特位的值
// 组合用途:没有干扰地获取特定比特位的值

//一般都是用1(000...1)比较方便,通过移动1的位置,加上不同的位运算符,能够实现不同的功能.

#define SETBIT(x,n)  (x |= (1<<(n-1))) //统一体现: 宏函数:宏加上了函数圆括号()就成了宏函数.普通函数不带分号,宏函数也不要带分号
#define CLRBIT(x,n)   (x &= ~(1<<(n-1))) //移位后取反

void ShowBits(int x)
{
    int num = sizeof(int) * 8;
    while (num)
    {
        if (x & (1 << (num - 1)))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        num--;
    };
    puts("");

}

int main()
{
    int x = 0;
    ShowBits(x);
    SETBIT(x,5);
    SETBIT(x,32);
    SETBIT(x,1);
    ShowBits(x);
    CLRBIT(x,5);
    CLRBIT(x,1);
    CLRBIT(x,32);
    ShowBits(x);
    return 0;
}
