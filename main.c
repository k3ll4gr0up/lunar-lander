#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define AE (unsigned char)142		/* Definition for Ä */
#define ae (unsigned char)132		/* Definition for ä */
#define OE (unsigned char)153		/* Definition for Ö */
#define oe (unsigned char)148		/* Definition for ö */
#define UE (unsigned char)154		/* Definition for Ü */
#define ue (unsigned char)129		/* Definition for ü */

int calculate(int height, int speed, int burn, int gravity) {
	return (speed+gravity-burn);
}

int help() {
	printf("Lunar Lander version 1.1\n");
	printf("Made by Lukas F%clling and Nicolai S%cper\n\n", ue, ue);
	printf("The following arguments are possible (only one):\n");
	printf("-d [1/2/3]\tDefine difficulty. 1 is easy 3 is hard.\n");
	printf("--info\tShow different intro.");
	printf("--help\tPrint this help and exit.\n");
	return 0;
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

int randomheight() {
	time_t t;
	
	time(&t);
	srand((unsigned int)t);
	return (rand() % 15000 + 4000);
}

int main(int argc, char *argv[]){
	
	const int gravity = 100;	/* The rate in which the spaceship descents in free fall (in ten seconds) */
	int height;					/* The height of the spaceship. */
	int speed;					/* The speed of the spaceship. */
	int burn;					/* The fuel which gets burned this step */
	int tensec;					/* The time the flight is running for. (in ten second steps) */
	int fuel;					/* The fuel you have left. (kilogram) */
	int prevheight;				/* The previous height to compare with actual. (coloured digits) */
	int step;					/* Counts the steps passed since last output of the collumn names */
	
	
	char version[]="1.1";		/* The Version of the program */
	char dead[]="\nThere were no survivors.\n\n";
	char crashed[]="\nThe Spaceship crashed. Good luck getting back home.\n\n";
	char success[]="\nYou made it! Good job!\n\n";
	char emptyfuel[]="\nThere is no fuel left. You're floating around like Wheatley.\n\n";
	
	printf("\nLunar Lander - Version %s\n", version);
	printf("This is a computer simulation of an Apollo lunar landing capsule.\n");
	printf("The on-board computer has failed so you have to land the capsule manually.\n");
	printf("Set burn rate of retro rockets to any value between 0 (free fall) and 200\n");
	printf("(maximum burn) kilo per second. Set burn rate every 10 seconds.\n"); /*that's wy we have to go with 10 second-steps.*/
	printf("Good Luck!\n");
	
		/* Set initial height, time, fuel, burn, prevheight, step and speed according to difficulty. */
		
	if(argc==1){					/* If there is only one argument (which is the program's name) */
		speed=1000;					/* Default to easy (and randomize the height) */
		height=randomheight();
		fuel=12000;
		tensec=0;
		burn=0;
		prevheight=height;
		step=1;
	}
	else {									/* If there are more arguments (or less) */
		if(strcmp(argv[1], "-d")==0){		/* If the "first" Argument is -d, check for the second argument*/
			if(strcmp(argv[2], "1")==0){	/* Easy */
				speed=1000;
				height=randomheight();
				fuel=12000;
				tensec=0;
				burn=0;
				prevheight=height;
				step=1;
			}
			if(strcmp(argv[2], "2")==0){	/* Medium */
				speed=1000;
				height=randomheight();
				fuel=1000;
				tensec=0;
				burn=0;
				prevheight=height;
				step=1;
			}
			if(strcmp(argv[2], "3")==0){	/* Hard */
				speed=2000;
				height=randomheight() - 2000;
				fuel=900;
				tensec=0;
				burn=0;
				prevheight=height;
				step=1;
			}
			else {					/* If argv[1] is not -d, default to Easy */
				speed=1000;
				height=randomheight();
				fuel=12000;
				tensec=0;
				burn=0;
				prevheight=height;
				step=1;
			}
		}	
		else if(strcmp(argv[1], "--info")==0){
			printf("\nLunar Lander - Version %s\n", version);
			printf("Made by Lukas F%clling and Nicolai S%cper\n\n", ue, ue);
			printf("\n\nContact us at http://k40s.net\n");
		}
		else if(strcmp(argv[1], "--help")==0){
			help();
			return 0;
		}
		else {					/* If the first Argument is something else, default to Easy */
			speed=1000;
			height=randomheight();
			fuel=12000;
			tensec=0;
			burn=0;
			prevheight=height;
			step=1;
		}
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
