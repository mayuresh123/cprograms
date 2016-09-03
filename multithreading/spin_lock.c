#include<stdio.h>
#include<pthread.h>

pthread_spinlock_t slock;

void *Func(void *i)
{
	pthread_spin_lock(&slock);
	printf("\nThread Executing : %d\n",(int)i);
	sleep(3);
	printf("\nExited Thread : %d\n",(int)i);
	pthread_spin_unlock(&slock);
}

int main()
{
	pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE);
	pthread_t thread[10];
	int i;
	for(i=0;i<10;i++)
	{
		pthread_create(&thread[i],NULL,Func,(void *)i);
	}
	pthread_spin_destroy(&slock);
	pthread_exit(NULL);
}
