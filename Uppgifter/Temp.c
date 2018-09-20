#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int a[2];
	int tmp;
	
	srand(time(NULL));
	a[0] = rand();
	a[1] = rand();
	
	if(a[0]>a[1])
 {
		tmp=a[0];
		a[0]=a[1];
		a[1]=tmp;
 }
	for(int i=0;i< 2;i++) {
		printf("%d",a[i]);
		printf("\n");
}
	
}
