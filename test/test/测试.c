#include <stdio.h>

void func()
{ }

int main()
{
	printf("%p\n",func);
	printf("%p\n",&func);
	return 0;
}
