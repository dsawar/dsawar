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

// Function to delete nodes that are multiples of 3
struct Node* deleteMultiplesOfThree(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        // If the current node's data is a multiple of 3
        if (current->data % 3 == 0) {
            if (current == head) {
                // If the head node is to be deleted
                head = current->next;
                free(current);
                current = head;
            } else {
                // If a middle or last node is to be deleted
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
    return head;
}

int main() {
    // Create and allocate nodes for the linked list
    struct Node *head, *second, *third, *fourth, *fifth, *sixth, *seventh, *eighth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));
    seventh = (struct Node*)malloc(sizeof(struct Node));
    eighth = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the linked list
    head->data = 10; head->next = second;
    second->data = 15; second->next = third;
    third->data = 21; third->next = fourth;
    fourth->data = 8; fourth->next = fifth;
    fifth->data = 18; fifth->next = sixth;
    sixth->data = 13; sixth->next = seventh;
    seventh->data = 6; seventh->next = eighth;
    eighth->data = 7; eighth->next = NULL;

    // Print the original linked list
    printf("Original Linked List:\n");
    linkedListTraversal(head);

    // Delete nodes that are multiples of 3
    head = deleteMultiplesOfThree(head);

    // Print the updated linked list
    printf("\nUpdated Linked List (after deleting multiples of 3):\n");
    linkedListTraversal(head);

    return 0;
}
