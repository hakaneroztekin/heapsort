#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "IOActions.h"
#include "Data.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
std::vector<std::string> split(const std::string &s, char delim);


void IOActions::openFile(){  // take input file
	ifstream & dataFile = this->dataFile;

	dataFile.open("log_inf.csv");
	if (!dataFile.is_open()){
		cout << "File open error";
	}
}

string ** IOActions::readFile(int size){
	string line;
	int lineCounter = 0;
	getline(dataFile, line); // skip the first line
	vector<string> tokens;
	string** wholeArray = new string*[size]; // initialize the 2D array
	for (int i = 0; i < size; ++i)
		wholeArray[i] = new string[42];

	istringstream sin(line);

	while (getline(dataFile, line) && lineCounter < size){
		std::vector<std::string> splitVector = split(line, ',');
		for (int i = 0; i < 42; i++){ // 42 is the column number
			string * test = &splitVector[i];
			wholeArray[lineCounter][i] = splitVector[i];
			//			cout << wholeArray[lineCounter][i] << "\t" << i << "\n";
		}

		//		cout << "Line #" << lineCounter << " " << wholeArray[lineCounter][0] << endl;
		lineCounter++;
	}

	return wholeArray;
}

void IOActions::saveFile(){ // save output file

}

void IOActions::closeFile(){
	this->dataFile.close();
}

ifstream & IOActions::getDataFile(){
	return this->dataFile;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}