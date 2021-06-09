#include <iostream>
#include <string>
#include <fstream>
#include "../../utils/exercise.h"
using namespace std;

const string HACKING_FILE_PATH = "./exercises/Hacking/testCases.txt";

//Son 61 elementos (9 números + 26 letras minúsculas + 26 mayúsculas. OJO: No cuenta la ñ)
char options[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

class Hacking:public Exercise{

public:

	void init(){
		input();
	};

	void hacking(string clave, char sol[], int i, int size, bool findClave){
	
		if (clave == sol){
			findClave = true;
			cout << "La clave es: ";
			for (int j=0; j<size; j++) cout << sol[j];
			cout << endl;
		}

		int j=0;
		while(!findClave and j<62){
			if (options[j]==clave[i]){
				sol[i] = options[j];
				hacking(clave, sol, i+1, size, findClave);
			}
			j+=1;
		}
	};


	int input(){

		fstream reader(HACKING_FILE_PATH);
		string clave;

		cout << "Ingrese su clave: (Clave del testCases)"; reader >> clave;
		while (clave.size()<5 or clave.size()>12){
			cout << "La clave debe tener un mínimo de 5 y un máximo de 12 caracteres alfanuméricos\n";
			cout << "Intente de nuevo: "; cin >> clave;
		}
		char sol[clave.size()];
		hacking(clave, sol, 0, clave.size(), false);

		return 0;
	};
};