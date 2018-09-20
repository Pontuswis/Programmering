#include <stdio.h>
#include <math.h>

#define LENGTH 10

int enterData(int measurements[], int nrOfMeasurements);
void viewData(int measurements[], int nrOfMeasurements);
int reset(int measurements[], int nrOfMeasurements);
void compute(int measurements[], int nrOfMeasurements);
int calcMax(int measurements[], int nrOfMeasurements);
int calcMin(int measurements[], int nrOfMeasurements);
float calcAvr(int measurements[], int nrOfMeasurements);
void copyArr(int measurements[], int tempArr[], int nrOfMeasurements);
void calcNorm(int tempArr[], int nrOfMeasurements);

int main(){
	char choice;
	int measurements[LENGTH] ={0};
	int nrOfMeasurements = 0;
	
	printf("Measurement tool 1.5\n");
	while(choice != 'q'){
		printf("VECRQ? ");
		scanf(" %c", &choice);
		
		switch(choice){
			case 'v': viewData(measurements, nrOfMeasurements);
			break;
			case 'e': nrOfMeasurements = enterData(measurements, nrOfMeasurements);
			break;
			case 'c': compute(measurements, nrOfMeasurements);
			break;
			case 'r': nrOfMeasurements = reset(measurements, nrOfMeasurements);
			break;
			case 'q': 
			break;
		}
	}
}

	int enterData(int measurements[], int nrOfMeasurements){

		for(int i=nrOfMeasurements;i<LENGTH;i++){
			printf("Enter measurement #%d (or 0)? ", nrOfMeasurements + 1);
			scanf("%d", &measurements[i]);
			if(measurements[i] == 0){
				break;
			}
			nrOfMeasurements++;
		}
	return nrOfMeasurements;
	
	}
	
	void viewData(int measurements[], int nrOfMeasurements){
		
		if(measurements[0] != 0){
			for(int i=0;i<nrOfMeasurements;i++){
				printf("%d ", measurements[i]);
			}
		}
		else{
			printf("No measurements");
		}
		printf("\n");
	}
	
	int reset(int measurements[], int nrOfMeasurements){
		
		for(int i=0;i<nrOfMeasurements;i++){
		measurements[i] = 0;
	}
	nrOfMeasurements = 0;
	return nrOfMeasurements;
	}
	
	void compute(int measurements[], int nrOfMeasurements){
		
		if(measurements[0] != 0){
			int max;
			int min;
			float avr;
			int tempArr[nrOfMeasurements];
		
			max = calcMax(measurements, nrOfMeasurements);
			min = calcMin(measurements, nrOfMeasurements);
			avr = calcAvr(measurements, nrOfMeasurements);
			copyArr(measurements, tempArr, nrOfMeasurements);
			calcNorm(tempArr, nrOfMeasurements);
			
			printf("Max value: %d\n", max);
			printf("Min value: %d\n", min);
			printf("Avr value: %0.2f\n", avr);
			printf("Normalized values: ");
			viewData(tempArr, nrOfMeasurements);
			
		}
		else{
			printf("No measurements\n");
		}
	}
	
	int calcMax(int measurements[], int nrOfMeasurements){
		
		int max;
		max = measurements[0];
		for(int i=1;i<nrOfMeasurements;i++){
			if(measurements[i]>max){
				max = measurements[i];
			}
		}
		return max;
		
	}
	
	int calcMin(int measurements[], int nrOfMeasurements){
		int min;
		min = measurements[0];
		for(int i=1;i<nrOfMeasurements;i++){
			if(measurements[i]<min){
				min = measurements[i];
			}
		}
		return min;
	}
	
	float calcAvr(int measurements[], int nrOfMeasurements){
		float sum=0;
		float avr=0;
		for(int i=0;i<nrOfMeasurements;i++){
			sum = sum + measurements[i];
		}
		avr = sum/nrOfMeasurements;
		return avr;
	}
	
	void copyArr(int measurements[], int tempArr[], int nrOfMeasurements){
		
		for(int i=0;i<nrOfMeasurements;i++){
			tempArr[i] = measurements[i];
		}
	}
	
	void calcNorm(int tempArr[], int nrOfMeasurements){
		float avr;
		avr = calcAvr(tempArr, nrOfMeasurements);
		
		for(int i=0;i<nrOfMeasurements;i++){
			tempArr[i] = roundf(tempArr[i] - avr);
		}
	}