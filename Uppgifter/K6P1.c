#include <stdio.h>

int main(){
	
	float num = 1;
	float max;
	
	printf("Enter a number, to exit the program enter 0\n");
	scanf("%f", &num);
	max=num;
	while (num > 0){
		
		printf("Enter a new number: ");
		scanf("%f", &num);
		if (num > max){ 
			max=num;
		}
	}
	printf("The largest number entered was: %f", max);
}