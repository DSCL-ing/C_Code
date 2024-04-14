#define _CRT_SECURE_NO_WARNINGS 1//scanf
#define _CRT_SECURE_NO_DEPRECATE//getch
#define _CRT_NONSTDC_NO_DEPRECATE//getch
#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcmp��
#include<dos.h>
#include<conio.h>//����̨������������� getch��
#define LEN sizeof(struct student)
#define FORMAT "%-15s  %-8d  %-8d  %-8d  %-15s\n  %-15s  %-15s  %-15s  %-8d\n  %-15s  %-8d  %-8d  %-15s  %-8d\n"
#define DATA stu[i].name,stu[i].age,stu[i].year,stu[i].mouth,stu[i].p_num,   stu[i].address,stu[i].school,stu[i].major,stu[i].num,      stu[i].subject,stu[i].score,stu[i].credit,stu[i].teacher,stu[i].gpa
struct student
{

	char name[15];	/*����*/
	int age;//����2
	int year;
	int mouth;//������������34
	int p_num;//�ֻ���5
	char address[15];//��ַ6
	char school[15];//ѧУ7
	char major[15];//רҵ8
	int num;		//ѧ��9
	char subject[15];//��Ŀ10
	int score;	//�ɼ�11
	int credit;//ѧ��12
	char teacher[15];	//��ʦ13
	int gpa;	/*ƽ��ѧ��*///14
}stu[50]; 
//= { "0", 0, 0, 0, 0, "0", "0", "0", 0, "0", 0, 0, "0", 0 };

void in();				/*¼��ѧ���ɼ���Ϣ*/
void show();			/*��ʾѧ����Ϣ*/
void order();			/*���ܷ�����*/
void del();				/*ɾ��ѧ���ɼ���Ϣ*/
void modify();			/*�޸�ѧ���ɼ���Ϣ*/
void menu();			/*���˵�*/
void insert();			/*����ѧ����Ϣ*/
void total();			/*����������*/
void search();			/*����ѧ����Ϣ*/


int n;
int main()
{
	menu();
	scanf("%d", &n);
	while (n)
	{
		switch (n)
		{
		case 1:in(); break;
		case 2:search(); break;
		case 3: del(); break;
		case 4: modify(); break;//
		case 5: insert(); break;//
		case 6: order(); break;//
		case 7: total(); break;
		case 8: show(); break;
		default:break;

		}

		getch();
		menu();/*ִ���깦���ٴ���ʾ�˵�����*/
		scanf("%d", &n);
	}
}




void menu()//Ŀ¼
{
	printf("ѧ����Ϣ����ϵͳ\n");
	printf("\n");
	printf("1.¼��ѧ����Ϣ\n");
	printf("2.����ѧ����Ϣ\n");
	printf("3.ɾ��ѧ����Ϣ\n");
	printf("4.��ѧ����Ϣ(δʵװ)\n");
	printf("5.����ѧ����Ϣ(δʵװ)\n");
	printf("6.����\n(δʵװ)");
	printf("7.ͳ��ѧ������\n");
	printf("8.��ʾ����ѧ����Ϣ\n");
	printf("9.�˳�ϵͳ\n");
	printf("\n");
	printf("��ѡ��0-9����");
}


