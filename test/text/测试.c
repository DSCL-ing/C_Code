

// x - y == 0的条件是 |x - y| < 精度
//即 x - y > -精度 && x - y < 精度

// 还可以使用fabs函数,C90,<math.h>, double fabs(double x); 返回x的绝对值
//即 fabs(x-y) < 精度

#include<stdio.h>
#include<math.h>
#include<float.h>

int main()
{
    double x = 0.0;

    if(fabs(x) < DBL_EPSILON ) printf("aaaa\n");
    else printf("bbbb\n");
    
    return 0;
}
    //printf("%0.50f\n",x - 0.9);
