// This program lets you create a linked list and delete the lowest value in it

#include "linked_list_functions.c"

// Functions
void printSelectionMenu();
int checkMenu();

int main()
{
    printf("This program lets you create a linked list and delete the lowest value in it.\n");
    struct Node *head = NULL;
    int amount;
    // An infinite cycle until the user enters 4
    while(1)
    {
        // Prints the user options on screen
        printSelectionMenu();
        // Gets the user selection(input) from screen
        int selection = checkMenu();
        if(selection == 1)
        {
            printf("Create a new linked list selected.\n\n");
            printf("Enter the amount of integers you want to enter to the list:\n");
            // Calling the number validation function
            numberValidation(&amount);
            // Calling the function which is responsible for creating the list
            createList(&head, amount);
        }
        if(selection == 2)
            printList(head);
        if(selection == 3)
            deleteGivenListNode(&head, findLowestValueInList(head));
    }
    return 0;
}

// A function which prints out the options on screen
void printSelectionMenu()
{
    printf("Please select one of the following actions:\n");
    printf("    1) Create a new linked list.\n");
    printf("    2) Print out all of the items in the list.\n");
    printf("    3) Remove the lowest value from the list.\n");
    printf("    4) Exit the program.\n");
}

// A function which returns the user selection (input)
int checkMenu()
{
    int menuNumber;
    // Running a cycle until the user inputs a valid number
    while(1)
    {
        numberValidation(&menuNumber);
        if(menuNumber > 0 && menuNumber < 4)
            break;
        else if(menuNumber == 4)
        {
            printf("Exiting the program...\n");
            exit(0);
        }
        printf("Wrong menu selection input entered. Try again.\n");
    }
    return menuNumber;
}
