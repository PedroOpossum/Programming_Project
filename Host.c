#include <stdio.h>
#include <stdlib.h>


    float Pool_Prize;
    int Num_Of_People;
    char Place[1000], Time[10], Date[15];
    char Rule_Selection[1000];
    char VideoGame[1000];
    int checkmark[4], checkmark_all_functions;



int Upload_Rules()
{
    FILE *Rules = NULL;
    printf("\nChoose a file: ");
    scanf("%s", Rule_Selection);
    Rules = fopen(Rule_Selection, "r");
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
    return checkmark[1]=1;
}

int Video_Game_Name()
{
    printf("\nInput Game Name: ");
    getchar();
    fgets(VideoGame, sizeof(VideoGame), stdin);
    return checkmark[2]=1;
}

int Time_and_Place()
{
    printf("\nEnter the date M/D/Y: ");
    getchar();
    fgets(Date, sizeof(Date),stdin);
    printf("\nEnter the time (AM or PM): ");
    fgets(Time, sizeof(Time),stdin);
    printf("\nEnter the location of the place: ");
    fgets(Place, sizeof(Place),stdin);
    return checkmark[3]=1;
}


int Pool_Prize_Money()
{
    printf("\nEnter the Pool Prize: ");
    scanf("%f", &Pool_Prize);
    return checkmark[4]=1;
    
}

int Number_of_People()
{
    printf("\nEnter the max amount of people that can join: ");
    scanf("%d", &Num_Of_People);
    return checkmark[5]=1;
    
}

void Publish(char *Rule_Selection, char *VideoGame, char *Place, char *Time, char *Date, float Pool_Prize, int Num_Of_People)
{



}

void Create_Tourtament()
{   
    int game_tourtament_choice = 0;
    tourtament:
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
            goto tourtament;
            break;
        case 2:
            Video_Game_Name();
            goto tourtament;
            break;
        case 3:
            Time_and_Place();
            goto tourtament;
            break;
        case 4:
            Pool_Prize_Money();
            goto tourtament;
            break;
        case 5:
            Number_of_People();
            goto tourtament;
            break;     
        case 6:
            for (int i = 1; i <= 5; i++) //This makes sure that all the functions have been processed before going into the function Publish otherwise redirect user to the beggining
            {
                if(checkmark[i])
                {
                    checkmark_all_functions++;
                }
            }

            if(checkmark_all_functions==5)
            {
                Publish(Rule_Selection,VideoGame,Date,Time,Place,Pool_Prize,Num_Of_People);
            }
            else
            {
                printf("\nDidn't complete steps 1-5");
                goto tourtament;
            }

            break;
        case 7:
            main();
            break;
        default:
            printf("\nInvalid Option\n");
            goto tourtament;
        
    } 
  
}


int main(void)
{
    int main_menu_choice = 0;

    main_menu:
    printf("1. Create a tourtament\n");
    printf("2. Settings\n");
    printf("3. Exit\n");

    printf("Please enter a number ");
    scanf("%d", &main_menu_choice);
    switch(main_menu_choice) 
    {
        case 1:
            Create_Tourtament();
            break;

        case 2:
            
            break;
        case 3:
            exit(0);
        default:
            printf("\n Invalid Option \n");
            goto main_menu;

    }   


}

