#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

void printArr(int a[]);
void sort(int a[]);
void fillArr(int a[]);

int main(){
	int v[LENGTH];
	int i;
	srand(time(NULL));
	
	
	fillArr(v);
	printArr(v);
	printf("\n");
	sort(v);
	printArr(v);
	printf("\n");
}

void printArr(int a[]){
	
	for(int i=0;i< LENGTH;i++){
		printf("%d,",a[i]);
	} 
}

void sort(int a[]){
	int tmp;
	
	for(int i=0;i<LENGTH -1;i++){
		for(int j=0;j<LENGTH -1-i;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}

void fillArr(int a[]){
	
	for(int i=0;i<LENGTH;i++){
		a[i]=rand()%20+1;
	}
}