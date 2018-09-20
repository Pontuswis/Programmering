#include <stdio.h>

int main(){
	
	int i, j, k;
	
	for (i = 1;i <= 10; i++){
		printf("%d, ", i);
	}
	
	printf("\n");
	
	for (j = 10;j > 0; j--){
		printf("%d, ", j);
	}
	
	printf("\n");
	
	for (k = 1;k <= 16; k = k*2){
		printf("%d, ", k);
	}
}