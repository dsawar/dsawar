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

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to insert a node at a specific position in the doubly linked list
struct Node* insertAtSpecificPosition(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        // Insertion at the beginning
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
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

// Function to delete a node at a specific position in the doubly linked list
struct Node* deleteSpecificPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* temp = head;

    if (position == 1) {
        // Deletion of the head node
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return head;
    }

    int count = 1;

    // Traverse to the node at the specified position
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    // Adjust pointers for deletion
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;

    // Perform operations
    printf("Performing operations on doubly linked list...\n");

    // Insert at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    printf("After inserting at the end:\n");
    linkedListTraversal(head);

    // Insert at a specific position
    head = insertAtSpecificPosition(head, 25, 3);
    head = insertAtSpecificPosition(head, 5, 1);
    printf("After inserting at specific positions:\n");
    linkedListTraversal(head);

    // Delete a specific position
    head = deleteSpecificPosition(head, 4);
    printf("After deleting from specific position:\n");
    linkedListTraversal(head);

    return 0;
}
