#include <iostream>
#include <fstream>
#include "../../utils/exercise.h"

using namespace std;

//must be directory from executable file.
const string TEST_CASES_FILE = "./exercises/mouseMaze/testCases.txt";

class RussianMultiplication:public Exercise{
private: 
	int a,b;

	void readInput(){
		ifstream reader;
		reader>>a>>b;
	}

	void printOutput(){
		
	}

public:
	void init(){

		readInput();
		printOutput();

	}
};
