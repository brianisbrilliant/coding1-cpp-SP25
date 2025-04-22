#include "filemgmt.h"

void ReadFromFile() {
	// this string will hold what the file contains.
	string fileContents;		// how do I add the contents of the file without using cout in the while loop?

	// open the file 
	ifstream file("file.txt");

	// for each line in the file, add it to the string.
	while (getline(file, fileContents)) {
		cout << fileContents << "\n";
	}

	// close the file so that other programs can use it.
	file.close();

}

void WriteToFile() {
	// opening the "file.txt" file. if it doesn't exist, create it.
	ofstream file("file.txt");

	// write a line to the file... well, to the buffer of the open file.
	file << "Play Ocarina of Time!\n";

	// close the file (saves it to disk)
	file.close();

}

void WriteArrayToFile(string* arr, int size) {

	ofstream file("favs.txt");			// open (or create) the file "favs.txt"

	if (!file.is_open()) {
		return;							// don't try to write to a file that is not open.
	}

	for (int i = 0; i < size; i++) {	// for each line in the array, add a line to the file
		file << arr[i] << ",";
	}

	// close the file (saves it to disk)
	file.close();
}