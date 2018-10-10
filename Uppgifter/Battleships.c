#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 6

void printSea(int sea[][DIM]);
void init(int sea[][DIM]);
int bomb(int sea[][DIM]);

int main(){
	int sea[DIM][DIM]={{0}};
	int nrOfHits=0;
	init(sea);
	//printSea(sea);
	for(int tries=0;tries<=6;tries++){
		if(bomb(sea)){
			nrOfHits++;
			if(nrOfHits<3){
				printf("TRAFF\n");
			}
		}
		else{
			printf("MISS\n");
		}
		if(nrOfHits==3){
			break;
		}
	}
	if(nrOfHits==3){
		printf("TRAFF OCH SANKT!");
	}
	else{
		printf("DU MISSLYCKADES!");
	}
}

void printSea(int sea[][DIM]){
	for(int i=1;i<DIM;i++){
		for(int j=1;j<DIM;j++){
			printf("%d ", sea[i][j]);
		}
		printf("\n");
	}
}

void init(int sea[][DIM]){
	srand(time(NULL));
	int row = rand()%5+1;
	int col = rand()%3+1;
	sea[row][col]=1;
	sea[row][col+1]=1;
	sea[row][col+2]=1;
}

int bomb(int sea[][DIM]){
	int row, col;
	printf("Vilken position vill du beskjuta? ");
	scanf("%d%d", &row, &col);
	if(sea[row][col]==1){
		sea[row][col]=2;
	}
}