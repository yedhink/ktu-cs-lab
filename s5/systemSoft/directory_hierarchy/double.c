#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fstab {
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir[10];

int main() {
	int choice,flag=0,flag2=0;
	char del[10];
	int dcnt = 0;
	printf("\n1) Create directory\n2) Create file\n3) Delete file\n4) Search\n5) Display\n6) Exit\n");
	while(1){
		flag = 0;
		printf("\n\nEnter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter directory name : ");
				scanf("%s",del);
				for (int i=0;i<dcnt;++i){
					if (strcmp(del,dir[i].dname)==0){
						flag =1;
						break;
					}
				}
				if (flag!=1){
					strcpy(dir[dcnt].dname,del);
					dir[dcnt].fcnt = 0;
					dcnt++;
				}
				else{
					printf("\nDirectory name already exists!\n");
				}
				break;
			case 2:
				if (dcnt != 0){
					printf("Enter directory name : ");
					scanf("%s",del);
					for (int i=0;i<dcnt;++i){
						if (strcmp(del,dir[i].dname)==0){
							flag2 = 1;
							printf("Enter file name : ");
							scanf("%s",del);
							FIT16CS12516. DOUBLE LEVEL DIRECTORY STRUCTURING
						}
					}
					for (int j=0;i<dir[j].fcnt;++j){
						if (strcmp(del,dir[i].fname[j])==0){
							flag =1;
							break;
						}
					}
					if (flag!=1){
						strcpy(dir[i].fname[dir[i].fcnt],del);
						dir[i].fcnt++;
					}
					else{
						printf("\nFile already exists!\n");
					}
				}
				if (flag2 == 0 || dcnt==0){
					printf("Directory not found");
				}
				break;
			case 3:
				printf("Enter directory name : ");
				scanf("%s",del);
				for (int i=0;i<dcnt;++i){
					if (strcmp(del,dir[i].dname)==0){
						printf("Delete file : ");
						scanf("%s",del);
						for (int j=0;j<dir[i].fcnt;++j){
							if (strcmp(del,dir[i].fname[j])==0){
								strcpy(dir[i].fname[j],dir[i].fname[dir[i].fcnt-1]);
								--dir[i].fcnt;
								printf("\nfile deleted\n");
								flag = 1;
								break;
							}
						}
						if (flag!=1){
							printf("No such file exist in this directory");
						}
						// if all files deleted then delete the directory
						if (dir[i].fcnt == 0){
							printf("\nWhole directory too deleted\n");
							dir[i] = dir[dcnt-1];
							--dcnt;
						}
					}
				}
				break;
			case 4:
				printf("Enter directory name : ");
				scanf("%s",del);
				for (int i=0;i<dcnt;++i){
					if (strcmp(del,dir[i].dname)==0){
						FIT16CS125
							4616. DOUBLE LEVEL DIRECTORY STRUCTURING
							flag = 0;
						printf("Search file : ");
						scanf("%s",del);
						// system("clear");
						for (int j=0; j < dir[i].fcnt ;++j) {
							if (strcmp(del,dir[i].fname[j])==0){
								system("clear");
								printf("File found in directory at position %d",j+1);
								flag = 1;
								break;
							}
						}
						if (flag!=1){
							printf("File not found");
						}
					}
				}
				break;
			case 5:
				system("clear");
				for (int i=0;i<dcnt;++i){
					printf("%s:\n",dir[i].dname);
					for (int j=0;j<dir[i].fcnt;++j){
						printf("\t%s\n",dir[i].fname[j]);
					}
				}
				break;
			case 6:
				exit(0);
		}
	}
}
return 0;
}
