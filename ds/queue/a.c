#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int capacity;
    int front, rear;
};

struct Queue* create_Queue() {
    int cap;
    printf("Enter capacity:\n");
    scanf("%d", &cap);

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    queue->capacity = cap;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->arr == NULL) {
        printf("Memory allocation failed!\n");
        free(queue);
        return NULL;
    }
    queue->front = -1; // Initialize front and rear
    queue->rear = -1;
    return queue;
}

void display(struct Queue* queue) {
    if (queue == NULL) {
        printf("Queue is NULL\n");
        return;
    }
    if (queue->front == -1 && queue->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = queue->front; i <= queue->rear; ++i) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* myQueue = create_Queue();

    if (myQueue == NULL) {
        printf("Queue creation failed\n");
        return 1;
    }

    // Test display function
    display(myQueue);

    return 0;
}
