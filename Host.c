#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Host.h"
#define MAX_TOURNAMENTS 10


struct Game_Tournament gt[MAX_TOURNAMENTS];


int current_tournament = 0;
int checkmark[5], checkmark_functions;


void Create_Tournament();
int Upload_Rules();
int Video_Game_Name();
int Time_and_Place();
int Pool_Prize_Money();
int Number_of_People();
void Publish();
void View_Tickets();


void Host_Menu()
{
   int main_menu_choice = 0;   
   while(1)
   {
     
       printf("\n\tHost Menu\n");
       printf("----------------------------------\n");
       printf("1. Create a tournament\n");
       printf("2. View Ticket\n");
       printf("3. Go back\n");
       printf("----------------------------------\n");
       printf("Please enter a number ");
       scanf("%d", &main_menu_choice);
       switch(main_menu_choice)
       {
           case 1:
               Create_Tournament();
               break;
           case 2:
               View_Tickets();
               break;
           case 3:
               return;
           default:
               printf("\n Invalid Option \n");
       }
   }




}



void View_Tickets()
{
   int choice;

   printf("Please type in which game tournament you want to view from the list: \n\n");
   for(int i=0; i<current_tournament; i++)
   { 
       printf("%d. %s\n", i+1, gt[i].VideoGame);
   }
   printf("\n");
   printf("Select the number you want to view: ");
   scanf("%d", &choice);
   FILE *ID_File = fopen("ID.txt", "r");
   if (ID_File == NULL)
   {
       printf("Error: Could not open rules file!\n");
       return;
   }

   // Print the rules of the selected tournament
   char ID[50] = {};
   char game_name[100] = {};
   
   printf("\n\tPlayer List for %s\n", gt[choice-1].VideoGame);
   printf("----------------------------------\n");
   while (fscanf(ID_File, "%s | %[^\n]\n", ID, game_name) == 2)
   {
       if (strcmp(game_name, gt[choice-1].VideoGame) == 0)
       {
           printf("%s\n", ID);
       }
   }
   fclose(ID_File); // Close the file after printing
}


void Create_Tournament()
{ 
   int game_tourtament_choice;
   while(1)
   {
       printf("\n\n1. Upload Rules\n");
       printf("2. Video Game Name\n");
       printf("3. Time and Place\n");
       printf("4. The Pool Prize Amount\n");
       printf("5. Number of People\n");
       printf("6. Publish\n");
       printf("7. Go Back\n\n");
 




       printf("Please enter number: ");
       scanf("%d", &game_tourtament_choice);
       switch(game_tourtament_choice)
       {
           case 1:
               Upload_Rules();
               break;
           case 2:
               Video_Game_Name();
               break;
           case 3:
               Time_and_Place();
               break;
           case 4:
               Pool_Prize_Money();
               break;
           case 5:
               Number_of_People();
               break;
           case 6:
               checkmark_functions = 0; 
               for (int i = 0; i <= 4; i++) //This makes sure that all the functions have been processed before going into the function Publish otherwise redirect user to the begining
               {
                   if(checkmark[i])
                   {
                       checkmark_functions++;
                   }
                   else
                   {
                       printf("\nDidn't complete step %d", i+1);
                   }
               }
               if(checkmark_functions==5)
               {
                   Publish();
                   break;
               }
               break;
           case 7:
               return;
           default:
               printf("\nInvalid Option\n");
         
       }
   }
}




int Upload_Rules()
{
   FILE *Rules = NULL;
   printf("\nChoose a file: ");
   scanf("%s", gt[current_tournament].Rule_Selection);
   gt[current_tournament].Rule_Selection[strcspn(gt[current_tournament].Rule_Selection, "\n")] = 0;
   Rules = fopen(gt[current_tournament].Rule_Selection, "r");
   if (Rules == NULL)
   {
       printf("\nFile could not be found, please try again.\n");
       return 0;
   } 

   printf("File opened successfully!\n");
   fclose(Rules);
   return checkmark[0]=1;
}




int Video_Game_Name()
{
   getchar();
   printf("\nInput Game Name: ");
   fgets(gt[current_tournament].VideoGame, sizeof(gt[current_tournament].VideoGame), stdin);
   gt[current_tournament].VideoGame[strcspn(gt[current_tournament].VideoGame, "\n")] = 0;
   return checkmark[1]=1;
}




int Time_and_Place()
{ 
  int mm, dd, yyyy;
  char date_input[11];
  getchar();

  while(1)
  {
      printf("\nEnter the date MM/DD/YYYY: ");
      fgets(date_input, sizeof(date_input),stdin);
      date_input[strcspn(date_input, "\n")] = 0;
      if (sscanf(date_input, "%2d/%2d/%4d", &mm, &dd, &yyyy) == 3 && mm >= 1 && mm <= 12 && dd >= 1 && dd <= 31 && yyyy >= 1900 && yyyy <= 2100)
      {
          strcpy(gt[current_tournament].Date, date_input); /*This validates the input before it is put into the structure.*/
          break;
      }
      else
      {
          printf("Invalid format. Please use MM/DD/YYYY.\n");
      }
  }


  char time_input[10], am_pm[3];
  int hour, min;
  getchar();

  while(1)
  {
      printf("\nEnter the time HH:MM (AM or PM): ");
      fgets(time_input, sizeof(time_input),stdin);
      time_input[strcspn(time_input, "\n")] = 0;

      if (sscanf(time_input, "%2d:%2d %2s", &hour, &min, am_pm) == 3 && hour >= 1 && hour <= 12 && min >= 0 && min <= 59 &&
          (strcasecmp(am_pm, "AM") == 0 || strcasecmp(am_pm, "PM") == 0))
      {
          strcpy(gt[current_tournament].Time, time_input); /*This vlidates the input before it is put into the structure.*/
          break;
      }
      else
      {
          printf("Invalid format. Please use (HH:MM AM/PM).\n");
      }
  } 
   printf("\nEnter the location of the place: ");
   fgets(gt[current_tournament].Place, sizeof(gt[current_tournament].Place),stdin);
   gt[current_tournament].Place[strcspn(gt[current_tournament].Place, "\n")] = 0;
 
  return checkmark[2]=1;

}



int Pool_Prize_Money()
{
 
   printf("\nEnter the Pool Prize: ");
   scanf("%f", &gt[current_tournament].Pool_Prize);
   return checkmark[3]=1;
 
}




int Number_of_People()
{
   printf("\nEnter the max amount of people that can join: ");
   scanf("%d", &gt[current_tournament].totalNumOfPeople);
   return checkmark[4]=1;
 
}



void Publish()
{
       char answer;
       for(int i = 0; i <=4; i++)
       {
           checkmark[i] = 0;
       }
       printf("\nPublishing Tournament:\n");


       for(int i = 0; i <= current_tournament; i++)
       {
           printf("Tournament #%d\n", i+1);
           printf("\nGame Name: %s", gt[i].VideoGame);
           printf("\nRules: %s", gt[i].Rule_Selection);
           printf("\nDate: %s", gt[i].Date);
           printf("\nTime: %s", gt[i].Time);
           printf("\nPlace: %s", gt[i].Place);
           printf("\nPool Prize: %.2f", gt[i].Pool_Prize);
           printf("\nNumber of People: %d\n\n", gt[i].totalNumOfPeople);
       }


       printf("Would you like to host another tournament? (Y/N)\n");
       getchar();
       scanf("%c",&answer);
       answer = tolower(answer);
       current_tournament++;
       if (answer == 'y' && current_tournament <= MAX_TOURNAMENTS)
       {
           return;
       }
       else
       {
           Main_Menu();
       }
}
