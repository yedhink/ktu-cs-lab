//Program to implement Undirected Graph and its Traversals
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



struct node{
	struct node* edge;
	int data;
};

struct node *vertex[50],*Q[50],*stack[50];
int top=-1,rear=-1,front=-1;
v_size=-1;
cv=0;

int build_graph();
int create_vertex(int);
int create_edge(int);
int search(int*,struct node *);
struct node* gptr(struct node*);
int push(struct node *);
struct node* pop();
int enqueue(struct node*);
struct node* dequeue();
int bfs();
int dfs();

int main(){
	int c,item;
	do{
		printf("\n\n1)Build Undirected Graph\n2)DFS\n3)BFS\n4)EXIT\n");
		printf("\nEnter Choice:- ");
		scanf("%d",&c);
		switch(c){
			case 1:build_graph();break;
			case 2:dfs();break;
			case 3:bfs();break;
			case 4:exit(0);
		}
	}while(1);
	return 0;	
}


struct node* gptr(struct node *v){
	int i=0;
	for(i=0;i<cv;++i){
		if(vertex[i]->data==v->data)
			return vertex[i];
		}
	return v;
} 

int search(int *visited,struct node* u){
	int i=0,flag=0;
	for(i=0;i<=v_size;++i){
		if(u->data==visited[i]){
			flag=1;
			break;
		}
	}
	return flag;
}
		
int push(struct node* e){
	stack[++top]=e;
	return 0;
}

struct node* pop(){
	if(top==-1)
		return NULL;
	else
		return stack[top--];
}

int dfs(){
	int visited[50];
	if(vertex[0]==0){
		printf("Graph Empty");
		return 0;
		}
	struct node* u=vertex[0];
	push(u);
	while(top!=-1){
		u=gptr(pop());
		if(search(&visited[0],u)==0){
			printf("V%d ",u->data);
			visited[++v_size]=u->data;
			while(u!=NULL){
				u=u->edge;
				if(u==NULL)
					break;
				push(u);				
				}
			}
		}
	v_size=-1;	
	return 0;
}

int enqueue(struct node* item){
	if(rear==-1)
		front=0;
	Q[++rear]=item;
	return 0;
}

struct node* dequeue(){
	int x=front;
	if(front==-1)
		return NULL;
	else{
		if(rear==front){
			rear=-1;
			front=-1;
			}
		else
			++front;
		}
	return Q[x];
}


int bfs(){
	int visited[50];
	if(vertex[0]==0){
		printf("Graph Empty");
		return 0;
		}
	struct node* u=vertex[0];
	enqueue(u);
	while(rear!=-1&&front!=-1){
		u=gptr(dequeue());
		if(search(&visited[0],u)==0){
			printf("V%d ",u->data);
			visited[++v_size]=u->data;
			while(u!=NULL){
				u=u->edge;
				if(u==NULL)
					break;
				enqueue(u);				
				}
			}
		}
	v_size=-1;	
	return 0;
}

int create_vertex(int i){
	struct node *x=(struct node*)malloc(sizeof(struct node));
	x->edge=NULL;
	printf("Enter next vertex as:- V");
	scanf("%d",&x->data);
	vertex[i]=x;
	return 0;
}	

int create_edge(int i){
	struct node *adj=(struct node*)malloc(sizeof(struct node)),*temp=vertex[i];
	adj->edge=NULL;
	printf("Enter adjacent Element of Vertex V%d:- V",vertex[i]->data);
	scanf("%d",&adj->data);
	while(temp->edge!=NULL)
		temp=temp->edge;
	temp->edge=adj;
	return 0;
}

int build_graph(){
	char c='y';
	while(c=='y'){
		create_vertex(cv);
		printf("\nDoes vertex V%d has an edge? ",vertex[cv]->data);
		__fpurge(stdin);
		scanf("%c",&c);
		while(c=='y'){
			create_edge(cv);
			printf("Is there another edge for vertex V%d? ",vertex[cv]->data);
			__fpurge(stdin);
			scanf("%c",&c);
			}
		printf("Do you want to insert more vertices?");
		__fpurge(stdin);
		scanf("%c",&c);
		printf("\n");
		++cv;
		}
	return 0;
}


