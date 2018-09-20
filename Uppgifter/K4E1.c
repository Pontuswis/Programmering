#include <stdio.h>

int main() {
	{
		int i = 5;
		int j = 3;
		printf("%d %d\n", i / j , i % j);
	}
	{
		int i = 2;
		int j = 3;
		printf("%d\n", (i + 10) % j);
	}
	{
		int i = 7;
		int j = 8;
		int k = 9;
		printf("%d\n", (i + 10) % k / j);
	}
	{
		int i = 1;
		int j = 2;
		int k = 3;
		printf("%d\n", (i + 5) % (j + 2) / k);
	}
	
	
}