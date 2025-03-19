#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Host.h"
#define MAX_TOURNAMENTS 10


struct Game_Tournament
{
    float Pool_Prize;
    int Num_Of_People;
    char Place[500], Time[10], Date[15];
    char Rule_Selection[500];
    char VideoGame[500];
    
} gt[MAX_TOURNAMENTS];

int current_tournament = 0;
int checkmark[4], checkmark_functions;

int Upload_Rules()
{
    FILE *Rules = NULL;
    printf("\nChoose a file: ");
    scanf("%s", gt[current_tournament].Rule_Selection);
    Rules = fopen(gt[current_tournament].Rule_Selection, "r");
    if (Rules == NULL) 
    {
        printf("\nFile could not be found, please try again.\n");
        return 0;
    }  
    else 
    {
        printf("File opened successfully!\n");
    }

    fclose(Rules);
    return checkmark[0]=1;
}

int Video_Game_Name()
{
    getchar();
    printf("\nInput Game Name: ");
    fgets(gt[current_tournament].VideoGame, sizeof(gt[current_tournament].VideoGame), stdin);
    return checkmark[1]=1;
}

int Time_and_Place()
{   
    getchar();
    printf("\nEnter the date M/D/Y: ");
    fgets(gt[current_tournament].Date, sizeof(gt[current_tournament].Date),stdin);
    printf("\nEnter the time (AM or PM): ");
    fgets(gt[current_tournament].Time, sizeof(gt[current_tournament].Time),stdin);
    printf("\nEnter the location of the place: ");
    fgets(gt[current_tournament].Place, sizeof(gt[current_tournament].Place),stdin);
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
    scanf("%d", &gt[current_tournament].Num_Of_People);
    return checkmark[4]=1;
    
}

int Publish()
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
            printf("Rules: %s", gt[i].Rule_Selection);
            printf("\nDate: %s", gt[i].Date);
            printf("Time: %s", gt[i].Time);
            printf("Place: %s", gt[i].Place);
            printf("Pool Prize: %.2f", gt[i].Pool_Prize);
            printf("\nNumber of People: %d\n\n", gt[i].Num_Of_People);
        }

        printf("Would you like to host another tournament? (Y/N)\n");
        getchar();
        scanf("%c",&answer);
        answer = tolower(answer);
        if (answer == 'y' && current_tournament <= MAX_TOURNAMENTS)
        {
            return current_tournament++;
        }
        else
        {
            return 0;
        }
}

void Create_Tourtament()
{   
    int game_tourtament_choice;
    do{
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
                for (int i = 0; i <= 4; i++) //This makes sure that all the functions have been processed before going into the function Publish otherwise redirect user to the beggining
                {
                    if(checkmark[i] == 1)
                    {
                        checkmark_functions++;
                    }
                }
                if(checkmark_functions==5)
                {
                    Publish();
                    break;
                }
                printf("\nDidn't complete steps 1-5");
                break;
            case 7:
                main();
                break;
            default:
                printf("\nInvalid Option\n");
            
        }
    } while(game_tourtament_choice!=7);
}


int main(void)
{
    int main_menu_choice = 0;

    do
    {
        printf("\n1. Create a tourtament");
        printf("\n2. Exit\n");
        printf("\nPlease enter a number ");
    scanf("%d", &main_menu_choice);
        switch(main_menu_choice) 
        {
            case 1:
                Create_Tourtament();
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("\n Invalid Option \n");

        }
      }  while(main_menu_choice!=2);

}
