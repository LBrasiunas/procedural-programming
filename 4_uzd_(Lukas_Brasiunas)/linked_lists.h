#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct Node
{
    // Data variable
    int value;
    // Node index variable
    int key;
    // Pointer to the next node
    struct Node *next;
};

// Functions
void numberValidation(int *n);
void printList(struct Node* node);
int getListSize(struct Node* node);
void createList(struct Node** head, int amount);
int findLowestValueInList(struct Node* head);
void deleteGivenListNode(struct Node** head, int index);
