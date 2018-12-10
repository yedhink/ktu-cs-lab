#include <stdio.h>
#include <stdlib.h>

int fifo(int np,int nf,int *p,int *fr){
    int cnt=0,least=0,flag,fault=0,victim=-1;
    while(cnt != np){
        flag = 0;
        for (int i = 0; i < nf; i++) {
            if(p[cnt]==fr[i]){
                flag = 1;
                break;
            }
        }
        if (flag==0) {
            ++fault;
            ++victim;
            victim = victim % nf;
            fr[victim] = p[cnt];
        }
        printf("\n%d)fault=%d, least=%d, page=%d, frame=%d\t",cnt,fault,victim,p[cnt-1],fr[victim]);
        for (int i = 0; i < nf; i++) {
            printf("%d, ",fr[i]);
        }
        printf("\n");
        ++cnt;
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

int main(int argc, const char *argv[])
{
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
    fault = fifo(n_pages,n_frames,p,frames);
    disp(n_pages,n_frames,p,frames,fault);
    return 0;
}