#include<stdio.h>
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
    //unsigned int x = 0xFFFFFFFF;
     int x = 0xFFFFFFFF;
    //printf("%d\n",x);
    //x = -1;
    //CLRBIT(x,32);
    //ShowBits(x);
    x>>=1;
    ShowBits(x);
    return 0;
}
