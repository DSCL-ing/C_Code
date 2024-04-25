1、注意每行 / 块代码的先后执行顺序，影响代码的思想逻辑


思想：低耦合   ---解耦
使函数尽可能与其他无关联 ， 安全

函数递归技巧：如果OJ所给的函数fun参数不好递归，可以另开个子函数_fun来递归

release 下调试会有问题，没有调试信息。所以一定要用debug模式调试

//一、
//在VS2008中出现问题： fatal error LNK1000 : Internal error during IMAGE::BuildImage错误解决
//修改链接选项，方法：项目->（项目名称）属性->链接器->常规 下面的“启用增量链接”，
//将“是(/ INCREMENTAL)”改为“否(/ INCREMENTAL:NO)”，然后确定就可以了。
//问题导致：多次预定义
//#define _CRT_SECURE_NO_WARNINGS 1//scanf
//#define _CRT_SECURE_NO_WARNINGS 1//scanf




