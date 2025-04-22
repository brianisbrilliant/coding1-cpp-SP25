// Brian Foster April 22nd, 2025
// playing with multiple files today.
// saving and loading to files too.


#include "filemgmt.h"		// import the extra functions that we have created.
using namespace std;


// read array from file. that's homework. 

// inclass assignment: 
// in a new source file (.cpp) and with a header file (.h)
// create a new class named item with the following variables and functions
	// string name, int location, item(), use(), examine()


int main() {
	cout << "Play Ocarina of Time.\n";

	ReadFromFile();			// edit the file.txt to include 3 lines of games to play.
	WriteToFile();			// please confirm that the file was created on your hard drive.

	// the array of favorites
	string favs[100];
	int nextIndex = 0;

	cout << "Type out your favorites, or type 'done' to stop.\n";
	while (true) {
		string input;				// to store the user's input
		cout << ">> ";
		getline(cin, input);		// get the user's input

		if (input == "done") {		// check to see if they're done,
			break;						// if so, break out of the loop.
		}

		favs[nextIndex] = input;	// otherwise, assign the user's input to the array
		nextIndex++;				// and point at the next element in the array.

	}

	WriteArrayToFile(favs, nextIndex);
				
}