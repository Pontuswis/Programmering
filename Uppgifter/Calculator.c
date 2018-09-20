#include <stdio.h>

int main(){
	
	float nr1, nr2, result;
	char oper, con = 'y';
	
		printf("Ange tal 1: ");
		scanf("%f", &nr1);
		while(con == 'y' ){
		printf("Ange tal 2: ");
		scanf("%f", &nr2);
	
		printf("Ange +,-,*,/: ");
		scanf(" %c", &oper);
	
		if (oper == '+'){
			result = nr1 + nr2;
		}
		else if(oper == '-'){
			result = nr1 - nr2;
		}
		else if(oper == '*'){
			result = nr1*nr2;
		}
		else if(oper == '/'){
			result = nr1/nr2;
		}
		else{
			result = nr1 + nr2;
		}

		printf("Result: %.2f\n", result);
		printf("Continue? (y/n): ");
		scanf(" %c", &con);
		nr1 = result;
	}
}