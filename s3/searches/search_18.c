/*Program to implement searching mathods*/

#include<stdio.h>
#include<stdlib.h>

int accept(int a[100],int);
int linsearch(int a[100],int);
int binsearch(int a[100],int);
int disp(int a[100],int);
int sort(int a[100],int);

int main(){
	int a[100],n,op;
  	printf("\nEnter the no. of elements : ");
  	scanf("%d",&n);
  	do{
  		printf("\n\nMENU:-\n1. Linear Search\n2. Binary Search\n3. Exit");
  		printf("\nEnter your choice : ");
  		scanf("%d",&op);
  		if (op == 1){
  			accept(a,n);
  			printf("\nThe entered array is :-\n");
  			disp(a,n);
  			linsearch(a,n);
  		}
  		else if (op == 2){
  			accept(a,n);
  			printf("\nThe entered array is :-\n");
  			disp(a,n);
  			sort(a,n);
  			printf("\nThe sorted array is :-\n");
  			disp(a,n);
  			binsearch(a,n);
  		}
  		else if (op == 3)
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

int linsearch(int a[100],int n){
	int ele,i,flag=0;
  	printf("\nEnter the element to be searched : ");
  	scanf("%d",&ele);
  	for (i=0;i<n;++i)
    	if (a[i]==ele){
    		printf("\nElement found at postion %d\n",i+1);
			flag=1;
			break;
     	}
  	if (flag==0)
    	printf("\nElement not present\n");
  	return 0;
}

int sort(int a[100],int n){
  int i,j,t;
  for (i=0;i<n-1;++i)
  	for (j=0;j<n-i-1;++j)
      if (a[j]>a[j+1]){
	  	t=a[j];
	  	a[j]=a[j+1];
	  	a[j+1]=t;
	  }
  return 0;
}

int binsearch(int a[100],int n){
  int ele,beg=0,last=n-1,mid;
  printf("\nEnter the element to be searched : ");
  scanf("%d",&ele);
  while (beg<=last){
  	mid=(beg+last)/2;
    if (a[mid]==ele){
    	printf("\nElement found at postion %d\n",mid+1);
    	break;
	}
	else if (ele>a[mid])
	    beg=mid+1;
	else
	    last = mid-1;
  }
  if (beg>last)
    printf("\nElement not present\n");
  return 0;
}

/*
OUTPUT:-

13816@fisat:/mnt/13816/s3ds$ ./linsearch_22

Enter the no. of elements : 8

Enter the elements :-
4
6
2
9
12
56
8
3

The entered array is :-
4  6  2  9  12  56  8  3  
Enter the element to be searched : 12

Element found at postion 5
13816@fisat:/mnt/13816/s3ds$ 
*/
