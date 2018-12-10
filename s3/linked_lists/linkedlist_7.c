/*To implement a linked list and it's operations*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
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
	if (start == NULL)
		temp->link = NULL;
	else
		temp->link = start;
	start = temp;
	display();
	return 0;
}

int insertend()
{
	struct node *t=start,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->info);
	temp->link = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		while (t->link != NULL)
			t = t->link;
		t->link = temp;
	}
	printf("\nElement added\n");
	display();
	return 0;
}

int insertpos()
{
	int pos,i;
	struct node *temp,*t=start;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element  : ");
	scanf("%d",&temp->info);
	temp->link = NULL;
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	if (pos==1)
	{
		temp->link = start;
		start = temp;
	}
	else
	{
		for (i=1;i<pos-1;++i)
			t = t->link;
		temp->link = t->link;
		t->link = temp;
	}
	display();
	return 0;
}

int insertbef()
{
	int ele;
	struct node *temp,*t=start,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element                                        : ");
	scanf("%d",&temp->info);
	printf("Enter the element before which new node is to be entered : ");
	scanf("%d",&ele);
	if (ele == t->info)
	{
		temp->link = start;
		start = temp;
		display();
		return 0;
	}
	p = t->link;
	while (p->info != ele)
	{
		t = t->link;
		p = p->link;
	}
	temp->link = t->link;
	t->link = temp;
	display();
	return 0;
}

int insertaft()
{
	int ele;
	struct node *temp,*t=start,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element                                       : ");
	scanf("%d",&temp->info);
	printf("Enter the element after which new node is to be entered : ");
	scanf("%d",&ele);
	while (t->info != ele)
		t = t->link;
	temp->link = t->link;
	t->link = temp;
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
	start = start->link;
	free(temp);
	display();
	return 0;
}

int deleteend()
{
	struct node *temp=start,*loc;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	if (temp->link == NULL)
	{
		start = NULL;
		free(temp);
		display();
		return 0;
	}
	loc = temp->link;
	while (loc->link != NULL)
	{
		temp = temp->link;
		loc = loc->link;
	}
	temp->link = NULL;
	free(loc);
	display();
	return 0;
}

int deletepos()
{
	int pos,i;
	struct node *temp=start,*loc;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("\nEnter the position of the node to be deleted : ");
	scanf("%d",&pos);
	if (pos == 1)
	{
		start = start->link;
		free(temp);
		display();
		return 0;
	}
	loc = temp->link;
	for (i=1;i<pos-1;++i)
	{
		temp = temp->link;
		loc = loc->link;
	}
	temp->link = loc->link;
	free(loc);
	display();
	return 0;

}

int deletebef()
{
	int ele;
	struct node *temp=start,*t,*p;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("\nEnter the element before which node is to be deleted : ");
	scanf("%d",&ele);
	if(temp->info == ele)
	{
		printf("\nNo node before specified position\n");
		return 0;
	}
	t = temp->link;
	if (t->info == ele)
	{
		start = start->link;
		free(temp);
		display();
		return 0;
	}
	p = t->link;
	while (p->info != ele)
	{
		temp = temp->link;
		t = t->link;
		p = p->link;
	}
	temp->link=t->link;
	free(t);
	display();
	return 0;	
}

int deleteaft()
{
	int ele;
	struct node *temp=start,*t,*p;
	if (start == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("\nEnter the element after which node is to be deleted : ");
	scanf("%d",&ele);
	t=temp->link;
	if (temp->info == ele)
	{
		temp->link = t->link;
		free(t);
		display();
		return 0;
	}
	p=t->link;
	while (t->info != ele && t->link != NULL)
	{
		t=t->link;
		p=p->link;
	}
	if (t->link==NULL)
	{
		printf("\nNo node after specified position\n");
		return 0;
	}
	t->link = p->link;
	free(p);
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
		temp = temp->link;
	}
	return 0;
}


