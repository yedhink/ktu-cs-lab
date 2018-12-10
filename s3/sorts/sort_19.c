/*Sorting Methods*/

#include<stdio.h>
#include<stdlib.h>

int insort(int a[100],int n);
int selsort(int a[100],int n);
int bubsort(int a[100],int n);
int accept(int a[100],int n);
int disp(int a[100],int n);

int main(){
	int a[100],n,op;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	do{
		printf("\n\nMENU:-\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit");
  		printf("\nEnter your choice : ");
  		scanf("%d",&op);
  		if (op == 1){
  			accept(a,n);
  			printf("\nEntered Array:-\n");
  			disp(a,n);
  			bubsort(a,n);
  			printf("\nSorted Array:-\n");
  			disp(a,n);
  		}
  		else if (op == 2){
  			accept(a,n);
  			printf("\nEntered Array:-\n");
  			disp(a,n);
  			selsort(a,n);
  			printf("\nSorted Array:-\n");
  			disp(a,n);
  		}
  		else if (op == 3){
  			accept(a,n);
  			printf("\nEntered Array:-\n");
  			disp(a,n);
  			insort(a,n);
  			printf("\nSorted Array:-\n");
  			disp(a,n);
  		}
  		else if (op == 4)
  			exit(0);
  		else
  			printf("\nInvalid Option\n");
	}while(1);	
	return 0;
}

int accept(int a[100],int n){
	int i;
	printf("\nEnter the elements :-\n");
  	for (i=0;i<n;++i)
    	scanf("%d",&a[i]);
    return 0;
}

int disp(int a[100],int n){
	int i;
	for (i=0;i<n;++i)
    	printf("%d  ",a[i]);
}


int insort(int a[100],int n){
	int i,j,m;
    for (i=1;i<n;++i){
    	m = a[i];
    	for (j=i-1;j>=0 && m<a[j];--j)
        	a[j+1] = a[j];
    	a[j+1] = m;
    	printf("\nPass %d:-\n",i);
    	disp(a,n);
  	}
  return 0;
}

int selsort(int a[100],int n){
	int i,j,min,t;
  	for (i=0;i<n-1;++i){
    	min = i;
    	for (j=i+1;j<n;++j)
    		if (a[j]<a[min])
    			min = j;
    	if (min != i){
    		t=a[i];
	  		a[i]=a[min];
	  		a[min]=t;
		}
		printf("\nPass %d:-\n",i);
    	disp(a,n);
  	}
  	return 0;
}

int bubsort(int a[100],int n){
	int i,j,t;
  	for (i=0;i<n-1;++i){
  		for (j=0;j<n-i-1;++j)
    	    if (a[j]>a[j+1]){
	  			t=a[j];
	  			a[j]=a[j+1];
	  			a[j+1]=t;
	  		}
	  	printf("\nPass %d:-\n",i);
	  	disp(a,n);
	  }
  return 0;
}

/*
OUTPUT:-

Enter the number of elements : 5


MENU:-
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Exit
Enter your choice : 1

Enter the elements :-
3
5
4
2
1

Entered Array:-
3  5  4  2  1  
Pass 0:-
3  4  2  1  5  
Pass 1:-
3  2  1  4  5  
Pass 2:-
2  1  3  4  5  
Pass 3:-
1  2  3  4  5  
Sorted Array:-
1  2  3  4  5  

MENU:-
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Exit
Enter your choice : 2

Enter the elements :-
4
2
3
5
1

Entered Array:-
4  2  3  5  1  
Pass 0:-
1  2  3  5  4  
Pass 1:-
1  2  3  5  4  
Pass 2:-
1  2  3  5  4  
Pass 3:-
1  2  3  4  5  
Sorted Array:-
1  2  3  4  5  

MENU:-
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Exit
Enter your choice : 3

Enter the elements :-
2
5
4
3
1

Entered Array:-
2  5  4  3  1  
Pass 1:-
2  5  4  3  1  
Pass 2:-
2  4  5  3  1  
Pass 3:-
2  3  4  5  1  
Pass 4:-
1  2  3  4  5  
Sorted Array:-
1  2  3  4  5  

MENU:-
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Exit
Enter your choice : 4

*/
