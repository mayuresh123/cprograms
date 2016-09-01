#include<pthread.h>
#include<stdio.h>

void *PrintMessage(void *arg);

int main()
{
	pthread_t thread1;
	void *ret_join;
	pthread_create(&thread1,NULL,PrintMessage,(void *)1);
	pthread_join(thread1,&ret_join);
	printf("Thread returned message: %s",(char *)ret_join);
	return 0;
}

void *PrintMessage(void *arg)
{
	pthread_exit("Exited Thread");
}
