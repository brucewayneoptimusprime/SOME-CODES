#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a queue
struct ArrayQueue {
    int front, rear, capacity;
    int* array;
};

// Function to create a new queue
struct ArrayQueue* createArrayQueue(int capacity) {
    struct ArrayQueue* queue = (struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct ArrayQueue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if the queue is empty
int isEmpty(struct ArrayQueue* queue) {
    return (queue->front == -1);
}

// Function to enqueue an element
void enqueue(struct ArrayQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    
    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element
int dequeue(struct ArrayQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    }
    
    int item = queue->array[queue->front];
    queue->front++;
    
    // If the last element is dequeued, reset front and rear
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    
    return item;
}

// Function to get the front element without removing it
int front(struct ArrayQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // Return an error value
    }
    return queue->array[queue->front];
}

int main() {
    struct ArrayQueue* queue = createArrayQueue(MAX_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", front(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Front element after dequeue: %d\n", front(queue));

    return 0;
}
