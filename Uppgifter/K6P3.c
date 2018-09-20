#include <stdio.h>

int main(){
	int num1, num2, m, n, temp;
	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &num2);
	num1=m;
	num2=n;
	
	while (n != 0){
		
		temp = m % n;
		m = n;
		n = temp;
	}
	num1 = num1/m;
	num2 = num2/m;
	printf("In lowest terms: %d/%d", num1, num2);
}