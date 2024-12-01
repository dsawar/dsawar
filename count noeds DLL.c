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
    int count = 0;
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
        count++;
    }
    printf("no of element: %d\n", count);
}

int main() {
    struct Node *head, *second, *third, *fourth, *fifth;

    // Allocate memory for five nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    // Initialize and link the first node
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    // Initialize and link the second node
    second->data = 20;
    second->prev = head;
    second->next = third;

    // Initialize and link the third node
    third->data = 30;
    third->prev = second;
    third->next = fourth;

    // Initialize and link the fourth node
    fourth->data = 40;
    fourth->prev = third;
    fourth->next = fifth;

    // Initialize and terminate the fifth node
    fifth->data = 50;
    fifth->prev = fourth;
    fifth->next = NULL;

    // Display the doubly linked list
    linkedListTraversal(head);

    // Count and display the number of nodes

    return 0;
}
