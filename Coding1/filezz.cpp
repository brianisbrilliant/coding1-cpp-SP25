#include "filezz.h"

void WriteToFile(string givenString) {
	// open (or create) the file
	ofstream file("file.txt", ios::app);		// ios::app to append to end of file.

	// early return if the file cannot be opened.
	if (!file.is_open()) {
		cout << "Could not open file.\n";
		return;
	}

	// write text to the open file
	file << givenString;

	// close the file (which saves it to disk)
	file.close();

}

void ReadFromFile() {
	string fileContents;			// this is where we store the text in the file.

	// open the file
	ifstream file("file.txt");

	// check that it's actually open
	if (!file.is_open()) {
		cout << "could not open the file.\n";
	}

	// cout everything in the file
	while (getline(file, fileContents)) {
		cout << fileContents << "\n";
	}

	// close the file.
	file.close();
}