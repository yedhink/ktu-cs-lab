// PROGRAM TO IMPLEMENT BANKERS ALGORITHM
#include <stdio.h>
#include <stdlib.h>

struct process{
  int alloc;
  int max;
  int need;
}p[10];

void resource_allocation(int n,int a,int pid,int req){
  for(int i=0;i<n;++i){
    printf("\nEnter process[%d] details : \n",i+1);
    printf("allocation\t= ");
    scanf("%d",&p[i].alloc);
    printf("max\t\t= ");
    scanf("%d",&p[i].max);
    p[i].need = p[i].max - p[i].alloc;
    if(p[i].need<0){
      p[i].need = 0;
    }
  }
  printf("process\t|alloc\t|max\t|need\t|available\t|new id\t|new req\n");
  for(int i=0;i<n;++i){
    if(i==0){
      printf("p%d\t|%d\t|%d\t|%d\t|%d\t\t|%d\t|%d\n",i,p[i].alloc,p[i].max,p[i].need,a,pid,req);
    }
    else{
      printf("p%d\t|%d\t|%d\t|%d\t|  \t\t|  \t|  \n",i,p[i].alloc,p[i].max,p[i].need);
    }
  }
}

void disp(int safe[],int len){
  printf("\n\n**********SAFE NOW**********\n");
  printf("SAFE SEQUENCE\n");
  for(int i =0;i<len;++i){
    printf("p%d, ",safe[i]);
  }
  printf("\n");
}

int safety_algo(int pid,int req,int n_proc,int avail){
  int a,n,cnt=0,safe[20],s=0;
  p[pid].alloc += req;
  p[pid].need  -= req;
  while(cnt != n_proc){
    printf("\nDEADLOCK");
    for(int pid=0;pid<n_proc;++pid){
      a = p[pid].alloc;
      n = p[pid].need;
      if ( n <= avail ){
        cnt += 1;
        avail += a;
        safe[s++] = pid;
        if ( cnt == n_proc ){
          disp(safe,s);
          return 0;
        }
      }
    }
  }
  disp(safe,s);
  return 0;
}

int main(int argc, char const* argv[]){
  int n_proc,avail,pid,req,cnt=0;
  printf("Enter num of process : ");
  scanf("%d",&n_proc);
  printf("\nEnter available\t= ");
  scanf("%d",&avail);
  printf("pid\t\t= ");
  scanf("%d",&pid);
  printf("req\t\t= ");
  scanf("%d",&req);
  resource_allocation(n_proc,avail,pid,req);
  if(req >= avail){
    printf("\nNo availability for new req\n");
    exit(0);
  }
  safety_algo(pid,req,n_proc,avail);
  return 0;
}
