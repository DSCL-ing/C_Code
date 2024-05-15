#include <stdio.h>


typedef char type_t;
#define N 10

int main()
{
	type_t *p = malloc(sizeof(type_t) * N);
	
	free(p);
	return 0;
} 
