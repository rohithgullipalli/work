#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t lock; 

void* thread1(void* arg) 
{ 
	sem_wait(&lock); 
	while(1) {
	printf("____thread1____\n"); 
	sleep(5); 
	}
	sem_post(&lock); 
} 

void* thread2(void *arg)
{
	sem_wait(&lock);
	while(1) {
	printf("----thread2----\n");
	sleep(2);
	}
	sem_post(&lock);
}

int main() 
{ 
	sem_init(&lock, 0, 1); 
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,thread1,NULL); 
	pthread_create(&t2,NULL,thread2,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&lock); 
	return 0; 
} 

