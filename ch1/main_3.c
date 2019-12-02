#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MILLION 1000000
#define LEN 3

void mat(int arr1[][LEN], int arr2[][LEN]);
void ini(int arr[][LEN]);

int mat1[LEN][LEN]={0,};
int mat2[LEN][LEN]={0,};
int mat3[LEN][LEN]={0,};

int main(){
	int i, q;
	
    struct timeval tpstart, tpend;
    long timediff;
	
	ini(mat1);
	ini(mat2);

	gettimeofday(&tpstart, NULL);

	mat(mat1, mat2);
	
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
	
	printf("timediff %ld\n", timediff);
	
	return 0;
}

void mat(int arr1[][LEN], int arr2[][LEN]){
	int i, q, r;
	int sum;
	for(i=0; i<LEN; i++){
		for(q=0; q<LEN; q++){
			sum=0;
			for(r=0; r<LEN; r++){
				sum+=arr1[i][r]*arr2[r][q];
			}
			mat3[i][q]=sum;
		}
		
	}
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
