#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>

#define N 5
#define thinking 0
#define hungry 1
#define eating 2
#define left (ph_num+4)%N
#define right (ph_num+1)%N

sem_t mutex,S[N];

int state[N];
int phil_num[N] = {0,1,2,3,4};

void take_fork(int);
void put_fork(int);
void test(int);

void *philospher(void *num){
  while (1) {
    int *i = num;
    sleep(1);
    take_fork(*i);
    sleep(0);
    put_fork(*i);
  }
}

void take_fork(int ph_num){
  sem_wait(&mutex);
  state[ph_num] = hungry;
  printf("philospher %d is hungry\n",ph_num+1);
  test(ph_num);
  sem_post(&mutex);
  sem_wait(&S[ph_num]);
  sleep(1);
}

void test(int ph_num){
  if(state[ph_num] == hungry
     && state[left] != eating
     && state[right] != eating){
    state[ph_num] = eating;
    sleep(2);
    printf("philospher %d takes fork %d and %d\n",
	   ph_num+1,left+1,ph_num+1);
    printf("philospher %d is eating\n",ph_num+1);
    sem_post(&S[ph_num]);
  }
}

void put_fork(int ph_num){
  sem_wait(&mutex);
  state[ph_num] = thinking;
  printf("philospher %d putting fork %d and %d down\n",
	 ph_num+1,left+1,ph_num+1);
  printf("philospher %d is thinking\n",ph_num+1);
  test(left);
  test(right);
  sem_post(&mutex);
}

int main() {
  pthread_t thread_id[N];
  sem_init(&mutex,0,1);
  for (int i=0; i < N; ++i) {
    sem_init(&S[i],0,0);
  }
  for (int i=0; i < N; ++i) {
    pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);
    printf("philospher %d is thinking\n",i+1);
  }

  for (int i=0; i < N; ++i) {
    pthread_join(thread_id[i],NULL);
  }
  return 0;
}
