#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDLENGTH 30
#define MAXPICTURES 10
#define MAX 10000

struct patient{
	char name[WORDLENGTH];
	char idNum[WORDLENGTH];
	int picRef[MAXPICTURES];
	int nrOfPics;
};
typedef struct patient Patient;

void databaseManagement(Patient patientDatabase[], int *pNrOfPatients,char fileName[]);
void regPatients(Patient patientDatabase[] , int *pNrOfPatients);
Patient createPatient(char name[], char idNum[], int picRef[], int nrOfPics);
void printDatabase(Patient patientDatabase[], int *pNrOfPatients);
void printPatient(Patient p);
void printMenu();
int searchSelect(Patient patientDatabase[], int *pNrOfPatients);
void searchName(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound);
void searchId(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound);
void searchPicRef(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound);
void sortSelect(Patient patientDatabase[], int *pNrOfPatients);
void sortByName(Patient patientDatabase[], int *pNrOfPatients);
void sortByidNum(Patient patientDatabase[], int *pNrOfPatients);
void addPictures(Patient patientDatabase[], int *pNrOfPatients);
void removePatient(Patient patientDatabase[], int *pNrOfPatients);
void saveToFile(Patient patientDatabase[], int *pNrOfPatients, char fileName[]);
void readFromFile(Patient patientDatabase[], int *pNrOfPatients, char fileName[]);
void selectFile(char fileName[]);

int main(){
	Patient patientDatabase[MAX];
	int nrOfPatients=0;
	char fileName[WORDLENGTH];
	selectFile(fileName);
	readFromFile(patientDatabase, &nrOfPatients, fileName);
	databaseManagement(patientDatabase, &nrOfPatients, fileName);
}

void databaseManagement(Patient patientDatabase[], int *pNrOfPatients, char fileName[]){
	char choice;
	while(choice != 'q'){
		printf("Register new patients (n)\n");
		printf("View all patients (v)\n");
		printf("Search for patients (s)\n");
		printf("Sort patients (z)\n");
		printf("Add pictures (a)\n");
		printf("Remove patient (r)\n");
		printf("Quit program (q)\n");
		scanf(" %c", &choice);
		switch(choice){
			case 'n': regPatients(patientDatabase, pNrOfPatients);
			break;
			case 'v': printDatabase(patientDatabase, pNrOfPatients);
			break;
			case 's': searchSelect(patientDatabase, pNrOfPatients);
			break;
			case 'z': sortSelect(patientDatabase, pNrOfPatients);
			break;
			case 'a': addPictures(patientDatabase, pNrOfPatients);
			break;
			case 'r': removePatient(patientDatabase, pNrOfPatients);
			break;
			case 'q': saveToFile(patientDatabase, pNrOfPatients, fileName);
			break;
		}
	}
}

void regPatients(Patient patientDatabase[] , int *pNrOfPatients){
	char again[WORDLENGTH] = "yes", name[WORDLENGTH], tmp[WORDLENGTH], idNum[WORDLENGTH];
	int picRef[WORDLENGTH];
	gets(tmp);
	while(strcmp(again,"yes") == 0){
		if(*pNrOfPatients<MAX){
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
				if(nrOfPics>=10){
					printf("You have entered the maximum number of pictures\n");
					break;
				}
			}
			gets(tmp);
			patientDatabase[*pNrOfPatients]=createPatient(name, idNum, picRef, nrOfPics);
			(*pNrOfPatients)++;
			printf("Do you want to continue? (yes/no) ");
			gets(again);
		}
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
	printMenu();
	for(int i=0;i<*pNrOfPatients;i++){
		printf("%s\t%s\t", patientDatabase[i].idNum, patientDatabase[i].name);
		printf("[ ");
		for(int j=0;j<patientDatabase[i].nrOfPics;j++){
			printf("%d ",  patientDatabase[i].picRef[j]);
		}
		printf("]");
		printf("\n\n");
	}
}

void printPatient(Patient p){
	printf("%s\t%s\t", p.idNum, p.name);
	printf("[ ");
	for(int i=0;i<p.nrOfPics;i++){
			printf("%d ",  p.picRef[i]);
		}
	printf("]");
	printf("\n\n");
}

