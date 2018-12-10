/*To implement a linked list and it's operations*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *right,*left;
};

struct node *start=NULL;

int insertbeg();
int insertend();
int insertpos();
int insertbef();
int insertaft();
int deletebeg();
int deleteend();
int deletepos();
int deletebef();
int deleteaft();
int display();

int main()
{
	int op;
	do
	{
		printf("\n\n\nMENU:-\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at a specified position\n4. Insert before a given element\n5. Insert after a given element\n6. Delete at the beginning\n7. Delete at the end\n8. Delete at a specified position\n9. Delete before a given element\n10. Delete after a given element\n11. Display\n12. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				insertbeg();
				break;
				
			case 2 :
				insertend();
				break;
			
			case 3 :
				insertpos();
				break;
				
			case 4 :
				insertbef();
				break;
					
			case 5 :
				insertaft();
				break;
				
			case 6 :
				deletebeg();
				break;
				
			case 7 :
				deleteend();
				break;
			
			case 8 :
				deletepos();
				break;
				
			case 9 :
				deletebef();
				break;
					
			case 10 :
				deleteaft();
				break;
				
			case 11 :
				display();
				break;			
			
			case 12 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int insertbeg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	if (start != NULL)
	{
		start->left = temp;
		temp->right = start;
	}
	start = temp;
	display();
	return 0;
}

int insertend()
{
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		t = start;
		while (t->right != NULL)
			t = t->right;
		t->right = temp;
		temp->left = t;
	}
	display();
	return 0;
}

int insertpos()
{
	int pos,i;
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	printf("Enter the position : ");
	scanf("%d",&pos);
	if (start == NULL && pos>1)
	{
		printf("\nPosition does not exist\n");
		return 0;
	}
	if (pos == 1)
	{
		if (start != NULL)
			start->left = temp;
		temp->right = start;
		start = temp;
	}
	else
	{
		t = start;
		for (i=1; i<pos-1; ++i)
		{
			if (t->right == NULL)
			{
				printf("\nPosition does not exist\n");
				return 0;
			}
			t = t->right;
		}
		temp->right = t->right;
		if (t->right != NULL)
			t->right->left = temp;
		t->right = temp;
		temp->left = t;
	}
	display();
	return 0;
}

int insertbef()
{
	int ele;
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	if (start == NULL)
	{
		printf("\nLinked List is Empty\n");
		return 0;
	}
	printf("\nEnter the element                : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	t = start;
	if (t->info == ele)
	{
		start->left = temp;
		temp->right = start;
		start = temp;
	}
	else
	{
		while (t->info != ele)
		{
			if (t->right == NULL)
			{
				printf("\nElement not found\n");
				return 0;
			}
			t = t->right;
		}
		temp->left = t->left->right;
		temp->right = t;
		t->left->right = temp;
		t->left = temp;
	}
	display();
	return 0;
}

int insertaft()
{
	int ele;
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	if (start == NULL)
	{
		printf("\nLinked List is Empty\n");
		return 0;
	}
	printf("\nEnter the element                : ");
	scanf("%d",&temp->info);
	temp->right = NULL;
	temp->left = NULL;
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	t = start;
	while (t->info != ele)
	{
		if (t->right == NULL)
		{
			printf("\nElement not found\n");
			return 0;
		}
		t = t->right;
	}
	temp->right = t->right;
	temp->left = t;
	if (t->right != NULL)
		t->right->left = temp;
	t->right = temp;
	display();
	return 0;
}

int deletebeg()
{
	struct node *temp=start;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	if (start->right != NULL)
		start->right->left = NULL;
	start = start->right;
	free(temp);
	display();
	return 0;
}

int deleteend()
{
	struct node *temp=start;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	while (temp->right != NULL)
		temp = temp->right;
	if (temp->left != NULL)
		temp->left->right = NULL;
	else
		start = NULL;
	free(temp);
	display();
	return 0;
}

int deletepos()
{
	int pos,i;
	struct node *temp=start;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("Enter the position : ");
	scanf("%d",&pos);
	if (pos == 1)
	{
		if (start->right != NULL)
			start->right->left = NULL;
		start = start->right;
		free(temp);
		display();
		return 0;
	}
	for (i=1; i<pos-1; ++i)
	{
		if (temp->right == NULL)
		{
			printf("\nPosition does not exist\n");
			return 0;
		}
		temp = temp->right;
	}
	if (temp->right->right != NULL)
		temp->right->right->left = temp;
	temp->right = temp->right->right;
	display();
	return 0;
}


int deletebef()
{
	int ele;
	struct node *temp=start,*t;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	if (temp->info == ele)
	{
		printf("\nNo node before specified element\n");
		return 0;
	}
	if (temp->right->info == ele)
	{
		start = start->right;
		start->left = NULL;
		free(temp);
		display();
		return 0;
	}
	while (temp->info != ele)
	{
		if (temp->right == NULL)
		{
			printf("\nElement not found\n");
			return 0;
		}
		temp = temp->right;
	}
	t = temp->left;
	temp->left->left->right = temp;
	temp->left = temp->left->left;
	free(t);
	display();
	return 0;
}

int deleteaft()
{
	int ele;
	struct node *temp=start,*t;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	while (temp->info != ele)
	{
		if (temp->right == NULL)
		{
			printf("\nElement not found\n");
			return 0;
		}
		temp = temp->right;
	}
	if (temp->right == NULL)
	{
		printf("\nNo node after specified node\n");
		return 0;
	}
	t = temp->right;
	if (temp->right->right != NULL)
		temp->right->right->left = temp;
	temp->right = temp->right->right;
	free(t);
	display();
	return 0;
}

int display()
{
	struct node *temp=start;
	if (start == NULL)
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

