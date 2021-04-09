/* Program to insert in a sorted list */
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* function to insert a new_node
in a list. Note that this
function expects a pointer
to head_ref as this can modify the
head of the input linked
list (similar to push())*/
void sortedInsert(struct Node** head_ref,
				struct Node* new_node)
{
	struct Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL
		|| (*head_ref)->data
			>= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		/* Locate the node before
the point of insertion */
		current = *head_ref;
		while (current->next != NULL
			&& current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */

/* A utility function to create a new node */
struct Node* newNode(int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void insert_end(struct node **head, int value)
{
    struct node * new_node = NULL;
    struct node * last = NULL;

    /*Create the new node*/
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
        return;
    }

    new_node->val = value;
    new_node->next = NULL;

    /*No element in the linked list. So point head to the new node*/
    if( *head == NULL)
    {
        *head = new_node;
        return;
    }

    /*Traverse to the last node*/
    last = *head;
    while(last->next) last = last->next;

    /*Point last node's link (next pointer) to the new node*/
    last->next = new_node;
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	int choice;
	struct Node* head = NULL;
	struct Node* new_node = newNode(5);
	while(1)
	{
		printf("1.Insert in sorted order\n");
		printf("2.Insert in serial order\n");
		printf("3.Display\n");
		printf("4.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			sortedInsert(head)
			break;
         case 2:
            insert_end(head)
		 case 3:
			display(head);
			break;
         case 4:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
	printList(head);

	return 0;
}
