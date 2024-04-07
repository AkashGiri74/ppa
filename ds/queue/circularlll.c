#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct Queue
{
    struct node * front;
    struct node * rear;
};

struct node * create_node()
{
    struct node * newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        int value;
        printf("enter element: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

struct Queue * create_queue()
{
    struct Queue * cqueue = NULL;
    cqueue = (struct Queue *)malloc(sizeof(struct Queue));
    if(cqueue == NULL)
    {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        cqueue->front = cqueue->rear = NULL;
    }
    return cqueue;
}

void enqueue(struct Queue * cqueue)
{
    struct node * newnode = NULL;
    newnode = create_node();
    if(cqueue->front == NULL && cqueue->rear == NULL)
    {
        cqueue->front = cqueue->rear = newnode;
        cqueue->rear->next = cqueue->front;
    }
    else
    {
        cqueue->rear->next = newnode;
        cqueue->rear = newnode;
        cqueue->rear->next = cqueue->front;
    }
}

void dequeue(struct Queue * cqueue)
{
    struct node * tempnode = NULL;
    if(cqueue->front == NULL && cqueue->rear == NULL)
    {
        puts("list is empty");
        return;
    }
    else if(cqueue->front->next == cqueue->rear)
    {
        free(cqueue->front);
        cqueue->front = NULL;
        cqueue->rear = NULL;
    }
    else
    {
        tempnode = cqueue->front;
        cqueue->front = cqueue->front->next;
        cqueue->rear->next = cqueue->front;
        free(tempnode);
    }
}

void display(struct Queue * cqueue)
{
    struct node * current = cqueue->front;
    if (current == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    }
    while(current != cqueue->front);
    printf("\n");
}

int get_front(struct Queue * cqueue)
{
    if (cqueue->front == NULL)
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return cqueue->front->data;
}

int get_rear(struct Queue * cqueue)
{
    if (cqueue->rear == NULL)
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return cqueue->rear->data;
}

int main()
{
    struct Queue * cqueue = NULL;
    cqueue = create_queue();
    int choice;
    do
    {
        puts("1. enqueue");
        puts("2. dequeue");
        puts("3. display");
        puts("4. get front");
        puts("5. get rear");
        puts("0. exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue(cqueue);
                break;
            case 2:
                dequeue(cqueue);
                break;
            case 3:
                display(cqueue);
                break;
            case 4:
                printf("Front element: %d\n", get_front(cqueue));
                break;
            case 5:
                printf("Rear element: %d\n", get_rear(cqueue));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);

    
}
