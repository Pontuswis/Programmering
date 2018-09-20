#include <stdio.h>

int main (){
	int m, n, temp;
	printf("Enter two intergers: ");
	scanf("%d %d", &m, &n);
	
	while (n != 0){
		
		temp = m % n;
		m = n;
		n = temp;
		
		
	}
	printf("Greatest common divisor: %d", m);
}