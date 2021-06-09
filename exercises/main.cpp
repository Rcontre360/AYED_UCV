#include <iostream>
#include "../utils/exercise.h"
#include "./Calendar/main.cpp"
#include "./mouseMaze/main.cpp"
#include "./RepeatedNumbers/main.cpp"
#include "./ListIntersection/main.cpp"
#include "./RussianMultiplication/main.cpp"
#include "./MCD/main.cpp"
#include "./MaximumMatrix/main.cpp"
#include "./MultipleFormulas/main.cpp"
#include "./Goldbach/main.cpp"
#include "./Hacking/main.cpp"

using namespace std;

const int NUMBER_OF_EXERCISES=10;

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
		array[7] = new MultipleFormulas();
		array[8] = new Goldbach();
		array[9] = new Hacking();
	}

	void startExercises(){
		for (int i=0;i<NUMBER_OF_EXERCISES;i++){
			cout<<"\nExercise number "<<i+1<<":\n\n";
			array[i]->init();
		}
		cout<<"end";
	}
};