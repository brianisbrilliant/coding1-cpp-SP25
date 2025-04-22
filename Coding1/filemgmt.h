#pragma once			// please only compile the stuff in here once.
#include <string>
#include <iostream>
#include <fstream>			// for File Stream		// alternatively, use ifstream for reading from file
using namespace std;


void ReadFromFile();
void WriteToFile();
void WriteArrayToFile(string* arr, int size);