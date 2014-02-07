#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculate(int height, int speed, int burn, int gravity) {
	return (speed+gravity-burn);
}

int windowcleaner(int step) {
	if(step>=24){
		printf("\nTime\t");
		printf("Speed\t\t");
		printf("Fuel\t\t");
		printf("Height\t\t");
		printf("Burn\n");
		printf("----\t");
		printf("-----\t\t");
		printf("----\t\t");
		printf("------\t\t");
		printf("----\n");
		step=1;
	}
	else if(step<24){
		step++;
	}
	return step;
}

int main(int argc, char *argv[]){
	
	const int gravity = 100;	/* The rate in which the spaceship descents in free fall (in ten seconds) */
	int height;			/* The height of the spaceship. */
	int speed;			/* The speed of the spaceship. */
	int burn;			/* The fuel which gets burned this step */
	int tensec;			/* The time the flight is running for. (in ten second steps) */
	int fuel;			/* The fuel you have left. (kilogram) */
	int prevheight;			/* The previous height to compare with actual. (coloured digits) */
	int step;			/* Counts the steps passed since last output of the collumn names */


	char dead[]="\nThere were no survivors.\n\n";
	char crashed[]="\nThe Spaceship crashed. Good luck getting back home.\n\n";
	char success[]="\nYou made it! Good job!\n\n";
	char emptyfuel[]="\nThere is no fuel left. You're floating around like Wheatley.\n\n";

	printf("\nLunar Lander - Version 1.0\n");
	printf("This is a computer simulation of an Apollo lunar landing capsule.\n");
	printf("The on-board computer has failed so you have to land the capsule manually.\n");
	printf("Set burn rate of retro rockets to any value between 0 (free fall) and 200\n");
	printf("(maximum burn) kilo per second. Set burn rate every 10 seconds.\n"); /*that's wy we have to go with 10 second-steps.*/
	printf("Good Luck!\n");
	
		/* Set initial height, time, fuel, burn, prevheight, step and speed properly to difficulty. */
	if(argv[1]="-d"){
		if(argv[2]="1"){	/* Easy */
			speed=1000;
			height=12000;
			fuel=12000;
			tensec=0;
			burn=0;
			prevheight=12000;
			step=1;
		}
		if(argv[2]="2"){	/* Medium */
			speed=1000;
			height=12000;
			fuel=1000;
			tensec=0;
			burn=0;
			prevheight=12000;
			step=1;
		}
		if(argv[2]="3"){	/* Hard */
			speed=2000;
			height=900;
			fuel=900;
			tensec=0;
			burn=0;
			prevheight=12000;
			step=1;
		}
	}
	else {				/* Default: Easy */
		speed=1000;
		height=12000;
		fuel=12000;
		tensec=0;
		burn=0;
		prevheight=12000;
		step=1;
	}
	
	printf("\nTime\t");
	printf("Speed\t\t");
	printf("Fuel\t\t");
	printf("Height\t\t");
	printf("Burn\n");
	printf("----\t");
	printf("-----\t\t");
	printf("----\t\t");
	printf("------\t\t");
	printf("----\n");
	
	do {
		
		step=windowcleaner(step);
	
		printf("%d0\t", tensec);
		printf("%d\t\t", speed);
		printf("%d\t\t", fuel);
		
		if(height<prevheight){
			printf("\x1b[31m%d\x1b[0m\t\t", height);
		}
		
		else if(height==prevheight){
			printf("%d\t\t", height);
			
		}
		
		else if(height>prevheight){
			printf("\x1b[32m%d\x1b[0m\t\t", height);
		}
		
		scanf("%i", &burn);
		
		if(burn<0 || burn>200) {					/* If there is a wrong entry */
		printf("The burn rate rate must be between 0 and 200.\n");
		continue;
		}
		
		prevheight = height;
		speed = calculate(height, speed, burn, gravity);
		height=height-speed;
		fuel = fuel-burn;
		
		if(fuel<=0) {
			break;
		}
		
		tensec++;
			
	}while(height>0);
	
	if(height<=0){
		if(speed>10){
			printf("%s", dead);
		}
		else if(speed<10){
			printf("%s", crashed);
		}
		else if(speed>0 || speed<3){
			printf("%s", success);
		}
	}
	else if(height>0){
		printf("%s", emptyfuel);
	}
	
	return 0;
}
