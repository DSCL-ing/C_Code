#include <stdio.h>

#define SQR(x) printf("The square of "#x" is %d.\n", ((x)*(x)));

int main()
{
    SQR(8);
    return 0;
}
