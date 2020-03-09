// Oracio Gonzalez 
// CST 210 Mastermind 


#include "Game.h"
#include <string>
#include <iostream>


using namespace std; 

Game::Game() // creates game 
{

	numGuesses = 0;
	int numcorrect = 0;
	bool outOfTurns = true; // variable allows to keep track of turns 
	SecretCode(); // calls SecretCode generator 
	// secretcode.print(); // used in case we want to test program more accurately

	for (int i = 0; i < 10; i++) {  // for loop runs the program up to 10 turns if needed
									// also the loop determines if user has run within 10 turns and displays "YOU WON" and the number of turns it took them
		getUserGuess();
		numcorrect = 0;
		for (int j = 0; j < 4; j++) {
			if (secretcode[j] == currentGuess[j]) {
				numcorrect++;
				if (numcorrect == 4) {
					cout << "Ganaste!!(spanish for YOU WON!!)" << endl;
					cout << "Number of turns it took you: " << i << endl;
					exit(0);
				}
			}

		}
		
		currentGuess.print();

		genFeedback(); 

		cout << "Black pegs: " << bp << endl;
		cout << "White pegs: " << wp << endl;


	}

	cout << "It's been 10 turns means YOU LOSE!!! Go home, you wack! " << endl;

	cout << "This was what you were aiming for: "; // displays the secretcode after user has complete 10 turns without guessing correctly 
	for (int i = 0; i < 4; i++) {
		cout << secretcode[i];

	}
	

}

int getIntInput() {
	// function came from stack overflow: this function gets valid integers from the user and will tell the user that 
	//										anything other than a interger is in valid 
			
	int x = 0;
	while (!(cin >> x)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again, please: ";

	}

	return x;
}


int getSingleGuess() { //this function gets an input from the user that's a number within 1 and 6 
		int n = 0;
		while (true) {
			n = getIntInput();
			if (n < 1 || n>6) {
				cout << "NO! Please enter numbers between 1 and 6: " << endl; // displays if integers are not within the given range
			}
			else {
				break;
			}
		}
		return n;
	
}

void Game::getUserGuess() { // creates getUserGuess
	cout << "Number = Color \n 1 = Blue\n 2 = yellow\n 3 = green\n 4 = black\n 5 = white\n 6 = red" << endl; //displays key for what integers equal what colors
	cout << "Please enter your guess here: " << endl;

	int n1 = getSingleGuess(); // calls getSingleGuess so user can enter single numbers at a time 
	int n2 = getSingleGuess();
	int n3 = getSingleGuess();
	int n4 = getSingleGuess();

	
	currentGuess.setGuess(n1, n2, n3, n4);


	// cin >> ;


}

void Game::SecretCode()

{
	secretcode.setCode();
	// secretcode.setCode();
	// secretcode.setGuess(6, 2,2,2);
}

void Game::genFeedback() {
	
	wp = 0;
	bp = 0;
	int noDouble_j = 0;
	int noDouble[] = { 0,0,0,0 }; // array allows to check for bp/wp easily 

	for (int i = 0; i < 4; i++) {    // this for loop that has a if statement within allows to keep track of black pegs
		if (secretcode[i] == currentGuess[i]) {
			bp++;
			noDouble[i] = 1;
		}	

	}

	// nested for loop/if statement allows to keep track of the different scenarios white pegs could encounter


	for (int i = 0; i < 4; i++) {       // i keeps track of secretcode positions
		noDouble_j = 0;
		if (noDouble[i] != 1) {			// checks for no duplicates in the black pegs 

		
		for (int j = 0; j < 4; j++) {    // j keeps track of currentguess positions 
			if (currentGuess[i] == secretcode[j] && noDouble[j] == 0 && i!=j && noDouble_j==0) { // checks for duplicates for both i and j
				noDouble[j] = 2;
				noDouble_j++;
				wp++;
				break; 
			}

			}
				
				
		
		}
		
	}


}