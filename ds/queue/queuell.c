#include<stdio.h>
#include<stdlib.h>

struct node
{   
   int data;
   struct node *next;
};

struct Queue
{  
   struct node *front;
   struct node *rear;
};

struct node* create_node()
{  
    int value;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("Enter data: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

struct Queue* create_queue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if(queue == NULL)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct node* newnode)
{  
    if(queue->front == NULL && queue->rear == NULL)
    {
        queue->front = queue->rear = newnode;
    }
    else
    {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}

void dequeue(struct Queue* queue)
{
    if(queue->front == NULL && queue->rear == NULL)
    {   
        puts("Queue is empty");
        return;
    }
    else
    {
        struct node* temp = queue->front;
        queue->front = queue->front->next;
        printf("Dequeued element is %d\n", temp->data);
        free(temp);
        if(queue->front == NULL)
        {
            queue->rear = NULL;
        }
    }
}

void display(struct Queue* queue)
{   
    struct node* temp = queue->front;
    if(temp == NULL)
    {   
        puts("Queue is empty");
        return;
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } 
    printf("\n");
}

int main()
{ 
    struct Queue* queue = create_queue();
    int choice;
    do
    {
        puts("1. Enqueue");
        puts("2. Dequeue");
        puts("3. Display");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                {
                    struct node* newnode = create_node();
                    enqueue(queue, newnode);
                }
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break; 
        }
    } while (choice != 0);

    return 0;
}
