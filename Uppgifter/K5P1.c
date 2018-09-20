#include <stdio.h>

int main(){
	
	int num;
	printf("Enter a number: \n");
	scanf("%d", &num);
	
	if (num < 9){
		printf("The number %d has 1 digit", num);
	}
	else if (num < 99){
		printf("The number %d has 2 digits", num);
		
	}
	else if(num < 999){
		printf("The number %d has 3 digits", num);
	}
	else{
		printf("The number %d has 4 digits", num);
	}
}