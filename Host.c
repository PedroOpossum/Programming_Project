#include <stdio.h>
#include <stdlib.h>

void upload_rules(Rules, Rule_Selection)
{

    printf("Choose a file: ");
    scanf("%s", Rule_Selection);

    Rules = fopen(Rule_Selection, "r");

    if (Rules == NULL)
    {
        printf("\n File could not be found, please try again\n");
    }

}

void Create_Tourtament()
{
    FILE *Rules = NULL;
    int Pool_Prize, game_tourtament_choose, number_of_people = 0;
    char Rule_Selection[1000], VideoGame[1000];
    
    
    tourtament:
    printf("\n\n\n1. Upload Rules\n");
    printf("2. Video Game Name\n");
    printf("3. Time and Place\n");
    printf("4. The Pool Prize Amount\n");
    printf("5. Number of People\n");
    printf("6. Publish\n");
    printf("7. Go Back\n\n");
 

    printf("Please enter number: ");
    scanf("%d", &game_tourtament_choose);

    switch(game_tourtament_choose)
    {
        case 1:
            upload_rules(Rules, Rule_Selection);
            
            break;
        case 2:

        
            break;
        case 3:

            break;
        case 4:

           
            break;
        case 5:

            break;
        case 6:
          
            printf("Not finished yet"); 
            break;
        case 7:
            
            break;
        default:
            printf("\nInvalid Option\n");
            goto tourtament;
    }
}



int main(void)
{
    int main_menu_choose = 0;

    main_menu:
    printf("1. Create a tourtament\n");
    printf("2. Settings\n");
    printf("3. Exit\n");

    printf("Please enter a number ");
    scanf("%d", &main_menu_choose);
    switch(main_menu_choose) 
    {
        case 1:
            Create_Tourtament();
            break;

        case 2:
            
            break;
        case 3:
          
            break;
        default:
            goto main_menu;

    }   


}

