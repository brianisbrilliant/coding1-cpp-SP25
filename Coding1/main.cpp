#include <iostream>
#include "filez.h"

using namespace std;

class bot {
    string name;
    int charge;

public:
    bot(string n, int c) {
        name = n;
        charge = c;
    }
};

void SaveBinary() {

}

void LoadBinary() {

}

int main() {

    bot bob("Bob", 9);


    cout << "Saving text to a new file.\n";
    SaveTextToNewFile();

    cout << "appending more text to the file.\n";
    AppendToEndOfFile("More text");

    cout << "Checking to see if the file is open...\n";
    CheckingOpenStatus();

    cout << "reading from file.\n";
    ReadingFromFile();

    return 0;
}