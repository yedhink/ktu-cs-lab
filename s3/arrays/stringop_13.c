//PROGRAM TO DO STRING OPERATIONS USING ARRAYS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int concat();
int rev();
int palin();
int subdel();
void display();
int len(char []);

char s[100],str2[100],sub[100];
int op=0;

int main(){
	int c;
	printf("\nMENU:-\n1. Enter String\n2. Concatanate\n3. Reverse\n4. Palindrome\n5. Search and Delete substring\n6. Display\n7. Exit");
	do{
		printf("\nEnter your choice : ");
		scanf("%d",&c);
		switch(c){
			case 1: __fpurge(stdin);
					printf("Enter String:- ");
					gets(s);
					break;	
			case 2:concat();break;
			case 3:rev();break;
			case 4:palin();break;
			case 5:subdel();break;
			case 6:display();break;
			case 7:exit(0);
			}
		}while(1);
return 0;
}

int len(char s[])
{
	int len=0;
	while(s[len]!=0)
		len++;
	return len;
}

int subdel()
{
	int m=0,search=0,k=0,flag=0,i,j;
	printf("Enter substring:- ");
	scanf("%s",&sub);
	while(s[m]!=0){
		for(i=0;s[i]!=0;++i)
		{
			flag=0;
			if(s[i]==sub[0])
			{
				for(j=i+1,k=1;sub[k]!=0;++k,++j){
					if(s[j]!=sub[k]){
						flag=1;
						break;
					}
				}
				if(flag==0)
					break;
			}
		}
		if(flag==0 && sub[k]==0)
		{
			for(j=i,k=i+len(sub);k<=len(s);++j,++k)
				s[j]=s[k];
			search=1;
			}
		m=i;
	}
	if(search==0)
		printf("Substring Not Found");
	else{
		display();
		}
	return 0;
}
		
int concat()
{
	int i=0,j=len(s);
	__fpurge(stdin);
	printf("Enter 2nd string:- ");
	gets(str2);
	while(str2[i]!=0)
	{
		s[j]=str2[i];
		i++;
		j++;
	}
	s[j]='\0';
	display();
	return 0; 
}

int rev()
{
	int i,j=0;
	char temp;
	for(i=len(s)-1 ; i>len(s)/2 - 1 ; i--)
	{
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		j++;
	}
	display();
	return 0; 
}

int palin()
{
	int i,j=0,flag=0;
	char temp;
	for(i=len(s)-1 ; i>(len(s)/2) ; i--)
		if(s[j++]!=s[i])
			flag=1;
	if(flag==0)
		printf("String is Palindrome\n");
	else
		printf("String not Palindrome\n");
	return 0;
}

void display()
{
	printf("String :- \n");
	printf("%s\n",s);
}

/*
13816@fisat:/mnt/13816/s3ds$ ./stringop_13

MENU:-
1. Enter 1st string
2. Concatanate
3. Reverse
4. Palindrome
5. Search and Delete substring
6. Display
7. Exit
Enter your choice : 1
Enter 1st string:- inindia

Enter your choice : 5
Enter substring:- in
String :- 
dia

Enter your choice : 5
Enter substring:- in
Substring Not Found
Enter your choice : 2
Enter 2nd string:- isdia
String :- 
diaisdia

Enter your choice : 3
String :- 
aidisaid

Enter your choice : 4
String not Palindrome

Enter your choice : 5
Enter substring:- aid
String :- 
is

Enter your choice : 7
13816@fisat:/mnt/13816/s3ds$
*/
