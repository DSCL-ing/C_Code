#define _CRT_SECURE_NO_WARNINGS 1//scanf
//#define _CRT_SECURE_NO_DEPRECATE//getch
//#define _CRT_NONSTDC_NO_DEPRECATE//getch
//#include<stdio.h>
//#include<stdlib.h>//Sleep(1000)
//#include<windows.h>//system("cls")
//#include<string.h>//strcmp、
//#include<dos.h>
//#include<conio.h>//控制台输入输出函数库 getch、
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>


#include<stdio.h>
#include<stdlib.h>

//char *myScanf()
//{
//	int n = 0, k = 100;            //初始化，字符串长度为0，字符串空间长度为100
//	char c;
//	char * s2 = NULL;
//	char *s1 = (char *)malloc(100);    //初始化字符串空间
//	if (s1 == NULL)
//		return NULL;                    //内存分配失败，返回         
//	while ((c = getchar()) != EOF){        //判断是否到文件结束，一个个读取字符
//		if (k <= n){                    //当前字符串长度大于等于字符串空间长度时
//			k *= 2;                    //长度增长2倍
//			s2 = (char *)realloc(s1, k);    //重新分配内存
//			if (s2 == NULL){                //内存分配失败
//				free(s1);              //释放已分配内存
//				return NULL;
//			}
//			else{                     //内存分配成功
//				s1 = s2;
//			}
//		}
//		s1[n++] = c;                    //字符串赋值字符
//	}
//	s1[n] = 0;                          //字符串末尾置为\0
//	return s1;
//}


int main()
{
	//int a = sizeof(char);
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int k = 0;
	k = a>b ? c : d>e ? d : e;
	printf("%d ", k);
	return 0;

}











































































/*	栈区如图
------------------------
| ---------------------- |
||                      ||
||                      ||
||                      ||
||                      ||
||                      ||
||----------------------||
||                      ||
||                      ||
||                      ||
||                      ||
||                      ||
||----------------------||
||                      ||
||                      ||
||                      ||
| ---------------------- |

*/