#include "Jugador.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//Constructor
Jugador::Jugador(string nombre_jugador, int puntuacion){
    this->nombre_jugador = nombre_jugador;
    this->puntacion = puntuacion;
}
//Metodos
string Jugador::getNombre_jugador(){
    return this->nombre_jugador;
}
int Jugador::getPuntuacion(){
    return this->puntacion;
}

vector<string> Jugador::getMano_Cartas(){
    return this->mano_cartas;
}

//Destructor
Jugador::~Jugador(){
    cout << "Se elimino el jugador." << endl;
}