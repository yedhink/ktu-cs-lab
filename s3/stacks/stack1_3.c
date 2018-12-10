#include<stdio.h>
#include<stdlib.h>

int push(int *a,int top);
int pop(int *a,int top);
int disp(int *a,int top);

int size;

int main()
{
	int *a,top=-1,op;
	printf("\nEnter the size of the stack : ");
	scanf("%d",&size);
	a=(int*)malloc(size*sizeof(int));
	do
	{
		printf("\n\n\nMENU:-\n1. Push\n2. Pop\n3. Display\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				top=push(a,top);
				break;
				
			case 2 :
				top=pop(a,top);
				break;
				
			case 3 :
				disp(a,top);
				break;
				
			case 4 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int push(int *a,int top)
{
	int item;
	if (top==size-1)
		printf("\nStack is full\n");
	else
	{
		printf("\nEnter the element to be inserted : ");
		scanf("%d",&item);
		top++;
		a[top]=item;
		disp(a,top);
	}
	return top;
}

int pop(int *a,int top)
{
	int item;
	if (top==-1)
		printf("\nStack is empty");
	else
	{
		item=a[top];
		top--;
		printf("\nElement %d deleted\n",item);
		disp(a,top);
	}
	return top;
}

int disp(int *a,int top)
{
	int i;
	if (top==-1)
		printf("\nStack is empty\n");
	else
	{
		printf("\nSTACK:-\n");
		for (i=0;i<=top;++i)
			printf("%d  ",a[i]);
	}
	return 0;
}
