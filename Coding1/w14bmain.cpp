// Brian Foster
// reading from and writing to files.
// let's try appending to a file this time.
// let's work on getting more out of our headers and other source files.
// maybe we can build an array of humans that we can write to a .csv file?

#include <iostream>
#include <fstream>				// filestream
#include <string>
using namespace std;

enum color {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};

class human {
public:
	string name;
	int age;
	color favColor;

	human(string givenName = "Bert", int givenAge = 22, color givenColor = ORANGE) {
		name = givenName;
		age = givenAge;
		favColor = givenColor;
	}
};

void AppendHumanToFile(human givenHuman) {
	// opening the "file.txt" file. if it doesn't exist, create it.
	ofstream file("file.txt");

	// write a line to the file... well, to the buffer of the open file.
	file << "Play Ocarina of Time!\n";

	// close the file (saves it to disk)
	file.close();
}


int main() {
	human bert;

	// okay, now write it to a csv file.
}