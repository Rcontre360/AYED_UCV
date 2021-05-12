#include <iostream>
#include <string>
#include <fstream>
#include "../../utils/exercise.h"
using namespace std;

const string TEST_CASES_PATH = "./exercises/Calendar/testCases.txt";

class Calendar:public Exercise{

private:
    struct Event{  //estructura de datos de un evento
            int day, month, dayOfTheYear;
            string events; 
    };

    bool monthValidation(int month){
         if (month>12||month<1){ // Valida el mes
             return false;
         }else{
             return true;
         }   
     }
     bool dayValidation (int day, int month, int &dayOfTheYear){
         switch (month){
            case 1: 
                if(day>31||day<1){
                    return false;
                    break;
                }
                dayOfTheYear=day;
                return true;
                break;
                
            case 2:
                if(day>28 || day < 1 ){         
                    return false; 
                    break;          
                }
                dayOfTheYear=day+31; //Suma los dias de los meses anteriores + los del mes actual para 
                return false;        // determinar en que dia del año está, para luego determinar el dia de la semana
                break;
            
            case 3:
                if(day>31||day<1){
                    return false;
                }
                dayOfTheYear=day+59;
                return true;
            case 4:
                if(day>30||day<1){
                    return false;
                }
                dayOfTheYear=day+90;
                return true;
            case 5:
                if(day>31||day<1){
                    return false;
                }
                dayOfTheYear=day+120;
                return true;
            case 6:
                if(day>30||day<1){
                    return false;
                }
                dayOfTheYear=day+151;
                return true;
            case 7:
                if(day>31||day<1){
                    return false;
                }
                dayOfTheYear=day+181;
                return true;
            case 8:
                if(day>31||day<1){
                    return false;
                }
                dayOfTheYear=day+212;
                return true;
            case 9:
                if(day>30||day<1){
                    return false;
                }
                dayOfTheYear=day+243;
                return true;
            case 10:
                if(day>31||day<1){
                    return false;
                }
                dayOfTheYear=day+273;
                return true;
            case 11:
                if(day>30||day<1){
                    return false;
                }
                dayOfTheYear=day+304;
                return true;
            case 12:
                if(day>31||day<1){               
                    return false;               
                }
                dayOfTheYear=day+334;   //Suma los dias de los meses anteriores + los del mes actual para 
                return true;            // determinar en que dia del año está, para luego determinar el dia de la semana
            default:
                 return false;
         }  
         
     };
     
    void printDate(int dayOfTheYear, int day, int month){
         int auxmodDayOfTheWeek = dayOfTheYear % 7; //switch para imprimir Dia de la semana
         switch(auxmodDayOfTheWeek){                // se calcula el la cantidad de dias que lleva el año hasta el dia
            case 1:                                 // del evento
                cout<<"Viernes ";
                break;
            case 2:
                cout<<"Sabado ";
                break;
            case 3:
                cout<<"Domingo ";
                break;
            case 4:
                cout<<"Lunes ";
                break;
            case 5:
                cout<<"Martes ";
                break;
            case 6:
                cout<<"Miercoles ";
                break;
            default:
                cout<<"Jueves ";
                break;
         }
         cout<<day;
         switch(month){    //switch para imprimir mes
            case 1:
                cout<<" de Enero:";   
                break;
            case 2:
                cout<<" de Febrero";
                break;
            case 3:
                cout<<" de Marzo";
                break;
            case 4:
                cout<<" de Abril";
                break;
            case 5:
                cout<<" de Mayo";
                break;
            case 6:
                cout<<" de Junio";
                break;
            case 7:
                cout<<" de Julio";
                break;
            case 8:
                cout<<" de Agosto";
                break;
            case 9:
                cout<<" de Septiembre";
                break;
            case 10:
                cout<<" de Octubre";
                break;   
            case 11:
                cout<<" de Noviembre";
                break;
            case 12:
                cout<<" de Diciembre";
                break; 
         }
         
     }

public:
    void init() {
        ifstream reader(TEST_CASES_PATH);
        int cantEvents;
        Event *evento;
        string prueba;
        cout<<"Ingrese Cantidad de Eventos que va a Agregar:"<<endl;
        reader>>cantEvents;
        evento = new Event[cantEvents];
        
        for(int i=0; i < cantEvents; i++){
            cout<<"Evento Nº "<<i+1<<'\n';
            do{
                cout<<"Ingrese el numero del mes: "<<endl;
                reader>>evento[i].month;
            }while(!monthValidation(evento[i].month)); // Va a estar en el while mientras sea un mes invalido

            do{
                cout<<"Ingrese el día: ";
                reader>>evento[i].day;
            }while(!dayValidation(evento[i].day, evento[i].month, evento[i].dayOfTheYear)); //Va a estar en el while mientras el
                                                                                            // dia sea invalido
            cout<<"Ingrese el nombre del evento: "<<endl;
            reader.ignore();
            getline (reader , evento[i].events); 
            
        }

        for(int i= 0; i<cantEvents; i++){
            cout<<"El evento "<<evento[i].events<<" será el dia ";
            printDate(evento[i].dayOfTheYear, evento[i].day, evento[i].month);
            cout<<" del año 2021"<<endl;
        }
        
    }
};