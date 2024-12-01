#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to count the number of nodes in the linked list


int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;
    
    // Link second and third nodes
    second->data = 11;
    second->next = third;
    
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    
    // Link fourth and fifth nodes
    fourth->data = 66;
    fourth->next = fifth;
    
    // Terminate the list at the fifth node
    fifth->data = 22;
    fifth->next = NULL;

    // Print the original list
    printf("Original List:\n");
    linkedListTraversal(head);

    // Count the number of nodes in the linked list
    int count = 0;
    struct Node* current = head;

    // Traverse through the linked list and count the nodes
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    printf("\nTotal number of nodes: %d\n", count);


    return 0;
}
