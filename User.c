#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Host.h"


void Ticket_Generator() 
{

    
    srand(time(0));
    for (int i = 0; i<20; i++)
    {
        int random_number = rand()%9+1;
        printf("%d", random_number);
    }
}
void Apply()
{
    int apply_option = 0;
    printf("\nPlease select which one you want to apply to from the list: ");
    scanf("%d", &apply_option);
    switch(apply_option)
    {

        default:
            printf("\nNot on the list, please try again\n\n");

    }

}

void Dropout()
{



}


void User_Menu()
{
    printf("\n\tUser Menu\n");
    printf("----------------------------------");
    printf("\n1. Apply for a game");
    printf("\n2. Drop-out");
    printf("\n3. Go back\n");
    printf("-----------------------------------\n");
    int main_menu_choose = 0;
    do
    {
        printf("Please enter a number ");
        scanf("%d", &main_menu_choose);
        switch(main_menu_choose) 
        {
            case 1:
                Apply();           
                break;
            case 2:
                Dropout();
                break;
            case 3: 
                return;
            default:
                printf("\nInvalid Option\n");
        } 
    }   while (main_menu_choose!=3);
}

