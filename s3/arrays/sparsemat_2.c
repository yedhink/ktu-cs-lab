#include<stdio.h>

int accept(int a[25][25],int r,int c);
int disp(int a[25][25],int r,int c);

int main()
{
	int a[25][25],spar[25][25],r,c,i,j,nonzero=0;
	
	printf("\nEnter the no. of rows    : ");
	scanf("%d",&r);
	printf("Enter the no. of columns : ");
	scanf("%d",&c);
		
	accept(a,r,c);
	printf("\nEntered matrix:-\n");
	disp(a,r,c);
	
	for(i=0;i<r;++i)
		for (j=0;j<c;++j)
			if (a[i][j]!=0)
			{
				++nonzero;
				spar[nonzero][0]=i;
				spar[nonzero][1]=j;
				spar[nonzero][2]=a[i][j];
			}
			
	spar[0][0]=r;
	spar[0][1]=c;
	spar[0][2]=nonzero;
			
	printf("\nSPARSE MATRIX :-\n");
	disp(spar,nonzero+1,3);
	return 0;
	
}

int accept(int a[25][25],int r,int c)
{
	int i,j;
	printf("\nEnter the matrix:-\n");
	for (i=0;i<r;++i)
		for (j=0;j<c;++j)
		{
			printf("Element[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	return 0;
}

int disp(int a[25][25],int r,int c)
{
	int i,j;
	for (i=0;i<r;++i)
	{
		for (j=0;j<c;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}

