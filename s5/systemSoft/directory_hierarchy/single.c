#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fstab {
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir;

int main() {
	int choice,flag=0;
	char del[10];
	dir.fcnt = 0;
	printf("Enter directory name : ");
	scanf("%s",dir.dname);
	while(1){
		flag = 0;
		printf("\n1) Create file\n2) Delete\n3) Search\n4) Display\n5) Exit\n");
		printf("\n\nEnter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter file name : ");
				scanf("%s",del);
				if (dir.fcnt != 0){
					for (int i=0;i<dir.fcnt;++i){
						if (strcmp(del,dir.fname[i])==0){
							flag = 1;
							break;
						}
					}
				}
				if (flag != 1){
					strcpy(dir.fname[dir.fcnt],del);
					dir.fcnt++;
				}
				break;
			case 2:
				printf("Delete file : ");
				scanf("%s",del);
				for (int i=0;i<dir.fcnt;++i){
					if (strcmp(del,dir.fname[i])==0){
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						dir.fcnt--;
						system("clear");
						printf("File deleted\n");
						FIT16CS125
							4315. SINGLE LEVEL DIRECTORY STRUCTURING
							flag = 1;
						break;
					}
				}
				if (flag!=1){
					printf("File not found");
				}
				break;
			case 3:
				printf("Search file : ");
				scanf("%s",del);
				system("clear");
				for (int i=0;i<dir.fcnt;++i){
					if (strcmp(del,dir.fname[i])==0){
						printf("File found at position %d",i+1);
						flag = 1;
						break;
					}
				}
				if (flag!=1){
					printf("File not found");
				}
				break;
			case 4:
				system("clear");
				printf("file count\t:%d\n%s:\n",dir.fcnt,dir.dname);
				for (int i=0;i<dir.fcnt;++i){
					printf("\t%s\n",dir.fname[i]);
				}
				break;
			case 5:
				exit(0);
		}
	}
}
return 0;
}
