
#include"Book.h"



void menu()
{
    printf("*******************************************************************************************\n");
    printf("*****************************  1.Add                2.Del    ******************************\n");
    printf("*****************************  3.Search             4.Mod    ******************************\n");
    printf("*****************************  5.Sort               6.Show   ******************************\n");
    printf("*****************************  7.Save               0.exit   ******************************\n");
    printf("*******************************************************************************************\n");
}




int main()
{
    struct Book book;
    Initialization(&book); 
    int input = 1;
    while (input)
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case EXIT:
            Destroy(&book);
            //Save(&book);
            break;  
        case ADD:Add(&book); break;
        case DEL:Del(&book); break;
        case SEARCH:Search(&book); break;
        case MOD:Mod(&book); break;
		case SORT:sort(&book); break;
        case SHOW:Show(&book); break;
        case SAVE:Save(&book); break;
        default:
            printf("输入有误，请重新输入\n");
            continue;
        }
		system("cls");
    }
    return 0;
}