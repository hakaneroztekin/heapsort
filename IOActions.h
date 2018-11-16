#include <iostream>
#include <fstream>
using namespace std;

class IOActions{
public:
	ifstream dataFile;
	IOActions(){}; // default constructor
	void openFile(); // take input file
	void saveFile(); // save output file
	void closeFile(); // close input file
	ifstream & getDataFile();
	string ** readFile(int size);
	~IOActions(){}; // destructor
};