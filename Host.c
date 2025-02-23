#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


float Pool_Prize;
int number_of_people;
int year, month, day, hour, minute; 
char Place[1000];
char Rule_Selection[1000];
char VideoGame[1000];

    
bool Upload_Rules()
{

    FILE *Rules = NULL;
    
    while (1) {
        printf("\nChoose a file: ");
        scanf("%s", Rule_Selection);
        Rules = fopen(Rule_Selection, "r");
        if (Rules == NULL) {
            printf("\nFile could not be found, please try again.\n");
        }  
        else 
        {
            printf("File opened successfully!\n");
            break;  
        }

    }
    return true;

    fclose(Rules);



}

bool Video_Game_Name()
{
    printf("\nInput Game Name: ");
    scanf("%s", VideoGame);
    return true;
}

bool Time_and_Place()
{
    printf("\nEnter the date M/D/Y: ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("\nEnter the time: ");
    scanf("%d:%d", &hour, &minute);
    printf("\nEnter the location of the place: ");
    scanf("%s", Place);
    return true;
}


bool Pool_Prize_Money()
{
    printf("\nEnter the Pool Prize: ");
    scanf("%f", &Pool_Prize);
    return true;
}

bool Number_of_People()
{
    printf("\nEnter the max amount of people that can join: ");
    scanf("%d", &number_of_people);
    return true;
}

void Publish()
{



}

void Create_Tourtament()
{   //
    int game_tourtament_choice = 0
    tournament:
    printf("\n\n1. Upload Rules\n");
    printf("2. Video Game Name\n");
    printf("3. Time and Place\n");
    printf("4. The Pool Prize Amount\n");
    printf("5. Number of People\n");
    printf("6. Publish\n");
    printf("7. Go Back\n\n");
 

    printf("Please enter number: ");
    scanf("%d", &game_tourtament_choice);
    
    /*switch(game_tourtament_choose)
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
        case 7:
            main();
            break;
        default:
            printf("\nInvalid Option\n");
            goto tourtament;
        
    } */
    if(Upload_Rules() && Video_Game_Name() && Time_and_Place() && Pool_Prize_Money() && Number_of_People() == true)
    {
        Publish();
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

