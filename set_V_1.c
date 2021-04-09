#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("null");
}

// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Helper function to return a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a given node at its correct sorted position into
// a given list sorted in increasing order
void sortedInsert(struct Node** head, struct Node* newNode)
{
    // special case for the head end
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // locate the node before the point of insertion
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}


int main(void)
{
    // input keys


    // print linked list

    int n,num,pos;int choice;char ch;
		printf("\n\t\t Singly Linked List \n");
		printf("-----------------------------------------------------\n");
		do
        {
            printf("\nMain Menu");
            printf("\n1. Create linked list serially");
            printf("\n2. Display linked list");
            printf("\n3. Insert Node Sorted");
            printf("\n4. Exit");
            printf("\nEnter Your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf(" Input the number of nodes : ");
                        scanf("%d", &n);
                        struct Node* head = NULL;

                        // construct a linked list
                         for (int i = n-1; i >= 0; i--) {
                                   printf("Enter the data: ");
                                   scanf("%d",&num);
                                     push(&head, num);
                                    }
                        break;
                case 2:      printList(head);
                         break;
                case 3: printf("\n Input data to insert : ");
                        scanf("%d", &num);
                       sortedInsert(&head, newNode(num));
                        break;
                case 4: exit(0);



                default: printf("\n Invalid input ");
                         break;

            }

            printf("\n Do you want to continue(y/n): ");
            scanf("%s",&ch);

        }while(ch=='y' || ch=='Y');

    return 0;
}
