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
    for (int i = 0; i < this->jugadores.size(); i++){
        for (int j = 0; j < 3; j++){
            //Asginar las 3 cartas random 
            Jugador* jugador_temporal = jugadores.at(i);
            random = rand() % this->baraja.size() + 0;
            string carta = baraja[random];
            jugador_temporal->getMano_Cartas().push_back(carta);
            cout << jugador_temporal->getCarta(j) << endl;

            //Remover carta de baraja
            this->baraja.erase(baraja.begin() + random);
        } 
    }   
    //Simulacion
    /*bool flag_fin = true;
    int contador_turno = 1;
    while(flag_fin == true){
        if(contador_turno % 2 != 0){
            Jugador* jugador_humano = jugadores.at(0);
            cout << jugador_humano->getNombre_jugador();
            int size = jugador_humano ->getTamano_mano();
            cout << size;
            string salida_mano_jugador;
            for (int i = 0; i < jugador_humano ->getTamano_mano(); i++){
                if(i == jugador_humano ->getTamano_mano() - 1){
                     salida_mano_jugador += jugador_humano ->getMano_Cartas().at(i) + " ]";
                     cout << "hola";
                 } else if(i == 0){
                     salida_mano_jugador += "[ " + jugador_humano->getMano_Cartas().at(i) + ", ";
                 
                 } else {
                     salida_mano_jugador += jugador_humano->getMano_Cartas().at(i) + ", ";
                 }
            }

            cout << "Mano de Jugador : " << salida_mano_jugador << endl;
            
            //cout <<  jugadores.at(0)->getNombre_jugador() << ":"
            cin >> contador_turno;
            ++contador_turno;
        } else {
            cout << "turno 2";
            ++contador_turno;
        }
    }*/
}

Juego::~Juego(){}