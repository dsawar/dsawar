#include <stdio.h>
#define MAX 5  // Maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Enqueue operation to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // Queue is empty
        }
        queue->arr[++queue->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue operation to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int dequeuedValue = queue->arr[queue->front++];
        printf("%d dequeued from queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

// Display the elements of the queue
void display(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);

    dequeue(&queue);
    display(&queue);

    return 0;
}
