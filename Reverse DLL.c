#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to traverse and print the doubly linked list
void linkedListTraversal(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List (Forward):\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the doubly linked list in reverse order
void linkedListReverseTraversal(struct Node* head) {
    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Doubly Linked List (Reverse):\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    // Print the original list
    linkedListTraversal(head);

    // Print the list in reverse order
    linkedListReverseTraversal(head);

    return 0;
}
