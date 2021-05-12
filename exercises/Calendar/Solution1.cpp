#include <iostream>
#include <string>
#include <fstream>
#include "../../utils/exercise.h"
using namespace std;

class Event {
public:

	int day, month, sumDays=0;
	string details, yearMonth;

	Event(int day1, int month1){
		fstream reader(TEST_CASES_PATH);

		while(!validMonth(month1)){
			cout << "Mes inválido, por favor intente de nuevo: ";
			cin >> month1;
		}
		month = month1;

		while(!validDay(day1, month)){
			cout << "Día inválido, por favor intente de nuevo: ";
			cin >> day1;
		}
		day = day1;

		cout<<"Nombre del evento: "<<endl;
		reader.ignore(); getline(reader, details);
	}

	bool validMonth (int month){ //Validando meses
 		if (month>=1 && month<=12) return true;
 		else return false;
 	}

 	bool validDay (int day, int month){ //Validando días

 		//Si el mes es ene, mar, may, jul, ago, oct o dic, tiene 31 días
 		if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
 			if (day>=1 && day<=31){
 				return true;
 			}
 			else return false;

 		} else if (month==2){ //Si el mes es feb (2021 no es bisiesto)
 				if (day>=1 && day<=28) return true;
 				else return false;

 		//Si el mes es abr, jun, sep o nov, tienen 30 días
 		} else if (month==4 || month==6 || month==9 || month==11){
 			if (day>=1 && day<=30) return true;
 			else return false;
 		}
 		return true;
 	}

 	void yearDay(){ //Calculando el día del año y el guardando mes en letra

 		switch (month){

 			case 1:
 				sumDays = day;
 				yearMonth = "enero";
 				break;

 			case 2:
 				sumDays = 31+day;
 				yearMonth = "febrero";
 				break;

 			case 3:
 				sumDays = 59+day;
 				yearMonth = "marzo";
 				break;

 			case 4:
 				sumDays = 90+day;
 				yearMonth = "abril";
 				break;

 			case 5:
 				sumDays = 120+day;
 				yearMonth = "mayo";
 				break;

 			case 6:
 				sumDays = 151+day;
 				yearMonth = "junio";
 				break;

 			case 7:
 				sumDays = 181+day;
 				yearMonth = "julio";
 				break;

 			case 8:
 				sumDays = 212+day;
 				yearMonth = "agosto";
 				break;

 			case 9:
 				sumDays = 243+day;
 				yearMonth = "septiembre";
 				break;

 			case 10:
 				sumDays = 273+day;
 				yearMonth = "octubre";
 				break;

 			case 11:
 				sumDays = 304+day;
 				yearMonth = "noviembre";
 				break;

 			case 12:
 				sumDays = 334+day;
 				yearMonth = "diciembre";
 				break;
 		}

 		int modSumDays = sumDays%7; //Calculando el día se la semana

 		switch(modSumDays){
 			case 1:
 				cout << "Viernes "; break;
 			case 2:
 				cout << "Sábado "; break;
 			case 3:
 				cout << "Domingo "; break;
 			case 4:
 				cout << "Lunes "; break;
 			case 5:
 				cout << "Martes "; break;
 			case 6:
 				cout << "Miércoles "; break;
 			case 0:
 				cout << "Jueves "; break;
 		}
 	}
	
};

class Solution1:public Exercise{
public:

	void init(){
		ifstream reader(TEST_CASES_PATH);
		int cant, month1, day1;

		bool go = false;
		while (!go){ //Se pide la cantidad de eventos, si es inválida se queda en el while
			cout<<"Cantidad de Eventos a Agregar:"<<endl;
			reader >> cant;
			if (cant<0) cout << "Cantidad inválida. Intente de nuevo.\n";
			else go = true;
		}

		for(int i=0; i<cant; ++i){
			cout<<"Numero del mes: "<<endl; reader >> month1;
			cout<<"Día: "; reader >> day1;
			Event test(day1, month1);
			test.yearDay();
			cout << test.day << " de " << test.yearMonth << ": " << test.details << "\n";
		}

	}

};
