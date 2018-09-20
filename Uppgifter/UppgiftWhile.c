#include <stdio.h>

int main(){
	
	int i, j, k;
	
	i = 1;
	while (i <= 10){
		printf("%d, ", i);
		i++;
	}
	
	printf("\n");
	
	j = 10;
	while (j > 0){
		printf("%d, ", j);
		j--;
	}
	
	printf("\n");
	
	k = 1;
	while (k <= 16){
		printf("%d, ", k);
		k = k*2;
	}
}