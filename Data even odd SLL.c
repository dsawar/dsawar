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

// Function to count even and odd nodes in the linked list
void countEvenOdd(struct Node* head, int* evenCount, int* oddCount) {
    struct Node* current = head;
    *evenCount = 0;
    *oddCount = 0;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
        current = current->next;
    }
}

int main() {
    // Create and allocate nodes for the linked list
    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the linked list
    head->data = 10; head->next = second;
    second->data = 15; second->next = third;
    third->data = 22; third->next = fourth;
    fourth->data = 33; fourth->next = fifth;
    fifth->data = 40; fifth->next = NULL;

    // Print the original linked list
    printf("Linked List:\n");
    linkedListTraversal(head);

    // Count even and odd nodes
    int evenCount, oddCount;
    countEvenOdd(head, &evenCount, &oddCount);

    // Print the counts
    printf("\nNumber of even nodes: %d\n", evenCount);
    printf("Number of odd nodes: %d\n", oddCount);

    return 0;
}
