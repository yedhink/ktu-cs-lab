#include<stdio.h>
#include<stdlib.h>

struct node
{
	int c,e;
	struct node *link;
};

struct node *startr = NULL,*temp = NULL,*tempr = NULL;

struct node* createpoly();
int polyadd(struct node *p,struct node *q);
int result(int coeff,int exp);
int display(struct node *ptr);

int main()
{
	struct node *poly1, *poly2;
	printf("\nPolynomial 1:-");
	poly1 = createpoly();
	printf("\nPolynomial 2:-");
	poly2 = createpoly();
	polyadd(poly1,poly2);
	printf("\nPolynomial 1:-\n");
	display(poly1);
	printf("\nPolynomial 2:-\n");
	display(poly2);
	printf("\nResult:-\n");
	display(startr);
	return 0;

} 

struct node* createpoly()
{
	int n,i;
	struct node *start = NULL,*ptr;
	printf("\nEnter the number of terms : ");
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("Coefficient of term %d : ",i);
		scanf("%d",&ptr->c);
		printf("Exponent of term %d    : ",i);
		scanf("%d",&ptr->e);
		ptr->link = NULL;
		
		if (start == NULL)
			start = ptr;
		else 
			temp->link = ptr;
		temp = ptr;
	}
	return start;
}

int polyadd(struct node *p,struct node *q)
{
	while (p!=NULL && q!=NULL)
	{
		if (p->e == q->e)
		{
			result(p->c+q->c,p->e);
			p = p->link;
			q = q->link;
		}
		else if (p->e > q->e)
		{
			result(p->c,p->e);
			p = p->link;
		}
		else
		{
			result(q->c,q->e);
			q = q->link;
		}
	}
	while (p!=NULL)
	{
		result(p->c,p->e);
		p = p->link;
	}
	while (q!=NULL)
	{
		result(q->c,q->e);
		q = q->link;
	}
}

int result(int coeff,int exp)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->c = coeff;
	ptr->e = exp;
	ptr->link = NULL;
	if (startr == NULL)
		startr = ptr;
	else
		tempr->link = ptr;
	tempr = ptr;
	return 0;
}

int display(struct node *ptr)
{
	struct node *temp = ptr;
	int i=1;
	while (temp!=NULL)
	{
		if (temp->link == NULL)
			printf("%dx^%d\n",temp->c,temp->e);
		else
			printf("%dx^%d + ",temp->c,temp->e);
		i++;
		temp = temp->link;
	}
	printf("\n");
	return 0;
}
