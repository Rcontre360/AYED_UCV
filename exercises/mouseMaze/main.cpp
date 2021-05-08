#include <iostream>
#include <vector>
#include "../../utils/fileReader.cpp"
#include "../../utils/exercise.h"

using namespace std;

const char 
	CHEESE = '%',
	FREE_FIELD = '.',
	BLOCKED_FIELD = '#'
;
const string TEST_CASES_FILE = "testCases.txt";

class MouseLaberinth:public Exercise{
private: 
	vector<vector<char>> table;

	int rows,columns,startRow,startColumn,maxNumberSteps;
	int I[4] = {-1,0,1,0};
	int J[4] = {0,1,0,-1};

	void readInput(){
		cin>>rows>>columns>>startRow>>startColumn>>maxNumberSteps;
		for (int i=0;i<rows;i++){
			char aux;
			vector<char> aux2;
			table.push_back(aux2);
			for (int j=0;j<columns;j++){
				cin>>aux;
				table[i].push_back(aux);
			}
		}
	}

	void printOutput(){
		cout<<"Mouse Laberinth:\n Using brute force: ";
		cout<<startBruteForce(startRow,startColumn,maxNumberSteps)<<'\n';
	}

	int startBruteForce(int posI,int posJ,int steps){
		int count = 0;
		int maxPath = 0;
		bool hasCheese = table[posI][posJ] == CHEESE;

		if (hasCheese){
			table[posI][posJ] = FREE_FIELD;
			count++;
		}

		for (int i=0;i<4;i++){
			int curI = posI+I[i], curJ = posJ+J[i];
			if (isVisitable(curI,curJ) && steps>0)
				maxPath=max(startBruteForce(curI,curJ,steps-1),maxPath);
		}

		if (hasCheese) 
			table[posI][posJ] = CHEESE;

		return count + maxPath;
	}

	bool isVisitable(int i,int j){
		return i<rows && i>=0 && j<columns && j>=0 && table[i][j]!=BLOCKED_FIELD; 
	}

public:
	void init(){

		readInput();
		printOutput();

	}
};
