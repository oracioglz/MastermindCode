// Oracio Gonzalez 
// CST 210 Mastermind 


#include "Guess.h"
#include <string>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


using namespace std;

Guess::Guess() // empty constructor
{
	

}

void Guess::setCode() // creates secret code 

{// key number = color

	// 1 = blue 
	// 2 = yellow 
	// 3 = green 
	// 4 = black 
	// 5 = white 
	// 6 = red

	srand(time(NULL)); // generates random numbers and also allows the program to not have the same number every time the program runs 

	for (int i = 0; i < 4; i++) {					// for loop sets up a parameter for the 4 secret code numbers to be within 1-6
		theGuess[i] = (rand() % 6) + 1;
	

	} 
	


};

void Guess::setGuess(int n1, int n2, int n3, int n4) { // creates a guess based on the inputted arguments 
													// sets argument values to respective order of guess 
	    theGuess[0] = n1;
		theGuess[1] = n2;
		theGuess[2] = n3;
		theGuess[3] = n4;

}

int Guess::operator[](int i) { // creates operator overloading for theGuess with [] 
	return theGuess[i];
 }

