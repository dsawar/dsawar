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
    if ((queue->rear + 1) % MAX == queue->front) {
        printf("Queue overflow\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;  // Queue is empty
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->arr[queue->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Dequeue operation to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int dequeuedValue = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;  // Queue is empty
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        printf("%d dequeued from queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

// Display the elements of the queue
void display(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue->arr[queue->rear]);  // Print the rear element
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

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    display(&queue);

    return 0;
}
