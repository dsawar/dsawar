#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and display the linked list
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode; // New head of the list
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode; // New node is the head if list is empty
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete the first node from the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head; // Updated head of the list
}

int main() {
    struct Node *head = NULL;

    // Insert nodes at the beginning
    printf("Inserting at the beginning:\n");
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 11);
    head = insertAtBeginning(head, 41);
    linkedListTraversal(head);

    // Insert nodes at the end
    printf("\nInserting at the end:\n");
    head = insertAtEnd(head, 66);
    head = insertAtEnd(head, 99);
    linkedListTraversal(head);

    // Delete node from the beginning
    printf("\nDeleting from the beginning:\n");
    head = deleteFromBeginning(head);
    linkedListTraversal(head);

    return 0;
}