/**************************************************************/
void in()/*¼��ѧ����Ϣ*/
{
	int i, m = 0;/*m�Ǽ�¼������*/
	char ch[2];
	FILE *fp;/*�����ļ�ָ��*/
	if ((fp = fopen("data.txt", "a+")) == NULL)/*��ָ���ļ�*/
	{
		printf("�ļ������ڣ�\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;/*ͳ�Ƶ�ǰ��¼����*/
		}
	}
	fclose(fp);

	if (m == 0)
	{
		printf("�ļ���û�м�¼!\n");
	}
	else
	{
		show();/*����show��������ʾԭ����Ϣ*/
	}
	if ((fp = fopen("data.txt", "wb")) == NULL)
	{
		printf("�ļ������ڣ�\n");
		return;
	}


	printf("����ѧ����Ϣ(y/n):");
	scanf("%s", ch);
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("���س����Լ���\n����ѧ��ѧ��:");
		scanf("%d", &stu[m].num);/*����ѧ��ѧ��*/
		for (i = 0; i<m; i++)
			if (stu[i].num == stu[m].num)
			{
			printf("number�Ѿ������ˣ������������!");
			getch();
			fclose(fp);
			return;
			}
		printf("����:"); scanf("%s", &stu[m].name[15]); getchar();
		printf("\n����:"); scanf("%d", &stu[m].age); getchar();
		printf("\n������:"); scanf("%d", &stu[m].year);getchar();
		printf("\n������:"); scanf("%d", &stu[m].mouth);getchar();
		printf("\n�ֻ���:"); scanf("%d", &stu[m].p_num);getchar();
		printf("\n��ַ:"); scanf("%s", &stu[m].address[50]);getchar();
		printf("\nѧУ:"); scanf("%s", &stu[m].school[15]);getchar();
		printf("\nרҵ:"); scanf("%s", &stu[m].major[15]);getchar();
		printf("\nѧ��:"); scanf("%d", &stu[m].num);getchar();	
		printf("\n��Ŀ:"); scanf("%s", &stu[m].subject[15]);getchar();
		printf("\n�ɼ�:"); scanf("%d", &stu[m].score);getchar();	
		printf("\nѧ��:"); scanf("%d", &stu[m].credit);getchar();
		printf("\n��ʦ:"); scanf("%s", &stu[m].teacher[15]);getchar();
		printf("\nƽ������:"); scanf("%s", &stu[m].gpa);getchar();
		
		if (fwrite(&stu[m], LEN, 1, fp) != 1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
		{
			printf("���ܱ���!");
			getch();
		}
		else
		{
			printf("%s ������!\n", stu[m].name);
			m++;
		}
		printf("����?(y/n):");/*ѯ���Ƿ����*/
		scanf("%s", ch);
	}
	fclose(fp);
	printf("OK!\n");
}




void show()//��ʾ����ѧ����Ϣ
{
	FILE *fp;
	int i, m = 0;
	//fp = fopen("data.txt", "rb");

	  	if((fp=fopen("data.txt","a+"))==NULL)/*��ָ���ļ�*/
	  	{ 
		  	printf("�ļ������ڣ�\n");
		  	return;
	 	}
	  	fclose(fp);
	  //	if(m==0)
	//	  	printf("�ļ���û�м�¼!\n");
		//	return;	 

	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
			m++;
	}
	fclose(fp);
	printf("����ɼ�\n");
	for (i = 0; i<5; i++)
	{

		printf(FORMAT, DATA);/*����Ϣ��ָ����ʽ��ӡ*/
		//printf("%-15s", stu[i].name);/*����Ϣ��ָ����ʽ��ӡ*/
	//printf("%-8d%-8d%-8d%-15s\n", stu[i].age, stu[i].year, stu[i].mouth, stu[i].p_num);
		//printf("%-15s%-15s%-15s%-8d\n", stu[i].address, stu[i].school, stu[i].major, stu[i].num);/*����Ϣ��ָ����ʽ��ӡ*/
		//printf("%-15s%-8d%-8d%-15s%-8d", stu[i].subject, stu[i].score, stu[i].credit, stu[i].teacher, stu[i].gpa);
		//printf("");
	}
	//system("pause");
}
//void menu()/*�Զ��庯��ʵ�ֲ˵�����*/
//{
//	system("cls");
//	printf("\n\n\n\n");
//	printf("\t\t|---------------ѧ����Ϣ����ϵͳ---------------|\n");
//	printf("\t\t|\t\t\t\t\t       |\n");
//	printf("\t\t|\t\t 1. ¼��ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 2. ����ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 3. ɾ��ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 4. �޸�ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 5. ����ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 6. ����\t\t       |\n");
//	printf("\t\t|\t\t 7. ͳ��ѧ������\t       |\n");
//	printf("\t\t|\t\t 8. ��ʾ����ѧ����Ϣ\t       |\n");
//	printf("\t\t|\t\t 0. �˳�ϵͳ\t\t       |\n");
//	printf("\t\t|\t\t\t\t\t       |\n");
//	printf("\t\t|----------------------------------------------|\n\n");
//	printf("\t\t\t��ѡ��(0-8):");
//}

