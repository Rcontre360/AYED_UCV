#include <iostream>
#include <fstream>
#include "../../utils/exercise.h"

using namespace std;

//must be directory from executable file.
const string MCD_TEST_CASES = "./exercises/MCD/testCases.txt";

class MCD:public Exercise{
private: 
	int *a,*b,numberOfTests;

	void readInput(){
		ifstream reader(MCD_TEST_CASES);
		reader>>numberOfTests;
		a = new int[numberOfTests];
		b = new int[numberOfTests];
		for (int i=0;i<numberOfTests;i++)
			reader>>a[i]>>b[i];
	}

	void printOutput(){
		for (int i=0;i<numberOfTests;i++)
			cout<<"Test number "<<i+1<<". "<<a[i]<<" and "<<b[i]<<": "<<mcd(a[i],b[i])<<'\n';
	}

	//tail recursion
	int mcd(int a,int b){
		int firstArgument, secondArgument;
		if (a>b){
			firstArgument = a-b;
			secondArgument = b;
		} else if (a<b){
			firstArgument = a;
			secondArgument = b-a;
		} else  {
			return a;
		}
		return mcd(firstArgument,secondArgument);
	}

public:
	void init(){

		readInput();
		printOutput();

	}
};
