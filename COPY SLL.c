#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to copy a linked list
struct Node* copyLinkedList(struct Node* head) {
    if (head == NULL) {
        return NULL; // Return NULL for an empty list
    }

    // Create the head node of the new list
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->data = head->data;
    newHead->next = NULL;

    // Traverse the original list and copy nodes
    struct Node* current = head->next;
    struct Node* newCurrent = newHead;

    while (current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;
        newCurrent->next = newNode;

        current = current->next;
        newCurrent = newCurrent->next;
    }

    return newHead;
}

int main() {
    // Create and allocate nodes for the original list
    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the original list
    head->data = 10; head->next = second;
    second->data = 20; second->next = third;
    third->data = 30; third->next = fourth;
    fourth->data = 40; fourth->next = fifth;
    fifth->data = 50; fifth->next = NULL;

    // Print the original linked list
    printf("Original Linked List:\n");
    linkedListTraversal(head);

    // Copy the linked list
    struct Node* copiedHead = copyLinkedList(head);

    // Print the copied linked list
    printf("\nCopied Linked List:\n");
    linkedListTraversal(copiedHead);

    return 0;
}
