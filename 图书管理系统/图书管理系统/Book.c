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
        while (fread(&tmp, sizeof(struct BookInfo), 1, pf))
        {
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
        printf("请输入姓名>:"); 
        scanf("%s", ps->data[ps->size].name);
        printf("请输入ISBN>:"); 
        scanf("%s", ps->data[ps->size].ISBN);
        printf("请输入价格>:"); 
        scanf("%s", ps->data[ps->size].price);

    ps->size++;
    printf("添加成功\n");
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
    printf("请输入编号>:");
    scanf("%d", &i);
    i -= 1;
    if (i < 0 || i > ps->size)
    {
        printf("输入有误\n");
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
}

void Show(struct Book *ps)
{
    if (ps->size == 0)
        printf("无数据\n");
    else
    {
        printf("NO:     %-30s\t%-20s\t%-10s\n", 
            "name",
            "ISBN",
            "price");
        for (int i = 0; i < ps->size; i++)
        {
            printf("NO.%-d\t%-30s%-20s\t%-10s\n",
                i+1,
                ps->data[i].name,
                ps->data[i].ISBN,
                ps->data[i].price);
        }
    }
}

void Search(struct Book *ps)
{
    printf("请输入查找的书名>:\n");

    int i = Find(ps);
    if (i == -1)
    {
        printf("数据不存在\n");
    }
    else
    {
        printf("NO.%-d\t%-30s%-20s\t%-10s\n",
            i + 1,
            ps->data[i].name,
            ps->data[i].ISBN,
            ps->data[i].price);
    }
}

void Mod(struct Book *ps)
{
    int i = 0;
    printf("请输入编号>:");
    scanf("%d", &i);
    if (i < 0 && i >= ps->size)
    {
        printf("数据不存在\n");
    }
    else
    {
        printf("请输入姓名>:"); scanf("%s", ps->data[i-1].name);
        printf("请输入ISBN>:"); scanf("%s", ps->data[i-1].ISBN);
        printf("请输入价格>:"); scanf("%s", ps->data[i-1].price);

        printf("修改成功\n");
    }
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
        fwrite(ps->data + i, sizeof(struct BookInfo), 1, pf);
    }
    fclose(pf);
    pf = NULL;
    printf("文件保存成功\n");
}