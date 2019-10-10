#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	
	struct Node *Next;
};

void display_stack(struct Node* head_ref);
void push(struct Node **head_ref);
void pop(struct Node **head_ref);

int main()
{
	struct Node *head = NULL;
	int n;
	while(1)
	{
		printf("STACK\n");
		printf("-----\n");
		printf("1.PUSH.\n2.POP\n3.DISPLAY\n4.QUIT\n");
		printf(">>");
		scanf("%d", &n);
	

		switch(n)
		{
			case 1: 
				push(&head);
				break;
			case 2: 
				pop(&head);
				break;
			case 3: 
				display_stack(head);
				break;
			case 4:
				
				exit(0);
                                        
			default: 
				printf("invalid choice");
				break;
		}

	}	
	return 0;
}

void push(struct Node **head_ref)
{
	int new_data;
	printf("Enter Data:");
	scanf(" %d", &new_data);
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	
	new_node->Next = (*head_ref);

	(*head_ref) = new_node;

}

void display_stack(struct Node* head_ref)
{
	if(head_ref == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("-------\n");
	while(head_ref != NULL)
	{
		printf("|  %d  |\n",head_ref->data);
		printf("-------\n");
		head_ref = head_ref->Next;
	}

}

void pop(struct Node** head_ref)
{

	if((*head_ref) == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	struct Node *temp;
	temp = (*head_ref);
	*head_ref = (**head_ref).Next;
	free(temp);
}	
