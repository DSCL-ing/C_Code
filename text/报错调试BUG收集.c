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




//二、---------------------------------------------------------------------------------------------------------------------------
//向下调整算法：前提：左右子树是堆 //适合建堆：递归从最小父亲开始（虽然可以从最小孩子）
void AdjustDown(HeapDataType *a, int size, int parent)
{
	////比较两个孩子中最大/小的进行交换
	//int child = parent * 2 + 1;
	//if (child < size &&  parent < size && a[child] < a[child + 1]) //// ------------这种逻辑是不对的，一个在while外面，一个在while里面，重复，当size == child的时候卡掉一个
	//{																				   //如果出现，务必消除，把while和if条件拆分出来
	//	child = child + 1;
	//}
	////调整到叶子结束	 		                                   //&&先判断左边
	//while (child < size &&  parent < size && a[parent] < a[child]) //child 可能越界，先保证child<size	
	//{
	//	Swap(&a[parent], &a[child]);
	//	parent = child;
	//	child = parent * 2 + 1;
	//	if (child < size &&  parent < size && a[child] < a[child + 1])//-----------------------------------------------------------------------
	//	{
	//		child = child + 1;
	//	}
	//} 


	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size &&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])//小堆大于最小孩子就交换，
		{						 //大堆小于最大孩子就交换
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}