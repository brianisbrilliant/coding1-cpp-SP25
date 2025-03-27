// Brian Foster Coding 1 Week 10
// Functions today!

#include <iostream>
#include <string>
using namespace std;

// global variables are dangerous
// global variables exist in all functions in this source file.
const bool debug = false;


// Functions!
//f(x) = y
//f(input) = output
//f(2) = 4
//f(3) = 6
//f(4) = 8

//all functions have a return type, a name, and (input parameters)
// declaring and defining a new function named "sayHello"
// it has a return type of void, which means it returns nothing
// it has one input parameter named "greeting" with a default value of "Hello!"
void sayHello(string greeting = "Hello!") {
	cout << greeting << "\n";
}

// declare the function here
// and define it AFTER main
void sayGoodbye(string asdf = "aloha");


// function name is .... triple(int givenNumber)
int triple(int givenNumber) {
	if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

	return givenNumber * 3;					// this is the output of the function.
}

// function overloading.
// function name is .... triple(double givenNumber)
double triple(double givenNumber) {
	if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

	return givenNumber * 3;
}

// function name is .... triple(float givenNumber)
float triple(float givenNumber) {
	if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

	return givenNumber * 3;
}

// function name is .... triple(string givenNumber)
string triple(string givenNumber) {
	if (debug) cout << "[givenNumber: " << givenNumber << ".]\n";

	return givenNumber + givenNumber + givenNumber;
}

// creating a new function named "getPlayerName"
// return type is string, with two input parameters for minSize and maxSize
string getPlayerName(int minSize = 5, int maxSize = 15) {
	string input;							// to store the player's input

	do {
		cout << "What is your name?\n";
		getline(cin, input);

		// data validation
		if (input.size() < minSize) {
			cout << "Your name needs to be at least " << minSize <<" characters.\n";
		}
		else if (input.size() > maxSize) {
			cout << "Your name needs to be fewer than " << maxSize + 1 << " characters.\n";
		}
		else {
			string greeting = "Hello " + input + "!";			// create a greeting that includes 
			sayHello(greeting);									// the player's name
			return input;										// output = player's name
		}
	} while (true);
}

// 10 minute task:
// create a function that returns a random number between min and max.
// ask the player for a min number, and a max number, 
// then use the function to return a random number between those values.

// helpful hints
// what will the function return?
// what are the inputs of the function?
// #include <cstdlib>
// #include <ctime>
// srand(time(0));   ... put this in main()

// getline(cin, input)
// int min = stoi(input);
// 
// for a random number between min and max: rand() % (max - min) + min;
// int range = (max - min) + 1;
// rand() % range + min;

int randomNumberInRange(int min = 0, int max = 10) {
	// check to ensure that max is larger than min.
	if (min >= max) {
		cout << "I cant' use those numbers.\n";
		return -1;
	}

	// calculate range
	int range = (max - min) + 1;		// 56 - 50, for example
	// return randon number
	return rand() % range + min;		// min = 50, for example.
}


bool randomBool() {
	int number = rand() % 10;

	// 50% of the time
	if (number > 4) 
		return true;
	else 
		return false;
}



/* block comment */
int main() {
	if (randomBool()) {
		cout << "You've won a prize!!!\n";
		// if true, call adventure
	}

	string input;

	cout << "Min = what?: ";
	getline(cin, input);
	int min = stoi(input);

	cout << "Max = what?: ";
	getline(cin, input);
	int max = stoi(input);

	cout << "A random number between " << min << " and " << max;
	cout << " is " << randomNumberInRange(min, max) << ".\n";


	// call the function
	sayHello();
	sayHello("Welcome to the thunderdome!!!");
	sayGoodbye();
	sayGoodbye("Here's looking at you, kid.");

	string playerName = getPlayerName();		// don't HAVE to specify min and max size

	cout << "Triple of 4 is " << triple(4) << ".\n";
	cout << "Triple of 4 is " << triple(33.99) << ".\n";
	cout << "Triple of 4 is " << triple(5.35) << ".\n";

	cout << "triple of five is " << triple("five") << ".\n";

	//cout << "Hello!\n";
	cout << "Please enter your top three favorite foods: \n";
	string input;		// to keep track of what the user types

	string favFoods[11];

	for (int i = 0; i < 3; i++) {					// 
		cout << "fav food #" << i + 1 << ": ";		// prompt the player with text
		getline(cin, input);						// get input from the player

		favFoods[i] = input;						// add that input to the array
	}

	cout << "Here are your favorite foods:\n";
	for (int i = 0; i < 3; i++) {					// run the loop 3 times
		cout << favFoods[i] << ".\n";				// output each favFood
	}
} // end of main



// after main, we can define our functions
void sayGoodbye(string farewell) {
	cout << farewell << "\n";
}