#include "Jugador.h"
#include <vector>
#ifndef JUEGO_H
#define JUEGO_H
using namespace std;
class Juego {
    //Atributos
    public:
        vector<string> baraja;
        vector<Jugador*> jugadores;
    
    public:
        Juego(Jugador*);//Constructor
        void Jugar(int);
        void revolverBaraja();
        void modificar_Puntuacion();
        void modificar_Mano_Jugador();
        ~Juego();//Destructor
};

#endif