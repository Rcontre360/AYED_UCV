#include <iostream>
#include "../utils/exercise.h"
#include "./Calendar/main.cpp"
#include "./mouseMaze/main.cpp"
#include "./RepeatedNumbers/main.cpp"
#include "./ListIntersection/main.cpp"
#include "./RussianMultiplication/main.cpp"
#include "./MCD/main.cpp"
#include "./MaximumMatrix/main.cpp"

using namespace std;

const int NUMBER_OF_EXERCISES=7;

class ExercicesStarter{
public:
	Exercise* array[NUMBER_OF_EXERCISES];

	ExercicesStarter(){
		array[0] = new MouseLaberinth();
		array[1] = new Calendar();
		array[2] = new RepeatedNumbers();
		array[3] = new ListIntersection();
		array[4] = new RussianMultiplication();
		array[5] = new MCD();
		array[6] = new MaximumMatrix();
	}

	void startExercises(){
		for (int i=0;i<NUMBER_OF_EXERCISES;i++){
			cout<<"\nExercise number "<<i+1<<":\n\n";
			array[i]->init();
		}
		cout<<"end";
	}
};