#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAX 100

struct car{
	char model[WORDLENGTH];
	int year;
	int milage;
};
typedef struct car Car;

void printCar(Car c);
Car createCar(char model[],int year, int milage);
void regCars(Car reg[], int *pNrOfCars);
void printRegister(Car reg[], int nrOfCars);
void saveToFile(Car reg[],int nrOfCars);
void readFromFile(Car reg[],int *pNrOfCars);


int main(){
	Car carRegister[MAX];
	int nrOfCars=0;
	char choice;
	readFromFile(carRegister, &nrOfCars);
	while(choice != 'q'){
		printf("Register cars (r)\n");
		printf("View register (v)\n");
		printf("Quit (q)\n");
		scanf(" %c", &choice);
		switch(choice){
			case 'r': regCars(carRegister, &nrOfCars);
			break;
			case 'v': printRegister(carRegister, nrOfCars);
			break;
			case 'q': saveToFile(carRegister, nrOfCars);
			break;
		}
	}
}

void printCar(Car c){
	printf("Model: %s, Year: %d, Milage: %d\n",c.model,c.year,c.milage); 
}

Car createCar(char model[],int year, int milage){
	Car c;
	strcpy(c.model,model);
	c.year=year;
	c.milage=milage;
	return c;
}

void regCars(Car reg[], int *pNrOfCars){
	char again[WORDLENGTH] = "yes", model[WORDLENGTH], tmp[WORDLENGTH];
	int year, milage;
	gets(tmp);
	while(strcmp(again,"yes") == 0){
		printf("Enter model: ");
		gets(model);
		printf("Enter year: ");
		gets(tmp);
		year=atoi(tmp);
		printf("Enter milage: ");
		gets(tmp);
		milage=atoi(tmp);
		reg[*pNrOfCars]=createCar(model,year,milage);
		(*pNrOfCars)++;
		printf("Do you want to continue? (yes/no) ");
		gets(again);
	}
}

void printRegister(Car reg[], int nrOfCars){
	for(int i=0;i<nrOfCars;i++){
		printf("%d. Model: %s, Year: %d, Milage: %d\n", i+1, reg[i].model, reg[i].year, reg[i].milage);
	}
}

void saveToFile(Car reg[],int nrOfCars){
	FILE *fp;
	fp=fopen("minFil.txt","w");
	if(fp!=NULL){
		int year,milage;
		for(int i=0;i<nrOfCars;i++){
			fprintf(fp,"%s %d %d\n", reg[i].model, reg[i].year, reg[i].milage);
		}
		fclose(fp);
	}
}

void readFromFile(Car reg[],int *pNrOfCars){
	FILE *fp;
	fp=fopen("minFil.txt","r");
	if(fp!=NULL){
		char model[WORDLENGTH];
		int year,milage;
		while(fscanf(fp,"%s %d %d",model,&year,&milage)==3){
			reg[*pNrOfCars] = createCar(model,year,milage);
			(*pNrOfCars)++;
		}
		fclose(fp);
	}
}