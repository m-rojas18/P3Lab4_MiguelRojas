#include <string>
#include <vector>
using namespace std;
#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
    //Atributos
    public:
        string nombre_jugador;
        int puntuacion;
        vector<string> mano_cartas;
    public:
        Jugador(string, int);//Constructor
        //Metodos
        friend class Juego;
        string getNombre_jugador();
        int getPuntuacion();
        int getTamano_mano();
        void setPuntuacion(int);
        string getCarta(int);
        void addCarta(string);
        ~Jugador();//Destructor
};

#endif