/*Program to represent a graph and implement it's traversal methods*/

#include<stdio.h>
#include<stdlib.h>

struct vertex{
	int info;
	struct vertex *v,*next;
};
struct vertex *graph = NULL,*stack[50],*queue[50];
int top=-1,front=-1,rear=-1,visit[50],num=-1;


int insert_vertex(struct vertex *g,int item);
int insert_node(struct vertex *p,int item);
int push(struct vertex *g);
struct vertex* pop();
int enqueue(struct vertex *g);
struct vertex* dequeue();
int search(int no);
struct vertex* gptr(struct vertex *g);
int dfs();


int main(){
	int item,i;
	//printf("\nEnter the first vertex : ");
	//scanf("%d",&item);
	insert_vertex(graph,1);
	do{
		printf("\n\nMENU:-\n1. Depth First Search\n2. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&i);
		switch(i){
			case 1 : 
				printf("\nDFS Traversal:-\n");
				dfs();
				printf("\n");
				break;
			
			case 2:
				exit(0);
			default :
				printf("\nInvalid Choice\n");
		}
	}while(1);
	return 0;
}

int insert_vertex(struct vertex *g,int item){
	struct vertex *new;
	int obj,f=0,ch;
	char op;
	new = (struct vertex*)malloc(sizeof(struct vertex));
	new->info = item;
	new->v = NULL;
	new->next = NULL;
	if (graph == NULL)
		graph = new;
	else
		g = new;
	if (graph == NULL)
		printf("\nGraph is empty\n");
	do{
		if (f == 0)
			printf("\nDoes vertex %d have any adjacent vertices?? (y/n) : ",new->info);
		else
			printf("\nDoes vertex %d have any more adjacent vertices?? (y/n) : ",new->info);
		setbuf(stdin,NULL);
		scanf("%c",&op);
		if (op=='y'||op=='Y'){
			printf("Enter the adjacent vertex : ");
			scanf("%d",&obj);
			insert_node(new,obj);
			f = 1;
		}	
	}while(op=='y'||op=='Y');
	printf("\nDoes the graph have another vertex?? (If yes, enter 1) : ");
	scanf("%d",&ch);
	if (ch==1){
		printf("Enter the next vertex : ");
		scanf("%d",&item);
		insert_vertex(new->next,item);
	}
	return 0;
}

int insert_node(struct vertex *p,int item){
	struct vertex *new,*temp = p->v;
	new = (struct vertex*)malloc(sizeof(struct vertex));
	new->info = item;
	new->v = NULL;
	new->next = NULL;
	while (temp!=NULL)
		temp = temp->v;
	temp = new;
	return 0;
}

int dfs(){
	struct vertex *temp = graph,*ptr;
	if (graph == NULL){
		printf("\nGraph is empty\n");
		return 0;
	}
	push(temp);
	while (top!=-1){
		temp = gptr(pop());
		if (search(temp->info) == 0){
			visit[++num]=temp->info;
			printf("%d  ",temp->info);
			ptr = temp->v;
			while (ptr!=NULL){
				push(ptr);
				ptr = ptr->v;
			}	
		}
	}
	return 0;
}



struct vertex* gptr(struct vertex *g){
	struct vertex *temp = graph;
	while (temp->info != g->info && temp!=NULL)
		temp = temp->next;
	return temp;
}



int search(int no){
	int i;
	for (i=0;i<=num;++i)
		if (visit[i]==no)
			return 1;
	return 0;
}

int push(struct vertex *g){
	top = top + 1;
	stack[top] = g;
	return 0;
}

struct vertex* pop(){
	if (top == -1)
		return NULL;
	else
		return(stack[top--]);
}

int enqueue(struct vertex *g){
	if (rear == -1)
		front = front + 1;
	rear = rear + 1;
	queue[rear] = g;
	return 0;	
}

struct vertex* dequeue(){
	struct vertex *temp;
	if (front==rear){
		temp = queue[front];
		front = -1;
		rear = -1;
		return temp;
	}
	return queue[front++];
}
