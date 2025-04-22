#include "filez.h"
#include <string>
#include <iostream>
using std::cout;

void ReadingFromFile(string filename) {
    // this will hold each line in the text document.
    string line;
    // Input File Stream
    ifstream file(filename);

    if (file.is_open()) {
        // get each line and assign it to the line variable.
        while (getline(file, line)) {
            cout << line << "\n";
        }
    }
    else {
        cout << "Cannot read from file.\n";
    }
}

void CheckingOpenStatus(string filename) {
    // see how I create the variable
    // and open it at the same time:
    // Output File Stream
    ofstream file(filename);
    if (file.is_open()) {
        file << "This is a line.\n";
        file << "This is another line.\n";
        file.close();
    }
    else {
        // cout << "unable to open file.\n";
    }

    return;
}

void AppendToEndOfFile(string text) {
    // Output File Stream
    ofstream file;
    file.open("save.txt", ios::out | ios::app);
    file << text << "\n";
    file.close();
}

void SaveTextToNewFile() {
    // Output File Stream
    ofstream file;
    file.open("save.txt");
    file << "Writing this to a file.\n";
    file.close();
}