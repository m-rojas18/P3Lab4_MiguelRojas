#include <string>
#include <vector>
using namespace std;

class Jugador {
    //Atributos
    public:
        string nombre_jugador;
        int puntacion;
        vector<string> mano_cartas;

    public:
        Jugador(string, int);//Constructor

        //Metodos
        string getNombre_jugador();
        int getPuntuacion();
        vector<string> getMano_Cartas();
        ~Jugador();//Destructor
};