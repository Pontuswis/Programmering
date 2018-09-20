#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6

int initiate();
void createFreqTable(int nrOfThrows,int freqTable[]);
void printFreqTable(int freqTable[]);
void fillWith0(int v[], int length);
void printArray(int v[], int length);
int throwDie();

int main(){

	int nrOfThrows;
	int freqTable[SIDES+1];
	srand(time(NULL));


	nrOfThrows = initiate();
	createFreqTable(nrOfThrows, freqTable);
	printFreqTable(freqTable);
}


int initiate(){
	
	int nr;
	printf("Hur manga tarningskast vill du gora? ");
	scanf("%d", &nr);
	return nr;
}

void createFreqTable(int nrOfThrows,int freqTable[]){
	
	int result;
	fillWith0(freqTable, SIDES+1);
	
	for(int i=0;i<nrOfThrows;i++){
		throwDie();
		result = throwDie();
		freqTable[result]++; 
	}
}

void printFreqTable(int freqTable[]){
	
	printf("------------------\n");
	printf("Varde\t Frekvens\n");
	
	for(int i=1;i<SIDES+1;i++){
		printf("%d\t %d\n", i, freqTable[i]);
	}
}

void fillWith0(int v[], int length){
	
	for(int i=0;i<length;i++){
		v[i] = 0;
	}
}

int throwDie(){
	int result;
	result = rand()%SIDES+1;
	return result;
}

void printArray(int v[], int length){
	
	for(int i=0;i<length;i++){
		printf("%d, ", v[i]);
	}
printf("\n");
	
}