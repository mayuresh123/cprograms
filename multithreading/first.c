#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message_function(void *ptr);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int cnt = 0;

int main()
{
	pthread_t thread1,thread2;
	const char *msg1="This is message 1";
	const char *msg2="This is message 2";
	
	int iter1,iter2;
	
	iter1 = pthread_create(&thread1,NULL,print_message_function,(void*) msg1);
	
	if(iter1)
	{
		fprintf(stderr,"error create thread1");
		exit(EXIT_FAILURE);
	}		

	iter2 = pthread_create(&thread2,NULL,print_message_function,(void*) msg2);
	
	if(iter2)
	{
		fprintf(stderr,"error create thread2");
		exit(EXIT_FAILURE);
	}		

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	exit(EXIT_SUCCESS);

	return 0;
}

void *print_message_function(void *ptr)
{
	pthread_mutex_lock(&mutex);
	cnt++;
	pthread_mutex_unlock(&mutex);
	char *msg;
	msg = (char*)ptr;
	printf("%s: counter: %d\n",msg,cnt);
}

