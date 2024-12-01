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

// Function to split the list into odd and even positioned nodes
void splitOddEven(struct Node* head, struct Node** oddHead, struct Node** evenHead) {
    struct Node *oddTail = NULL, *evenTail = NULL;
    int position = 1;

    while (head != NULL) {
        if (position % 2 != 0) { // Odd position
            if (*oddHead == NULL) {
                *oddHead = head;
                oddTail = head;
            } else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        } else { // Even position
            if (*evenHead == NULL) {
                *evenHead = head;
                evenTail = head;
            } else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        head = head->next;
        position++;
    }

    // Terminate both lists
    if (oddTail != NULL) oddTail->next = NULL;
    if (evenTail != NULL) evenTail->next = NULL;
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

    // Split the list into odd and even position lists
    struct Node* oddHead = NULL;
    struct Node* evenHead = NULL;
    splitOddEven(head, &oddHead, &evenHead);

    // Print the two resulting lists
    printf("\nOdd Position Linked List:\n");
    linkedListTraversal(oddHead);

    printf("\nEven Position Linked List:\n");
    linkedListTraversal(evenHead);

    return 0;
}
