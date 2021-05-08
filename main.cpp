#include <iostream>
#include <fstream>
#include "./exercises/main.cpp"

using namespace std;

int main(){
	ExercicesStarter *exercises = new ExercicesStarter();
  
	exercises->startExercises();

	return 0;
}