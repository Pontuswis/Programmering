#include <stdio.h>
#define LENGTH 10

int main(){
	
	int a[LENGTH];
	int i;
	int eights = 0;
	
	for (i=0;i<LENGTH;i++){
		scanf("%d", &a[i]);
	}
	for (i=0;i<LENGTH;i++){
		if (a[i] == 8){
			eights++;
		}
	}
	printf("Antal 8or: %d\n", eights);
}