// Brian Foster Coding 1 Spring 2025
// Week 14 Reading from and Writing To files.


#include "filezz.h"		// import the header file, which automatically imports the definitions too.
#include "ship.h"

int main() {
	cout << "Let's write some new files!\n";
	
	ReadFromFile();

	WriteToFile("Did you get the Switch 2 Preorder?\n");

	ship minnow;
	minnow.type = CRUISER;
	minnow.status();

	return 0;
}

/*
	files we'll use today

	1. mainw14.cpp		<-- this is the entry point for the rest of the program.
	2. filez.h
	3. filez.cpp
	4. ship.h
	5. ship.cpp

	the header file just has the #includes and the function declarations
	the source file (.cpp) will have the function definitions.

*/