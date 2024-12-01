#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;  // Point the new node to the current top
    *top = newNode;        // Make the new node the top
    printf("%d pushed to stack\n", value);
}

// Function to pop the top element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Make the next node the top
    free(temp);            // Free the memory of the popped node
    printf("%d popped from stack\n", poppedValue);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;  // Initialize an empty stack

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the current stack
    display(stack);

    // Peek at the top element
    printf("Top element is: %d\n", peek(stack));

    // Pop an element from the stack
    pop(&stack);

    // Display the updated stack
    display(stack);

    // Peek at the new top element
    printf("Top element is: %d\n", peek(stack));

    // Pop all elements
    pop(&stack);
    pop(&stack);

    // Display the empty stack
    display(stack);

    return 0;
}
