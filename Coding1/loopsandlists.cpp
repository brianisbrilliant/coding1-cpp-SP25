// Brian Foster Coding1b Feb 20th, 2025
// Loops and Lists

#include <iostream>
#include <string>
#include <ctime>			// for random numbers
#include <cstdlib>			// for random numbers
using namespace std;

int main() {
	srand(time(0));			// for random numbers
	cout << "welcome to week 5!\n";
	
	// if/else if/else
	// variables
	// while and do-while
	// random numbers


	cout << "What program would you like to run?\n";
	cout << "Press 1 for keep playing.\n";
	cout << "Press 2 for Player name.\n";

	string input;			// make a variable to store the input from the player
	getline(cin, input);	// get the input from the player

	// test the input from the player
	// stoi() stands for "string to integer" and converts a string to an integer (if it can)
	if (stoi(input) == 1) {
		cout << "Let's start the Keep Playing program!\n";
	}
	else if (stoi(input) == 2) {
		cout << "Let's start the Player Name program.\n";
	}
	else {
		cout << "I didn't understand that request.\n";
	}

	// lists
		// arrays
		// vectors
	// loops
		// for loop
	// more logic
		// switch statement
		// if/elseif/else

	// arrays
	string colors[4];

	colors[0] = "Red";
	colors[1] = "Blue";
	colors[2] = "Green";
	colors[3] = "Yellow";

	cout << "The first color in our array of colors is " << colors[0] << ".\n";

	// let's loop through all of the colors.
	// 10:29am - see image of whiteboard
	cout << "\nHere are all of the colors in the array:\n";
	int iterator = 0;					// the iterator counts, starting at 0
	while (iterator < 4) {				// loop as long as we're less than the array's size				
		cout << colors[iterator] << "\n";		// send the array element's value to the console.
		iterator += 1;					// add 1 to the iterator
	}

	// let's build a new list, using player input.
	cout << "Who are your best friends?\n";

	// keep using string input from earlier.
	string bestfriends[10];		// size of 10. arrays must specify size in c++.
	int currentElement = 0;		// this points at the next available spot in the array
	do {
		cout << "enter a name, or type 'quit' to quit.\n";
		
		getline(cin, input);				// using cin, get input and assign it to temp
		
		if (input == "quit") {
			break;				// they said quit, that's not one of their friends.
		}

		bestfriends[currentElement++] = input;		// after currentElement is used, add 1

	} while (currentElement < 10);			// ! is the not operator. 
										// "loop while input is NOT equal to quit"
											// and while currentElement is <= 10.

	// error looks like this:
	// there's a main()::input AND a do::input

	cout << "Here are all of your best friends. Looks like a great party!\n";
	// for(setup, test, action) { code }
	for (int i = 0; i < currentElement; i++) {
		cout << bestfriends[i] << "\n";
	}

	// in-class assignment - replace 10 with currentElement to shorten the list.
	// Done

	// create an array of 33 random numbers between 1777 and 2025
	// then, tell the user what the highest number in that array is.

	// use pseudocode to plan your program.
	/*	this is a block comment
		1. get the includes from other homework

		2. create the array
		string years[33];

		3. create highscore (or "mostRecentYear")
		highscore = 0

		4. create a random number within the range of 1777-2025)
		get the range by saying 2025 - 1777 = 248

		does 0+1777 = 1777? yes
		does 248 + 1777 = 2025?yes


			// add 1 to the "range" because modulus gives us 1 less as a max.
		int years = (rand() % 249) + 1777;		//placeholder

		if(years > highscore) 
			// replace highscore with years[i]

		print years at end of program.
		
	*/
	int min = 1777;
	int max = 2025;
	int range = max - min;
	int randomYear = (rand() % (range + 1)) + min;

	// prof's pseudocode
		// add includes 
		// seed the random number generator
	// create the array of intergers with a size of 33 (var type, var name, [var size]);
	int randomYears[33];

	// use a for loop to generate 33 random numbers and assign them to the array
		// optionally check "mostRecentYear" at the end of each loop
	
	// run 33 times, adding a random number to the array each time.
	// let's check for most recent year
	int mostRecentYear = 0;
	for (int i = 0; i < 33; i++) {
		randomYears[i] = (rand() % (248 + 1) + 1777);

		// is this year more recent than the previous record?
		if (randomYears[i] > mostRecentYear) {
			mostRecentYear = randomYears[i];
		}
	}

	// show all years.
	for (int i = 0; i < 33; i++) {
		cout << randomYears[i] << "\n";
	}

	cout << "The most recent year in the list is " << mostRecentYear << ".\n";


		// print the most recent year.
			// Extra requirement, print all years.
	



	return 0;
}