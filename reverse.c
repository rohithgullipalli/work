#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
}node_t;

void push(struct node **head, int data)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	
	new_node->val = data;
	
	new_node->next = *head;
	
	*head = new_node;
} 


void delete(struct node **head, int data)
{
	struct node *temp = *head,*prev;
	if(temp != NULL && temp->val == data)
	{
		*head = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL && temp->val != data)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL) return;

	prev->next = temp->next;

	free(temp);

}

int Nthnode(struct node *head,int index)
{
	struct node *current = head;
	int count = 0;
	while(current != NULL)
	{
		if(count == index)
			return (current->val);
		count++;

		current = current->next;
	}
}

void reverse(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL;
	struct node *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}
		
	
void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d\n",n->val);
		n = n->next;
	}
}

int main()
{
	struct node *head = NULL;
	int index;

	head = malloc(sizeof(struct node));

	head->val = 1;
	head->next = NULL;
	
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);

	printf("elements in list \n");
	printList(head);	

	reverse(&head);

	printf("reversed list \n");
	printList(head);	

	return 0;
}
