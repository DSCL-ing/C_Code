1��ע��ÿ�� / �������Ⱥ�ִ��˳��Ӱ������˼���߼�


˼�룺�����   ---����
ʹ�����������������޹��� �� ��ȫ

�����ݹ鼼�ɣ����OJ�����ĺ���fun�������õݹ飬���������Ӻ���_fun���ݹ�

release �µ��Ի������⣬û�е�����Ϣ������һ��Ҫ��debugģʽ����

//һ��
//��VS2008�г������⣺ fatal error LNK1000 : Internal error during IMAGE::BuildImage������
//�޸�����ѡ���������Ŀ->����Ŀ���ƣ�����->������->���� ����ġ������������ӡ���
//������(/ INCREMENTAL)����Ϊ����(/ INCREMENTAL:NO)����Ȼ��ȷ���Ϳ����ˡ�
//���⵼�£����Ԥ����
//#define _CRT_SECURE_NO_WARNINGS 1//scanf
//#define _CRT_SECURE_NO_WARNINGS 1//scanf




//����---------------------------------------------------------------------------------------------------------------------------
//���µ����㷨��ǰ�᣺���������Ƕ� //�ʺϽ��ѣ��ݹ����С���׿�ʼ����Ȼ���Դ���С���ӣ�
void AdjustDown(HeapDataType *a, int size, int parent)
{
	////�Ƚ��������������/С�Ľ��н���
	//int child = parent * 2 + 1;
	//if (child < size &&  parent < size && a[child] < a[child + 1]) //// ------------�����߼��ǲ��Եģ�һ����while���棬һ����while���棬�ظ�����size == child��ʱ�򿨵�һ��
	//{																				   //������֣������������while��if������ֳ���
	//	child = child + 1;
	//}
	////������Ҷ�ӽ���	 		                                   //&&���ж����
	//while (child < size &&  parent < size && a[parent] < a[child]) //child ����Խ�磬�ȱ�֤child<size	
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
		if (a[child] > a[parent])//С�Ѵ�����С���Ӿͽ�����
		{						 //���С������Ӿͽ���
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