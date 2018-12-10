//Program to Convert an Infix Expression to Prefix form and it's evaluation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char postexp[50];
char stack[50];
int top = -1;
int flag = 0;

int push(char x);
char pop();
int output(char item);
int icp(char x);
int isp(char x);
int convert(char exp[50]);
int evaluate();
char* rev(char s[]);
int len(char s[]);

int main(){
	char exp[50];
	int p=0,q,result;
	puts(postexp);
	printf("\nEnter the expression :-\n");
	__fpurge(stdin);
	gets(exp);
	for (q=0;exp[q]!='\0';++q);
	rev(exp);
	exp[q]='(';
	exp[q+1] = '\0';
	convert(exp);
	rev(postexp);
	printf("\nPrefix form:-\n");
	puts(postexp);
	for (p=0;postexp[p]!='\0';++p)
		if (isalnum(postexp[p])){
			printf("\nEnter the value of operand %c : ",postexp[p]);
			__fpurge(stdin);
			scanf("%c",&postexp[p]);
		}
	result = evaluate();
	printf("Result = %d\n\n",result);
	return 0;
}


int convert(char exp[50]){
	char x,item;
	int i=0;
	push(')');
	while (top > -1){
		item = exp[i];
		x = pop();
		if (isalnum(item)){
			push(x);
			output(item);
		}
		else if (item == '('){
			while (x != ')'){
				output(x);
				x = pop();
			}
		}
		else if (isp(x)>icp(item)){
			while (isp(x)>icp(item)){
				output(x);
				x = pop();
			}
			push(x);
			push(item);
		}
		else if (isp(x)<=icp(item)){
			push(x);
			push(item);
		}
		else 
			printf("\nInvalid Symbol\n");
		++i;
	}
}

int evaluate(){
	char item,op,x,y,w;
	int i=0,t=0,u,v;
	rev(postexp);
	item = postexp[i];
	while (item != '\0'){
		if (isalnum(item))
			push(item);
		else{
			op = item;
			x = pop();
			y = pop();
			u = x - '0';
			v = y - '0';
			switch (op){
				case '+' : t = u + v; break;
				case '-' : t = u - v; break;
				case '*' : t = u * v; break;
				case '/' : t = u / v; break;
				case '^' : t = pow(u,v); break;
			}
			w = t + '0';
			push(w);
		}
		i = i+1;
		item = postexp[i];
	}
	x = pop();
	u = x - '0';
	return u;
}

int push(char e){
	top = top + 1;
	stack[top] = e;
	return 0;
}

char pop(){
	if (top == -1)
		printf("\nStack is empty\n");
	else
		return(stack[top--]);
}

int output(char item){
	int j=0;
	if (flag == 1)
		for (j=0;postexp[j]!='\0';++j);
	postexp[j] = item;
	postexp[j+1] = '\0';
	flag = 1;
}

int isp(char e){
	switch(e){
	case '+' :
	case '-' : return 2;
	case '*' :
	case '/' : return 4;
	case '^' : return 5;
	case ')' : return 0;
	default  : 
		if (isalnum(e))
			return 8;		
	}
}

int icp(char e){
	switch(e){
	case '+' :
	case '-' : return 1;
	case '*' :
	case '/' : return 3;
	case '^' : return 6;
	case ')' : return 9;
	case '(' : return 0;
	default  : 
		if (isalnum(e))
			return 7;		
	}
}

int len(char s[]){
	int len=0;
	while(s[len]!=0)
		len++;
	return len;
}

char* rev(char s[]){
	int i,j=0;
	char temp;
	for(i=len(s)-1 ; i>len(s)/2 - 1 ; i--,j++){
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
	}
	return s; 
}

/*
OUTPUT:-

13816@fisat:/mnt/13816/s3ds$ ./intopre_16


Enter the expression :-
A/B+(C-D)*E

Prefix form:-
+/AB*-CDE

Enter the value of operand A : 4

Enter the value of operand B : 2

Enter the value of operand C : 5

Enter the value of operand D : 3

Enter the value of operand E : 6
Result = 14

13816@fisat:/mnt/13816/s3ds$ 
*/
