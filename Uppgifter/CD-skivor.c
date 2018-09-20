#include <stdio.h>

int main()
{
	int i = 1;
	while (i != 0){
	
		int antal; 
		float pris = 9.90;
		float total;
		printf("Hur manga skivor vill du ha?\n ");
		scanf("%d", &antal);
	
	
		if(antal < 10){
			total = antal * pris;
			printf("Da blir det %.0f kroner\n", total);
	
		}
		else if (antal < 50){
			total = (antal * pris)*0.95;
			printf("Da blir det %.0f kroner\n", total);
		}
	
		else {
			total = (antal * pris)*0.90;
			printf("Da blir det %.0f kroner\n", total);
		}
	
		printf("For att avsluta ditt kop tryck 0, for att fortsatta tryck 1\n");
		scanf("%d", &i);
	}
	}