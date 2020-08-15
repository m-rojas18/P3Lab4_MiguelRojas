#include "Juego.h"
#include "Jugador.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
Juego::Juego(Jugador* jugador){
    this->jugadores.push_back(jugador);
}


void Juego::Jugar(int cantidad_jugadores){
    //Crear Baraja
    //Meter Copas
    this->baraja.push_back("A|O?");
    this->baraja.push_back("2|O?");
    this->baraja.push_back("3|O?");
    this->baraja.push_back("4|O?");
    this->baraja.push_back("5|O?");
    this->baraja.push_back("6|O?");
    this->baraja.push_back("7|O?");
    this->baraja.push_back("8|O?");
    this->baraja.push_back("9|O?");
    this->baraja.push_back("10|O?");
    this->baraja.push_back("J|O?");
    this->baraja.push_back("Q|O?");
    this->baraja.push_back("K|O?");

    //Meter Corazones
    this->baraja.push_back("A|<3");
    this->baraja.push_back("2|<3");
    this->baraja.push_back("3|<3");
    this->baraja.push_back("4|<3");
    this->baraja.push_back("5|<3");
    this->baraja.push_back("6|<3");
    this->baraja.push_back("7|<3");
    this->baraja.push_back("8|<3");
    this->baraja.push_back("9|<3");
    this->baraja.push_back("10|<3");
    this->baraja.push_back("J|<3");
    this->baraja.push_back("Q|<3");
    this->baraja.push_back("K|<3");

    //Meter Treboles
    this->baraja.push_back("A|-#");
    this->baraja.push_back("2|-#");
    this->baraja.push_back("3|-#");
    this->baraja.push_back("4|-#");
    this->baraja.push_back("5|-#");
    this->baraja.push_back("6|-#");
    this->baraja.push_back("7|-#");
    this->baraja.push_back("8|-#");
    this->baraja.push_back("9|-#");
    this->baraja.push_back("10|-#");
    this->baraja.push_back("J|-#");
    this->baraja.push_back("Q|-#");
    this->baraja.push_back("K|-#");

    //Meter Diamantes
    this->baraja.push_back("A|<>");
    this->baraja.push_back("2|<>");
    this->baraja.push_back("3|<>");
    this->baraja.push_back("4|<>");
    this->baraja.push_back("5|<>");
    this->baraja.push_back("6|<>");
    this->baraja.push_back("7|<>");
    this->baraja.push_back("8|<>");
    this->baraja.push_back("9|<>");
    this->baraja.push_back("10|<>");
    this->baraja.push_back("J|<>");
    this->baraja.push_back("Q|<>");
    this->baraja.push_back("K|<>");

    //Crear Robots
    int cantidad_robots = cantidad_jugadores - 1;
    string nombre_robot;
    for (int i = 1; i <= cantidad_robots; i++){
        nombre_robot = "bot-" + std::to_string(i);
        //Crear nuevo jugador y agregarlo a la lista de jugadores
        Jugador* jugador_robot = new Jugador(nombre_robot, 0);
        this->jugadores.push_back(jugador_robot);
    }

    //Revolver Baraja (Asignar Cartas)
    int random;
    
    srand(time(0));
    for (int i = 0; i < jugadores.size(); i++){
        //cout << "jugador " << i << endl;
        Jugador* jugador_temporal = jugadores.at(i);
        for (int j = 0; j < 3; j++){
            //Asginar las 3 cartas random 
            random = rand() % this->baraja.size() + 0;
            string carta = baraja[random];
            jugador_temporal -> addCarta(carta);

            //cout << jugador_temporal -> getCarta(j) << endl;
            //Remover carta de baraja
            this->baraja.erase(baraja.begin() + random);
        } 
    }   
    //Asignar puntos

    int suma_puntos_user ;
    for (int i = 0; i < jugadores.size(); i++){
         Jugador* jugador_temporal = jugadores.at(i);
        for (int j = 0; j < jugador_temporal->getTamano_mano(); j++){
            string carta_jugador = jugador_temporal->getCarta(j);
            int valor_carta = valorCarta(carta_jugador); 
            suma_puntos_user += valor_carta; 
        }
        jugador_temporal->setPuntuacion(suma_puntos_user);
    }
    //cout << "Puntos Jugador 0: " << jugadores.at(0)->getPuntuacion() << endl;
    
    //Simulacion
    bool flag_fin = true;
    int contador_turno = 1;
    while(flag_fin == true){

        if(contador_turno % 2 != 0){
            Jugador* jugador_humano = jugadores.at(0);
            int size = jugador_humano ->getTamano_mano();
            //cout << size << endl;
            string salida_mano_jugador = "";
            for (int i = 0; i < jugador_humano ->getTamano_mano(); i++){
                if(i == jugador_humano ->getTamano_mano() - 1){
                     salida_mano_jugador += jugador_humano ->getCarta(i) + " ]";
                 } else if(i == 0){
                     salida_mano_jugador += "[ " + jugador_humano->getCarta(i) + ", ";
                 } else {
                     salida_mano_jugador += jugador_humano->getCarta(i) + ", ";
                 }
            }

            int opcion_user;
            cout << "Mano de "<< jugador_humano->getNombre_jugador() << ": " << salida_mano_jugador << endl;
            cout << "Desea tomar otra carta? [1 si | 2no ]: ";
            cin >> opcion_user;
            while(opcion_user != 1 && opcion_user != 2){
                cout << "Ingreso una opcion no valida." << endl
                << "Desea tomar otra carta? [1 si | 2no ]: ";
                cin >> opcion_user;
            }
            cout << endl;
            if(opcion_user == 1){
                //Seguir con el juego
                //Verificar si hay cartas
                if(baraja.empty()){
                    //Terminar juego ya que no hay mas cartas
                    flag_fin = false;
                } else {
                    int valor_random = rand() % baraja.size() + 0;
                    string carta_random = baraja[valor_random];
                    jugador_humano->addCarta(carta_random);
                    int valor_carta_agarrada = valorCarta(carta_random);
                    jugador_humano->setPuntuacion(jugador_humano->getPuntuacion() + valor_carta_agarrada);
                }
            } else {
                //Elegio no tomar mas cartas
                //Termina el juego
                flag_fin = false;
            }

            if(flag_fin == false){
                //Verificar Resultados

                if(jugador_humano->getPuntuacion() == 31){
                    cout <<"Ganador: " << jugador_humano->getNombre_jugador() << ", puntos: 31" << endl;
                } else if(jugador_humano->getPuntuacion() > 31){
                    cout <<"Perdedor: " << jugador_humano->getNombre_jugador() << ", puntos: " << jugador_humano->getPuntuacion() << endl;
                } else {
                    cout <<"Perdedor: " << jugador_humano->getNombre_jugador() << ", puntos: " << jugador_humano->getPuntuacion() << endl;
                }
                //Verificar Robots
                for (int i = 0; i < jugadores.size(); i++){
                    Jugador* robot_jugando = jugadores.at(i);

                    if(i == 0){
                    //do nothing, no va revisar el objeto del humano
                    } else {
                        //Revisar si algun robot gano
                        if(robot_jugando->getPuntuacion() == 31){
                            cout <<"Ganador: " << robot_jugando->getNombre_jugador() << ", puntos: 31" <<endl;
                        } else if(robot_jugando->getPuntuacion() > 31){
                            cout <<"Perdedor: " << robot_jugando->getNombre_jugador() << ", puntos: " << robot_jugando->getPuntuacion() << endl;
                        } else {
                            cout <<"Perdedor: " << robot_jugando->getNombre_jugador() << ", puntos: " << robot_jugando->getPuntuacion() << endl;
                        }
                    }
                }//fin for de robots
                cout << endl;
            }//Fin if de resultados
             ++contador_turno;
        }  else {
        //Turno de Computadora
        for (int i = 0; i < jugadores.size(); i++){
            Jugador* robot_i = jugadores.at(i);

            if(i == 0){
                //do nothing, no va revisar el objeto del humano
            }
        }
            
        ++contador_turno;
        }
    }
}
int Juego::valorCarta(string carta){

	if(carta[0] == 'A')
		return 1;
	else if(carta[0] == '2')
		return 2;
	else if(carta[0] == '3')
		return 3;
	else if(carta[0] == '4')
		return 4;
	else if(carta[0] == '5')
		return 5;
	else if(carta[0] == '6')
		return 6;
	else if(carta[0] == '7')
		return 7;
	else if(carta[0] == '8')
		return 8;
	else if(carta[0] == '9')
		return 9;
	else if(carta[0] == '1')
		return 10;
	else if(carta[0] == 'J')
		return 11;
	else if(carta[0] == 'Q')
		return 12;
	else if(carta[0] == 'K')
		return 13;
	else
		return 0;
}

Juego::~Juego(){}