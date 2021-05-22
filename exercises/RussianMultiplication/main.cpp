#include <iostream>
#include <fstream>
#include "../../utils/exercise.h"

using namespace std;

//must be directory from executable file.
const string RUSSIAN_MULTIPLICATION_TEST_CASES = "./exercises/RussianMultiplication/testCases.txt";

class RussianMultiplication:public Exercise{
private: 
	int *a,*b,numberOfTests;

	void readInput(){
		ifstream reader(RUSSIAN_MULTIPLICATION_TEST_CASES);
		reader>>numberOfTests;
		a = new int[numberOfTests];
		b = new int[numberOfTests];
		for (int i=0;i<numberOfTests;i++)
			reader>>a[i]>>b[i];
	}

	void printOutput(){
		for (int i=0;i<numberOfTests;i++)
			cout<<"Test number "<<i+1<<". "<<a[i]<<" and "<<b[i]<<": "<<Multiplication(a[i],b[i])<<'\n';
	}

	//tail recursion?
	int Multiplication(int a,int b){
		int sum = a%2==1?b:0;
		if (a==0)
			return 0;
		return sum+Multiplication(a/2,b*2);
	}

public:
	void init(){

		readInput();
		printOutput();

	}
};
