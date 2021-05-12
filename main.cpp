#include <iostream>
#include <fstream>
#include "./exercises/main.cpp"

using namespace std;

int main(){
	ExercicesStarter *exercises = new ExercicesStarter();
  // ifstream a("./exercises/mouseMaze/testCases.txt");
  // int c,b;
  // a>>c>>b;
  // cout<<c<<b;
	exercises->startExercises();

	return 0;
}