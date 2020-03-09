// Oracio Gonzalez 
// CST 210 Mastermind 


#pragma once
#include <iostream>

using namespace std; 


class Guess					// Guess holds the data members and member functions 

{
private:
	int theGuess[4]; 
	bool isValid; 
public:
	int operator[] (int); // here without the operator[] overload theGuess[] would have no meaning
	Guess();
	void setGuess(int, int, int, int);
	void setCode();

	void print() // function gets the user's guess and displays their guess in the console
	{
		cout << "Guess: ";
		for (int i = 0; i < 4; i++) {
			cout << theGuess[i] << "";

		}
		cout << endl;
	}






};

