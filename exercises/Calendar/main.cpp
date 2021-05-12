#include <iostream>
#include <string>
#include "../../utils/exercise.h"

const string TEST_CASES_PATH = "./exercises/Calendar/testCases.txt";

#include "./Solution1.cpp"
#include "./Solution2.cpp"

using namespace std;

class Calendar:public Exercise{
public:
	void init(){
		Exercise *solution1 = new Solution1();
		Exercise *solution2 = new Solution2();

		cout<<"Calendar exercise, solution 1: \n\n";
		solution1->init();
		cout<<"Calendar exercise, solution 2: \n\n";
		solution2->init();
	}
};