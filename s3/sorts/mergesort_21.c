/*Program to perform Merge Sort*/

#include<stdio.h>
#include<stdlib.h>

int disp(int a[100],int n);
int mergesort(int a[100],int n,int low,int high);
int merge(int a[100],int low, int mid, int high);

int s=0;

int main(){
	int a[100],n,i;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	printf("\nEnter the elements :-\n");
  	for (i=0;i<n;++i)
    	scanf("%d",&a[i]);
    printf("\nEntered Array:-\n");
    disp(a,n);
    mergesort(a,n,0,n-1);
    printf("\nSorted Array:-\n");
  	disp(a,n);
    return 0;
}

int mergesort(int a[100],int n,int low,int high){
	int mid;
	if (low<high){
		mid = (low+high)/2;
		mergesort(a,n,low,mid);
		mergesort(a,n,mid+1,high);
		merge(a,low,mid,high);
		printf("\nPass %d:-\n",++s);
		disp(a,n);
	}
	return 0;
}

int merge(int a[100],int low, int mid, int high){
	int k=low,i=low,j=mid+1,b[100];
	while (i<=mid && j<=high){
		if (a[i]<=a[j]){
			b[k] = a[i];
			++i;
		}
		else{
			b[k] = a[j];
			++j;
		}
		++k;
	}
	while (i<=mid){
		b[k] = a[i];
		++i;
		++k;
	}
	while (j<=high){
		b[k] = a[j];
		++j;
		++k;
	}
	for (i=low;i<=high;++i)
		a[i] = b[i];
	return 0;
}

int disp(int a[100],int n){
	int i;
	for (i=0;i<n;++i)
    	printf("%d  ",a[i]);
    printf("\n");
}

/*
OUTPUT:-


Enter the number of elements : 7

Enter the elements :-
6
4
7
1
2
3
5

Entered Array:-
6  4  7  1  2  3  5  

Pass 1:-
4  6  7  1  2  3  5  

Pass 2:-
4  6  1  7  2  3  5  

Pass 3:-
1  4  6  7  2  3  5  

Pass 4:-
1  4  6  7  2  3  5  

Pass 5:-
1  4  6  7  2  3  5  

Pass 6:-
1  2  3  4  5  6  7  

Sorted Array:-
1  2  3  4  5  6  7  
*/
