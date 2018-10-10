#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAX 10000

struct patient{
	char name[WORDLENGTH];
	char idNum[WORDLENGTH];
	int picRef[WORDLENGTH];
	int nrOfPics;
};
typedef struct patient Patient;

void databaseManagement(Patient patientDatabase[], int *pNrOfPatients);
void regPatients(Patient patientDatabase[] , int *pNrOfPatients);
Patient createPatient(char name[], char idNum[], int picRef[], int nrOfPics);
void printDatabase(Patient patientDatabase[], int *pNrOfPatients);
void searchPatients();
void sortSelect(Patient patientDatabase[], int *pNrOfPatients);
void sortByName(Patient patientDatabase[], int *pNrOfPatients);
void sortByidNum(Patient patientDatabase[], int *pNrOfPatients);
void saveToFile(Patient patientDatabase[], int *pNrOfPatients);
void readFromFile(Patient patientDatabase[], int *pNrOfPatients);

int main(){
	Patient patientDatabase[MAX];
	int nrOfPatients=0;
	readFromFile(patientDatabase, &nrOfPatients);
	databaseManagement(patientDatabase, &nrOfPatients);
}

void databaseManagement(Patient patientDatabase[], int *pNrOfPatients){
	char choice;
	while(choice != 'q'){
		printf("Register patients (r)\n");
		printf("View all patients (v)\n");
		printf("Search for patients (s)\n");
		printf("Sort patients (z)\n");
		printf("Quit program (q)\n");
		scanf(" %c", &choice);
		switch(choice){
			case 'r': regPatients(patientDatabase, pNrOfPatients);
			break;
			case 'v': printDatabase(patientDatabase, pNrOfPatients);
			break;
			case 's': searchPatients();
			break;
			case 'z': sortSelect(patientDatabase, pNrOfPatients);
			break;
			case 'q': saveToFile(patientDatabase, pNrOfPatients);
			break;
		}
	}
}

void regPatients(Patient patientDatabase[] , int *pNrOfPatients){
	char again[WORDLENGTH] = "yes", name[WORDLENGTH], tmp[WORDLENGTH], idNum[WORDLENGTH];
	int picRef[WORDLENGTH];
	gets(tmp);
	while(strcmp(again,"yes") == 0){
		printf("Enter name: ");
		gets(name);
		printf("Enter id number: ");
		gets(idNum);
		int nrOfPics=0;
		for(int i=0;i<WORDLENGTH;i++){
			printf("Enter picRef: ");
			scanf("%d", &picRef[i]);
			if(picRef[i]==0){
				break;
			}
			nrOfPics++;
		}
		gets(tmp);
		patientDatabase[*pNrOfPatients]=createPatient(name, idNum, picRef, nrOfPics);
		(*pNrOfPatients)++;
		printf("Do you want to continue? (yes/no) ");
		gets(again);
	}
}

Patient createPatient(char name[WORDLENGTH], char idNum[], int picRef[], int nrOfPics){
	Patient p;
	strcpy(p.name, name);
	strcpy(p.idNum, idNum);
	for(int i=0;i<nrOfPics;i++){
		p.picRef[i]=picRef[i];
	}
	p.nrOfPics=nrOfPics;
return p;
}

void printDatabase(Patient patientDatabase[], int *pNrOfPatients){
	for(int i=0;i<*pNrOfPatients;i++){
		printf("Name: %s id number: %s Reference pictures: ", patientDatabase[i].name, patientDatabase[i].idNum);
		for(int j=0;j<patientDatabase[i].nrOfPics;j++){
			printf("%d, ",  patientDatabase[i].picRef[j]);
		}
		printf("\n");
	}
}

void searchPatients(){
	printf("SearchPatients\n");
}

void sortSelect(Patient patientDatabase[], int *pNrOfPatients){
	char choice;
	printf("Select sorting method\n");
	printf("By name (n) ");
	printf("By id number (i) ");
	scanf(" %c", &choice);
	switch(choice){
		case 'n': sortByName(patientDatabase, pNrOfPatients);
		break;
		case 'i': sortByidNum(patientDatabase, pNrOfPatients);
		break;
	}
}

void sortByName(Patient patientDatabase[], int *pNrOfPatients){
	Patient tmp;
	for(int i=0;i<*pNrOfPatients-1;i++){
		for(int j=0;j<*pNrOfPatients-1;j++){
			if(strcmp(patientDatabase[j].name, patientDatabase[j+1].name)>0){
				tmp=patientDatabase[j];
				patientDatabase[j]=patientDatabase[j+1];
				patientDatabase[j+1]=tmp;
			}
		}
	}
}

void sortByidNum(Patient patientDatabase[], int *pNrOfPatients){
	Patient tmp;
	for(int i=0;i<*pNrOfPatients-1;i++){
		for(int j=0;j<*pNrOfPatients-1;j++){
			if(strcmp(patientDatabase[j].idNum, patientDatabase[j+1].idNum)>0){
				tmp=patientDatabase[j];
				patientDatabase[j]=patientDatabase[j+1];
				patientDatabase[j+1]=tmp;
			}
		}
	}
}

void saveToFile(Patient patientDatabase[], int *pNrOfPatients){
	FILE *fp;
	fp=fopen("minFil.txt","w");
	if(fp!=NULL){
		for(int i=0;i<*pNrOfPatients;i++){
			fprintf(fp,"%s %s %d\n", patientDatabase[i].name, patientDatabase[i].idNum, patientDatabase[i].nrOfPics);
			for(int j=0;j<patientDatabase[i].nrOfPics;j++){
				fprintf(fp,"%d\n", patientDatabase[i].picRef[j]);
			}
		}
		fclose(fp);
	}
}

void readFromFile(Patient patientDatabase[], int *pNrOfPatients){
	FILE *fp;
	fp=fopen("minFil.txt","r");
	if(fp!=NULL){
		char firstName[WORDLENGTH], lastName[WORDLENGTH], idNum[WORDLENGTH]; 
		int picRef[WORDLENGTH];
		int nrOfPics=0, length, tmp;
		while(fscanf(fp,"%s %s %s %d", firstName, lastName, idNum, &nrOfPics)==4){
			for(int i=0;i<nrOfPics;i++){
				fscanf(fp,"%d", &tmp);
				picRef[i]=tmp;
			}
			length = strlen(firstName);
			firstName[length]=' ';
			firstName[length+1]='\0';
			strcat(firstName ,lastName);
			patientDatabase[*pNrOfPatients] = createPatient(firstName, idNum, picRef, nrOfPics);
			(*pNrOfPatients)++;
		}
		fclose(fp);
	}
}