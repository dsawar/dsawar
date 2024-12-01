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
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search an element in the doubly linked list
void searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not present in the list\n", key);
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

    // Print the list
    linkedListTraversal(head);

    // Search for an element
    searchElement(head, 20);
    searchElement(head, 40);

    return 0;
}
