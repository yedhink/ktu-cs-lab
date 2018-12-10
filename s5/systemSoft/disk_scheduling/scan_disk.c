#include <stdio.h>
#include <stdlib.h>

int *track,n,head,diff,head_movement = 0,end=199;

int get_pos(int val){
    for (int i = 0; i < n+3; i++) {
        if(track[i]==val){
            return i;
        }
    }
    return -1;
}

int scan(){
    int mid = end/2,pos = get_pos(head),diff;
    printf("\nhead movements\n");
    if(head<mid){
        for (int i = pos; i!=0; i--) {
            printf("%d  ",track[i]);
            diff = track[i]-track[i-1];
            if(diff < 0){
                diff = diff * -1;
            }
            head_movement = head_movement + diff;
        }
        printf("%d  ",track[0]);
        diff = track[pos+1]-0;
        if(diff < 0){
            diff = diff * -1;
        }
        head_movement = head_movement + diff;
        for (int i = pos+1; i<n+1; i++) {
            printf("%d  ",track[i]);
            diff = track[i+1]-track[i];
            if(diff < 0){
                diff = diff * -1;
            }
            head_movement = head_movement + diff;
        }
    }
    else{
        for (int i = pos; i<n+1; i++) {
            printf("%d  ",track[i]);
            diff = track[i+1]-track[i];
            if(diff < 0){
                diff = diff * -1;
            }
            head_movement = head_movement + diff;
        }
        printf("%d  ",track[n+2]);
        diff = track[n+2]-track[n+1];
        if(diff < 0){
            diff = diff * -1;
        }
        head_movement = head_movement + diff;
        for (int i = pos-1; i!=1; i--) {
            printf("%d  ",track[i]);
            diff = track[i]-track[i-1];
            if(diff < 0){
                diff = diff * -1;
            }
            head_movement = head_movement + diff;
        }
    }
    printf("%d  %d\n",track[n+1],track[n+2]);
    return 0;
}

int sort(){
    int temp;
    for (int i = 0; i < n+3; i++) {
        for (int j = 0; j < (n+3)-i-1; j++) {
            if(track[j]>track[j+1]){
                temp = track[j];
                track[j] = track[j+1];
                track[j+1] =  temp;
            }
        }
    }
}

int main(){
    printf("Enter number of tracks\t: ");
    scanf("%d",&n);
    track = (int*)malloc((n+3)*sizeof(int));
    printf("Enter head value\t\t: ");
    scanf("%d",&head);
    track[0] = 0;
    track[1] = head;
    printf("Enter each of the tracks\n");
    for (int i = 2; i < n+2; i++) {
        printf("track[%d] = ",i);
        scanf("%d",&track[i]);
    }
    track[n+2] = end;
    sort();
    scan();
    printf("\n\ntotal head movements = %d\n",head_movement);
    return 0;
}
