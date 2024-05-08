#include <stdio.h>




int main()
{
#ifdef TEST1 || TEST2
	puts("1");
#else
	puts("2");
#endif

    return 0;
}
