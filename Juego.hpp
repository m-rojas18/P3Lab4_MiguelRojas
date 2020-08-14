#include "Jugador.hpp"
#include <vector>
using namespace std;
class Juego {
    friend void Jugar();
    //Metodo Friend
    friend void  Jugar(int);
    //Atributos
    public:
        vector<string> baraja;
        vector<Jugador*> jugadores_partida;
    
    public:
        Juego();//Constructor
        friend class Jugador;
        void  Jugar(int);
        void modificar_Puntuacion();
        void modificar_Mano_Jugador();
        ~Juego();//Destructor
};