#include <stdio.h>

int main(){
	
	printf("Lunar decent challenge!\n");
	printf("You will pilot a lunar decent the last 250m.\n");
	printf("Each turn represent 1-second decent time.\n");
	printf("Set the throttle for each turn (0-100)\n");
	printf("But remeber you only have 500kg of fuel\n");
	
	int t = 0;
	float h = 250;
	float v = -25.0;
	int f;
	int b = 500;
	
	printf("Time	Height	Velocity Fuel Throttle?\n");
	
	while (h > 0){
		
		printf("%d	%.1f	%.1f	%d	", t, h, v, b );
		
		if (b > 0){
			scanf("%d", &f);
		}
		else{
			f = 0;
			b = 0;
			printf("WARNING! You are out of fuel!\n");
		}
		
		if (f > 100){
			printf("You cannot enter a number larger than 100\n");
			printf("Throttle is now set to 100\n");
			f = 100;
		}
		
		t++;
		h = h+v+(0.1*f-1.5)/2;
		v = v+(0.1*f-1.5);
		b = b-f;
	}
	
	if (v >= -2){
		printf("SUCCESS! You landed at %.1fm/s", v);
	}
	else {
		printf("FAILED! Crash landing at %.1fm/s", v);
	}
}