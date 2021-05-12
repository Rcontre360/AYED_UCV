#include <iostream>
#include "../utils/exercise.h"
#include "./Calendar/main.cpp"
#include "./mouseMaze/main.cpp"

using namespace std;

const int NUMBER_OF_EXERCISES=2;

class ExercicesStarter{
public:
	Exercise* array[NUMBER_OF_EXERCISES];

	ExercicesStarter(){
		array[0] = new MouseLaberinth();
		array[1] = new Calendar();
	}

	void startExercises(){
		for (int i=0;i<NUMBER_OF_EXERCISES;i++){
			cout<<"Exercise number "<<i+1<<":\n";
			array[i]->init();
		}
		cout<<"end";
	}
};