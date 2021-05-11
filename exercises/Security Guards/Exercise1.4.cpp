#include <iostream>
using namespace std;

struct Company              //estructura compañia, tiene el int de quejas que ha hecho la compañia y su nombre
{
    int cant_quejas;
    string name;
};
struct Vigilante               // estructura Vigilante, tiene un bool que representa si ha recibido o no una queja
{                              // la cantidad de quejas que se han hecho de el, su Id, su nombre, su direccion
    bool queja;                // y la compañia que ha hecho las quejas sobre el
    int cant_quejas, ID;
    string name, direccion;
    Company company_queja;   
};

void guardIn(Vigilante guardia, int i, Vigilante &most_quejas){ // Funcion para ingresar los datos del  Vigilante
        
        cout << "Ingrese el nombre y apellido del Vigilante Nº" << i + 1 <<endl;
        cin.ignore();
        getline(cin,guardia.name);
        cout << "Ingrese la direccion de " << guardia.name <<endl;
        getline(cin,guardia.direccion);
        cout << "Ingrese el ID de " << guardia.name <<endl;
        cin>>guardia.ID;
        int aux=0; // auxiliar que sirve para saber el valor bool de quejas
        do{
            cout << "¿" << guardia.name <<" ha recibido quejas? Ingrese el numero de la opcion"<<endl;
            cout <<"1-Si"<<endl;
            cout <<"2-No"<<endl;          
            cin>>aux;            
            if(aux==1){
                guardia.queja=true;         //if que da el respectivo valor al bool de queja
                break;                      // se encuentra en un while que valida que sea introducido
            }else if(aux==2){               // un valor valido
                guardia.queja=false;
                break;
            }
        }while(aux!=1 && aux!=2);
        if(guardia.queja){              // si el guardia a tenido quejas, se procede a pedir el numero de quejas
            do{
                cout << "Ingrese la cantidad de quejas que ha tenido " << guardia.name <<endl;
                cin>>guardia.cant_quejas;
            }while (guardia.cant_quejas<=0);
            if(guardia.cant_quejas>most_quejas.cant_quejas){
                most_quejas=guardia;  //Si el guardia actual ha tenido mas quejas, que el guardia con mas quejas, entonces
            }                         //el guardia actual será el guardia con mas quejas
        }
}

void companyIn(Company empresa, int i, Company &most_quejas){ //Funcion para ingresar los datos referente a las compañias
    cout << "Ingrese el nombre de la empresa Nº" << i + 1 <<endl;
    cin.ignore();
    getline(cin,empresa.name);
    cout << "Ingrese la cantidad de quejas de la empresa " << empresa.name <<endl;
    cin>>empresa.cant_quejas;
    if(empresa.cant_quejas>most_quejas.cant_quejas){
        most_quejas=empresa;
    }

}

void printDataGuard(Vigilante most_quejas){         // Funcion que imprime los datos referentes al vigilante con mas 
    cout <<"Guardia con mas quejas"<< endl;       // quejas recibidas
    cout <<"Nombre: "<<most_quejas.name<< endl;
    cout <<"ID: "<<most_quejas.ID<< endl;
    cout <<"Direccion: "<<most_quejas.direccion<< endl;
    cout <<"Cantidad de quejas: "<<most_quejas.cant_quejas<<endl;

}

void printDataCompany(Company most_quejas){
    cout <<"Compañia con mas quejas"<< endl;       // Funcion que imprime los datos referentes a la compañia con mas
    cout <<"Nombre: "<<most_quejas.name<< endl;    // quejas efectuadas
    cout <<"Cantidad de quejas: "<<most_quejas.cant_quejas<<endl;
}

int main()
{
    int cant_vigilante, cant_company;
    Vigilante *guardia, most_queja_guard;
    Company *empresa, most_queja_company;
    most_queja_company.cant_quejas = 0;
    most_queja_company.name="No hay";
    cout << "Ingrese el número de Vigilantes a ingresar: " << endl;
    cin >> cant_vigilante;
    guardia = new Vigilante[cant_vigilante];
    for (int i = 0; i < cant_vigilante; i++)
    {
     guardIn(guardia[i],i, most_queja_guard);    
    }
    cout << "Ingrese el número de Compañias a ingresar" << endl;
    cin >> cant_company;
    empresa = new Company[cant_company];
    for(int i=0; i<cant_company; i++){
        companyIn(empresa[i],i, most_queja_company);
    }
    printDataGuard(most_queja_guard);
    printDataCompany(most_queja_company);
    return 0;
}