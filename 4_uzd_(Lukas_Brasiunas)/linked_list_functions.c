// A file containing all of the functions for manipulating linked lists

#include <stdio.h>
#include <stdlib.h>

#include "linked_lists.h"

// Function for validating integer input
void numberValidation(int *n)
{
    // Running a cycle until valid info is entered
    while(1)
    {
        // Assigning temporary data
        *n = -1;
        char c = 'c';

        // Checking if input is valid
        if(scanf("%d%c", n, &c) == 2 && (c == '\n' || c == ' '))
            break;
        // If input is not valid, discarding useless information
        else
        {
            printf("Wrong input!\n");
            while(!isspace(getchar()))
                ;
        }
    }
}

// This function prints out elements of he linked list starting from the given node
void printList(struct Node* node)
{
    // Checking if a linked list does not exist
    if(node == NULL)
    {
        printf("There is nothing to print out because a linked list does not yet exist!\n\n");
        return;
    }
    printf("Printing out list items:\n");
    // Running a cycle until the last node of the linked list
    while(node != NULL)
    {
        printf(" %d ", node->value);
        // Moving the current position to the next node
        node = node->next;
    }
    printf("\n\n");
}

// Function for getting the size of the list from the given node
int getListSize(struct Node* node)
{
    int size;
    // Checking if a linked list does not exist
    if(node == NULL)
    {
        printf("A linked list does not yet exist or is empty!\n");
        return 0;
    }
    // Running a cycle until the last element of the list and tracking the list size
    for(size = 0; node != NULL; ++size)
        node = node->next;
    return size;
}

// This function is responsible for creating a linked list with a size of (amount) from the given node
void createList(struct Node** head, int amount)
{
    // A temporary integer variable for storing the first data value of the first node
    int tempNumber;
    // Allocating memory to the node
    *head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the integer of node 1:\n");
    // Validating the data value input
    numberValidation(&tempNumber);
    // Assigning required information to the first node
    (*head)->value = tempNumber;
    (*head)->key = 1;
    (*head)->next = NULL;

    // A couple of new Node* variables
    struct Node* newNode = NULL, *temp;
    // Assigning the first node data to a new temporary
    //  Node* variable without altering the first node data
    temp = *head;
    // Running a cycle responsible for acquiring the data for the other new nodes
    for(int i = 2; i <= amount; ++i)
    {
        // Allocating memory to a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        // Checking if the memory allocation was unsuccessful
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.\n");
            break;
        }

        // Entering the data
        printf("Enter the integer of node %d:\n", i);
        numberValidation(&tempNumber);

        // Assigning data to the new node
        newNode->value = tempNumber;
        newNode->key = i;
        newNode->next = NULL;

        // Linking the previous node to the new node
        temp->next = newNode;
        // Assigning new node data to the temporary Node* variable
        temp = temp->next;
    }
    printf("List created successfully.\n\n");
}

// Searches for the lowest value in the linked list and returns it's location (index)
int findLowestValueInList(struct Node* head)
{
    // Checking if a linked list does not exist
    if(head == NULL)
        return;
    int number, index;
    struct Node *current = head;
    // Assigning some information from the given node
    number = current->value;
    index = current->key;
    current = current->next;

    // Running a cycle until the last node in the list
    while(current != NULL)
    {
        // Checking if the previous number value is higher to the current node value
        if(number > current->value)
        {
            // Saving the new lower number and it's index
            number = current->value;
            index = current->key;
        }
        current = current->next;
    }
    return index;
}

// A function for deleting (removing) the node with the given index (key)
void deleteGivenListNode(struct Node** head, int index)
{
    // Checking if a linked list does not exist
    if(*head == NULL)
    {
        printf("There is nothing to delete from because a linked list does not yet exist!\n\n");
        return;
    }
    else
    {
        struct Node *current = *head;
        struct Node *previous = NULL;
        // Running a cycle until it finds the specified index (key)
        while(current->key != index)
        {
            // Checking if the specified node does not exist
            if(current->next == NULL)
            {
                printf("Given node is not found!\n");
                return;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        // Checking whether the specified node is the first one in the list
        if(current == *head)
            *head = (*head)->next;
        // Checking if the cycle found the node with the given index (key)
        if(current->key == index && previous != NULL)
            previous->next = current->next;
    }
    printf("Successfully deleted a node from the list.\n\n");
}
