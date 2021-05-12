#include <iostream>
#include <vector>
#include <fstream>
#include "../../utils/exercise.h"

using namespace std;

const string TEST_FILE_PATH = "./exercises/RepeatedNumbers/testCases.txt";

class RepeatedNumbers:public Exercise{
private:
	vector<vector<int>> array;

public:

	void init(){
		input();
		output();
	}

private:
	void input(){
		fstream reader(TEST_FILE_PATH);
		int n,m;

		cout<<"Number of test cases \n";
		reader>>n;

		for (int i=0;i<n;i++){
			cout<<"Number of elements in array "<<i<<" : ";
			array.push_back({});
			reader>>m; cout<<m<<'\n';
			for (int j=0;j<m;j++){
				int aux;
				reader>>aux;
				array[i].push_back(aux);
			}
		}
	}

	void output(){
		for (int i=0;i<array.size();i++){
			cout<<"Linear solution O(N) "<<i<<" :"<<linearSolution(array[i][0],1,array[i])<<'\n';
			cout<<"Logarithmic solution O(ln(N)): "<<logarithmicSolution(0,array[i].size(),array[i])<<'\n';
		}
	}

	int linearSolution(int prev,int i, vector<int> array){
		if (i>=array.size() || prev!=array[i]){
			return prev;
		}
		return linearSolution(array[i+1],i+2, array);
	}

	int logarithmicSolution(int start,int end,vector<int> array){
		int midPos = (end-start)/2 + start;

		if (midPos==array.size() || midPos==0)
			return array[start];
		if (end-start==1)
			return array[start+1];

		bool isMidEven = midPos%2==0;
		bool areEqual = array[midPos]==array[midPos+1];

		if ((areEqual && isMidEven) || (!areEqual && !isMidEven))
			return logarithmicSolution(midPos,end,array);
		else
			return logarithmicSolution(start, midPos, array);
	}

};