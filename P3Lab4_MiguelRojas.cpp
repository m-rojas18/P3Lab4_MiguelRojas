#include <iostream>
#include <string>
using namespace std;
friend  void Jugar(int);
int main(){
    char seguir = 's';
    int opcion_user;
    while(seguir == 's'){
        cout << "Menu Juego Lab 4 !!" << endl
        << "[1] Jugar 31" << endl
        << "[2] Salir "<< endl
        << "Seleccione una opcion: ";
        cin >> opcion_user; 
        cout << endl;
        switch(opcion_user){
            case 1:{
                //Opcion Jugar
                //Pedir numero de Jugadores
                int cantidad_jugadores = 0;
                cout << "Ingrese el numero de jugadores (2 - 10): ";
                cin >> cantidad_jugadores;
                while(cantidad_jugadores < 2 || cantidad_jugadores > 10){
                    cout << "Numero de jugadores no valido." << endl
                    << "Vuelva a ingresar el numero de jugadores (2 - 10): ";
                    cin >> cantidad_jugadores;
                }
                cout << endl;
                //Pedir nombre de jugador humano
                string nombre_jugador;
                cout << "Ingrese su nombre: ";
                cin >> nombre_jugador;
                cout << endl;
                //Llamar a metodo
                Jugar(cantidad_jugadores);
                break;
            }
            case 2:{
                //Opcion Salir
                seguir = 'n';
                cout << "Fin del Programa.\n\n";
                break;
            }
            default :
                cout << "Ingreso una opcion no valida." << endl;
        }
    }
    
    return 0;
}