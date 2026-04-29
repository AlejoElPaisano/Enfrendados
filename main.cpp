#include "FuncionesMatematicas.h"
#include "Salas.h"
#include <iostream>
#include <ctime>
#include "rlutil.h"
using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);
    string MejorJugador = "No existe";
    int MejorPuntaje = 0;

    ///srand() inicializa el generador de numeros aleatorios con una "semilla"
    ///la semilla es siempre la misma
    ///con time(null) cambias esa semilla y siempre es diferente
    srand(time(NULL));
    MostrarMenu( MejorJugador, MejorPuntaje);
}
