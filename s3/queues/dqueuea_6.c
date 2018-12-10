/*Program to represent double-ended queue using arrays and to implement it's operations*/

#include<stdio.h>
#include<stdlib.h>

int inf(int *Q);
int outf(int *Q);
int inr(int *Q);
int outr(int *Q);
int display(int *Q);

int size,front=-1,rear=-1;

int main()
{
	int *Q,op;
	printf("\nEnter the size of the queue : ");
	scanf("%d",&size);
	Q=(int*)malloc(size*sizeof(int));
	do
	{
		printf("\n\n\nMENU:-\n1. Insert at rear\n2. Delete from front\n3. Insert at front\n4. Delete from rear\n5. Display\n6. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				inr(Q);
				break;
				
			case 2 :
				outf(Q);
				break;
			
			case 3 :
				inf(Q);
				break;
				
			case 4 :
				outr(Q);
				break;
					
			case 5 :
				display(Q);
				break;
				
			case 6 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int inr(int *Q)
{
	int item,next;
	next = (rear+1)%size;
	if (front == next)
	{
		printf("\nQueue is full\n");
		return 0;
	}
	printf("\nEnter the element : ");
	scanf("%d",&item);
	if (front == -1 && rear == -1)
		front = front+1;
	rear = (rear+1)%size;
	Q[rear]=item;
	display(Q);
	return 0;
}

int outf(int *Q)
{
	int item;
	if (front == -1 && rear == -1)
		{
			printf("\nQueue is empty\n");
			return 0;
		}
	item=Q[front];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front+1)%size;
	printf("\nElement %d has been deleted\n",item);
	display(Q);
	return 0;
}

int inf(int *Q)
{
	int item,next;
	if (front == 0)
		next = size-1;
	else
		next = front - 1;
	if (next == rear)
	{
		printf("\nQueue is full\n");
		return 0;
	}
	printf("\nEnter the element : ");
	scanf("%d",&item);
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
		front=next;
	Q[front] =  item;
	display(Q);
	return 0;
}

int outr(int *Q)
{
	int item;
	if (front == -1 && rear == -1)
		{
			printf("\nQueue is empty\n");
			return 0;
		}
	if (front == rear)
	{
		item = Q[rear];
		front = -1;
		rear = -1;
		printf("\nElement %d has been deleted\n",item);
		display(Q);
		return 0;
	}
	item = Q[rear];
	if (rear == 0)
		rear = size - 1;
	else
		rear = rear - 1;
	printf("\nElement %d has been deleted\n",item);
	display(Q);
	return 0;
}

int display(int *Q)
{
	int i=front;
	if (front == -1 && rear == -1)
		{
			printf("\nQueue is empty\n");
			return 0;
		}
	printf("\nQUEUE:-\n");
	while (1)
	{
		printf("%d  ",*(Q+i));
		if (i == rear)
			break;
		i=(i+1)%size;
	}
	return 0;
}

/*
13816@fisat:/mnt/13816/s3ds$ ./dqueuea_6

Enter the size of the queue : 4



MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Enter the element : 10

QUEUE:-
10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 3

Enter the element : 100

QUEUE:-
100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 5

QUEUE:-
100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Enter the element : 20

QUEUE:-
100  10  20  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 3   

Enter the element : 110

QUEUE:-
110  100  10  20  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 5

QUEUE:-
110  100  10  20  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Queue is full



MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 3

Queue is full



MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 4

Element 20 has been deleted

QUEUE:-
110  100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Enter the element : 120

QUEUE:-
110  100  10  120  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 4

Element 120 has been deleted

QUEUE:-
110  100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 3

Enter the element : 111

QUEUE:-
111  110  100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 2

Element 111 has been deleted

QUEUE:-
110  100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 2

Element 110 has been deleted

QUEUE:-
100  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 2

Element 100 has been deleted

QUEUE:-
10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 3

Enter the element : 122

QUEUE:-
122  10  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Enter the element : 222

QUEUE:-
122  10  222  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 1

Enter the element : 333

QUEUE:-
122  10  222  333  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 5

QUEUE:-
122  10  222  333  


MENU:-
1. Insert at rear
2. Delete from front
3. Insert at front
4. Delete from rear
5. Display
6. Exit
Enter your choice : 6
13816@fisat:/mnt/13816/s3ds$ 
*/

