#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and display the linked list
void linkedListTraversal(struct Node* ptr) {
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

// Function to insert a node at a specific position in the linked list
struct Node* insertAtSpecificPosition(struct Node* head, int newData, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = head;
        return newNode; // New head of the list
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);

    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    printf("Inserting at the beginning:\n");
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 11);
    head = insertAtBeginning(head, 41);
    linkedListTraversal(head);

    // Insert node at specific position
    printf("\nInserting at specific position (position 2):\n");
    head = insertAtSpecificPosition(head, 66, 2);
    linkedListTraversal(head);

    // Delete node from the end
    printf("\nDeleting from the end:\n");
    head = deleteFromEnd(head);
    linkedListTraversal(head);

    return 0;
}
