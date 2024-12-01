#include <stdio.h>
#include <stdlib.h>

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

// Function to split the linked list into two lists
void splitLinkedList(struct Node* head, struct Node** firstHead, struct Node** secondHead, int splitPoint) {
    struct Node* temp = head;
    int count = 1;

    // Traverse to the split point
    while (temp != NULL && count < splitPoint) {
        temp = temp->next;
        count++;
    }

    // Set the head of the second list
    *secondHead = temp->next;
    temp->next = NULL; // Terminate the first list
    *firstHead = head;
}

int main() {
    struct Node *head, *second, *third, *fourth, *fifth, *sixth, *seventh, *eighth, *ninth, *tenth;

    // Allocate memory for 10 nodes in the linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    eighth = (struct Node *)malloc(sizeof(struct Node));
    ninth = (struct Node *)malloc(sizeof(struct Node));
    tenth = (struct Node *)malloc(sizeof(struct Node));

    // Initialize data and links for all 10 nodes
    head->data = 1; head->next = second;
    second->data = 2; second->next = third;
    third->data = 3; third->next = fourth;
    fourth->data = 4; fourth->next = fifth;
    fifth->data = 5; fifth->next = sixth;
    sixth->data = 6; sixth->next = seventh;
    seventh->data = 7; seventh->next = eighth;
    eighth->data = 8; eighth->next = ninth;
    ninth->data = 9; ninth->next = tenth;
    tenth->data = 10; tenth->next = NULL;

    // Print the original list
    printf("Original Linked List:\n");
    linkedListTraversal(head);

    // Split the list
    struct Node* firstHead = NULL;
    struct Node* secondHead = NULL;
    splitLinkedList(head, &firstHead, &secondHead, 4);

    // Print the two resulting lists
    printf("\nFirst Linked List (4 nodes):\n");
    linkedListTraversal(firstHead);

    printf("\nSecond Linked List (6 nodes):\n");
    linkedListTraversal(secondHead);

    return 0;
}
