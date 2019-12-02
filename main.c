#include<stdio.h>
#include<pthread.h>

volatile int global=0;
void* ft(void *arg);

int main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, ft, (void*)NULL);
	pthread_create(&t2, NULL, ft, (void*)NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("expect: 20000 result: %d \n", global);
	return 0;
}

void* ft(void *arg){
	int i;
	for(i=0; i<10000; i++){
		global++;
	}
	return NULL;
}
