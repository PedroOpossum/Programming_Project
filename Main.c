#include <stdio.h>
#include <stdlib.h>
#include "Host.h"

// Function prototypes
void Host_Menu();
void User_Menu();

int main(void) 
{
    int choice;
    
    do { 
        printf("\n\tVideo Game Tournament\n");
        printf("----------------------------------\n");
        printf("1. Host Menu\n");
        printf("2. User Menu\n");
        printf("3. Exit\n");
        printf("----------------------------------\n");
        printf("Please enter a number: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                Host_Menu();  // Call the host menu
                break;
            case 2:
                User_Menu();  // Call the user menu
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }
    } while(choice != 3);

    return 0;
}