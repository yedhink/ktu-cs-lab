/*Program to represent queue using linked lists and to implement it's operations*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *front=NULL,*rear=NULL;

int enqueue();
int dequeue();
int display();

int main()
{
	int op;
	do
	{
		printf("\n\n\nMENU:-\n1. ENQUEUE\n2. DEQUEUE\n3. Display\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				enqueue();
				break;
				
			case 2 :
				dequeue();
				break;
				
			case 3 :
				display();
				break;
				
			case 4 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int enqueue()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->link = NULL;
	if (front == NULL)
		front = temp;
	else
		rear->link = temp;
	rear= temp;
	display();
	return 0;
}

int dequeue()
{
	struct node *temp;
	if (front == NULL)
	{
		printf("\nQueue is empty\n");
		return 0;
	}
	temp = front;
	if (front == rear)
	{
		front = NULL;
		rear = NULL;
		free(temp);
		display();
		return 0;
	}
	front=front->link;
	display();
	free(temp);
	return 0;
}

int display()
{
	struct node *temp=front;
	if (front == NULL)
	{
		printf("\nQueue is empty\n");
		return 0;
	}
	printf("\nQueue :-\n");
	while (temp != NULL)
	{
		printf("%d  ",temp->info);
		temp = temp->link;
	}
	return 0;
}

