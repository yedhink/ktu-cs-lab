/*Program to perform Quick Sort*/

#include<stdio.h>
#include<stdlib.h>

int disp(int a[100],int n);
int quicksort(int a[100],int n,int first,int last);

int s=1;

int main(){
	int a[100],n,i;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	printf("\nEnter the elements :-\n");
  	for (i=0;i<n;++i)
    	scanf("%d",&a[i]);
    printf("\nEntered Array:-\n");
    disp(a,n);
    quicksort(a,n,0,n-1);
    printf("\nSorted Array:-\n");
  	disp(a,n);
    return 0;
}

int quicksort(int a[100],int n,int first,int last){
	int i,j,t,pivot;
	if (first < last){
		pivot = a[first];
		i = first;
		j = last;
		while (i<j){
			while (a[i]<=pivot && i<last)
				++i;
			while (a[j]>=pivot && j>first)
				--j;
			if (i<j){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		t = a[j];
		a[j] = a[first];
		a[first] = t;
		printf("\nPass %d:-\n",s++);
		disp(a,n);
		quicksort(a,n,first,j-1);
		quicksort(a,n,j+1,last);
	}
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
2
4
6
1
7
3
5

Entered Array:-
2  4  6  1  7  3  5  

Pass 1:-
1  2  6  4  7  3  5  

Pass 2:-
1  2  3  4  5  6  7  

Pass 3:-
1  2  3  4  5  6  7  

Pass 4:-
1  2  3  4  5  6  7  

Sorted Array:-
1  2  3  4  5  6  7  
*/
