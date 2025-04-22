#pragma once
#include <string>
#include <iostream>
#include <fstream>			// for File Stream		// alternatively, use ifstream for reading from file
using namespace std;

void SaveTextToNewFile();
void AppendToEndOfFile(string text);
void CheckingOpenStatus(string filename = "file.txt");
void ReadingFromFile(string filename = "data.txt");

