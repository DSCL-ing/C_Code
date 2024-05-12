#include <stdio.h>


int main()
{
    int a[5][5] = { 0 };
    for (int i = 0; i < 25; i++)
    {
        *(&**a + i) = i;
    }
    for (int i = 0; i < 25; i++)
    {
        printf("%d ", *(&**a + i));
    }
    puts("");

    int(*p)[4];
    p = a;
    printf("pa=%p, pb=%p", &a[4][2], &p[4][2]);  //请问结果分别是多少?

    //先将指针模拟数组多维访问的方式降维成一维: p[4][2] = *(*(p + 4) + 2);
    //p所指向的类型是int[4],因此步长是4个int
    //a本身是数组,不需要降维
    //编译器会查看元素是否是地址,或者说,默认指针计算就是把元素值当作地址.所以不用当心指针解引用后是指针还是数据的影响.


    //printf("pa=%p, pb=%p",&a[4][2],&p[4][2]);

# if 0

    int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", *(*(a + i) + j));
        }
        puts("");
    }

    //printf("%p\n",a+1);
    //printf("%p\n",a[0]+4);
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof((&a[0])));
#endif

    return 0;
}
