#include <stdio.h>

struct line{
	
	float k,m;
};
typedef struct line Line;

float xCrossing(Line l1){
	return -l1.m/l1.k;
}

int main(){
	
	Line myLine;
	myLine.k=-1;
	myLine.m=2;
	printf("Skarningen med x-axeln sker vid x = %f",xCrossing(myLine));
}