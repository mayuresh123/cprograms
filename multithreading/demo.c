#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex_t = PTHREAD_MUTEX_INITIALIZER;



void *fun(void *arg)
{
	int *msg = (int*)arg;
	int data;
	pthread_mutex_lock(&mutex_t);
	printf("\n%d\n",*msg);
	
	scanf("%d",&data);
	pthread_mutex_unlock(&mutex_t);
}

int main(void)
{
	pthread_t thread[20];
	int ret,i;

	for(i=0;i<20;i++)
	{
		pthread_create(&thread[i],NULL,fun,&i);

//		pthread_join(thread[i],NULL);

	}
	
	for(i=0;i<20;i++)
	{
		//pthread_join(thread[i],NULL);
	}
	
	ret=1;

	while(ret)
	{
		printf("\nIn main\n");
		ret++;
		if(ret == 5000) break;
	}

	return 0;
}
