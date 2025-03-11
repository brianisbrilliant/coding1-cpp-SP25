// Brian Foster
// Week 8 Recap

#include <iostream>
#include <string>
#include <cstdlib>		// c standard library
#include <ctime>		// c time library.
using namespace std;


int main() {
	// seed the random number generator
	srand(time(0));

	bool debug = true;		// turn this to false when shipping the game.

	cout << "Hello world!\n";

	// ask the player if they prefer cheese or pepperoni pizza.
	// use an if, else if, and else to check their input
	// have the computer agree or disagree with their choice, or berate them for any other option.

	// ask the player if they prefer cheese or pepperoni pizza.
	cout << "What's your favorite pizza topping - Cheese or Pepperoni?\n";
	string input = "";
	getline(cin, input);

	// use an if, else if, and else to check their input
	// have the computer agree or disagree with their choice, or berate them for any other option.
	if (input == "Cheese")			cout << "That's my favorite topping too!\n";
	else if (input == "Pepperoni")	cout << "Pepperoni is okay.\n";
	else if (input == "Sausage")	cout << "Uhhh, okay.... cool.\n";
	else							cout << "EAUGH!! How could you like " << input << "?!?! GROSSS!!!\n\n";


	// build a guess the number game.
	// have the computer choose a random number between 1 and 10. (inclusive)
	// int theNumber = rand()...
	int theNumber = rand() % 10 + 1;
	// start a while loop
	while (true) {
		if (debug) cout << "The number is " << theNumber << ".\n";

		// ask the player to guess the number
		cout << "What is your guess?\n";
		getline(cin, input); 
		int playerGuess = 0;

		if (input == "quit") {
			cout << "oh, leaving already? See you again, I hope.\n";
			break;
		}

		try { 
			playerGuess = stoi(input); 
		}
		catch (invalid_argument) { 
			cout << "That's not a number, please try again.\n"; 
			continue; 
		}

		if (playerGuess == theNumber) {
			cout << "Yep! That's the number! You guessed it!\n";
			break;
		}

		if (playerGuess > theNumber) {
			cout << "Lower!\n";
		} 
		else {
			cout << "Higher!\n";
		}
	
	}
	// 
	// if they said "quit" break out of the loop.
	// if the number is correct, tell the player, and end the loop.
	// if the number is too high, have the computer say "lower!"
	// if the number is too low, have the computer say "higher!"
	// 
	// don't forget 
		// #include <cstdlib>
		// #include <ctime>
		// in main(), srand(time(0));

	// (hard mode) have the player pick a number, and let the computer guess.
	// second part - add a debug mode that will tell the player what the number is.
	// in main(), bool debug = true;
	// in loop, if(debug) cout << "The number is << theNumber << ".\n";

	cout << "give me a number\n";
	getline(cin, input);

	int playerGuess = 0;
	// advanced!
	try {
		playerGuess = stoi(input);
	}
	catch(invalid_argument) {
		cout << "That's not a number.\n";
	}


	if (playerGuess == 4) {
		cout << "Yep! that's a number.\n";
	}
	else {
		cout << "either the program crashed, or you typed a different number than 4.\n";
	}





	return 0;
}