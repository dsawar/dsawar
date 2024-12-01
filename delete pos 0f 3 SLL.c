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

// Function to delete nodes whose positions are multiples of 3
struct Node* deleteNodesAtMultiplesOfThree(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;
    int position = 1; // Track position of the current node

    while (current != NULL) {
        if (position % 3 == 0) { // Check if the position is a multiple of 3
            if (prev == NULL) {
                // Special case: deleting the head node
                head = current->next;
                free(current);
                current = head;
            } else {
                // General case: deleting nodes in the middle or end
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            // Move pointers forward if not deleting
            prev = current;
            current = current->next;
        }
        position++;
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

    // Delete nodes at positions that are multiples of 3
    head = deleteNodesAtMultiplesOfThree(head);

    // Print the updated linked list
    printf("\nUpdated Linked List (after deleting nodes at positions multiples of 3):\n");
    linkedListTraversal(head);

    return 0;
}
