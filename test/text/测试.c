

// x - y == 0的条件是 |x - y| < 精度
//即 x - y > -精度 && x - y < 精度

// 还可以使用fabs函数,C90,<math.h>, double fabs(double x); 返回x的绝对值
//即 fabs(x-y) < 精度

#include<stdio.h>
#include<math.h>
#include<float.h>

int main()
{
    double x = 1.0;
    double y = 0.1;

    //验证x - 0.9 是否等于 0.1
    //<float.h> 内置最小精度值 DBL_EPSILON 和 FLT_EPSILON ,1.0+DBL_EPSILON != 1.0 ,1.0加上一个很小很小的值不等于1.0,EPSILON就是这个很小的值,数学概念,略
    if(fabs((x-0.9)- y) < DBL_EPSILON ) printf("aaaa\n");
    else printf("bbbb\n");
    
    return 0;
}
    //printf("%0.50f\n",x - 0.9);
