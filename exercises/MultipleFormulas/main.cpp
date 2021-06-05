#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../../utils/exercise.h"

const string MULTIPLE_FORMULAS_TEST_CASES = "./exercises/MultipleFormulas/testCases.txt";

class MultipleFormulas:public Exercise{
private:
	vector<char> operations = {'+','-','*','/'};

	void input(){
		fstream reader(MULTIPLE_FORMULAS_TEST_CASES);
		int testCases,numbers,target;
		reader>>testCases;

		for (int i=0;i<testCases;i++){
			reader>>numbers>>target;
			cout<<"test case "<<i+1<<": "<<numbers<<' '<<target<<endl;
			solve(numbers,target,1,"");
		}
	}

	void solve(int numbers,int target,int current,string partial){
		if (current>numbers){
			if (evaluate(partial)==target)
				cout<<partial<<endl;
			return;
		}

		for (int i=0;i<4;i++){
			if (current==1 && operations[i]=='*' || operations[i]=='/') continue;

			string cur = partial+operations[i]+to_string(current);
			solve(numbers,target,current+1,cur);
		}
	}

	float evaluate(string formula){
		float amount = 0;
		string currentNumber = "";
		for (int i=0;i<formula.length();i++){
			if (!isNumber(formula[i])){
				char op = formula[i++];

				while (i<formula.length() && isNumber(formula[i]))
					currentNumber+=formula[i++];
				i--;

				int change = operate(amount,op,stoi(currentNumber));
				currentNumber = "";
				amount = change;
			}
		}
		return amount;
	}

	bool isNumber(char a){
		return count(operations.begin(), operations.end(),a)<=0;
	}

	float operate(float amount,char op,int num){
		if (op=='+')
			return amount+num;
		if (op=='-')
			return amount-num;
		if (op=='*')
			return amount*num;
		return amount/num;
	}

public:
	void init(){
		input();
	}
};
