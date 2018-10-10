#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

void makeThrows(int results[], int nrOfDices, int nrOfThrows);
int throwDice(int nrOfDices);
void viewResults(int results[], int nrOfThrows);
float medelVardet(int results[], int nrOfThrows);
float median(int results[], int nrOfThrows);
void sort(int v[],int n);

int main(){
	
	srand(time(NULL));
	int nrOfDices;
	int nrOfThrows;
	int results[MAX];
	printf("Ange antal tarningar som skall kastas: ");
	scanf("%d", &nrOfDices);
	if(nrOfDices<1){
		nrOfDices=1;
	}
	printf("Ange antal ganger de skall kastas(max 1000): ");
	scanf("%d", &nrOfThrows);
	if(nrOfThrows>MAX){
		nrOfThrows=MAX;
	}
	
	makeThrows(results, nrOfDices, nrOfThrows);
	viewResults(results, nrOfThrows);
}

void makeThrows(int results[], int nrOfDices, int nrOfThrows){
	for(int i=0;i<nrOfThrows;i++){
		results[i]=throwDice(nrOfDices);
	}
}

int throwDice(int nrOfDices){
	int sum=0;
	for(int i=0;i<nrOfDices;i++){
		sum+=rand()%6+1;
	}
	return sum;
}

void viewResults(int results[], int nrOfThrows){
	if(nrOfThrows<20){
		printf("Resultaten blev: ");
		for(int i=0;i<nrOfThrows;i++){
			printf("%d, ", results[i]);
		}
		printf("\n");
	}
	
	float medel;
	float medi;
	
	medel = medelVardet(results, nrOfThrows);
	printf("Medelvardet: %.2f\n", medel);
	medi = median(results, nrOfThrows);
	printf("Medianen: %.2f", medi);
}

float medelVardet(int results[], int nrOfThrows){
	float sum;
	for(int i=0;i<nrOfThrows;i++){
		sum+=results[i];
	}
	sum = sum/nrOfThrows;
	return sum;
}

float median(int results[], int nrOfThrows){
	int tmp[MAX];
	float medi;
	for(int i=0;i<nrOfThrows;i++){
		tmp[i]=results[i];
	}
	sort(tmp, nrOfThrows);
	
	if(nrOfThrows%2==0){
		medi = tmp[nrOfThrows/2] + tmp[nrOfThrows/2-1];
		medi = medi/2;
    }
	else{
        medi=tmp[nrOfThrows/2];
    }
	return medi;
}

void sort(int v[],int n)
{
    int i,j,tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(v[j]>v[j+1])
            {
                tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
            }
        }
    }

}
