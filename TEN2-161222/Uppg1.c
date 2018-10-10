#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int tal = rand()%10+1;
	int gissning;
	int antal=0;
	while(gissning != tal){
		printf("Gissa ett tal (1-10): ");
		scanf("%d", &gissning);
		antal++;
	}
	printf("Ratt. Det kravdes %d gissningar", antal);
}