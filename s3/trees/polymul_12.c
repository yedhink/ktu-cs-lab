#include<stdio.h>
#include<stdlib.h>

struct node
{
	int c,e;
	struct node *link;
};

struct node *startr = NULL,*temp = NULL,*tempr = NULL;

struct node* createpoly();
int multiply(struct node *p,struct node *q);
int result(int coeff,int exp);
int display(struct node *ptr);

int main()
{
	struct node *poly1, *poly2;
	printf("\nPolynomial 1:-");
	poly1 = createpoly();
	printf("\nPolynomial 2:-");
	poly2 = createpoly();
	multiply(poly1,poly2);
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

int multiply(struct node *p,struct node *q)
{
	struct node *temp1,*t=p;
	while (t!=NULL)
	{
		temp1 = q;
		while (temp1!=NULL)
		{
			result(t->c*temp1->c,t->e+temp1->e);
			temp1 = temp1->link;
		}
		t = t->link;
	}
	return 0;
}

int result(int coeff,int exp)
{
	struct node *t=startr,*ptr;
	printf("\nC = %d , E = %d ",coeff,exp);
	while (t!=NULL)
	{
		if (t->e == exp)
		{
			t->c = t->c +coeff;
			return 0;
		}
		t = t->link;
	}
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
