#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int calculate(int height, int speed, int burn, int gravity) {
	return (speed+gravity-burn);
}

int main(){	
	const int gravity = 100;						/* The rate in which the spaceship descents in free fall (in ten seconds) */
	int height;							/* The height of the spaceship. */
	int speed;							/* The speed of the spaceship. */
	int burn;							/* The fuel which gets burned this step */
	int tensec;							/* The time the flight is running for. (in ten second steps) */
	int fuel;							/* The fuel you have left. (kilogram) */
	char title[]="Lunar Lander - Version 0.0.1";
	char license[]="Licensed under the GPLv2.";
	char start[]="Press any key to start.";
	char intro0[]="This is a computer simulation of an Apollo lunar landing capsule.";
	char intro1[]="The on-board computer has failed so you have to land the capsule manually.";
	char intro2[]="Set burn rate of retro rockets to any value between 0 (free fall) and 200";
	char intro3[]="(maximum burn) kg per second. Set burn rate every 10 seconds."; /*that's wy we have to go with 10 second-steps.*/
	char intro4[]="Good Luck!";
	char dead[]="\nThere were no survivors.";
	char crashed[]="\nThe Spaceship crashed. Good luck getting back home.";
	char success[]="\nYou made it! Good job!";
	int row,col;							/* store the number of rows and */
							                /* the number of colums of the screen, */
	initscr();					                /* start the curses mode, */
	getmaxyx(stdscr,row,col);					/* get the number of rows and columns, */
	mvprintw(row/2,(col-strlen(title))/2,"%s",title);		/* print the message at the center of the screen */
	mvprintw(row-2,(col-strlen(license))/2,"%s",license);
	mvprintw(row-1,(col-strlen(start))/2,"%s",start);
	refresh();
	getch();
	clear();
	mvprintw(1,1,"%s",intro0);					/*Here we draw the intro.*/
	mvprintw(2,1,"%s",intro1);
	mvprintw(3,1,"%s",intro2);
	mvprintw(4,1,"%s",intro3);
	mvprintw(5,1,"%s",intro4);
	refresh();
	getch();
	endwin();							/* End Curses Mode.*/

	
	/* Set initial height, time, fuel and speed. */
	speed=1000;
	height=12000;
	fuel=12000;
	tensec=0;
	
	do {
		printf("\n%d0 Seconds passed.", tensec);
		if(fuel=0)  {
			printf("\nNo fuel left.");
		}
		else{
			printf("\nYou have %d kg of fuel left.", fuel);
		}
		printf("\nHeight: %d", height);
		printf("\nBurn: ");
		scanf("%i", &burn);
	
		if(burn<0 || burn>200) {
			printf("The burn rate rate must be between 0 and 200.\n");
			continue;
		}
		fuel = fuel-burn;
		speed = calculate(height, speed, burn, gravity);
		tensec++;
	
	}while(height>0);
	
	if(speed>10){
		printf("%s", dead);
	}
	else if(speed<10){
		printf("%s", crashed);
	}
	else if(speed=0){
		printf("%s", success);
	}
	
	return 0;
}
