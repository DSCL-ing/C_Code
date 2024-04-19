
#define _CRT_SECURE_NO_WARNINGS 
#include<math.h>
#include<stdio.h>
//#pragma warning(disable:4996)

int main()
{
    int i = 0;
start:
    printf("[%d] goto running ...\n",i);
    i++;
    if(i<10) goto start;
    return 0;
}
