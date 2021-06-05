#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "../../utils/exercise.h"

typedef vector<vector<int>> Matrix;

const string MAXIMUM_MATRIX_TEST_CASES = "./exercises/MaximumMatrix/testCases.txt";
const int INF = 99999999;


class WithKadane{
public:
	static vector<int> start(Matrix m){
		Matrix withSum = getSumMatrix(m);
		int max = -INF;
		vector<int> solved(4);

		for (int i=0;i<withSum.size();i++)
			for (int j=i;j<withSum.size();j++){
				vector<int> applyKadane = withSum[j];

				for (int k=0;k<applyKadane.size() && i!=j;k++)
					applyKadane[k]-=withSum[i][k];

				vector<int> res = kadaneAlgorithm(applyKadane);

				if (res[0]>max){
					solved[0] = i==j?0:i+1;
					solved[1] = j;
					solved[2] = res[1];
					solved[3] = res[2];
					max = res[0];
				}
			}

		return solved;
	}
private:
	static Matrix getSumMatrix(Matrix m){
		Matrix sum = m;
		for (int i=0;i<m.size();i++) sum[i] = m[i];

		for (int i=0;i<m.size();i++)
			for (int j=0;j<m[i].size();j++)
				if (i-1>=0)
					sum[i][j]+=sum[i-1][j];

		return sum;
	}

	static vector<int> kadaneAlgorithm(vector<int> in){
		int current = 0,best = -INF;
		vector<int> sections(3),aux(3);

		for (int i=0;i<in.size();i++){
			if (current+in[i]>0 && current<=0)
				aux[1] = i;
			current = max(current+in[i],0);

			if (current>best){
				aux[2] = i;
				sections = aux;
				best = current;
			}
		}
		sections[0] = best;
		return sections;
	}

};


class WithBacktracking{
public:
	vector<int> solution;
	set<vector<int>> DP;
	int mx;

	vector<int> start(Matrix m){
		Matrix sumMatrix = getSumMatrix(m);

		mx = -INF;
		solution.clear();

		solve(sumMatrix,{0,0,0,0});
		return {solution[0],solution[2],solution[1],solution[3]};
	}

private:
	Matrix getSumMatrix(Matrix m){
		Matrix sum = m;
		for (int i=0;i<m.size();i++) sum[i] = m[i];

		for (int i=0;i<m.size();i++)
			for (int j=0;j<m[i].size();j++)
				if (i-1>=0)
					sum[i][j]+=sum[i-1][j];

		for (int i=0;i<m.size();i++)
			for (int j=0;j<m[i].size();j++)
				if (j-1>=0)
					sum[i][j]+=sum[i][j-1];

		return sum;
	}

	void solve(Matrix mt,vector<int> xy){
		int m = mt.size(), n = mt[0].size();
		int current = calculate(mt, xy);

		if (DP.count(xy)) return;
		else DP.insert(xy);

		if (current>mx){
			solution = xy;
			mx = current;
		}

		if (xy[2]+1<m){
			xy[2]++; solve(mt,xy); 
			xy[0]++; solve(mt,xy);
			xy[2]--; xy[0]--;
		}
		if (xy[3]+1<n){
			xy[3]++; solve(mt,xy); 
			xy[1]++; solve(mt,xy);
			xy[3]--; xy[1]--;
		}
	}

	int calculate(Matrix m,vector<int> coords){
		int a = coords[0], b = coords[1], c = coords[2], d = coords[3];
		int total = m[c][d];

		if (b-1>=0) 
			total -= m[c][b-1];
		if (a-1>=0 && b-1>=0) 
			total+=m[a-1][b-1];
		if (a-1>=0) 
			total-= m[a-1][d];

		return total;
	}
};

class MaximumMatrix:public Exercise{
private:
	int testCases;

	void input(){
		fstream reader(MAXIMUM_MATRIX_TEST_CASES);
		reader>>testCases;

		for(int i=0;i<testCases;i++){
			int n,m;
			reader>>n>>m;
			Matrix current;
			for (int j=0;j<n;j++){
				vector<int> aux(m);
				current.push_back(aux);
				for (int k=0;k<m;k++)
					reader>>current[j][k];
			}
			output(current);
		}
	}

	void output(Matrix m){
		cout<<"Using kadane's algorithm: ";
		print(WithKadane::start(m));
		cout<<"Using backtracking: ";
		WithBacktracking a;
		print(a.start(m));
		cout<<endl;
	}

	void print(vector<int> arr){
		for (auto i:arr) cout<<i<<' ';
		cout<<endl;
	}

public:
	void init(){
		input();
	}
};