void order()/*�Զ���������*/
{
	//FILE *fp;
	//struct student t;
	//int i = 0, j = 0, m = 0;
	//if ((fp = fopen("data.txt", "r+")) == NULL)
	//{
	//	printf("�ļ������ڣ�\n");
	//	return;
	//}
	//while (!feof(fp))
	//	if (fread(&stu[m], LEN, 1, fp) == 1)
	//		m++;
	//fclose(fp);
	//if (m == 0)
	//{
	//	printf("�ļ���û�м�¼!\n");
	//	return;
	//}
	//if ((fp = fopen("data.txt", "wb")) == NULL)
	//{
	//	printf("�ļ������ڣ�\n");
	//	return;
	//}
	//for (i = 0; i<m - 1; i++)
	//	for (j = i + 1; j<m; j++)/*˫��ѭ��ʵ�ֳɼ��Ƚϲ�����*/
	//		if (stu[i].sum<stu[j].sum)
	//		{
	//	t = stu[i]; stu[i] = stu[j]; stu[j] = t;
	//		}
	//if ((fp = fopen("data.txt", "wb")) == NULL)
	//{
	//	printf("�ļ������ڣ�\n");
	//	return;
	//}
	//for (i = 0; i<m; i++)/*�������ź������������д��ָ���Ĵ����ļ���*/
	//	if (fwrite(&stu[i], LEN, 1, fp) != 1)
	//	{
	//	printf("%s ���ܱ����ļ�!\n");
	//	getch();
	//	}
	//fclose(fp);
	//printf("����ɹ�\n");
	;
}

