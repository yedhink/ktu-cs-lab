#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Processes{
	char pname[50];
	int at;
	int bt;
	int prio;
	int tt;
	int wt;
    int status;
}p[10];

struct done{
	char d_name[50];
	int ct;
	int st;
}d[10];

float g_tt_avg = 0.0;
float g_wt_avg = 0.0;
int num      = 0;

void create_process(int n){
	for(int i=0;i<n;++i){
		printf("Enter process name : ");
		scanf("%s",p[i].pname);
		printf("Enter arrival time : ");
		scanf("%d",&p[i].at);
		printf("Enter bt : ");
		scanf("%d",&p[i].bt);
		printf("Enter priority : ");
		scanf("%d",&p[i].prio);
		printf("\nEnter NEXT process\n");
    p[i].status = 0;
	}
}

void priority(int n){
    int idle     = 0;
    int cur_time = 0;
    int k        = 0;
    int flag     = 0;
    int found    = 0;
    int x      = 0;

    while(x<n){
        flag =0;
        found =0;
        for(int j=0;j<n;++j){
            if(p[j].status == 0 && (p[j].at <= cur_time) && found==0){
                k = j;
                flag++;
                found++;
            }
            else if(p[j].status == 0 && (p[j].at <= cur_time) && found>0){
                if(p[j].prio < p[k].prio){
                    k=j;
                }
            }
        }

        if(flag==0 && idle==0){
            strcpy(d[num].d_name,"idle");
            printf("%s entered idle first with d_name = %s",p[x].pname,d[num].d_name);
            d[num].st = cur_time;
            cur_time++;
            idle = 1;
            ++num;
        }
        else if(flag >0){
            if(idle == 1){
                d[num].ct = cur_time;
                ++num;
            }
            strcpy(d[num].d_name,p[k].pname);
            d[num].st   = cur_time;
            d[num].ct   = cur_time + p[k].bt;
            p[k].tt     = d[num].ct - p[k].at;
            g_tt_avg    = g_tt_avg + p[k].tt;
            p[k].wt     = p[k].tt - p[k].bt;
            g_wt_avg    = g_wt_avg + p[k].wt;
            cur_time    = d[num].ct;
            p[k].status = 1;

            ++num;
            ++k;
            ++x;
            idle = 0;
        }
        else{
            cur_time++;
        }
	}
}


void display_table(int n){
	printf("\n");
	printf("\n|pn\t|at\t|priority\t|tt\t|wt\t|status\n");
	printf("------------------------------------------\n");
	for(int i=0;i<n;++i){
		printf("\n|%s\t|%d\t|%d\t\t|%d\t|%d\t|%d\n",
                p[i].pname, p[i].at,
                p[i].prio,    p[i].tt,
                p[i].wt,    p[i].status);
	}
	printf("\n*******Averages*******\nttavg = %f\nwtavg = %f\n",g_tt_avg/n,g_wt_avg/n);
}

void display_gant(int n){
	printf("\n");
	printf("********GANT CHART*********\n------------------------------------------\n");
	for(int i=0;i<num;++i){
		printf("|%s\t|",d[i].d_name);
	}
	printf("\n------------------------------------------\n");
	printf("0\t");
	for(int i=0;i<num;++i){
		printf("%d\t",d[i].ct);
	}
	printf("\n\n");
}




int main(){
	int n;
	setbuf(stdin,NULL);
	printf("Enter num of processes : ");
	scanf("%d",&n);
	create_process(n);
  priority(n);
	display_table(n);
	display_gant(n);
	return 0;
}
