



//
//最近开始研究C++程序，编译的时候老是遇到如题中的问题，百度了一下，发现如下的解决方法，贴出来大家共同学习一下：
//在VS2008中出现问题： fatal error LNK1000 : Internal error during IMAGE::BuildImage错误解决
//修改链接选项，方法：项目->（项目名称）属性->链接器->常规 下面的“启用增量链接”，
//将“是(/ INCREMENTAL)”改为“否(/ INCREMENTAL:NO)”，然后确定就可以了。
//问题导致：多次预定义
//#define _CRT_SECURE_NO_WARNINGS 1//scanf
//#define _CRT_SECURE_NO_WARNINGS 1//scanf

