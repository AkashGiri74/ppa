#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int marks[3]; // Assuming 3 subjects
    int totalMarks;
    struct Student* next;
};

// Function to insert a new student node at the end of the linked list
void insertStudent(struct Student** headRef, int rollNumber, char name[], int marks[], int totalMarks) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->rollNumber = rollNumber;
    for (int i = 0; i < 50 && name[i] != '\0'; i++) {
        newNode->name[i] = name[i];
    }
    for (int i = 0; i < 3; i++) {
        newNode->marks[i] = marks[i];
    }
    newNode->totalMarks = totalMarks;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Student* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to perform bubble sort on the linked list
// void sortStudentsByRollNumber(struct Student* head) {
//     int swapped;
//     struct Student *ptr1;
//     struct Student *lptr = NULL;

//     if (head == NULL)
//         return;

//     do {
//         swapped = 0;
//         ptr1 = head;

//         while (ptr1->next != lptr) {
//             if (ptr1->rollNumber > ptr1->next->rollNumber) {
//                 int tempRollNumber = ptr1->rollNumber;
//                 ptr1->rollNumber = ptr1->next->rollNumber;
//                 ptr1->next->rollNumber = tempRollNumber;

//                 char tempName[50];
//                 for (int i = 0; i < 50; i++) {
//                     tempName[i] = ptr1->name[i];
//                     ptr1->name[i] = ptr1->next->name[i];
//                     ptr1->next->name[i] = tempName[i];
//                 }

//                 int tempMarks[3];
//                 for (int i = 0; i < 3; i++) {
//                     tempMarks[i] = ptr1->marks[i];
//                     ptr1->marks[i] = ptr1->next->marks[i];
//                     ptr1->next->marks[i] = tempMarks[i];
//                 }

//                 int tempTotalMarks = ptr1->totalMarks;
//                 ptr1->totalMarks = ptr1->next->totalMarks;
//                 ptr1->next->totalMarks = tempTotalMarks;

//                 swapped = 1;
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     } while (swapped);
// }

// Function to print the sorted students in tabular format
void printStudents(struct Student* head) {
    printf("-----------------------------------------------------------------\n");
    printf("| %-12s | %-20s | %-5s | %-5s | %-5s | %-11s |\n", "Roll Number", "Name", "Mark 1", "Mark 2", "Mark 3", "Total Marks");
    printf("-----------------------------------------------------------------\n");
    struct Student* temp = head;
    while (temp != NULL) {
        printf("| %-12d | %-20s | %-5d | %-5d | %-5d | %-11d |\n", temp->rollNumber, temp->name, temp->marks[0], temp->marks[1], temp->marks[2], temp->totalMarks);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------------\n");
}

int main() {
    int numberOfStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numberOfStudents);
    getchar(); // Consume newline character left in the input buffer

    struct Student* head = NULL;

    // Input student details
    for (int i = 0; i < numberOfStudents; i++) 
    {
        int rollNumber, marks[3], totalMarks = 0;
        char name[50];
        printf("Enter Roll Number for student %d: ", i+1);
        scanf("%d", &rollNumber);
        printf("Enter Name for student %d: ", i+1);
        getchar(); // Consume newline character left in the input buffer
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = '\0'; // Removing newline character from the end
        printf("Enter marks for three subjects for student %d: ", i+1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &marks[j]);
            totalMarks += marks[j];
        }
        insertStudent(&head, rollNumber, name, marks, totalMarks);
    }

    // Sort the students by roll number
    sortStudentsByRollNumber(head);

    // Print the sorted students in tabular format
    printStudents(head);

    // Free memory allocated for linked list nodes
    struct Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
