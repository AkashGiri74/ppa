#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int roll_number;
    char name[10];
    int age;
};

struct node {
    struct student data;
    struct node* next;
};

void createlinkedlist(struct node**, int);
struct node* createnode(int);
void display(struct node*);
void swap(struct node*, struct node*);
void sort_by_roll_number(struct node*);

int main() {
    struct node* first = NULL;
    int n;
    printf("Enter how many students: ");
    scanf("%d", &n);

    createlinkedlist(&first, n);
    printf("Before sorting:\n");
    display(first);

    sort_by_roll_number(first);
    printf("\nAfter sorting:\n");
    display(first);

    return 0;
}

void createlinkedlist(struct node** head, int n) {
    struct node* newnode = NULL;
    struct node* travnode = *head;
    int i;

    for (i = 0; i < n; i++) {
        int roll_number;
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &roll_number);
        getchar(); // Consume the newline character

        newnode = createnode(roll_number);

        if (*head == NULL) {
            *head = newnode;
        } else {
            travnode = *head;
            while (travnode->next != NULL) {
                travnode = travnode->next;
            }
            travnode->next = newnode;
        }
    }
}

struct node* createnode(int roll_number) {
    struct node* newnode = NULL;
    char name[10];
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    } else {
        newnode->next = NULL;
        newnode->data.roll_number = roll_number;

        printf("Enter name for student with roll number %d: ", roll_number);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        strcpy(newnode->data.name, name);

        printf("Enter age for student with roll number %d: ", roll_number);
        scanf("%d", &newnode->data.age);
        getchar(); // Consume the newline character
    }

    return newnode;
}

void sort_by_roll_number(struct node* head) {
    struct node *temp, *traverse;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    for (temp = head; temp->next != NULL; temp = temp->next) {
        for (traverse = temp->next; traverse != NULL; traverse = traverse->next) {
            if (temp->data.roll_number > traverse->data.roll_number) {
                swap(temp, traverse);
            }
        }
    }
}

void swap(struct node* node1, struct node* node2) {
    struct student temp_data = node1->data;
    node1->data = node2->data;
    node2->data = temp_data;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("Roll Number: %d\n", head->data.roll_number);
        printf("Name: %s\n", head->data.name);
        printf("Age: %d\n\n", head->data.age);

        head = head->next;
    }
}
