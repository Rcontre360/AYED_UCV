#include <iostream>
#include <fstream>
#include "../../utils/exercise.h"
using namespace std;

const string TEST_FILE_PATH = "./exercises/Goldbach/testCases.txt";

class Goldbach:public Exercise{

public:

	int (init){
		input()
	};

	bool esPrimo(int n){
		if (n==1) return false;
		for (int j=2; j<n; j++){
			if(n%j==0) return false;
		}
		return true;
	}

	bool goldbach(int num, int i){
		if (i>=num) return false;
		//Ejemplo: Si num = 5 y es la 2da llamada (i=2), se evalúa si 2 y 3 (num-i => 5-3) son primos
		if (esPrimo(i) && esPrimo(num-i)){
			printf("%s %d %s %d %s %d%s\n", "La suma de los primos", i, "y", num-i, "da como resultado", num, ".");
			return true;
		}
		return goldbach(num, ++i);
	}

	int input(){

		fstream reader(TEST_FILE_PATH);
		int num;

		cout << "Ingrese un número natural: (Número del testCases)."; reader >> num;
		if (goldbach(num, 1))
			cout << "Por lo tanto, el número ingresado cumple con la propiedad de Goldbach.\n";
		else
			cout << "El número ingresado no cumple con la propiedad de Goldbach.\n";

		return 0;
	}

};