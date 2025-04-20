/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: usage of linkedlist
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

//create list with no nodes, just a start pointer.
void createListNoNodes() {
    start = NULL;
    printf("Empty list create.\n");
}

//create list with a single node. Data to fill the node is the precondition andmust be passed as a parameter.
void createListNode(struct Student s){
    start = (struct Student*)malloc(sizeof(struct Student));
    *start = s;
    start->nextaddr = NULL;
    printf("Single node list create.\n");
}

//insert a node at the front of the list.
void InsertFront(struct Student s) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    *newNode = s;
    newNode->nextaddr = start;
    start = newNode;
    printf("Inserted at front.\n");
}

//insert a node at the end of the list.
void InsertEnd(struct Student s) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    *newNode = s;
    newNode->nextaddr = NULL;
    struct Student* current = start;
    while (current->nextaddr != NULL) {
        current = current->nextaddr;
        }
    current->nextaddr = newNode;
    printf("Inserted at end.\n");
}

//insert a node in the middle of the list
void InsertMiddle(struct Student s, const char* afterPUID) {
    struct Student* current = start;
    while (current != NULL && strcmp(current->PUID, afterPUID) != 0) {
        current = current->nextaddr;
    }
    if (current == NULL) {
        printf("InsertMiddle failed: PUID not found.\n");
        return;
    }

    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    *newNode = s;
    newNode->nextaddr = current->nextaddr;
    current->nextaddr = newNode;
    printf("Inserted in middle after PUID %s.\n", afterPUID);
}

//delete the first node in the list
void DeleteFront() {
    if (start == NULL) return;
    struct Student* temp = start;
    start = start->nextaddr;
    free(temp);
    printf("Deleted front node.\n");
}

////delete a node in the middle of the list
void DeleteEnd() {
    if (start == NULL) return;

    if (start->nextaddr == NULL) {
        free(start);
        start = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct Student* current = start;
    struct Student* prev = NULL;

    while (current->nextaddr != NULL) {
        prev = current;
        current = current->nextaddr;
    }

    prev->nextaddr = NULL;
    free(current);
    printf("Deleted end node.\n");
}

//delete a node in the middle of the list
void DeleteMiddle(const char* puid) {
    if (start == NULL) return;

    struct Student* current = start;
    struct Student* prev = NULL;

    while (current != NULL && strcmp(current->PUID, puid) != 0) {
        prev = current;
        current = current->nextaddr;
    }

    if (current == NULL) {
        printf("DeleteMiddle failed: PUID %s not found.\n", puid);
        return;
    }

    if (prev == NULL) {
        start = current->nextaddr;
    } else {
        prev->nextaddr = current->nextaddr;
    }

    free(current);
    printf("Deleted node with PUID %s.\n", puid);
 
}

//Traverse the list
void Traverse() {
    struct Student* current = start;
    printf("Student List:\n");
    while (current != NULL) {
        printf("Name: %s %s, PUID: %s, Age: %d\n",
               current->FirstName, current->LastName, current->PUID, current->age);
        current = current->nextaddr;
    }
}

// find a particular node by using the PUID of each node to search. Return -1 if that PUID is not in the list which means it does not exist
int Search(const char* puid) {
    struct Student* current = start;
    while (current != NULL) {
        if (strcmp(current->PUID, puid) == 0) {
            printf("Found: %s %s, PUID: %s, Age: %d\n",
                   current->FirstName, current->LastName, current->PUID, current->age);
            return 0;
        }
        current = current->nextaddr;
    }
    
    printf("The PUID Does not exist!");
  return -1;
}

int main() {
    
    while(1){
        int menu; //reads user options
            //menu options
       printf("\nMain Menu\n");
       printf("1. Create List No Nodes\n");
       printf("2. Create List Node\n");
       printf("3. Insert Front\n");
       printf("4. Insert Middle\n");
       printf("5. Insert End\n");
       printf("6. Delete Front\n");
       printf("7. Delete Middle\n");
       printf("8. Delete End\n");
       printf("9. Traverse \n");
       printf("10. Search\n");
       printf("11. Exit\n");
       scanf("%i", &menu);
       
       struct Student temp;
       
       switch(menu){
           case 1: 
               createListNoNodes();
               Traverse();
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
                createListNode(temp);
                Traverse();
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
                InsertFront(temp);
                Traverse();
                break;
           
           
          case 4:
                printf("Insert Middle\n");
                printf("Enter First Name: ");
                scanf("%s", temp.FirstName);
                printf("Enter Last Name: ");
                scanf("%s", temp.LastName);
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
                printf("Enter Age: ");
                scanf("%d", &temp.age);
                char order_after[11];
                printf("This data gets inserted after PUID: ");
                scanf("%s", order_after);
                InsertMiddle(temp, order_after);
                Traverse();
                break;
           
          case 5:
                printf("Insert End");
                printf("Enter First Name: ");
                scanf("%s", temp.FirstName);
                printf("Enter Last Name: ");
                scanf("%s", temp.LastName);
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
                printf("Enter Age: ");
                scanf("%d", &temp.age);
                InsertEnd(temp);
                Traverse();
                break;
           
           
          case 6:
              DeleteFront();
              Traverse();
              break;
           
           
          case 7:
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
                DeleteMiddle(temp.PUID);
                Traverse();
                break;
           
           
          case 8:
              DeleteEnd();
              Traverse();
              break;
           
           
           case 9:
                Traverse();
                break;
           
           
           case 10:
                printf("Enter PUID: ");
                scanf("%s", temp.PUID);
               Search(temp.PUID);
               break;
    
           
           case 11:
            exit(0);
            break;
        
       }
    }
    return 0;
}





