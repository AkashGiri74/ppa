#include<stdio.h>
#include<stdlib.h>

struct element {
    int data;
    int priority;
};

struct PQueue {
    struct element* arr;
    int capacity;
    int size;
};

struct PQueue* create_queue() {
    int capacity;
    struct PQueue* pq = NULL;
    pq = (struct PQueue*)malloc(sizeof(struct PQueue));
    if (pq == NULL) {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    puts("Enter capacity");
    scanf("%d", &capacity);
    pq->capacity = capacity;
    pq->arr = (struct element*)malloc(pq->capacity * sizeof(struct element));
    if (pq->arr == NULL) {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    pq->size = 0;
    return pq;
}

int is_full(struct PQueue* pq) {
    return pq->size == pq->capacity;
}

void enqueue(struct PQueue* pq) {
    int i, data, priority;
    if (is_full(pq)) {
        puts("Priority queue is full");
        return;
    }
    puts("Enter data");
    scanf("%d", &data);
    puts("Enter priority");
    scanf("%d", &priority);

    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    (pq->size)++;
    struct element temp;
    for (i = pq->size - 1; i > 0; i--) {
        if (pq->arr[i].priority > pq->arr[i - 1].priority) {
            temp = pq->arr[i];
            pq->arr[i] = pq->arr[i - 1];
            pq->arr[i - 1] = temp;
        }
    }
}

void display(struct PQueue* pq) {
    if (pq->size == 0) {
        puts("Priority queue is empty");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main() {
    struct PQueue* pq = NULL;
    pq = create_queue();
    int choice;
    do {
        puts("1. Enqueue");
        puts("2. Display");
        puts("Enter your choice");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(pq);
                break;
            case 2:
                display(pq);
                break;
        }
    } while (choice != 0);
    free(pq->arr);
    free(pq);
    return 0;
}
