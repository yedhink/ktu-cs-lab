// PROGRAM TO IMPLEMENT FCFS
#include<stdio.h>
#include<stdlib.h>

struct Processes{
	char pname[50];
	int at;
	int bt;
	int tt;
	int wt;
	int ct;
	int start_time;
	int idle;
	int idle_start;
}p[10];


struct done{
	char pname[50];
	int st;
	int et;
}d[10];

int n_done = 1;
float tt_avg;
float wt_avg;

void create_process(int n){
	for(int i=0;i<n;++i){
		printf("Enter process name : ");
		scanf("%s",p[i].pname);

		printf("Enter arrival time : ");
		scanf("%d",&p[i].at);

		printf("Enter burst time : ");
		scanf("%d",&p[i].bt);

		printf("\nEnter NEXT process\n");
	}
}

void sort(int n){
	struct Processes temp;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n-i-1;++j){
			if(p[i].at>p[j].at){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void start_schedule(int n){
	int current_time = 0;
	tt_avg = 0.0;
	wt_avg = 0.0;
	for(int i=0;i<n;++i){
		p[i].idle = 0;
		if(current_time >= p[i].at){
			p[i].start_time = current_time;
			current_time = current_time + p[i].bt;
			printf("cur time = %d and bt = %d\n",current_time,p[i].bt);
			p[i].ct = current_time;
			p[i].tt = p[i].ct - p[i].at;
			p[i].wt = p[i].tt - p[i].bt;
			tt_avg =tt_avg + p[i].tt;
			wt_avg =wt_avg + p[i].wt;
		    	strcpy(d[n_done].pname,p[i].pname);
			d[n_done].st = p[i].at;
			d[n_done].et = p[i].ct;
		}
		else{
		    	strcpy(d[n_done].pname,"idle");
			d[n_done].st = current_time;

			p[i].idle_start = current_time;
			while(current_time != p[i].at){
				p[i].idle = p[i].idle + 1;
				current_time = current_time + 1;
			}
			d[n_done].et = current_time;
			i = i -1;
		}
		++n_done;
	}
}

void display_table(int n){
	printf("\n");
	printf("\n|pn\t|at\t|bt\t|tt\t|wt\n");
	printf("------------------------------------------\n");
	for(int i=0;i<n;++i){
		printf("\n|%s\t|%d\t|%d\t|%d\t|%d\n",p[i].pname,p[i].at,p[i].bt,p[i].tt,p[i].wt);
	}
	printf("\n*******Averages*******\nttavg = %f\nwtavg = %f\n",tt_avg/4,wt_avg/4);
}

void display_gant(int n){
	printf("\n");
	printf("********GANT CHART*********\n------------------------------------------\n");
	for(int i=0;i<n_done;++i){
		printf("|%s\t|",d[i].pname);
	}
	printf("\n------------------------------------------\n");
	printf("0\t");
	for(int i=0;i<n_done;++i){
		printf("%d\t",d[i].et);
	}
	printf("\n\n");
}

int main(){
	int n;
	setbuf(stdin,NULL);
	printf("Enter num of processes : ");
	scanf("%d",&n);
	create_process(n);
	sort(n);
	start_schedule(n);
	display_table(n);
	display_gant(n);
	return 0;
}