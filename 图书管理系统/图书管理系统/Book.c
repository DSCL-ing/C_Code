#define _CRT_SECURE_NO_WARNINGS 1

#include"Book.h"



void loadBook(struct Book*ps)//�����ļ���¼
{
    int i = 0;
    FILE*pf = fopen("Book.txt", "r");
    if (pf == NULL){
        perror("�ļ������ڣ���ʼ��");
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

//��ʼ��
void Initialization(struct Book *ps)
{
    ps->data = (struct BookInfo*)malloc(DEFAULT_SZ*sizeof(struct BookInfo));
    if (ps->data == NULL){
        perror("��ʼ������ʧ��");
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    loadBook(ps);
}

void CheckCapacity(struct Book*ps)//���yu����
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
        printf("���ݳɹ�\n");
    }
    else{
        perror("����ʧ��");
        return;
    }
}

//���
void Add(struct Book * ps)
{
    CheckCapacity(ps);
        printf("����������>:"); 
        scanf("%s", ps->data[ps->size].name);
        printf("������ISBN>:"); 
        scanf("%s", ps->data[ps->size].ISBN);
        printf("������۸�>:"); 
        scanf("%s", ps->data[ps->size].price);

    ps->size++;
    printf("��ӳɹ�\n");
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
    printf("��������>:");
    scanf("%d", &i);
    i -= 1;
    if (i < 0 || i > ps->size)
    {
        printf("��������\n");
    }
    else
    {
        for (i ; i < ps->size - 1; i++)
        {
            ps->data[i] = ps->data[i+1];
        }
        ps->size--;
        printf("ɾ���ɹ�\n");
    }
}

void Show(struct Book *ps)
{
    if (ps->size == 0)
        printf("������\n");
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
    printf("��������ҵ�����>:\n");

    int i = Find(ps);
    if (i == -1)
    {
        printf("���ݲ�����\n");
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
    printf("��������>:");
    scanf("%d", &i);
    if (i < 0 && i >= ps->size)
    {
        printf("���ݲ�����\n");
    }
    else
    {
        printf("����������>:"); scanf("%s", ps->data[i-1].name);
        printf("������ISBN>:"); scanf("%s", ps->data[i-1].ISBN);
        printf("������۸�>:"); scanf("%s", ps->data[i-1].price);

        printf("�޸ĳɹ�\n");
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
        perror("���ļ�ʧ��");
        return;
    }
    for ( i = 0; i < ps->size; i++)
    {
        fwrite(ps->data + i, sizeof(struct BookInfo), 1, pf);
    }
    fclose(pf);
    pf = NULL;
    printf("�ļ�����ɹ�\n");
}