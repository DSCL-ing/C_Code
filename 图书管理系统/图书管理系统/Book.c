#define _CRT_SECURE_NO_WARNINGS 1

#include"Book.h"



void loadBook(struct Book*ps)//加载文件记录
{
    int i = 0;
    FILE*pf = fopen("Book.txt", "r");
    if (pf == NULL){
        perror("文件不存在，初始化");
        fclose(pf);
        pf = NULL;
        return;
    }
        struct BookInfo tmp = { 0 };
		while (fscanf(pf, "%s ", &(tmp.name)) != EOF)
        {
			
			fscanf(pf, "%s ", &(tmp.ISBN));
			fscanf(pf, "%s ", &(tmp.price));
			fgetc(pf);
            ps->data[ps->size] = tmp;
            ps->size++;
            CheckCapacity(ps);
        }
    fclose(pf);
    pf = NULL;
}

//初始化
void Initialization(struct Book *ps)
{
    ps->data = (struct BookInfo*)malloc(DEFAULT_SZ*sizeof(struct BookInfo));
    if (ps->data == NULL){
        perror("初始化容量失败");
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    loadBook(ps);
}

void CheckCapacity(struct Book*ps)//检查yu增容
{
    if (ps->capacity <= ps->size){
    }
    else{
        return;
    }
    struct BookInfo* ptr = (struct BookInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct BookInfo));
    if (ptr != NULL){       
        ps->data = ptr;
        ps->capacity += 2;
        printf("增容成功\n");
    }
    else{
        perror("增容失败");
        return;
    }
}

//添加
void Add(struct Book * ps)
{
	CheckCapacity(ps);
	struct BookInfo tmp;
	printf("请输入姓名>:");
	scanf("%s", tmp.name);
	printf("请输入ISBN>:");
	scanf("%s", tmp.ISBN);
	printf("请输入价格>:");
	scanf("%s", tmp.price);
	int ret = 0;
	for (int i = 0; i < ps->size; i++)
	{
		if (!strcmp(ps->data[i].name ,tmp.name)||!strcmp(ps->data[i].ISBN,tmp.ISBN))
		{
			printf("书籍已存在，是否覆盖？(y/n)\n");
			char flag[5];
			scanf("%s", &flag);
			if (!strcmp(flag,"y"))
			{
				ps->data[i] = tmp;
				printf("覆盖成功\n");
				system("pause");
				return;
			}
			else
			{
				break;
			}
		}
	}
	ps->data[ps->size] = tmp;
	ps->size++;
	printf("添加新书籍成功\n");
	system("pause");
}

static int Find(struct Book *ps)
{
     char name[MAX_NAME];
    scanf("%s", name);
    int i = 0;
    for (i; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name,name))
        {
            return i;
        }
    }
    return -1;
}

void Del(struct Book *ps)
{
    int i = 0;
    printf("请输入需要删除的书籍的书名>:");
    scanf("%d", &i);
    i -= 1;
    if (i < 0 || i > ps->size)
    {
        printf("没有该书籍\n");
    }
    else
    {
        for (i ; i < ps->size - 1; i++)
        {
            ps->data[i] = ps->data[i+1];
        }
        ps->size--;
        printf("删除成功\n");
    }
	system("pause");
}

void Print(const struct Book *ps , int i )
{
	printf("%-20s %-10s %-5s\n",
		ps->data[i].name,
		ps->data[i].ISBN,
		ps->data[i].price);
}

void Show(const struct Book *ps)
{
    if (ps->size == 0)
        printf("无数据\n");
    else
    {
		printf("\t%-20s %-10s %-5s\n",
			"name",
			"ISBN",
			"price");
		for (int i = 0; i < ps->size; i++)
		{
			printf("NO:%d\t", i+1);
			Print(ps,i);
		}
    }
	system("pause");
}

void Search(struct Book *ps)
{
    printf("请输入需要查找的书籍的书名>:\n");

    int i = Find(ps);
    if (i == -1)
    {
        printf("没有该书籍\n");
    }
    else
    {
		printf("\t%-20s %-10s %-5s\n",
			"name",
			"ISBN",
			"price");
		Print(ps, i);
        //printf("NO.%-d\t%-20s%-10s\t%-5s\n",
        //    i + 1,
        //    ps->data[i].name,
        //    ps->data[i].ISBN,
        //    ps->data[i].price);
    }
	system("pause");
}

void Mod(struct Book *ps)
{
    printf("请输入要修改的书名>:");
	int i = Find(ps);
    if (i == -1)
    {
        printf("没有该书籍\n");
    }
    else
    {
        printf("请输入姓名>:"); scanf("%s", ps->data[i].name);
        printf("请输入ISBN>:"); scanf("%s", ps->data[i].ISBN);
        printf("请输入价格>:"); scanf("%s", ps->data[i].price);

        printf("修改成功\n");
    }
	system("pause");
}

void sort(struct Book *ps)
{
	struct BookInfo tmp;
	int flag = 0;//哨兵卫
	for (int i = 0; i < ps->size; ++i)
	{
		for (int j = 1; j < ps->size - i; ++j)
		{
			if (strcmp(ps->data[j-1].name, ps->data[j].name)>0)
			{
				tmp = ps->data[j - 1];
				ps->data[j - 1] = ps->data[j];
				ps->data[j] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	printf("排序成功\n");
	system("pause");
}

void Destroy(struct Book *ps)
{
    free(ps->data);
    ps->data = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void Save(struct Book *ps)
{
    int i = 0;
    FILE*pf = fopen("Book.txt", "w");
    if (pf == NULL)
    {
        perror("打开文件失败");
        return;
    }
    for ( i = 0; i < ps->size; i++)
    {
        //fwrite(ps->data + i, sizeof(struct BookInfo), 1, pf);
		fprintf(pf, "%s %s %s\n", ps->data[i].name ,ps->data[i].ISBN , ps->data[i].price);
		//fprintf(pf, "%s ", ps->data->ISBN);
		//fprintf(pf, "%s ", ps->data->price);
    }
    fclose(pf);
    pf = NULL;
    printf("文件保存成功\n");
	system("pause");
}