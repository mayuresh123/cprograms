#include<stdio.h>
#include<pthread.h>

void *PrintThread(void *id);

int main()
{
	pthread_t thread[100];//,thread2,thread3,thread4;
	int flag,i;
	for(i=0;i<100;i++)
	{
		pthread_create(&thread[i],NULL,PrintThread,(void *)i);
	}
	pthread_exit(NULL);
}

void *PrintThread(void *id)
{
	printf("\nThread Id: %d\n",(int)id);
}
