/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: Stack and Queue
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXNAME 30

//Structure student
struct Student
{
    char FirstName[MAXNAME];
    char LastName[MAXNAME];
    char PUID[11];
    int age;
    struct Student *nextaddr;
};
struct Student* start = NULL;

//push
void push(strut Student temp){
    if(start == NULL) {
        printf("Empty");
        return;
    }
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    *newStudent = temp;
    newStudent->nextaddr = start;
    start = newStudent;
}
//pop
void pop(){
    struct Student* temp = start;
    start = start->nextaddr;
    free(temp);
    
}

// Print the Stack
void printStack() {
    struct Student* current = start;
    while (current != NULL) {
        printf("%s %s, PUID: %s, Age: %d\n", current->FirstName, current->LastName, current->PUID, current->age);
        current = current->nextaddr;
    }
}
// Queue Enqueue (Insert at end)
void enqueue(struct Student temp) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    *newStudent = temp;
    newStudent->nextaddr = NULL;

    if (queueTail == NULL) { // Empty queue
        queueHead = queueTail = newStudent;
    } else {
        queueTail->nextaddr = newStudent;
        queueTail = newStudent;
    }
}
// Queue Dequeue (Remove from front)
void dequeue() {
    if (queueHead == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Student* temp = queueHead;
    queueHead = queueHead->nextaddr;
    if (queueHead == NULL) { // Queue became empty
        queueTail = NULL;
    }
    free(temp);
}
// Empty the Queue
void emptyQueue() {
    while (queueHead != NULL) {
        dequeue();
    }
}

// Print the Queue
void printQueue() {
    struct Student* current = queueHead;
    printf("Queue contents:\n");
    while (current != NULL) {
        printf("%s %s, PUID: %s, Age: %d\n", current->FirstName, current->LastName, current->PUID, current->age);
        current = current->nextaddr;
    }
}



//Queue head and tail
struct Student* queueHead = NULL;
struct Student* queueTail = NULL;

int main() {
    while(1){
        int menu; //reads user options
            //menu options
       printf("\nMain Menu\n");
       printf("1. Pop - delete a node from the Stack\n");
       printf("2. Push - add a node to the Stack\n");
       printf("3. Enqueue - add a node to the Queue\n");
       printf("4. Dequeue - delete a node from the queue\n");
       printf("5. Empty Queue - remove all of the nodes from the queue\n");
       printf("6. Empty Stack - remove all of the nodes from the stack\n");
       printf("87. Print Queue - print the nodes of the Queue in the order of arrival into the queue\n");
       printf("8. Print Stack - print the nodes of the Stack, which should be the reverse of the Queue\n");
       printf("9. Reverse Queue - Use the Stack to reverse the order of the elements in the Queue, by pushingthem on and then popping them in reverse order. This will be the test if your stack and queue structures work.\n");
       printf("10. Exit\n");
       scanf("%i", &menu);
       
       struct Student temp;
       switch(menu){
          case 1: 
              pop();
              printStack();
              break;
           
          case 2:
                printf("Create List\n");
                printf("Enter First Name: ");
                scanf("%s", temp.FirstName);
                printf("Enter Last Name: ");
                scanf("%s", temp.LastName);
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
                printf("Enter Age: ");
                scanf("%d", &temp.age);
                push(temp);
                printStack();
                break;
           
          case 3:
                printf("Insert Middle\n");
                printf("Enter First Name: ");
                scanf("%s", temp.FirstName);
                printf("Enter Last Name: ");
                scanf("%s", temp.LastName);
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
                printf("Enter Age: ");
                scanf("%d", &temp.age);
                enqueue(temp);
                printQueue();
                break;
           
          case 4: 
              dequeue();
              printQueue();
              break;
           
          case 5:
                emptyQueue();
                break;
            
          case 6:
                emptyStack();
                break;
            
          case 7:
                printQueue();
                break;
          case 8:
                printStack();
                break;
                
            
          case 9:
                while (queueHead != NULL) {
                    push(*queueHead);
                    dequeue();
                }
                while (start != NULL) {
                    enqueue(*start);
                    pop();
                }
                printf("Queue reversed!\n");
                break;
               
    
           
          case 10:
            exit(0);
            break;
        
       }
    }
    return 0;
}