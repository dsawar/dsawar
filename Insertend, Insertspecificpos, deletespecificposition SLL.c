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

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;  // If list is empty, return the new node as the head
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to insert a node at a specific position in the linked list
struct Node* insertAtSpecificPosition(struct Node* head, int newData, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    // Inserting at position 1 (beginning of the list)
    if (position == 1) {
        newNode->next = head;
        return newNode;  // New head of the list
    }

    struct Node* temp = head;
    int count = 1;

    // Traverse until the desired position is reached
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
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

// Function to delete a node at a specific position in the linked list
struct Node* deleteAtSpecificPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return NULL;
    }

    // Deleting the head node (position 1)
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    int count = 1;

    // Traverse until the node just before the one to be deleted
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    // Remove the node at the specified position
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    printf("Inserting at the end:\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    linkedListTraversal(head);

    // Insert node at specific position
    printf("\nInserting at position 3:\n");
    head = insertAtSpecificPosition(head, 25, 3);
    linkedListTraversal(head);

    // Delete node at specific position
    printf("\nDeleting node at position 4:\n");
    head = deleteAtSpecificPosition(head, 4);
    linkedListTraversal(head);

    return 0;
}
