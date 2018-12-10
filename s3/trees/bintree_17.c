//To build and Perform the Operations of a Binary tree

#include<stdio.h>
#include<stdlib.h>

int a[100];
int size=0;

int inorder(int i);
int build_tree(int i,int item);
int search(int i,int item);
int insertion();
int deletion(int item);

int main(){
	int op,item,flag;
	do
	{
		printf("\n\n\nMENU:-\n1. Build a Tree\n2. Insert an element\n3. Delete an element\n4. Search for an element\n5. Inorder Traversal\n6. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				printf("\nEnter the root element : ");
				scanf("%d",&item);
				build_tree(0,item);
				printf("\n\nInorder Traversal:-\n");
				inorder(0);
				break;
			
			case 2 :
				insertion();
				break;
			
			case 3 :
				printf("\nEnter the element : ");
				scanf("%d",&item);
				deletion(item);
				//inorder(0);
				break;
			
			case 4 :
				printf("\nEnter the element : ");
				scanf("%d",&item);
				flag = search(0,item);
				if (flag == -1)
					printf("\nItem does not exist\n");
				else
					printf("\nItem found at node %d\n",flag+1);
				break;
				
			case 5 :
				inorder(0);
				printf("\n");
				break;
				
			case 6 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int build_tree(int i,int item){
	char op;
	a[i] = item;
	size = size+1;
	printf("\nDoes node %d have left subtree?? (Y/N) : ",i+1);
	__fpurge(stdin);
	scanf("%c",&op);
	if (op == 'Y' || op == 'y'){
		printf("Enter the element : ");
		scanf("%d",&item);
		build_tree(2*i+1,item);
	}
	printf("\nDoes node %d have right subtree?? (Y/N) : ",i+1);
	__fpurge(stdin);
	scanf("%c",&op);
	if (op == 'Y' || op == 'y'){
		printf("\nEnter the element : ");
		scanf("%d",&item);
		build_tree(2*i+2,item);
	}
	return 0;
}

int search(int i,int item){
	int x = -1;
	if (a[i]==item)
		return i;
	if (2*i+1 <= size)
		x = search(2*i+1,item);
	else
		return -1;
	if (x == -1 && 2*i+2 <= size)
		x = search(2*i+2,item);
	return x;
}

int insertion(){
	int l,item,key;
	char op;
	printf("\n Enter the value of the node after which new node has to be inserted : ");
	scanf("%d",&key);
	l = search(0,key);
	if (l == -1){
		printf("\nSearch is unsuccesful\nItem does not exist\n\n");
		return 0;
	}
	if (a[2*l+1]==0 || a[2*l+2]==0){
		printf("\nIs the item to be inserted left of right node?? (L/R)  ");
		__fpurge(stdin);
		scanf("%c",&op);
		if ((op == 'L' || op == 'l') && a[2*l+1]==0){
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&item);
			a[2*l+1] = item;
			printf("\nItem inserted\n");
			inorder(0);
		}
		else if ((op == 'R' || op == 'r') && a[2*l+2]==0){
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&item);
			a[2*l+2] = item;
			printf("\nItem inserted\n");
			inorder(0);
		}
		else 
			printf("\nDesired insertion not possible\n\n");
	}
	else 
		printf("\nLeaf node insertion not possible!!\n\n");
	return 0;
}

int deletion(int item){
	int l;
	l = search(0,item);
	if (l == -1){
		printf("\nSearch is unsuccesful\nItem does not exist\n\n");
		return 0;
	}
	if (a[2*l+1]==0 && a[2*l+2]==0){
		a[l] = 0;
		printf("\nElement Deleted\n");
		inorder(0);
	}
	else
		printf("\nThe node containing %d is not a leaf node\n\n",item);
	return 0;
}

int inorder(int i){
	if (i <= size){
		inorder(2*i+1);
		if (a[i] != 0)
			printf("%d  ",a[i]);
		inorder(2*i+2);
	}
	return 0;
}

/*
OUTPUT:-

13816@fisat:/mnt/13816/s3ds$ ./bintree_17



MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 1

Enter the root element : 1

Does node 1 have left subtree?? (Y/N) : y
Enter the element : 2

Does node 2 have left subtree?? (Y/N) : y
Enter the element : 5

Does node 4 have left subtree?? (Y/N) : n

Does node 4 have right subtree?? (Y/N) : n

Does node 2 have right subtree?? (Y/N) : y

Enter the element : 7

Does node 5 have left subtree?? (Y/N) : n

Does node 5 have right subtree?? (Y/N) : n

Does node 1 have right subtree?? (Y/N) : y

Enter the element : 3

Does node 3 have left subtree?? (Y/N) : n

Does node 3 have right subtree?? (Y/N) : y

Enter the element : 6

Does node 7 have left subtree?? (Y/N) : n

Does node 7 have right subtree?? (Y/N) : n


Inorder Traversal:-
5  2  7  1  3  6  


MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 4

Enter the element : 3

Item found at node 3



MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 4

Enter the element : 5

Item found at node 4



MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 4

Enter the element : 9

Item does not exist



MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 3

Enter the element : 2

The node containing 2 is not a leaf node




MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 2

 Enter the value of the node after which new node has to be inserted : 2

Leaf node insertion not possible!!




MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 2

 Enter the value of the node after which new node has to be inserted : 3

Is the item to be inserted left of right node?? (L/R)  r

Desired insertion not possible




MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 3

Enter the element : 7

Element Deleted
5  2  1  3  6  


MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 2

 Enter the value of the node after which new node has to be inserted : 3

Is the item to be inserted left of right node?? (L/R)  l

Enter the element to be inserted : 4

Item inserted
5  2  1  4  3  6  


MENU:-
1. Build a Tree
2. Insert an element
3. Delete an element
4. Search for an element
5. Inorder Traversal
6. Exit
Enter your choice : 6
13816@fisat:/mnt/13816/s3ds$ 
*/
