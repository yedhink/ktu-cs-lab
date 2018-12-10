/*Program to represent queue using arrays and to implement it's operations*/

#include<stdio.h>
#include<stdlib.h>

int enqueue(int *Q);
int dequeue(int *Q);
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
		printf("\n\n\nMENU:-\n1. ENQUEUE\n2. DEQUEUE\n3. Display\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				enqueue(Q);
				break;
				
			case 2 :
				dequeue(Q);
				break;
				
			case 3 :
				display(Q);
				break;
				
			case 4 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int enqueue(int *Q)
{
	int item;
	if (rear == size-1)
	{
		printf("\nQueue is full\n");
		return 0;
	}
	printf("\nEnter the element : ");
	scanf("%d",&item);
	if (front == -1 && rear == -1)
		front = front+1;
	rear = rear + 1;
	Q[rear]=item;
	display(Q);
	return 0;
}

int dequeue(int *Q)
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
		front = front+1;
	printf("\nElement %d has been deleted\n",item);
	display(Q);
	return 0;
}
int display(int *Q)
{
	int i;
	if (front == -1 && rear == -1)
		{
			printf("\nQueue is empty\n");
			return 0;
		}
	printf("\nQUEUE:-\n");
	for (i=front;i<=rear;++i)
		printf("%d  ",*(Q+i));
	return 0;
}

/*
13816@fisat:/mnt/13816/s3ds$ ./queuea_4

Enter the size of the queue : 3



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 2

Queue is empty



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 3

Queue is empty



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 1

Enter the element : 45

QUEUE:-
45  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 1

Enter the element : 56

QUEUE:-
45  56  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 1

Enter the element : 89

QUEUE:-
45  56  89  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
*/
Enter your choice : 1

Queue is full



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 2

Element 45 has been deleted

QUEUE:-
56  89  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 1

Queue is full



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 2

Element 56 has been deleted

QUEUE:-
89  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 2

Element 89 has been deleted

Queue is empty



MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 1

Enter the element : 45

QUEUE:-
45  


MENU:-
1. ENQUEUE
2. DEQUEUE
3. Display
4. Exit
Enter your choice : 4

