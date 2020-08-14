#include <iostream>
using namespace std;

int main(){
    char seguir = 's';
    int opcion_user;
    while(seguir == 's'){
        cout << "Menu Lab 4" << endl 
            << "[1]" << endl
            << "[2]" << endl
            <<"[ ] Salir" << endl
            << "Seleccione una opcion: ";
        cin >> opcion_user;
        cout << endl;
        switch(opcion_user){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                //Opcion de Salir
                seguir = 'n';
                cout << "Fin de Programa" <<endl;
                break;
            }
            default:{
                cout << "Ingreso una opcion no valida.\n\n";
            }
        }
    }
    
    return 0;
}