#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

void printArr(int a[], int n);
void sort(int a[], int n);

int main(){
	int v[LENGTH];
	int i;
	srand(time(NULL));
	
	
	for(i=0;i<LENGTH;i++){
		v[i]=rand()%20+1;
	}
	
	printArr(v, LENGTH);
	printf("\n");
	sort(v, LENGTH);
	printArr(v, LENGTH);
	printf("\n");
}

void printArr(int a[], int n){
	
	for(int i=0;i< LENGTH;i++){
		printf("%d,",a[i]);
	} 
}

void sort(int a[], int n){
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