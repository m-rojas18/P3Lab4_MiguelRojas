#include "Jugador.h"
#include <string>
#include <vector>
using namespace std;
//Constructor
Jugador::Jugador(string nombre_jugador, int puntuacion){
    this->nombre_jugador = nombre_jugador;
    this->puntuacion = puntuacion;
    // for (int i = 0; i < 3; i++) { mano_cartas.push_back("#" + std::to_string(i)); }
    
}
//Metodos
string Jugador::getNombre_jugador(){return this->nombre_jugador;}

int Jugador::getPuntuacion(){return this->puntuacion;}


int Jugador::getTamano_mano(){return mano_cartas.size();}

string Jugador::getCarta(int posicion){return mano_cartas.at(posicion);}

void Jugador::addCarta(string carta) { mano_cartas.push_back(carta); }

void Jugador::setPuntuacion(int nueva_puntuacion){this->puntuacion = nueva_puntuacion;}

//Destructor
Jugador::~Jugador(){} 