void del()/*�Զ���ɾ������*/   /*�߼��������ж�data.txt�ļ��Ƿ���ڣ�������ڣ������������ж��ļ��Ƿ�Ϊ�գ���Ϊ�գ�������Ҫɾ����ѧ��ѧ�ţ�����ļ�������
						���ء��ļ������ڡ����ļ�����Ϊ���򷵻ء��ļ���û�м�¼��
						����ѧ��----�ж��Ƿ������ѧ�š��У�ѯ���Ƿ�ɾ����yɾ����n��ɾ�� �����ҵ��˼�¼��ѡ��ɾ������
						û�У���û���ҵ�����ѧ��!��
						*/
{
	FILE *fp;
	int snum, i, j, m = 0;
	char ch[2];
	if ((fp = fopen("data.txt", "r+")) == NULL)		//data.txt�ļ������� 
	{
		printf("�ļ������ڣ�\n");
		return;
	}
	while (!feof(fp))  if (fread(&stu[m], LEN, 1, fp) == 1) m++;
	fclose(fp);
	if (m == 0)
	{
		printf("�ļ���û�м�¼��\n");			//data.txt�ļ����ڣ�������û������ 
		return;
	}

	printf("������ѧ��ѧ��");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
		if (snum == stu[i].num)
		{
		printf("�ҵ���������¼���Ƿ�ɾ��?(y/n)");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*�ж��Ƿ�Ҫ����ɾ��*/
		{
			for (j = i; j<m; j++)
				stu[j] = stu[j + 1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
			m--;/*��¼���ܸ�����1*/
			if ((fp = fopen("data.txt", "wb")) == NULL)
			{
				printf("�ļ�������\n");
				return;
			}
			for (j = 0; j<m; j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
				if (fwrite(&stu[j], LEN, 1, fp) != 1)
				{
				printf("can not save!\n");
				getch();
				}
			fclose(fp);
			printf("ɾ���ɹ�!\n");
		}
		else{
			printf("�ҵ��˼�¼��ѡ��ɾ����");
		}
		break;
		}
		else
		{
			printf("û���ҵ�����ѧ��!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
		}
}

void search()/*�Զ�����Һ���*/			//�����������ļ���û�е�ѧ��ʱ����� 
{
	FILE *fp;
	int snum, i, m = 0;
	if ((fp = fopen("data.txt", "rb")) == NULL)
	{
		printf("�ļ������ڣ�\n");
		return;
	}
	while (!feof(fp))
		if (fread(&stu[m], LEN, 1, fp) == 1)
			m++;
	fclose(fp);
	if (m == 0)
	{
		printf("�ļ���û�м�¼��\n");
		return;
	}
	printf("������number:");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
		if (snum == stu[i].num)/*���������ѧ���Ƿ��ڼ�¼��*/
		{
		printf("number  name           elective    experiment  required    sum\t\n");
//		printf(FORMAT, DATA);/*�����ҳ��Ľ����ָ����ʽ���*/
		break;
		}
	if (i == m) printf("û���ҵ�����ѧ��!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
}

void modify()/*�Զ����޸ĺ���*/			//������Ҫ�޸��ļ���û�м�¼��ѧ��ʱ������˵���ҵ��ˡ������� 
{
	//FILE *fp;
	//struct student t;
	//int i = 0, j = 0, m = 0, snum;
	//if ((fp = fopen("data.txt", "r+")) == NULL)
	//{
	//	printf("�ļ������ڣ�\n");
	//	return;
	//}
	//while (!feof(fp))
	//	if (fread(&stu[m], LEN, 1, fp) == 1)
	//		m++;
	//if (m == 0)
	//{
	//	printf("�ļ���û�м�¼��\n");
	//	fclose(fp);
	//	return;
	//}
	//show();
	//printf("������Ҫ�޸ĵ�ѧ��number�� ");
	//scanf("%d", &snum);
	//for (i = 0; i<m; i++)
	//	if (snum == stu[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
	//	{
	//	printf("�ҵ�������ѧ��,�����޸�������Ϣ!\n");
	//	printf("name:");
	//	scanf("%s", stu[i].name);/*��������*/
	//	printf("elective:");
	//	scanf("%lf", &stu[i].elec);/*����ѡ�޿γɼ�*/
	//	printf("experiment:");
	//	scanf("%lf", &stu[i].expe);/*����ʵ��γɼ�*/
	//	printf("required course:");
	//	scanf("%lf", &stu[i].requ);/*������޿γɼ�*/
	//	printf("�޸ĳɹ�!");
	//	stu[i].sum = stu[i].elec + stu[i].expe + stu[i].requ;

	//	if ((fp = fopen("data.txt", "wb")) == NULL)
	//	{
	//		printf("can not open\n");
	//		return;
	//	}
	//	for (j = 0; j<m; j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
	//		if (fwrite(&stu[j], LEN, 1, fp) != 1)
	//		{
	//		printf("can not save!");
	//		getch();
	//		}
	//	fclose(fp);
	//	break;
	//	}
	//if (i == m)
	//	printf("û���ҵ�����ѧ��!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
	;
}

void insert()/*�Զ�����뺯��*/
{
	//FILE *fp;
	//int i, j, k, m = 0, snum;
	//if ((fp = fopen("data.txt", "r+")) == NULL)
	//{
	//	printf("�ļ������ڣ�\n");
	//	return;
	//}
	//while (!feof(fp))
	//	if (fread(&stu[m], LEN, 1, fp) == 1)
	//		m++;
	//if (m == 0)
	//{
	//	printf("�ļ���û�м�¼!\n");
	//	fclose(fp);
	//	return;
	//}
	//printf("������Ҫ�����λ��(number)��\n");
	//scanf("%d", &snum);/*����Ҫ�����λ��*/
	//for (i = 0; i<m; i++)
	//	if (snum == stu[i].num)
	//		break;
	//for (j = m - 1; j>i; j--)
	//	stu[j + 1] = stu[j];/*�����һ����¼��ʼ�������һλ*/
	//printf("����������Ҫ�����ѧ����Ϣ.\n");
	//printf("number:");
	//scanf("%d", &stu[i + 1].num);
	//for (k = 0; k<m; k++)
	//	if (stu[k].num == stu[m].num)
	//	{
	//	printf("number�Ѿ����ڣ������������!");
	//	getch();
	//	fclose(fp);
	//	return;
	//	}
	//printf("name:");
	//scanf("%s", stu[i + 1].name);
	//printf("elective:");
	//scanf("%lf", &stu[i + 1].elec);
	//printf("experiment:");
	//scanf("%lf", &stu[i + 1].expe);
	//printf("required course:");
	//scanf("%lf", &stu[i + 1].requ);
	//stu[i + 1].sum = stu[i + 1].elec + stu[i + 1].expe + stu[i + 1].requ;
	//printf("����ɹ�������������������棡");
	//if ((fp = fopen("data.txt", "wb")) == NULL)
	//{
	//	printf("���ܴ򿪣�\n");
	//	return;
	//}
	//for (k = 0; k <= m; k++)
	//	if (fwrite(&stu[k], LEN, 1, fp) != 1)/*���޸ĺ�ļ�¼д������ļ���*/
	//	{
	//	printf("���ܱ���!");
	//	getch();
	//	}
	//fclose(fp);
	;
}

void total()
{
	FILE *fp;
	int m = 0;
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("�ļ������ڣ�\n");
		return;
	}
	while (!feof(fp))
		if (fread(&stu[m], LEN, 1, fp) == 1)
			m++;			/*ͳ�Ƽ�¼������ѧ������*/
	if (m == 0) { printf("no record!\n"); fclose(fp); return; }
	printf("����༶һ���� %d ��ѧ��!\n", m);/*��ͳ�Ƶĸ������*/
	fclose(fp);
}
