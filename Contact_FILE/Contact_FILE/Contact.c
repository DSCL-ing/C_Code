#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"



void loadContact(struct Contact*ps)//加载文件记录
{
    int i = 0;
    FILE*pf = fopen("Contact.txt", "r");
    if (pf == NULL){
        perror("文件不存在，初始化");
        fclose(pf);
        pf = NULL;
        return;
    }
        struct PeopleInformation tmp = { 0 };
        while (fread(&tmp, sizeof(struct PeopleInformation), 1, pf))
        {
            ps->data[ps->size] = tmp;
            ps->size++;
            CheckCapacity(ps);
        }
    fclose(pf);
    pf = NULL;
}

//初始化，令当前存放数大小为0，令所有数组元素为0
void Initialization(struct Contact *ps)
{
    //int i = 0;
    //memset(ps->data, 0, sizeof(ps->data));//只能是0，所有字节都设置成0，ps->data(数组名就是地址），sizeof（数组名）计算整个数组的大小

    ps->data = (struct PeopleInformation*)malloc(DEFAULT_SZ*sizeof(struct PeopleInformation));
    if (ps->data == NULL){
        perror("初始化容量失败");
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    loadContact(ps);
}

void CheckCapacity(struct Contact*ps)//检查并增容
{
    if (ps->capacity <= ps->size){
        //printf("内存已满\n");
    }
    else{
        return;
    }
    struct PeopleInformation* ptr = (struct PeopleInformation*)realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeopleInformation));
    if (ptr != NULL){             //扩容成功后再执行下一步
        ps->data = ptr;
        ps->capacity += 2;
        printf("增容成功\n");
    }
    else{
        perror("增容失败");
        return;
    }
}

//添加数据，在size后面
void Add(struct Contact * ps)
{
    CheckCapacity(ps);//值传递，地址传过去了，不是NULL，问题不大
        printf("请输入姓名>:"); 
        scanf("%s", ps->data[ps->size].name);
        printf("请输入性别>:"); 
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入年龄>:"); 
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入号码>:"); 
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址>:"); 
        scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功\n");
}

static int Find(const struct Contact *ps)//静态变量，限制在当前文件中使用，隐藏于此文件而不被外界发现
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

void Del(struct Contact *ps)
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
        //printf("存在该数据,是否删除（Y\N）\n");
        //printf("%-20s\t%-10s\t%-5d\t%-20s\t%-30s\n", ps->data[i].name, ps->data[i].sex, ps->data[i].age, ps->data[i].tele, ps->data[i].addr);
        //scanf()
        int i = 0;
        for (i ; i < ps->size - 1; i++)
        {
            ps->data[i] = ps->data[i++];
        }
        ps->size--;//数据少一个，大小减一
        printf("删除成功");
    }
}

void Show(const struct Contact *ps)
{
    if (ps->size == 0)
        printf("无数据\n");
    else
    {
        printf("NO:     %-10s\t%-5s\t%-5s\t%-20s\t%-30s\n", 
            "name",
            "sex",
            "age", 
            "tele", 
            "addr");
        for (int i = 0; i < ps->size; i++)
        {
            printf("NO.%-d\t%-10s\t%-5s\t%-5d\t%-20s\t%-30s\n",
                i+1,
                ps->data[i].name,
                ps->data[i].sex,
                ps->data[i].age, 
                ps->data[i].tele,
                ps->data[i].addr);
        }
    }
}

void Search(const struct Contact *ps)
{
    printf("请输入查找的对象>:\n");

    int i = Find(ps);
    if (i == -1)
    {
        printf("数据不存在\n");
    }
    else
    {
        printf("NO.%-d\t%-20s\t%-10s\t%-5d\t%-20s\t%-30s\n",
            i+1,
            ps->data[i].name,
            ps->data[i].sex, 
            ps->data[i].age, 
            ps->data[i].tele, 
            ps->data[i].addr);
    }
}

void Mod(struct Contact *ps)
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
        printf("请输入性别>:"); scanf("%s", ps->data[i-1].sex);
        printf("请输入年龄>:"); scanf("%d", &ps->data[i-1].age);
        printf("请输入号码>:"); scanf("%s", ps->data[i-1].tele);
        printf("请输入地址>:"); scanf("%s", ps->data[i-1].addr);
        printf("修改成功\n");
    }
}

void Destroy(struct Contact *ps)
{
    free(ps->data);
    ps->data = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void Save(struct Contact *ps)
{
    int i = 0;
    FILE*pf = fopen("Contact.txt", "w");
    if (pf == NULL)
    {
        perror("打开文件失败");
        return;
    }
    for ( i = 0; i < ps->size; i++)
    {
        fwrite(ps->data + i, sizeof(struct PeopleInformation), 1, pf);
    }
    fclose(pf);
    pf = NULL;
    printf("文件保存成功\n");
}