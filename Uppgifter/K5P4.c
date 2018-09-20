#include <stdio.h>

int main(){
	int WindSpeed;
	printf("Enter the wind speed (in knots): ");
	scanf("%d", &WindSpeed);

	if (WindSpeed < 1){
		printf("Calm");
	}
	else if (WindSpeed < 3){
		printf("Light air");
	}
	else if (WindSpeed < 27){
		printf("Breeze");
	}
	else if (WindSpeed < 47){
		printf("Gale");
	}
	else if (WindSpeed < 63){
		printf("Storm");
	}
	else{
		printf("Hurricane");
	}
	}