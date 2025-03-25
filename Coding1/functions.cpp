// Brian Foster
// All about Functions

// warm-up task - create an array with three names.
// use a loop to display all of the names.
// compile and run this program to finish.


#include <iostream>
#include <string>
using namespace std;

// whenever possible - don't use global variables. it's safer. it avoids bugs.
// global variables go at the top, so that all the functions can use them.
int currentShirtSizeElement = 0;		// this keeps track of our shirtSize array
string professor = "Brian";


// declaring and defining a new function
// the function must be declared before it is used.
// the function CAN be defined later in the code.
// this function returns nothing.
// this function's name is "sayHello()"
void sayHello() {
	cout << "Hello!\n";
}

// build a sayGoodbye() function
// returnType nameOfFunction() { code goes here }
// then call the function after sayHello()
void sayGoodbye() {
	cout << "Goodbye!\n";
}

// adding two numbers with (parameters)
// parameters go inside the parenthesis
// they are the INPUTS for our function.
// optionally, we can add default values for our input parameters.
// we are creating two variables in the input parameter (parenthesis).
void add(int number1 = 2, int number2 = 0) {
	//cout << "The sum of number1 and number2 is ";
	cout << "The sum of " << number1 << " and " << number2 << " is ";
	cout << number1 + number2 << endl;
}

// overload the add function
// this one adds two floats!
// don't forget to call this function in main()
void add(float firstNum, float secondNum) {
	cout << firstNum << " plus " << secondNum << " equals ";
	cout << firstNum + secondNum << endl;
}

// break your brain before the break,
// overload add() to accept two strings.
// using concatenation!
// call with	add("coffee", "coffee");
void add(string firstWord, string secondWord) {
	cout << firstWord << " plus " << secondWord << " equals ";
	cout << firstWord + secondWord << endl;
}

// break until 11am
	// global variables
	// adventure 2.0




// return types - the OUTPUT of the function.
bool askYN(string question = "y/n?") {
	// in a do-while loop,
	do {
		cout << question << " (y/n)" << endl;	// ask the user the question
		string input;
		getline(cin, input);		// get input from player

		if (input == "y") {			// if y, return true
			return true;				// this quits the function
		}
		else if (input == "n") {	// if n, return false
			return false;
		}
		else {						// else, loop again.
			cout << "Please type 'y' or 'n'.\n";
		}

	} while (true);
}

// show array elements function
// doesn't return anything.
// accepts one parameter as a pointer (sshhhhh you don't know about those yet)
// call with 	show(names, 3);
void show(string* array, int arraySize) {
	cout << "Here are the contents of your array:\n";
	for (int i = 0; i < arraySize; i++) {
		cout << array[i] << endl;
	}
}



// create a function that accepts a pointer to an array of strings
// let it add another element, as long as there are spaces.
void addShirtSize(string* array) {
	string input;
	while(true) {
		if (currentShirtSizeElement > 9) {
			cout << "That is all the shirt sizes we can support.\n";
			break;
		}

		cout << "Please add a shirt size to the array.\n";
		cout << "or type 'done' to stop.\n";
		getline(cin, input);

		if (input == "done") {
			break;				// break out of the loop.
		}

		// increment the global counter
		array[currentShirtSizeElement++] = input;
	}
}

// in-class assignment
// 1. add a while loop to addshirtSize() that let's the user add sizes 
	// until they say DONE or they fill up the array.


int main() {
		
	// SETUP
	string shirtSizes[10];		// creating the array of shirtSHizes.
	// int currentSize = 0;
	addShirtSize(shirtSizes);		// add 3 shirt sizes
	show(shirtSizes, currentShirtSizeElement);				// show shirtSizes


	string playerName = "brian";	// local variable


	// calling the sayHello() function
	sayHello();
	sayGoodbye();
	add();
	add(23);		// when you call the function, you send the two input parameters.
	add(23, 2);
	add(22.2f, 23.5f);		// floats need 'f' after the numbers.

	if (askYN("Do you like pizza?")) {
		cout << "Let's get some pizza for lunch!\n";
	}
	else {
		cout << "I would not care to know you.\n";
	}

	string names[3];		// create an array
							// add three names
	names[0] = "Jack";
	names[1] = "Liz";
	names[2] = "Kenneth";

	show(names, 3);

	int counter = 0;
	while (counter < 3) {
		cout << names[counter++] << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << names[i] << endl;
	}
}

