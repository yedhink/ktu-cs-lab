#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *lc,*rc;
};

struct node *root = NULL;

int insertion();
int deletion(int item);
int search(int item);
int inorder(struct node *ptr);
int preorder(struct node *ptr);
int postorder(struct node *ptr);
struct node* successive(struct node *ptr);

int main(){
	int op,item,flag;
	do
	{
		printf("\n\n\nMENU:-\n1. Insert an element\n2. Delete an element\n3. Search for an element\n4. Inorder Traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&op);
		
		switch (op)
		{
			case 1 :
				insertion();
				break;
				
			case 2 :
				printf("\nEnter the element : ");
				scanf("%d",&item);
				deletion(item);
				inorder(root);
				break;
			
			case 3 :
				printf("\nEnter the element : ");
				scanf("%d",&item);
				flag = search(item);
				if (flag == 0)
					printf("\nItem does not exist\n");
				else
					printf("\nItem found\n");
				break;
				
			case 4 :
				inorder(root);
				printf("\n");
				break;
					
			case 5 :
				preorder(root);
				printf("\n");
				break;
				
			case 6 :
				postorder(root);
				printf("\n");
				break;
				
			case 7 :
				exit(0);
				
			default:
				printf("\nIvalid Choice");
		}
		
	}while(1);
	return 0;
}

int insertion(){
	struct node *ptr,*parent,*temp=root;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&ptr->info);
	ptr->rc = NULL;
	ptr->lc = NULL;
	if (root==NULL){
		root = ptr;
		inorder(root);
		return 0;
	}
	while (temp!=NULL){
		parent = temp;
		if (ptr->info<temp->info)
			temp = temp->lc;
		else
			temp = temp->rc;
	}
	if (ptr->info < parent->info)
		parent->lc = ptr;
	else
		parent->rc = ptr;
	inorder(root);
	return 0;
}

int deletion(int item){
	int flag=0,op,n;
	struct node *parent,*ptr,*temp = root;
	while (temp!=NULL && flag==0){
		if (item < temp->info){
			parent = temp;
			temp = temp->lc;
		}
		else if (item == temp->info)
			flag = 1;
		else{
			parent = temp;
			temp = temp->rc;
		}
	}
	if (flag == 0){
		printf("\nItem does not exist\n");
		return 0;
	}
	
	if (temp->lc == NULL && temp->rc == NULL){
		if (parent->lc == temp)
			parent->lc = NULL;
		else 
			parent->rc = NULL;
		free(temp);
	}
	else if (temp->lc != NULL && temp->rc != NULL){
		ptr = successive(temp);
		n = ptr->info;
		deletion(ptr->info);
		temp->info = n;
	}
	else{
		if (parent->lc == temp)
			if (temp->lc == NULL)
				parent->lc = temp->rc;
			else
				parent->lc = temp->lc;
		else
			if (temp->lc == NULL)
				parent->rc = temp->rc;
			else
				parent->rc = temp->lc;
		free(temp);
	}
}

int search(int item){
	int flag = 0;
	struct node *temp = root;
	while (temp!=NULL && flag==0){
		if (item < temp->info)
			temp = temp->lc;
		else if (item == temp->info)
			flag = 1;
		else
			temp = temp->rc;
	}
	return flag;
}

int inorder(struct node *ptr){
	if (ptr != NULL){
		inorder(ptr->lc);
		printf("%d  ",ptr->info);
		inorder(ptr->rc);
	}
	return 0;
}

int preorder(struct node *ptr){
	if (ptr != NULL){
		printf("%d  ",ptr->info);
		preorder(ptr->lc);
		preorder(ptr->rc);
	}
	return 0;
}
int postorder(struct node *ptr){
	if (ptr != NULL){
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d  ",ptr->info);
	}
	return 0;
}

struct node* successive(struct node *ptr){
	struct node *temp = ptr->rc;
	if (temp != NULL)
		while (temp->lc != NULL)
			temp = temp->lc;
	return(temp);
}
