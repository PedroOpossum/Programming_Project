#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Host.h"

void User_Menu();

void Dropout();

void List_Menu();
void Ticket_Generator() ;



void User_Menu()
{
    
    int main_menu_choose = 0;
    while(1)
    {
        printf("\n\tUser Menu\n");
        printf("----------------------------------");
        printf("\n1. Apply for a game");
        printf("\n2. Drop-out");
        printf("\n3. Go back\n");
        printf("-----------------------------------");
        printf("\nPlease enter a number ");
        scanf("%d", &main_menu_choose);
        switch(main_menu_choose) 
        {
            case 1:
                List_Menu();           
                break;
            case 2:
                Dropout();
                break;
            case 3: 
                return;
            default:
                printf("\nInvalid Option\n");
        } 
    }  
}



void List_Menu()
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


void Ticket_Generator()
{

    
    srand(time(0));
    for (int i = 0; i<20; i++)
    {
        int random_number = rand()%9+1;
        printf("%d", random_number);
    }
}



void Dropout()
{



}

