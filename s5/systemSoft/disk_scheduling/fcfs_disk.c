#include <stdio.h>
#include <stdlib.h>

int main() {
  int n,head,diff,*track,head_movement = 0;
  printf("Enter number of tracks\t: ");
  scanf("%d",&n);
  track = (int*)malloc(n*sizeof(int));
  printf("Enter head value\t\t: ");
  scanf("%d",&head);
  track[0] = head;
  printf("Enter each of the tracks\n");
  for (int i = 1; i < n+1; i++) {
    printf("track[%d] = ",i);
    scanf("%d",&track[i]);
  }
  for (int i = 0; i < n; i++) {
    diff = track[i+1]-track[i];
    if(diff < 0){
      diff = diff * -1;
    }
    head_movement = head_movement + diff;
  }
  printf("\nhead movements = %d",head_movement);
  return 0;
}
