#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Host.h"

void User_Menu();
void Dropout();
void List_Menu();
void Final_Confirmation(int list_choice);
int Ticket_Generator(int list_choice);


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
    while(1)
    {
        int list_choice = 0;
        printf("\nPlease select which one you want to apply to from the list: \n\n");
        for (int i = 0; i<=current_tournament; i++)
        {
            printf("%d. %s\t Prize: %.2f\t%d/%d \n", i+1, gt[i].VideoGame, gt[i].Pool_Prize, gt[i].NumOfPeople, gt[i].totalNumOfPeople);
        }

        printf("\n\nEnter Number: ");
        scanf("%d", &list_choice);
        if(list_choice<MAX_TOURNAMENTS||list_choice>0)
        {
            list_choice-=1; //minus 1 to point to the correct list
            Final_Confirmation(list_choice);
            return;
        }
        printf("Not in the list");
    }
 
}



void Final_Confirmation(int list_choice)
{
    while(1)
    {
        int usernum = 0; 
        printf("\n1. View Rules\n");
        printf("2. View Date, Time, Place\n");
        printf("3. Apply Option\n");
        printf("4. Back\n\n");

        printf("Please enter number: ");
        scanf("%d", &usernum);
        
        switch(usernum)
        {
            case 1:

                break;
            case 2:
                printf("\nDate: %s Time: %s Place: %s\n\n", gt[list_choice].Date, gt[list_choice].Time, gt[list_choice].Place); 
                break;
            case 3:
                Ticket_Generator(list_choice);
                return;
            case 4:
                return;
            default:
            printf("\nSorry. The number given does not exist!\n\n");


        }
    }
}



int Ticket_Generator(int list_choice)
{

    
    srand(time(0));
    for (int i = 0; i<20; i++)
    {
        int random_number = rand()%9+1;
        printf("%d", random_number);
    }
    return gt[list_choice].NumOfPeople +=1;
}



void Dropout()
{



}

