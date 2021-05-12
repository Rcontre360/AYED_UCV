#include <iostream>
#include "../utils/exercise.h"
#include "./Calendar/main.cpp"
#include "./mouseMaze/main.cpp"
#include "./RepeatedNumbers/main.cpp"

using namespace std;

const int NUMBER_OF_EXERCISES=3;

class ExercicesStarter{
public:
	Exercise* array[NUMBER_OF_EXERCISES];

	ExercicesStarter(){
		array[0] = new MouseLaberinth();
		array[1] = new Calendar();
		array[2] = new RepeatedNumbers();
	}

	void startExercises(){
		for (int i=0;i<NUMBER_OF_EXERCISES;i++){
			cout<<"\nExercise number "<<i+1<<":\n\n";
			array[i]->init();
		}
		cout<<"end";
	}
};