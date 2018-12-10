/*
  Producer Consumer Problem
  -------------------------

  aim : buffer can only be used by one of the process
  if buffer full then consumer has to consume for producing another.

  constraints : fixed size buffer

  1) PTHREAD_CREATE
  -----------------
  int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
  pthread_t *thread  :  thread id
  const pthread_attr_t *attr  :  default attr = NULL
  void *(*start_routine) (void *)  :  which function the thread should work on
  void *arg  :  args for that function

  2) SEM_INIT
  -----------------
  semaphore to be initialized(of type sem_t)
  can be either 0 or 1. 0-> semapgore is shared bw threads of a process
  value to be intialized to semaphore

  3) SEM_WAIT
  -----------------
  name of semaphore to be decremented

  4) PTHREAD_JOIN
  -----------------
  waits untill thread is terminated
  thread name
*/
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>

sem_t mutex,empty,full;

int buffer[5],get=0,item=0,gitem,put=0,pro[20],con[20];

/*
  print our the buffer item
  *(int*)arg -> for getting integer val as such
  for signalling we use sem_post -> increments val
  also increment slot for full at end
*/
void *producer(void *arg){
  do
    {
      sem_wait(&empty);
      sem_wait(&mutex);
      buffer[put%5] = item;
      ++item;
      printf("producer %d produces %d item buffered[%d] : %d\n",
	     (*(int*)arg),
	     buffer[put%5],
	     put%5,
	     item
	     );
      ++put;
      sem_post(&mutex);
      sem_post(&full);
      sleep(3);
    } while (1);
}

/*
  wait out full,mutex
  store buffer[get%5] to a variable
*/
void *consumer(void *arg){
  do
    {
      sem_wait(&full);
      sem_wait(&mutex);
      gitem = buffer[get%5];
      printf("consumer %d consumes %d item buffered[%d] : %d\n",
	     (*(int*)arg),
	     gitem,
	     get%5,
	     gitem
	     );
      ++get;
      sem_post(&mutex);
      sem_post(&empty);
      sleep(2);
    } while (1);
}


int main() {
  int p,c;
  pthread_t a[10],b[10];
  // initialize mutex to 1
  sem_init(&mutex,0,1);
  sem_init(&full,0,0);
  //no of slots = 5
  sem_init(&empty,0,5);

  printf("No of producers\t:");
  scanf("%d",&p);
  printf("No of consumers\t:");
  scanf("%d",&c);

  for (int i = 0; i < p; ++i) {
    pro[i] = i;
    pthread_create(&a[i],NULL,producer,&pro[i]);
  }

  for (int i = 0; i < c; ++i) {
    con[i] = i;
    pthread_create(&b[i],NULL,consumer,&con[i]);
  }

  for (int i = 0; i < p; ++i) {
    pro[i] = i;
    pthread_join(a[i],NULL);
  }

  for (int i = 0; i < c; ++i) {
    con[i] = i;
    pthread_join(b[i],NULL);
  }
  return 0;
}
