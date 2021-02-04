#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	int A[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	int key = 0;
	for(int j = 2; j < sizeof(A)/sizeof(A[0]); j++){
		key = A[j];
		int i = j - 1;
		while(i > 0 && A[i] > key){			
			A[i+1] = A[i];
			i--;
		}
	A[i+1] = key;
	}
}
