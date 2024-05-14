#include <stdio.h>


struct stu
{
	int num;
	int arr[];
};

int main()
{
	struct stu s;	
	s.num = 5;
	s.arr = malloc(4*s.num);
	return 0;
}
