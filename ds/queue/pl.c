#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

void enqueue(struct node **head) {
    int value, priority;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    } else {
        printf("enter data: ");
        scanf("%d", &value);
        newnode->data = value;
        printf("enter priority: ");
        scanf("%d", &priority);
        newnode->priority = priority;
        newnode->next = NULL;
    }

    if (*head == NULL || (*head)->priority > newnode->priority) {
        newnode->next = *head;
        *head = newnode;
    } else {
        struct node *current = *head;
        struct node *prev = NULL;
        while (current != NULL && current->priority <= newnode->priority) {
            prev = current;
            current = current->next;
        }
        newnode->next = current;
        prev->next = newnode;
    }
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        while (head != NULL) {
            printf("Data = %d, Priority = %d\n", head->data, head->priority);
            head = head->next;
        }
    }
}

void dequeue(struct node **head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    printf("Dequeued element: Data = %d, Priority = %d\n", temp->data, temp->priority);
    free(temp);
}

int main() {
    struct node *front = NULL;
    int choice;
    do {
        printf("1. Enqueue\n");
        printf("2. Display\n");
        printf("3. Dequeue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(&front);
                break;
            case 2:
                display(front);
                break;
            case 3:
                dequeue(&front);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}
