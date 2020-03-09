// Oracio Gonzalez 
// CST 210 Mastermind 

#pragma once
#include "Guess.h"
#include <string>

using namespace std;

class Game		// Game holds the data members and member functions

{
private: 
	Guess secretcode;
	Guess currentGuess;
	int wp;
	int bp;
	int numGuesses;
	void getUserGuess();
	void genFeedback();
	bool isWinner();
	bool outOfTurns();
public:
	string getCode();
	void SecretCode();
	void playGame();
	Game();
};

