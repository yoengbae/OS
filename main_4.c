#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#define MILLION 1000000
#define LEN 3

void ini(int arr[][LEN]);
void* ft(void* a);

int mat1[LEN][LEN]={0,};
int mat2[LEN][LEN]={0,};
int mat3[LEN][LEN]={0,};
int w=0;

int main(){
	int i, q;
	
    struct timeval tpstart, tpend;
    long timediff;
	
	pthread_t t[LEN];
	
	ini(mat1);
	ini(mat2);
	gettimeofday(&tpstart, NULL);
	for(i=0; i<LEN; i++){
		pthread_create(&t[i], NULL, ft, (void*)&w);
		w++;
	}
	for(i=0; i<LEN; i++){
		pthread_join(t[i], NULL);
	}
	
	gettimeofday(&tpend, NULL);
	timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	
	for(i=0; i<LEN; i++){
		for(q=0; q<LEN; q++){
			printf("%d ", mat1[i][q]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0; i<LEN; i++){
		for(q=0; q<LEN; q++){
			printf("%d ", mat2[i][q]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0; i<LEN; i++){
		for(q=0; q<LEN; q++){
			printf("%d ", mat3[i][q]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("timediff: %ld\n", timediff);

	return 0;
}


void ini(int arr[][LEN]){
	int i, q;
	for(i=0; i<LEN; i++){
		for(q=0; q<LEN; q++){
			arr[i][q]=rand()%10;
		}
	}
	return;
}

void* ft(void* a){
	int b=*(int*)a;
	int q, r, sum;
	for(q=0; q<LEN; q++){
		sum=0;
		for(r=0; r<LEN; r++){
			sum+=mat1[b][r]*mat2[r][q];
		}
		mat3[b][q]=sum;
	}
	return NULL;
}
