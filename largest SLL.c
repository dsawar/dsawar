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

// Function to find the node with the largest data value and its position
void findLargestNode(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    int maxData = current->data; // Assume the first node contains the max value
    int position = 1; // Position of the first node is 1
    int maxPosition = 1; // Position of the largest node

    current = current->next;
    int currentPosition = 2; // Start checking from the second node

    // Traverse through the linked list to find the node with the largest data value
    while (current != NULL) {
        if (current->data > maxData) {
            maxData = current->data;
            maxPosition = currentPosition;
        }
        current = current->next;
        currentPosition++;
    }

    printf("Largest data value: %d at position: %d\n", maxData, maxPosition);
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

    // Find and print the node with the largest data value and its position
    findLargestNode(head);

    return 0;
}
