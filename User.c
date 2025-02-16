#include <stdio.h>
#include <stdlib.h>


void Creating_Main_Menu_Screen()
{

    printf("\n\tVideo Game Tournament\n");

    printf("----------------------------------\n");
    int main_menu_choose = 0;
    main_menu:
    printf("1. Apply for a game\n");
    printf("2. Drop-out\n");
    printf("3. Exit\n");
    printf("-----------------------------------\n");

    printf("Please enter a number ");
    scanf("%d", &main_menu_choose);
    switch(main_menu_choose) 
    {
        case 1:
            
            break;

        case 2:
            
            break;
        case 3: 
            exit(0);
            break;
        default:
            goto main_menu;

    }   
}

int main(void)
{
    Creating_Main_Menu_Screen();
}

