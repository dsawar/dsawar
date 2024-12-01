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

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBegin(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    return head;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBegin(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;

    // Perform operations
    printf("Performing operations on doubly linked list...\n");

    // Insert at the beginning
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);
    printf("After inserting at the beginning:\n");
    linkedListTraversal(head);

    // Insert at the end
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    printf("After inserting at the end:\n");
    linkedListTraversal(head);

    // Delete from the beginning
    head = deleteFromBegin(head);
    printf("After deleting from the beginning:\n");
    linkedListTraversal(head);

    return 0;
}
