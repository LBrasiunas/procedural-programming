// A file for testing the functions in "linked_lists.h"

#include <assert.h>
#include "linked_list_functions.c"

// Function
void testingFunctions(struct Node* node);

int main()
{
    printf("This is the testing program for the linked list functions.\nPlease enter the "
           "following data: (1 7 4) or (1 2 5) in order for the testing program to work.\n");
    struct Node* head = NULL;
    // Checking if assignment was successful
    assert(head == NULL);
    // Calling the create list function to create a linked list consisting of 3
    createList(&head, 3);
    printf("Testing the list size, delete given node and find lowest value index functions...\n");
    // Calling the function for testing other functions
    testingFunctions(head);
    printf("Everything is OK.\n");
    return 0;
}

// A function for testing the other functions
void testingFunctions(struct Node* node)
{
    // The tests
    assert(getListSize(node) == 3);
    assert(findLowestValueInList(node) == 1);
    deleteGivenListNode(&node, 3);
    assert(node->key == 1 && node->next->key == 2);
    assert(findLowestValueInList(node) == 1);
    assert(getListSize(node) == 2);
    deleteGivenListNode(&node, 2);
    assert(node->key == 1);
    assert(findLowestValueInList(node) == 1);
    assert(getListSize(node) == 1);
    deleteGivenListNode(&node, 1);
    assert(getListSize(node) == 0);
}
