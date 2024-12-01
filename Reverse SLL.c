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

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev to the current node
        current = next;        // Move current to the next node
    }
    return prev;  // New head of the reversed list
}

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

    // Reverse the linked list
    struct Node* reversedHead = reverseLinkedList(head);

    // Print the reversed list
    printf("\nReversed List:\n");
    linkedListTraversal(reversedHead);

    return 0;
}
