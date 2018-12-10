// PROGRAM TO IMPLEMENT ROUND ROBIN
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Processes{
	char pname[50];
	int at;
	int bt;
	int ct;
	int tt;
	int wt;
    int status;
    int left;
}p[10];

struct done{
	char d_name[50];
	int ct;
	int st;
}d[10];

float g_tt_avg = 0.0;
float g_wt_avg = 0.0;
int q[100],front=-1,rear=0,t=0;
int ls=0,idle=0,m=0;

void enq(int j){
    q[rear] = j;
    ++rear;
    if(front == -1){
        ++front;
    }
}

int deq(){
    int item;
    item = q[front];
    ++front;
    if(front == rear){
        front = -1;
        rear = 0;
    }
    return item;
}

void create_process(int n){
    printf("Enter Time quantum : ");
    scanf("%d",&t);
	for(int i=0;i<n;++i){
		printf("Enter process name : ");
		scanf("%s",p[i].pname);
		printf("Enter arrival time : ");
		scanf("%d",&p[i].at);
		printf("Enter burst time : ");
		scanf("%d",&p[i].bt);
		printf("\nEnter NEXT process\n");
        p[i].status = 0;
        p[i].left = p[i].bt;
	}
}

void display_table(int n){
	printf("\n");
	printf("\n|pn\t|at\t|bt\t|tt\t|wt\t|status\n");
	printf("------------------------------------------\n");
	for(int i=0;i<n;++i){
		printf("\n|%s\t|%d\t|%d\t|%d\t|%d\t|%d\n",
                p[i].pname, p[i].at,
                p[i].bt,    p[i].tt,
                p[i].wt,    p[i].status);
        g_tt_avg = g_tt_avg + p[i].tt;
        g_wt_avg = g_wt_avg + p[i].wt;
	}
	printf("\n*******Averages*******\nttavg = %f\nwtavg = %f\n",g_tt_avg/n,g_wt_avg/n);
}

void display_gant(int n){
	printf("\n");
	printf("********GANT CHART*********\n------------------------------------------------------------------------------------\n");
	for(int i=0;i<m;++i){
		printf("|%s\t|",d[i].d_name);
	}
	printf("\n------------------------------------------------------------------------------------\n");
	printf("0\t");
	for(int i=0;i<m;++i){
		printf("%d\t",d[i].ct);
	}
	printf("\n\n");
}

void round_robin(int n){
    int i=0,j=0,k=0;
    while(ls<n){
        for(j=0;j<n;++j){
            if(p[j].status == 0 && p[j].at <= i){
                enq(j);
                p[j].status = 1;
            }
        }
        if(idle == 0 && front == -1){
            printf("entered idle case\n");
            strcpy(d[m].d_name,"idle");
            d[m].ct = i;
            idle = 1;
            ++i;
        }
        else if(front != -1){
            if(idle == 1){
                d[m].ct = i;
                idle = 0;
                ++m;
            }
            k = deq();
            d[m].st = i;
            strcpy(d[m].d_name,p[k].pname);
            if(p[k].left <= t){
                d[m].ct = i + p[k].left;
                i = d[m].ct;
                p[k].tt = d[m].ct - p[k].at;
                p[k].wt = p[k].tt - p[k].bt;
                p[k].status = 2;
                ++ls;
                ++m;
            }
            else{
                d[m].ct = i + t;
                i = i + t;
                p[k].left = p[k].left - t;
                ++m;
                for(j=0;j<n;++j){
                    if(p[j].status == 0 && p[j].at <= i){
                        enq(j);
                        p[j].status = 1;
                    }
                }
                enq(k);
            }
        }
        else{
            ++i;
        }
    }
}

int main(){
	int n;
	setbuf(stdin,NULL);
	printf("Enter num of processes : ");
	scanf("%d",&n);
	create_process(n);
	printf("\nExited creation\n");
    round_robin(n);
	printf("value of m = %d",m);
	display_table(n);
	display_gant(n);
	return 0;
}
