#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Host.h"

void User_Menu();
void Dropout();
void List_Menu();
void Final_Confirmation(int list_choice);
void Read_Rules(int list_choice);
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


void Dropout()
{
    char input_id[50];
    printf("Enter your ID to drop out: ");
    scanf(" %[^\n]", input_id);

    FILE *file = fopen("ID.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        printf("Error opening files.\n");
        return;
    }


    char file_id[50];
    char game_name[100];
    int found = 0;

    while (fscanf(file, "%s | %[^\n]\n", file_id, game_name) == 2)
    {
        if (strcmp(file_id, input_id) != 0)
        {
            fprintf(temp, "%s | %s\n", file_id, game_name);
        }
        else
        {  
            found = 1;
        }
    }
    fclose(file);
    fclose(temp); 
    remove("ID.txt");
    rename("temp.txt", "ID.txt");
    if (found)
        printf("You have successfully dropped out.\n");
    else
        printf("ID not found.\n");
}


void List_Menu()
{ 
   
    int list_choice = 0;
    if(current_tournament == 0)
    {
        printf("\n\nThere are no tournaments at the current moment\n\n");
        return;
    }

    while(1)
    {
        printf("\nPlease select which one you want to apply to from the list: \n\n");
        for (int i = 0; i<current_tournament; i++)
        {
            printf("%d. %s\t Prize: %.2f\t%d/%d \n", i+1, gt[i].VideoGame, gt[i].Pool_Prize, gt[i].NumOfPeople, gt[i].totalNumOfPeople);
        }

        printf("\n\nEnter Number: ");
        scanf("%d", &list_choice);
        if(list_choice<=MAX_TOURNAMENTS||list_choice>0)
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
               Read_Rules(list_choice);
               break;
           case 2:
               printf("\nDate: %s || Time: %s || Place: %s\n\n", gt[list_choice].Date, gt[list_choice].Time, gt[list_choice].Place);
               break;
           case 3:
               Ticket_Generator(list_choice);
               printf("Your Ticket has been generated.\n");
               break;
           case 4:
               return;
           default:
           printf("\nSorry. The number given does not exist!\n\n");
       }
   }
}


void Read_Rules(int list_choice) {
    FILE *rulesFile = fopen(gt[list_choice].Rule_Selection, "r");
    if (rulesFile == NULL) {
        printf("Error: Could not open rules file!\n");
        return;
    }


    // Print the rules of the selected tournament
    printf("\nTournament Rules for %s:\n", gt[list_choice].VideoGame);
    char ch;
    while ((ch = fgetc(rulesFile)) != EOF) {
        putchar(ch); // Print each character
    }


    fclose(rulesFile); // Close the file after printing
}


int Ticket_Generator(int list_choice)
{
   FILE* Ticket = fopen("Ticket.txt", "a+");
   FILE* ID_File = fopen("ID.txt", "a+");
   if (Ticket == NULL)
   {
       printf("The File does not Exist!\n");
       exit(0);
   }
  
   if (ID_File == NULL)
   {
       printf("The File does not Exist!\n");
       exit(0);
   }
    /* Prints to first File*/
   fprintf(Ticket,"\t\tGame Tournament\n");
   fprintf(Ticket,"-------------------------------\n");
   fprintf(Ticket,"Name: %s\n", gt[list_choice].VideoGame);
   fprintf(Ticket,"Time: %s\n", gt[list_choice].Time);
   fprintf(Ticket,"Date: %s\n", gt[list_choice].Date);
   fprintf(Ticket,"Place: %s\n", gt[list_choice].Place);
   fprintf(Ticket,"-------------------------------\n");

   srand(time(0));
   fprintf(Ticket,"ID:");
    /*Prints Random Number ID to both files. One for ID and one for Ticket.*/

    for (int j = 0; j < 20; j++)
    {
        int random_number = rand()%9+1;
        fprintf(Ticket, "%d", random_number);
        fprintf(ID_File, "%d", random_number);
    }
  
    fprintf(ID_File, " | %s\n", gt[list_choice].VideoGame);
    fclose(ID_File);
    fprintf(Ticket,"\n-------------------------------\n");
    fclose(Ticket);
   
   if(gt[list_choice].NumOfPeople < gt[list_choice].totalNumOfPeople)
   {
    return gt[list_choice].NumOfPeople +=1;
   }

   printf("\n\nCannot apply, reached max amounts of players\n\n");
   return 0;



}

