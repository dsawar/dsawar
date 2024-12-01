#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
void concatenate(struct Node* list1, struct Node* list2) {
    struct Node* temp = list1;
    
    // Traverse to the end of the first list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Connect the last node of the first list to the head of the second list
    temp->next = list2;
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create two linked lists
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    struct Node* head2 = createNode(6);
    head2->next = createNode(7);
    head2->next->next = createNode(8);
    head2->next->next->next = createNode(9);
    head2->next->next->next->next = createNode(10);

    printf("List 1 before concatenation:\n");
    printList(head1);

    printf("List 2 before concatenation:\n");
    printList(head2);

    // Concatenate the two lists
    concatenate(head1, head2);

    printf("List after concatenation:\n");
    printList(head1);

    return 0;
}
