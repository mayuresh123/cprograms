#include<stdio.h>
#include<pthread.h>

pthread_mutex_t myMutex;
void *Func(void *);
int cnt = 0;

int main()
{
	pthread_t thread[10];
	int i;
	pthread_mutex_init(&myMutex,0);
	for(i=0;i<10;i++)
	{
		pthread_create(&thread[i],NULL,Func,(void *)i);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(thread[i],0);
	}
	pthread_mutex_destroy(&myMutex);
}

void *Func(void *id)
{
	int i;
	printf("\nThread Executed : %d\n",(int)id);
	pthread_mutex_lock(&myMutex);
	cnt++;
	printf("\nThread Id : %d \t Thread cnt : %d\n",(int)id,cnt);
	pthread_mutex_unlock(&myMutex);
	
	printf("\nThread Exit : %d\n",(int)id);
}
