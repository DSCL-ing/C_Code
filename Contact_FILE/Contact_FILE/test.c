
#include"Contact.h"



void menu()
{
    printf("*******************************************************************************************\n");
    printf("*****************************  1.Add                2.Del    ******************************\n");
    printf("*****************************  3.Search             4.Mod    ******************************\n");
    printf("*****************************  5.Show               6.Save   ******************************\n");
    printf("*****************************  0.exit               0.exit   ******************************\n");
    printf("*******************************************************************************************\n");
}




int main()
{
    struct Contact con;//size:当前大小，capacity:容量，data:成员数组
    Initialization(&con); 
    int input = 1;
    while (input)
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            Destroy(&con);//释放，销毁空间
            //Save(&con);
            break;  //跳出后循环条件刚好为假
        case ADD:Add(&con); break;
        case DEL:Del(&con); break;
        case SEARCH:Search(&con); break;
        case MOD:Mod(&con); break;
        case SHOW:Show(&con); break;
        case SAVE:Save(&con); break;
        default:
            printf("输入有误，请重新输入\n");
            continue;
        }
    }
    return 0;
}