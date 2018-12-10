#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *top=NULL;

int push();
int pop();
int display();

int main()
{
	int op;
	do
	{
		printf("\n\n\nMENU:-\n1. Push\n2. Pop\n3. Display\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				push();
				break;
				
			case 2 :
				pop();
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

int push()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->link = top;
	top=temp;
	display();
	return 0;
}

int pop()
{
	struct node *temp;
	if (top == NULL)
	{
		printf("\nStack is empty\n");
		return 0;
	}
	temp=top;
	top=top->link;
	free(temp);
	display();
	return 0;
}

int display()
{
	struct node *temp=top;
	if (top == NULL)
	{
		printf("\nStack is empty\n");
		return 0;
	}
	printf("\nStack :-\n");
	while (temp != NULL)
	{
		printf("%d  ",temp->info);
		temp = temp->link;
	}
	return 0;
}