void printMenu(){
	printf("ID-number\t Name\t\t Image references\n");
	printf("-----------------------------------------------------");
	printf("\n");
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

int searchSelect(Patient patientDatabase[], int *pNrOfPatients){
	char choice;
	int nrOfPatientsFound=0;
	int patientFound;
	printf("Search for name(n), id number(i) or Reference picture(p)? ");
	scanf(" %c", &choice);
	switch(choice){
		case 'n': searchName(patientDatabase, pNrOfPatients, &nrOfPatientsFound, &patientFound);
		break;
		case 'i': searchId(patientDatabase, pNrOfPatients, &nrOfPatientsFound, &patientFound);
		break;
		case 'p': searchPicRef(patientDatabase, pNrOfPatients, &nrOfPatientsFound, &patientFound);
		break;
	}
	if(nrOfPatientsFound==1){
		return patientFound;
	}
	else{
		patientFound=10001;
		return patientFound;
	}
}

 void searchName(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound){
	char searchWord[WORDLENGTH];
	scanf("%s", searchWord);
	printMenu();
	for(int i=0;i<*pNrOfPatients;i++){
		if(strstr(patientDatabase[i].name, searchWord)){
			printPatient(patientDatabase[i]);
			(*pNrOfPatientsFound)++;
			*pPatientFound=i;
		}
	}
}

void searchId(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound){
	char searchWord[WORDLENGTH];
	scanf("%s", searchWord);
	printMenu();
	for(int i=0;i<*pNrOfPatients;i++){
		if(strcmp(patientDatabase[i].idNum, searchWord)==0){
			printPatient(patientDatabase[i]);
			(*pNrOfPatientsFound)++;
			*pPatientFound=i;
		}
	}
}

void searchPicRef(Patient patientDatabase[], int *pNrOfPatients, int *pNrOfPatientsFound, int *pPatientFound){
	int searchNum;
	scanf("%d", &searchNum);
	printMenu();
	for(int i=0;i<*pNrOfPatients;i++){
		for(int j=0;j<patientDatabase[i].nrOfPics;j++)
		if(patientDatabase[i].picRef[j]==searchNum){
			printPatient(patientDatabase[i]);
			(*pNrOfPatientsFound)++;
			*pPatientFound=i;
		}
	}
}

void addPictures(Patient patientDatabase[], int *pNrOfPatients){
	int patientFound;
	char choice;
	patientFound=searchSelect(patientDatabase, pNrOfPatients);
	if(patientFound<10000){
		for(int i=patientDatabase[patientFound].nrOfPics;i<WORDLENGTH;i++){
			if(patientDatabase[patientFound].nrOfPics>=10){
				printf("You have entered the maximum number of pictures\n");
				break;
			}
			printf("Enter picRef: ");
			scanf("%d", &patientDatabase[patientFound].picRef[i]);
			if(patientDatabase[patientFound].picRef[i]==0){
				break;
			}
			patientDatabase[patientFound].nrOfPics++;
		}
	}
	printf("Do you want to search again? (y/n) ");
	scanf(" %c", &choice);
	if(choice=='y'){
		addPictures(patientDatabase, pNrOfPatients);
	}
}

void removePatient(Patient patientDatabase[], int *pNrOfPatients){
	int patientFound;
	char choice;
	patientFound=searchSelect(patientDatabase, pNrOfPatients);
	if(patientFound<10000){
		printf("Do you wish to remove this patient? (y/n) ");
		scanf(" %c", &choice);
		if(choice=='y'){
			for(int i=patientFound;i<*pNrOfPatients-1;i++){
				patientDatabase[i] = patientDatabase[i+1];
			}
			(*pNrOfPatients)--;
		}
	}
	printf("Do you want to search again? (y/n) ");
	scanf(" %c", &choice);
	printf("\n");
	if(choice=='y'){
		removePatient(patientDatabase, pNrOfPatients);
	}
}

void saveToFile(Patient patientDatabase[], int *pNrOfPatients, char fileName[]){
	FILE *fp;
	fp=fopen(fileName,"w");
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

void readFromFile(Patient patientDatabase[], int *pNrOfPatients, char fileName[]){
	FILE *fp;
	fp=fopen(fileName,"r");
	if(fp!=NULL){
		char firstName[WORDLENGTH], lastName[WORDLENGTH], idNum[WORDLENGTH]; 
		int picRef[MAXPICTURES];
		int nrOfPics=0, length, tmp;
		while(fscanf(fp,"%s %s %s %d", firstName, lastName, idNum, &nrOfPics)==4){
			for(int i=0;i<nrOfPics;i++){
				fscanf(fp,"%d", &picRef[i]);
			}
			length = strlen(firstName);
			firstName[length]=' ';
			firstName[length+1]='\0';
			strcat(firstName ,lastName);
			patientDatabase[*pNrOfPatients] = createPatient(firstName, idNum, picRef, nrOfPics);
			(*pNrOfPatients)++;
			if(*pNrOfPatients>=MAX){
				printf("The file is to large, entering the first 10000 patients\n");
				break;
			}
		}
		fclose(fp);
	}
}

void selectFile(char fileName[]){
	printf("Pease enter a file to open: ");
	gets(fileName);
	printf("\n");
}
