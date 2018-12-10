#include <stdio.h>
#include <stdlib.h>

int lru(int np,int nf,int *p,int *fr){
  int cnt=0,least=0,flag,fault=0,victim=-1,next=1;
  int c_len=0,min,min_pos=0;
  int *count = (int*)malloc(3*sizeof(int));
  for (int i = 0; i < 3; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < np; i++) {
    flag = 0;
    for (int j = 0; j < nf; j++) {
      if(p[i]==fr[j]){
        flag = 1;
        count[j] = next;
        ++next;
        ++c_len;
      }
    }
    if (flag==0){
      if(i<nf){
        fr[i]=p[i];
        count[i]=next;
      }
      else{
        min = count[0];
        min_pos = 0;
        for (int k = 1; k < nf; k++) {
          if(count[k]<min){
            min = count[k];
            min_pos = k;
          }
        }
        fr[min_pos] = p[i];
        count[min_pos] = next;
        ++next;
      }
      ++fault;
    }
  }
  return fault;
}

void disp(int np,int nf,int *p,int *fr,int fault){
  printf("\nFrames after replacing\n");
  for (int i = 0; i < nf; i++) {
    printf("%d ",fr[i]);
  }
  printf("\nNo of faults = %d\n",fault);
}

int main(int argc, const char *argv[]) {
  int n_frames,n_pages,fault;
  printf("Enter no of frames = ");
  scanf("%d",&n_frames);
  printf("Enter no of pages = ");
  scanf("%d",&n_pages);
  int *p = (int*)malloc(21*sizeof(int));
  int *frames = (int*)malloc(n_frames*sizeof(int));
  printf("\nEnter page numbers\n");
  for (int i = 0; i < n_pages; i++) {
    printf("p[%d]=",i);
    scanf("%d",&p[i]);
    frames[i] = -1;
  }
  fault = lru(n_pages,n_frames,p,frames);
  disp(n_pages,n_frames,p,frames,fault);
  return 0;
}
