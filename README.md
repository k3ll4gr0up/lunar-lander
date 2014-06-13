# ![lunar](http://k40s.net/download/lunar32.png) Lunar Lander [![Build Status](https://travis-ci.org/k3ll4gr0up/lunar-lander.png?branch=master)](https://travis-ci.org/k3ll4gr0up/lunar-lander)


This is a port in C of the original "Lunar Lander" video game, which is written in BASIC. [Tell me more.](http://k40s.net/post/lunar-lander/)

## Building

This application depends on:

- Linux because Windows(r)(tm) is crap.
- Build tools. Mainly gcc, make and some other stuff. 
- A VT1000 compatible terminal emulator for the color output.

Just run ```make``` if you have all depencies and ```make install``` to install. ```make clean``` will clean the project up.

## About this game

Lunar Lander was the first-ever PC game written in 1967 by a student. It was originally written in BASIC, but there are plenty of other languages out there in which this game is written. @nicolaisueper and myself go to the same school where we had to pick a topic for a project we had to do. We decided to write a text-based game in C. As we stumbled upon lunar-lander at [technologizer](http://technologizer.com/2009/07/19/lunar-lander/) we decided to write a similar program like this in C. 

So we took a look at the BASIC sources which we got [here](http://www.vintage-basic.net/bcg/lunar.bas) and began writing. Now the final version of our program is finished ~~and we are just about to begin working on a GUI version of this~~.

## Difficulty

You can change the difficulty of the game using the command-line argument "d". 
The usage is: 
```
lunar-lander -d [1/2/3]
```
Where 1 is the easiest and 3 the hardest. If you don't specify a difficulty, the easiest will be used.

