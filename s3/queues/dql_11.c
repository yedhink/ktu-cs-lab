/*Program to represent double-ended queue using arrays and to implement it's operations*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *right,*left;
};

struct node *front=NULL, *rear=NULL;

int inf();
int outf();
int inr();
int outr();
int display();

int main()
{
	int op;
	do
	{
		printf("\n\n\nMENU:-\n1. Insert at rear\n2. Delete from front\n3. Insert at front\n4. Delete from rear\n5. Display\n6. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				inr();
				break;
				
			case 2 :
				outf();
				break;
			
			case 3 :
				inf();
				break;
				
			case 4 :
				outr();
				break;
					
			case 5 :
				display();
				break;
				
			case 6 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int inr()
{
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	if (front == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		t = front;
		while (t->right != NULL)
			t = t->right;
		t->right = temp;
		temp->left = t;
		rear = temp;
	}
	display();
	return 0;
}

int outf()
{
	struct node *temp=front;
	if (front == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	temp = front;
	if (temp->right == NULL)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		front->right->left = NULL;
		front = front->right;
	}
	free(temp);
	display();
	return 0;
}

int inf()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	if (front != NULL)
	{
		front->left = temp;
		temp->right = front;
	}
	else
		rear = temp;
	front = temp;
	display();
	return 0;
}

int outr()
{
	struct node *temp=front;
	if (front == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	while (temp->right != NULL)
		temp = temp->right;
	if (temp->left != NULL)
		temp->left->right = NULL;
	else
	{
		front = NULL;
		rear = NULL;
	}
	if (rear != NULL)
		rear = rear->left;
	free(temp);
	display();
	return 0;
}

int display()
{
	struct node *temp=front;
	if (front == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("\nElements :-\n");
	while (temp != NULL)
	{
		printf("%d  ",temp->info);
		temp = temp->right;
	}
	return 0;
}

