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

// Function to insert a node at a specific position in the doubly linked list
struct Node* insertAtSpecificPosition(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        // Insertion at the beginning
        return insertAtBegin(head, data);
    }

    struct Node* temp = head;
    int count = 1;

    // Traverse to the node before the specified position
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    // Adjust pointers for insertion
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

// Function to delete a node from the end of the doubly linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        // If the list has only one node
        head = NULL;
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

    // Insert at a specific position
    head = insertAtSpecificPosition(head, 25, 2);
    head = insertAtSpecificPosition(head, 35, 5);
    printf("After inserting at specific positions:\n");
    linkedListTraversal(head);

    // Delete from the end
    head = deleteFromEnd(head);
    printf("After deleting from the end:\n");
    linkedListTraversal(head);

    return 0;
}
