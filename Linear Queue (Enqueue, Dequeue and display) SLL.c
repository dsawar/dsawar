#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure of the Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue an element to the rear of the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    // If the queue is empty, both front and rear will point to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    
    q->front = q->front->next;  // Move front to the next node
    
    // If the front becomes NULL, then the queue is empty, so update rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);  // Free the memory of the dequeued node
    printf("%d dequeued from queue\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);  // Initialize the queue
    
    // Enqueue some elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // Display the current queue
    display(&q);
    
    // Dequeue an element
    dequeue(&q);
    
    // Display the updated queue
    display(&q);
    
    // Enqueue more elements
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    // Display the final queue
    display(&q);
    
    return 0;
}
