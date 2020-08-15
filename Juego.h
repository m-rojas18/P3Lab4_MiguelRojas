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
        friend class Jugador;
        void Jugar(int);
        void modificar_Mano_Jugador();
        void get_Puntos();
        int valorCarta(string);
        ~Juego();//Destructor
};

#endif