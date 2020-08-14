#include "Jugador.h"
#include <string>
#include <vector>
using namespace std;
//Constructor
Jugador::Jugador(string nombre_jugador, int puntuacion){
    this->nombre_jugador = nombre_jugador;
    this->puntacion = puntuacion;
}
//Metodos
string Jugador::getNombre_jugador(){return this->nombre_jugador;}

int Jugador::getPuntuacion(){return this->puntacion;}

vector<string> Jugador::getMano_Cartas(){return this->mano_cartas;}

int Jugador::getTamano_mano(){return mano_cartas.size();}

string Jugador::getCarta(int posicion){return mano_cartas.at(posicion);}
//Destructor
Jugador::~Jugador(){} 