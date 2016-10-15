#include<stdio.h>
#include<stdlib.h>

/*NOTES - Singly Linked List Operations :-
 :: Concept ::-
 1. The address of the first node is always stored in a reference variable known as front or start or head.
 2. The reference part of the last node must be null.
 :: Operations :-
 1. Insert
		-Insert at begining 
		-Insert at specified location
		-Insert at end of the list
2.	Delete
		-Delete from the begining of the list
		-Delete a specific node
		-Delete from end of the list
3.	Display

:: Advantages ::-
		-Dynamic in size.
		-Easy to insert/delete an element
:: Drawbacks ::-
		-Cannot access elements of list randomly.Only linear search is possible, Hence binary search is not possible on Linked list.
		-Extra memory space is required for storing a pointer with every element.
*/

//Define a node with a variable to hold data and a pointer variable to hold address of the next node.
//Also create a pointer variable of the type node which holds the address of the first node(always points to the first node in the list).
struct intList
{
	int val;
	struct intList *nextVal;
}*head;

typedef struct intList iList; //(Optional): create an alias for the node for ease of use in the program

void insert() // To insert elements into the list at the end
{	
	iList *temp, *eol;
	int newVal;
	do
	{
		temp=(iList *)malloc(sizeof(iList));

		system("clear");
		printf("Enter a value to be inserted (0 for menu): ");	
		scanf("%d",&newVal);
		temp->val=newVal;
		if (newVal==0) // If user wants to exit insert operation
			exit;
		else if (head==NULL) // If the element to be inserted is the first element
		{
			head=temp;
			head->nextVal=NULL;
		}
		else // Traverse through the list to the last element to append new value
		{	
			eol=head;
			//sleep(5);
			while(eol->nextVal!=NULL)
			{
				eol=eol->nextVal;
			}
			if(eol->nextVal==NULL)
			{
				eol->nextVal=temp;
				temp->nextVal=NULL;
			}
		}
	}while(newVal!=0);
}

void displayList() // To display all the elements in the list
{
	iList *temp;
	temp=head;
	int n=1;
	system("clear");
	printf("Elements of the list are:\n");
	do
	{
		printf(" Element %d is: %d\n",n,temp->val);
		temp=temp->nextVal;
		n=n+1;
	} while(temp);
sleep(n);
}

// To delete an element from the list based on value input by user
void deleteElement() // To delete a given element in the list
{
	// deleting the only element in the list
	//	deleting the first element in the list
	//	deleting inbetween element in the list
	//	deleting the last element in the list
	struct intList *temp, *temp1;
	int elementToDelete, elementFound=0;
	temp=temp1=head; // temp is now pointing to the start of the list

	system("clear");
	printf("Enter the value of the element to delete (0 for menu): ");
	scanf("%d",&elementToDelete);

	if(elementToDelete==0) // if user opts to exit the delete operation 
		exit;
	else if(head->val == elementToDelete && head->nextVal==NULL) // If element to delete is the first and only element in the list
		{
			free(temp1); 
			head=NULL;
			elementFound=1;
		}
	else if(head->val == elementToDelete && head->nextVal!=NULL) //If the element to delete is the first element in the list of elements
		{
			temp=temp->nextVal;
			head=temp;
			free(temp1);
			elementFound=1;
		}
	else
	{
		do
		{
			if (temp->val == elementToDelete)// If element to delete is in-between element or the last element
			{
				temp1->nextVal=temp->nextVal; // here temp1 means previous element in the list
				temp=NULL;		// how to eleminate this
				elementFound=1;		
			}
			else
			{
				temp1=temp;
				temp=temp->nextVal;
			}
		} while(temp); 
		free(temp);
	}
	if(elementFound==0)
	{
		printf("Element not found!");
	}
}

int main()
{
	int choice;
	head=NULL;

	do
	{
		system("clear");
		printf("\n Single Linked List Operations\n");
		printf("\n 1. Insert an Element\n 2. Delete an Element\n 3. Display Elements\n 0. To Exit\n\n Enter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{		
			case 1:
				insert();
				break;
			case 2:
				if (head==NULL)
				{
					system("clear");
					printf("List is Empty!\n");
					sleep(3);
					system("clear");
				}
				else
					deleteElement();
				break;
			case 3:
				if (head==NULL)
				{
					system("clear");
					printf("List is Empty!\n");
					sleep(3);
					system("clear");
				}
				else
					displayList();
				break;
			default:
				if(choice!=0)
				{
					system("clear");
					printf("Invalid Input\n");
					sleep(3);
					system("clear");				
				}

		}
	}while(choice);
	
	system("clear");
	return 0;
}