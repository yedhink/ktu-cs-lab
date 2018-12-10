/*Program to perform heap sort*/

#include<stdio.h>
#include<stdlib.h>

int insertion(int item);
int heapsort();

int n=-1,num;
int a[50];

int main(){
	int i;
	printf("\nEnter the number of elements : ");
	scanf("%d",&num);
	printf("\nEnter the elements of the array:-\n");
	for (i=0;i<num;++i){
	  	printf("Enter element %d : ",i+1);
	 	scanf("%d",&a[i]);
	 	insertion(a[i]);
	}
	printf("\nEntered elements:-\n");
	for (i=0;i<=n;++i)
		printf("%d  ",a[i]);
	printf("\n");
	heapsort();
	printf("\n\nSorted elements:-\n");
	for (i=0;i<=n;++i)
		printf("%d  ",a[i]);
	printf("\n");
	return 0;
}

int insertion(int item){
	int i,p,temp;
	n = n+1;
	a[n] = item;
	i =n;
	p = i/2;
	while (p>=0 && a[i]>a[p]){
		temp = a[i];
		a[i] = a[p];
		a[p] = temp;
		i = p;
		p = p/2;
	}
	return 0;
}

int heapsort(){
	int i=n,j,lc,rc,x,y,t,p,q=1;
	while (i>0){
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		i = i-1;
		j=0;
		while (j<i){
			lc = 2*j+1;
			rc = 2*j+2;
			if (lc <= i)
				x = a[lc];
			else
				x = -32676;
			if (rc <= i)
				y = a[rc];
			else
				y = -32676;
			if (x>=y & a[j]<=x){
				t = a[j];
				a[j] = a[lc];
				a[lc]=t;
				j = lc;
			}
			else if (y>x && a[j]<=y){
				t = a[j];
				a[j] = a[rc];
				a[rc] = t;
				j = rc;
			}
			else
				break;
		}
	printf("\nPass %d:-\n",q);
	for (p=0;p<=n;++p)
    	printf("%d  ",a[p]);	
    q++;
	}
	return 0;
}
