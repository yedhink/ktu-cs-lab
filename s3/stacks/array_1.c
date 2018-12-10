#include<stdio.h>
#include<stdlib.h>

int disp(int a[25],int n);
int insert(int a[25],int n);
int delete(int a[25],int n);
int search(int a[25],int n);
int sort(int a[25],int n);
int accept(int a[25],int n);

int main()
{
	int a[25],n,op;
	printf("\nEnter the no. of elements : ");
	scanf("%d",&n);
	accept(a,n);
	do
	{
		printf("\nMENU:-\n1. Display\n2. Insert\n3. Delete\n4. Search\n5. Sort\n6. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		switch (op)
		{
			case 1 :
				disp(a,n);
				break;
			
			case 2 :
				insert(a,n);
				break;
			
			case 3 :
				n=delete(a,n);
				break;
				
			case 4 : 
				search(a,n);
				break;
				
			case 5 :
				sort(a,n);
				break;
				
			case 6:
				exit(0);
				
			default :
				printf("\nInvalid Choice");
		}
	}while(1);
	return 0;
}

int accept(int a[25],int n)
{
	int i;
	printf("Enter the elements :-\n");
	for (i=0;i<n;++i)
	{
		printf("Element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	return 0;
}

int disp(int a[25],int n)
{
	int i;
	printf("\nArray :-\n");
	for (i=0;i<n;++i)
		printf("%d  ",a[i]);
	return 0;
}

int search(int a[25],int n)
{
	int i,no;
	printf("\nEnter the number to be searched : ");
	scanf("%d",&no);
	for (i=0;i<n;++i)
		if (a[i]==no)
		{
			printf("\nNumber found at position %d",i+1);
			break;
		}
	if (i>=n)
		printf("\nNumber not found\n");
	return 0;
}

int sort(int a[25],int n)
{
	int i,j,t,min;
	for (i=0;i<n-1;++i)
	{
		min=i;
		for (j=i+1;j<n;++j)
			if (a[j]<a[min])
				min=j;
		if (i!=min)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
	disp(a,n);
	return 0;
}

int insert(int a[25],int n)
{
	int i,ele,pos;
	printf("\nEnter the element to be inserted : ");
	scanf("%d",&ele);
	printf("Enter the position               : ");
	scanf("%d",&pos);
	for (i=n;i>=pos-1;--i)
	{
		a[i+1]=a[i];
		if (i==pos-1)
			a[i]=ele;
	}
	n++;
	disp(a,n);
}

int delete(int a[25],int n)
{
	int i,j,del;
	printf("\nEnter the element to be deleted : ");
	scanf("%d",&del);
	for (i=0;i<n;++i)
		if (a[i]==del)
		{
			for (j=i;j<n-1;++j)
				a[j]=a[j+1];
			--i;
			--n;
		}
	disp(a,n);
	return n;
}
