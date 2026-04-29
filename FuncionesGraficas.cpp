///TODAS LAS FUNCIONES ENCARGADAS DE LA PARTE VISUAL
#include <iostream>
#include "FuncionesGraficas.h"
#include "rlutil.h"
#include "FuncionesMatematicas.h"
using namespace std;

void Encorchar(int resultado){
    cout << "[" << resultado << "] ";
}

void Sangria(){
    int current_y = whereY();
    rlutil::locate(3, current_y);
}

void MostrarDados(int v[], int tam, int x, int y){///PERMITE DIBUJAR LOS DADOS STOCK DE 6 CARAS
    int DadoPosicionX;
    int i;
    ///Tam son los dados stock
    for(i=0;i<tam;i++){
        if (i > 5){
                DadoPosicionX =  x + (8*(i-6));
                DibujarDado( v[i], DadoPosicionX, y + 5);
                rlutil::locate(DadoPosicionX + 2, y + 4);
                cout << i+1;
                rlutil::locate(DadoPosicionX, y + 10);///Con esto definimos un valor util para sangria()
        }
        else{
                DadoPosicionX = x + (8*i);
                DibujarDado( v[i], DadoPosicionX, y);
                rlutil::locate(DadoPosicionX + 2, y - 1);
                cout << i+1;
                rlutil::locate(DadoPosicionX, y + 4);///Con esto definimos un valor util para sangria()
        }
    }
}

void DibujarDado12(int Numero, int x, int y){///PERMITE DIBUJAR LOS DADOS DE 12 CARAS
    rlutil::hidecursor();
    DibujarSombraRectangulo(x, y, x + 6, y + 3);
    DibujarRectangulo(x, y, x + 6, y + 3, rlutil::RED);
    Esperar(500);
    DibujarRectangulo(x, y, x + 6, y + 3, rlutil::BLUE);
    Esperar(500);
    DibujarRectangulo(x, y, x + 6, y + 3, rlutil::MAGENTA);

    ///Dibujar los numeros
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    rlutil::setColor(rlutil::WHITE);

    switch(Numero){
        case 1:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '1';
            break;
        case 2:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '2';
            break;
        case 3:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '3';
            break;
        case 4:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '4';
            break;
        case 5:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '5';
            break;
        case 6:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '6';
            break;
        case 7:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '7';
            break;
        case 8:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '8';
            break;
        case 9:
            rlutil::locate(x + 2,y + 1);
            cout << '0';
            rlutil::locate(x + 3,y + 1);
            cout << '9';
            break;
        case 10:
            rlutil::locate(x + 2,y + 1);
            cout << '1';
            rlutil::locate(x + 3,y + 1);
            cout << '0';
            break;
        case 11:
            rlutil::locate(x + 2,y + 1);
            cout << '1';
            rlutil::locate(x + 3,y + 1);
            cout << '1';
            break;
        case 12:
            rlutil::locate(x + 2,y + 1);
            cout << '1';
            rlutil::locate(x + 3,y + 1);
            cout << '2';
            break;
    }

    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);
    rlutil::showcursor();
}

void DibujarDado(int Numero, int x, int y){///PERMITE DIBUJAR UN DADO DE 6 CARAS
    rlutil::hidecursor();

    DibujarSombraRectangulo(x, y, x + 5, y + 3);
    DibujarRectangulo(x, y, x + 5, y + 3, rlutil::RED);
    Esperar(500);
    DibujarRectangulo(x, y, x + 5, y + 3, rlutil::BLUE);
    Esperar(500);
    DibujarRectangulo(x, y, x + 5, y + 3, rlutil::WHITE);

    ///Dibujar los puntos
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    switch(Numero){
        case 1:
            rlutil::locate(x + 2,y + 1);
            cout << 'o';
            break;
        case 2:
            rlutil::locate(x + 1,y + 1);
            cout << 'o';
            rlutil::locate(x + 3,y + 1);
            cout << 'o';
            break;
        case 3:
            rlutil::locate(x + 1,y);
            cout << 'o';
            rlutil::locate(x + 2,y + 1);
            cout << 'o';
            rlutil::locate(x + 3,y + 2);
            cout << 'o';
            break;
        case 4:
            rlutil::locate(x + 1,y);
            cout << 'o';
            rlutil::locate(x + 3,y);
            cout << 'o';
            rlutil::locate(x + 1,y + 2);
            cout << 'o';
            rlutil::locate(x + 3,y + 2);
            cout << 'o';
            break;
        case 5:
            rlutil::locate(x + 1,y);
            cout << 'o';
            rlutil::locate(x + 3,y);
            cout << 'o';
            rlutil::locate(x + 1,y + 2);
            cout << 'o';
            rlutil::locate(x + 3,y + 2);
            cout << 'o';
            rlutil::locate(x + 2,y + 1);
            cout << 'o';
            break;
        case 6:
            rlutil::locate(x + 1,y);
            cout << 'o';
            rlutil::locate(x + 2,y);
            cout << 'o';
            rlutil::locate(x + 3,y);
            cout << 'o';
            rlutil::locate(x + 1,y + 2);
            cout << 'o';
            rlutil::locate(x + 2,y + 2);
            cout << 'o';
            rlutil::locate(x + 3,y + 2);
            cout << 'o';
            break;
    }

    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);

    rlutil::locate(x,y + 5);
    rlutil::showcursor();
}

void DibujarRectangulo(int x1, int y1, int x2, int y2 , int Color){
    rlutil::setColor(Color);

    string Fila = "";
    for (int x = x1; x < x2; x++){
        Fila += 'Û';
    }

    for (int y = y1; y < y2; y++){
        rlutil::locate(x1, y);
        cout << Fila;
    }
    rlutil::setColor(rlutil::BLACK);
}

void DibujarSombraRectangulo(int x1, int y1, int x2, int y2){///RECORRE LOS COSTADOS DE UN RECTANGULO y DIBUJA SU SOMBRA
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);

    for (int y = y1; y < y2; y++){
            rlutil::locate(x1 - 1, y);
            cout << (char) 219;/// Caracter "Û"
        }
    for (int x = x1 - 1; x < x2; x++){
        rlutil::locate(x, y2);
        cout << (char) 223;/// Caracter "ß"
    }
}

void DibujarMargen( int x1, int y1, int x2, int y2){
    ///DIBUJAMOS LAS LINEAS SUPERIORES DEL MARGEN
    for (int x = x1; x < x2; x++){
            rlutil::locate(x1 + x, y1);
            if (x == x1) cout << (char) 201; /// Caracter "É"
            else if (x == x2 - 1) cout << (char) 187; ///
            else cout << (char) 205; ///Caracter "Í"
    }
    ///DIBUJAMOS LOS LATERALES DEL MARGEN
    for (int y = (y1 + 1); y < (y2 - 1); y++){
        rlutil::locate(x1 + 1, y);
        cout << (char) 186; ///Caracter º
        rlutil::locate(x2, y);
        cout << (char) 186; ///Caracter º
    }
    ///DIBUJAMOS LAS LINEAS INFERIORES DEL MARGEN
    for (int x = x1; x < x2; x++){
            rlutil::locate(x1 + x, y2 - 1);
            if (x == x1) cout << (char) 200; /// Caracter "É"
            else if (x == x2 - 1) cout << (char) 188; ///
            else cout << (char) 205; ///Caracter "Í"
    }
}

void DibujarPantallaDeJuego(string Jugador1, string Jugador2, int PuntajeJ1, int PuntajeJ2, int DadosStockJ1, int DadosStockJ2, int Ronda){
    system("cls");
    DibujarMargen( 1, 1, 64, 30);
    DibujarMargen( 1, 30, 64, 40);

    ///DIBUJADO DEL TITULO RONDA
    switch(Ronda){
    case 1:
        DibujarTituloRonda1(20,2);
        break;
    case 2:
        DibujarTituloRonda2(20,2);
        break;
    case 3:
        DibujarTituloRonda3(20,2);
        break;
    }

    ///DIBUJAR DATOS DE JUGADOR 1:
    rlutil::locate(12,32); cout << "JUGADOR Nø1"<< endl;
    rlutil::locate(3,34);            cout << "-Nombre: " << Jugador1<< endl;
    Sangria();            cout << "-Puntaje: " << PuntajeJ1<< endl;
    Sangria();            cout << "-Dados Stock: " << DadosStockJ1<< endl;

    ///DIBUJAR LINEA
    for (int i = 0; i < 8; i++){
            rlutil::locate(33,31 + i);
            cout << "||";
    }

    ///DIBUJAR DATOS DE JUGADOR 2:
    rlutil::locate(44,32); cout << "JUGADOR Nø2";
    rlutil::locate(35,whereY() + 2); cout << "-Nombre: " << Jugador2;
    rlutil::locate(35,whereY() + 1); cout << "-Puntaje: " << PuntajeJ2;
    rlutil::locate(35,whereY() + 1); cout << "-Dados Stock: " << DadosStockJ2;
}

void ResumenJugada(string UltimoJugador, int Resultado, int DadosSeleccionados[], int CantidadDeDadosSeleccionados, int NumeroObjetivo, int DadosStockJugador, int DadosStockContrincante,  int PuntajeJugador){
    system("cls");
    DibujarMargen( 1, 1, 64, 40);
    int X,Y;

    switch(Resultado){
    case 0:
        DibujarJugadaNoExitosa(19,2);
        X = 3;
        Y = 15;
        rlutil::locate(X,Y++); cout << "-" << UltimoJugador << " Eligio los siguientes dados:" << endl;
        rlutil::locate(X,Y++); mostrarVector(DadosSeleccionados, CantidadDeDadosSeleccionados);
        rlutil::locate(X,Y++); cout << "-Dando una suma de:" << SumarVector(DadosSeleccionados, CantidadDeDadosSeleccionados) << endl;
        rlutil::locate(X,Y++); cout << "-Cuando el objetivo era llegar a "<< NumeroObjetivo<< endl;
        rlutil::locate(X,Y++); cout << "-Como castigo su nuevo stock sera de "<< DadosStockJugador << endl;
        rlutil::locate(X,Y++); cout << "y el del contrincante sera:  "<< DadosStockContrincante << endl;
        rlutil::locate(X,Y++); cout << "-Su puntaje no tendra cambios " << endl;
        break;
    case 1:
        DibujarJugadaExitosa(19,2);
        X = 3;
        Y = 15;
        rlutil::locate(X,Y++); cout << "-" << UltimoJugador << " Eligio los siguientes dados:" << endl;
        rlutil::locate(X,Y++); mostrarVector(DadosSeleccionados, CantidadDeDadosSeleccionados);
        rlutil::locate(X,Y++); cout << "-Dando una suma de:" << SumarVector(DadosSeleccionados, CantidadDeDadosSeleccionados) << endl;
        rlutil::locate(X,Y++); cout << "-logrando llegar al objetivo."<< endl;
        rlutil::locate(X,Y++); cout << "-Como recompensa los " << CantidadDeDadosSeleccionados << " dados que selecciono" << endl;
        rlutil::locate(X,Y++); cout << " se los llevara el contrincante." << endl;
        rlutil::locate(X,Y++); cout << "-" << UltimoJugador << " tiene ahora "<< DadosStockJugador <<" dados." << endl;
        rlutil::locate(X,Y++); cout << "-El contrincante tiene ahora "<< DadosStockContrincante <<" dados." << endl;
        rlutil::locate(X,Y++); cout << "-" << UltimoJugador << " tiene un nuevo puntaje de: " << endl;
        rlutil::locate(X,Y++); cout << "-" << NumeroObjetivo;
        break;
    case 2:
        DibujarJugadaGanadora(17,2);
        X = 3;
        Y = 15;
        rlutil::locate(X,Y++); cout << "Jugada GANADORA" << endl;
        rlutil::locate(X,Y++); cout << "-" << UltimoJugador << " Eligio todos sus dados." << endl;
        rlutil::locate(X,Y++); cout << "-Dando una suma de:" << SumarVector(DadosSeleccionados, CantidadDeDadosSeleccionados) << endl;
        rlutil::locate(X,Y++); cout << "-logrando llegar al objetivo y quedarse sin dados."<< endl;
        rlutil::locate(X,Y++); cout << "-Como recompensa gana la partida y su puntaje es ahora: " << endl;
        rlutil::locate(X,Y++); cout << "-" << PuntajeJugador - (10000)<< " + 10000 = " << PuntajeJugador <<  endl;
        break;
    }
    Esperar(1000);
    rlutil::locate(15,38);
    cout << "Precione cualquier tecla continuar"<<endl;
    rlutil::anykey();
}
///ARTE ASCII ==========================
void DibujarMonitorEmpate(int X, int Y) {
    rlutil::locate(X, Y++);
    cout << "  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";

    for (int i = 0 ; i < 25; i++){

        rlutil::locate(X, Y++); cout << "  ÛÛ                                                     ÛÛ";

    }

    rlutil::locate(X, Y++);
    cout << "  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";

    rlutil::locate(X, Y++);
    cout << "                        ÛÛÛÛÛÛÛÛÛÛ                     ";

    rlutil::locate(X, Y++);
    cout << "ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
}

void DibujarEmpateJugadoresElegirPosiciones (int X , int Y){

    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛ»ÛÛÛ»   ÛÛÛ»ÛÛÛÛÛÛ»  ÛÛÛÛÛ» ÛÛÛÛÛÛÛÛ»ÛÛÛÛÛÛÛ»";
    rlutil::locate(X, Y++); cout << "ÛÛÉÍÍÍÍ¼ÛÛÛÛ» ÛÛÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÈÍÍÛÛÉÍÍ¼ÛÛÉÍÍÍÍ¼";
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛ»  ÛÛÉÛÛÛÛÉÛÛºÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛº   ÛÛº   ÛÛÛÛÛ»  ";
    rlutil::locate(X, Y++); cout << "ÛÛÉÍÍ¼  ÛÛºÈÛÛÉ¼ÛÛºÛÛÉÍÍÍ¼ ÛÛÉÍÍÛÛº   ÛÛº   ÛÛÉÍÍ¼  ";
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛ»ÛÛº ÈÍ¼ ÛÛºÛÛº     ÛÛº  ÛÛº   ÛÛº   ÛÛÛÛÛÛÛ»";
    rlutil::locate(X, Y++); cout << "ÈÍÍÍÍÍÍ¼ÈÍ¼     ÈÍ¼ÈÍ¼     ÈÍ¼  ÈÍ¼   ÈÍ¼   ÈÍÍÍÍÍÍ¼";

}

void DibujarCaritaTristeYTexto (int X , int Y){
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(X, Y++); cout << "    ÛÛ» ";
    rlutil::locate(X, Y++); cout << "ÛÛ»ÛÛÉ¼ ";
    rlutil::locate(X, Y++); cout << "ÈÍ¼ÛÛº  ";
    rlutil::locate(X, Y++); cout << "ÛÛ»ÛÛº  ";
    rlutil::locate(X, Y++); cout << "ÈÍ¼ÈÛÛ» ";
    rlutil::locate(X, Y++); cout << "    ÈÍ¼ ";

    Y++;

    rlutil::locate(X, Y ++); cout << "Se ha producido un empate en la tirada y es";
    rlutil::locate(X, Y ++); cout << "necesario volver a tirar los dados lo mas";
    rlutil::locate(X, Y ++); cout << "pronto posible";

    Y++;

    rlutil::locate(X, Y ++); cout << "20% completado";
}

void DibujarCodigoQR (int x , int y){

    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(x, y++); cout << "ÛÛÛÛÛÛÛÛ  ÛÛÛÛ ÛÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛ    ÛÛ  ÛÛ    ÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛ ÛÛ ÛÛ ÛÛÛÛÛÛ ÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛ ÛÛ ÛÛ  ÛÛ ÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛ    ÛÛ ÛÛ     ÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛÛÛÛÛÛÛ ÛÛ ÛÛ ÛÛÛ";
    rlutil::locate(x, y++); cout << "         ÛÛ ÛÛ ÛÛ ";
    rlutil::locate(x, y++); cout << "ÛÛ Û ÛÛ ÛÛÛÛÛ ÛÛÛÛ";
    rlutil::locate(x, y++); cout << " ÛÛÛ ÛÛ   ÛÛ Û ÛÛ";
    rlutil::locate(x, y++); cout << "ÛÛ ÛÛÛÛÛÛ ÛÛÛÛÛÛÛÛ";

    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);
}

void DibujarTextoInformacionError (int X , int Y){

    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(X, Y++); cout << "Para obtener mas informacion";
    rlutil::locate(X, Y++); cout << "sobre este empate y las muy";
    rlutil::locate(X, Y++); cout << "posibles soluciones. Visitar";

    rlutil::setColor(rlutil::GREY);

    rlutil::locate(X, Y++); cout << "store.steam.com/thecoders";
    Y++;
    rlutil::locate(X, Y++); cout << "If you call a suppport person";
    rlutil::locate(X, Y++); cout << "give them this info:";
    Y++;
    rlutil::locate(X, Y++); cout << "What failed. thecoders.inc";
    rlutil::locate(X, Y++); cout << "Press any key to continue...";

    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);

}

void DibujarTituloRonda1 (int X , int Y){

    rlutil::locate(X, Y++); cout << "°ÛßÜ°ÛßÛ°ÛßÛ°ÛßÜ°ÛßÛ°°°ßÛ°";
    rlutil::locate(X, Y++); cout << "°ÛßÜ°Û°Û°Û°Û°Û°Û°ÛßÛ°°°°Û°";
    rlutil::locate(X, Y++); cout << "°ß°ß°ßßß°ß°ß°ßß°°ß°ß°°°ßßß";
}

void DibujarTituloRonda2 (int X , int Y){

    rlutil::locate(X, Y++); cout << "°ÛßÜ°ÛßÛ°ÛßÛ°ÛßÜ°ÛßÛ°°°ßßÜ";
    rlutil::locate(X, Y++); cout << "°ÛßÜ°Û°Û°Û°Û°Û°Û°ÛßÛ°°°Üß°";
    rlutil::locate(X, Y++); cout << "°ß°ß°ßßß°ß°ß°ßß°°ß°ß°°°ßßß";
}

void DibujarTituloRonda3 (int X , int Y){

    rlutil::locate(X, Y++); cout << "°ÛßÜ°ÛßÛ°ÛßÛ°ÛßÜ°ÛßÛ°°°ßßÛ";
    rlutil::locate(X, Y++); cout << "°ÛßÜ°Û°Û°Û°Û°Û°Û°ÛßÛ°°°°ßÜ";
    rlutil::locate(X, Y++); cout << "°ß°ß°ßßß°ß°ß°ßß°°ß°ß°°°ßß°";
}

void DibujarTrofeo (int x , int y){
    rlutil::locate(x, y++); cout << "        ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "        ÛÛÛ                             ÛÛ";
    rlutil::locate(x, y++); cout << "        ÛÛÛ                             ÛÛ";
    rlutil::locate(x, y++); cout << "        ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "         ÛÛ                            ÛÛ ";
    rlutil::locate(x, y++); cout << "         ÛÛ                            ÛÛ ";
    rlutil::locate(x, y++); cout << "   ÛÛÛÛÛÛÛÛÛ                          ÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "   ÛÛ     ÛÛ                          ÛÛ     ÛÛ ";
    rlutil::locate(x, y++); cout << "   ÛÛÛ    ÛÛÛ                        ÛÛÛ    ÛÛÛ ";
    rlutil::locate(x, y++); cout << "     ÛÛÛ   ÛÛ                        ÛÛ   ÛÛÛ ";
    rlutil::locate(x, y++); cout << "      ÛÛÛ  ÛÛ                        ÛÛ  ÛÛÛ ";
    rlutil::locate(x, y++); cout << "       ÛÛÛ  ÛÛ                      ÛÛ  ÛÛÛ";
    rlutil::locate(x, y++); cout << "         ÛÛ ÛÛÛ                    ÛÛÛ ÛÛ ";
    rlutil::locate(x, y++); cout << "          ÛÛÛÛÛÛÛÛÛ            ÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "                 ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "                    ÛÛÛÛÛÛÛÛÛÛ  ";
    rlutil::locate(x, y++); cout << "                     ÛÛ    ÛÛ";
    rlutil::locate(x, y++); cout << "                    ÛÛÛ    ÛÛÛ";
    rlutil::locate(x, y++); cout << "                   ÛÛÛ      ÛÛÛ";
    rlutil::locate(x, y++); cout << "                 ÛÛÛÛ        ÛÛÛÛ";
    rlutil::locate(x, y++); cout << "               ÛÛÛ              ÛÛÛ";
    rlutil::locate(x, y++); cout << "              ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(x, y++); cout << "              ÛÛ                  ÛÛ";
    rlutil::locate(x+14, y++); cout << "ÛÛ                  ÛÛ";
    rlutil::locate(x +14, y++); cout << "ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
}

void DibujarTituloGanador (int x , int y){

    rlutil::locate(x, y++); cout << "ÛÛÛÛÛÛ»   ÛÛÛÛÛ» ÛÛÛ»   ÛÛ» ÛÛÛÛÛ» ÛÛÛÛÛÛ»  ÛÛÛÛÛÛ» ÛÛÛÛÛÛ» ";
    rlutil::locate(x, y++); cout << "ÛÛÉÍÍÍÍ¼ ÛÛÉÍÍÛÛ»ÛÛÛÛ»  ÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÍÛÛ»ÛÛÉÍÍÛÛ»";
    rlutil::locate(x, y++); cout << "ÛÛº  ÛÛÛ»ÛÛÛÛÛÛÛºÛÛÉÛÛ» ÛÛºÛÛÛÛÛÛÛºÛÛº  ÛÛºÛÛº   ÛÛºÛÛÛÛÛÛÉ¼";
    rlutil::locate(x, y++); cout << "ÛÛº   ÛÛºÛÛÉÍÍÛÛºÛÛºÈÛÛ»ÛÛºÛÛÉÍÍÛÛºÛÛº  ÛÛºÛÛº   ÛÛºÛÛÉÍÍÛÛ»";
    rlutil::locate(x, y++); cout << "ÈÛÛÛÛÛÛÉ¼ÛÛº  ÛÛºÛÛº ÈÛÛÛÛºÛÛº  ÛÛºÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÛÉ¼ÛÛº  ÛÛº";
    rlutil::locate(x, y++); cout << " ÈÍÍÍÍÍ¼ ÈÍ¼  ÈÍ¼ÈÍ¼  ÈÍÍÍ¼ÈÍ¼  ÈÍ¼ÈÍÍÍÍÍ¼  ÈÍÍÍÍÍ¼ ÈÍ¼  ÈÍ¼";
}

void DibujarMarcoDecorativo (int X , int Y){
    rlutil::locate(X, Y++); cout << " _____                                               _____";
    rlutil::locate(X, Y++); cout << "( ___ )                                             ( ___ )";
    rlutil::locate(X, Y++); cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |";
    rlutil::locate(X, Y++); cout << " |   |                                               |   |";
    rlutil::locate(X, Y++); cout << " |   |                                               |   |";
    rlutil::locate(X, Y++); cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|";
    rlutil::locate(X, Y++); cout << "(_____)                                             (_____)";
}

void DibujarSeleccionDeJugadores (int X , int Y) {
    rlutil::locate(X, Y++); cout << " _____                                      _____ ";
    rlutil::locate(X, Y++); cout << "( ___ )                                    ( ___ )";
    rlutil::locate(X, Y++); cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
    rlutil::locate(X, Y++); cout << " |   | °Ûßß°Ûßß°Û°°°Ûßß°Ûßß°Ûßß°ßÛß°ÛßÛ°ÛßÛ |   | ";
    rlutil::locate(X, Y++); cout << " |   | °ßßÛ°Ûßß°Û°°°Ûßß°Û°°°Û°°°°Û°°Û°Û°Û°Û |   | ";
    rlutil::locate(X, Y++); cout << " |   | °ßßß°ßßß°ßßß°ßßß°ßßß°ßßß°ßßß°ßßß°ß°ß |   | ";
    rlutil::locate(X, Y++); cout << " |   |               °ÛßÜ°Ûßß               |   | ";
    rlutil::locate(X, Y++); cout << " |   |               °Û°Û°Ûßß               |   | ";
    rlutil::locate(X, Y++); cout << " |   |               °ßß°°ßßß               |   | ";
    rlutil::locate(X, Y++); cout << " |   | °ßßÛ°Û°Û°Ûßß°ÛßÛ°ÛßÜ°ÛßÛ°ÛßÜ°Ûßß°Ûßß |   | ";
    rlutil::locate(X, Y++); cout << " |   | °°°Û°Û°Û°Û°Û°ÛßÛ°Û°Û°Û°Û°ÛßÜ°Ûßß°ßßÛ |   | ";
    rlutil::locate(X, Y++); cout << " |   | °ßß°°ßßß°ßßß°ß°ß°ßß°°ßßß°ß°ß°ßßß°ßßß |   | ";
    rlutil::locate(X, Y++); cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
    rlutil::locate(X, Y++); cout << "(_____)                                    (_____)";
}

void DibujarMarcoSeleccionJugadores (int X , int Y){

    // L¡nea superior
    rlutil::locate(X, Y++);
    cout << (char)201;
    for(int i = 0; i < 57; i++) cout << (char)205;
    cout << (char)187;

    // L¡neas intermedias
    for(int i = 0; i < 3; i++) {
        rlutil::locate(X, Y++);
        cout << (char)186;
        for(int j = 0; j < 57; j++) cout << " ";
        cout << (char)186;
    }

    // L¡nea inferior
    rlutil::locate(X, Y++);
    cout << (char)200;
    for(int i = 0; i < 57; i++) cout << (char)205;
    cout << (char)188;
}

void DibujarMVP(int X, int Y) {

    rlutil::setBackgroundColor(rlutil::CYAN);
    rlutil::setColor(rlutil::BLACK);

    rlutil::locate(X, Y++); cout << " ÛÛÛÛÛÛ   ÛÛÛÛÛÛ ÛÛÛÛÛ   ÛÛÛÛÛ ÛÛÛÛÛÛÛÛÛÛÛ ";
    rlutil::locate(X, Y++); cout << "°°ÛÛÛÛÛÛ ÛÛÛÛÛÛ °°ÛÛÛ   °°ÛÛÛ °°ÛÛÛ°°°°°ÛÛÛ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ°ÛÛÛÛÛ°ÛÛÛ  °ÛÛÛ    °ÛÛÛ  °ÛÛÛ    °ÛÛÛ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ°°ÛÛÛ °ÛÛÛ  °ÛÛÛ    °ÛÛÛ  °ÛÛÛÛÛÛÛÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ °°°  °ÛÛÛ  °°ÛÛÛ   ÛÛÛ   °ÛÛÛ°°°°°°  ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ      °ÛÛÛ   °°°ÛÛÛÛÛ°    °ÛÛÛ        ";
    rlutil::locate(X, Y++); cout << " ÛÛÛÛÛ     ÛÛÛÛÛ    °°ÛÛÛ      ÛÛÛÛÛ       ";
    rlutil::locate(X, Y++); cout << "°°°°°     °°°°°      °°°      °°°°°        ";
}

void DibujarCartelMVP (int X ,int Y){
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    for (int i = 1 ; i <= 19; i++){
    rlutil::locate(X, Y++); cout << "ÛÛ°°                                                 ÛÛ";
    }
    rlutil::locate(X, Y++); cout << "ÛÛ°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°ÛÛ";
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";

    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::locate(X, Y++); cout << "          ÛÛ²²ÛÛ                       ÛÛ²²ÛÛ ";
    rlutil::locate(X, Y++); cout << "    ²²²   ÛÛ²²ÛÛ                 ²²²   ÛÛ²²ÛÛ ";
    rlutil::locate(X, Y++); cout << "     ²²²  ÛÛ  ÛÛ                  ²²²  ÛÛ  ÛÛ ";
    rlutil::locate(X, Y++); cout << "      ²²² ÛÛ  ÛÛ                   ²²² ÛÛ  ÛÛ ";
    rlutil::locate(X, Y++); cout << "       ²²²ÛÛ  ÛÛ                    ²²²ÛÛ  ÛÛ ";
}

void DibujarTheBestPlayer (int x , int y){

    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::BLACK);


    rlutil::locate(x, y++); cout << "°ßÛß°Û°Û°Ûßß°°°ÛßÜ°Ûßß°Ûßß°ßÛß";
    rlutil::locate(x, y++); cout << "°°Û°°ÛßÛ°Ûßß°°°ÛßÜ°Ûßß°ßßÛ°°Û°";
    rlutil::locate(x, y++); cout << "°°ß°°ß°ß°ßßß°°°ßß°°ßßß°ßßß°°ß°";

    rlutil::locate(x, y++); cout << "   °ÛßÛ°Û°°°ÛßÛ°Û°Û°Ûßß°ÛßÜ   ";
    rlutil::locate(x, y++); cout << "   °Ûßß°Û°°°ÛßÛ°°Û°°Ûßß°ÛßÜ   ";
    rlutil::locate(x, y++); cout << "   °ß°°°ßßß°ß°ß°°ß°°ßßß°ß°ß   ";


}

void DibujarPantallaEmpate() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTGREEN);

    // Fondo Matrix
    for (int y = 2; y <= 38; y++) {
        for (int x = 3; x <= 63; x++) {
            char c;
            int r = rand() % 40;
            if (r < 2) c = '|';
            else if (r < 5) c = '°';
            else if (r < 8) c = '²';
            else if (r < 10) c = 'Û';
            else c = ' ';
            rlutil::locate(x, y);
            cout << c;
        }
    }

    // T¡tulo EMPATE
    int X = 8, Y = 8;
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛ»ÛÛÛ»   ÛÛÛ»ÛÛÛÛÛÛ»  ÛÛÛÛÛ» ÛÛÛÛÛÛÛÛ»ÛÛÛÛÛÛÛ»";
    rlutil::locate(X, Y++); cout << "ÛÛÉÍÍÍÍ¼ÛÛÛÛ» ÛÛÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÈÍÍÛÛÉÍÍ¼ÛÛÉÍÍÍÍ¼";
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛ»  ÛÛÉÛÛÛÛÉÛÛºÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛº   ÛÛº   ÛÛÛÛÛ»  ";
    rlutil::locate(X, Y++); cout << "ÛÛÉÍÍ¼  ÛÛºÈÛÛÉ¼ÛÛºÛÛÉÍÍÍ¼ ÛÛÉÍÍÛÛº   ÛÛº   ÛÛÉÍÍ¼  ";
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛÛÛ»ÛÛº ÈÍ¼ ÛÛºÛÛº     ÛÛº  ÛÛº   ÛÛº   ÛÛÛÛÛÛÛ»";
    rlutil::locate(X, Y++); cout << "ÈÍÍÍÍÍÍ¼ÈÍ¼     ÈÍ¼ÈÍ¼     ÈÍ¼  ÈÍ¼   ÈÍ¼   ÈÍÍÍÍÍÍ¼";

    rlutil::locate(15, 37);
    cout << "[ Presione una tecla para continuar ]";
}

void DibujarPasto(int x1,int x2, int y, int altura){
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::setColor(rlutil::BLACK);
    for(int x = x1; x < x2; x++){
        ///dibujamos 1 pasto
        int alturaPasto = AleatorioConLimite(altura);
        for(int h = 0; h < alturaPasto; h++){
            rlutil::locate(x,y - h);
            cout << 'Û';
        }
    }
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);
}

void DibujarLogoUTN( int X , int Y){
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "       ";
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "       ";
    rlutil::locate(X, Y++); cout << " " << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << "        ";
    rlutil::locate(X, Y++); cout << "  " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "         ";
    rlutil::locate(X, Y++); cout << "   " << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "          ";
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "       ";
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "       ";
    rlutil::locate(X, Y++); cout << "   " << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << (char)219 << "          ";
    rlutil::locate(X, Y++); cout << "  " << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << (char)219 << " " << (char)219 << (char)219 << (char)219 << "         ";
    rlutil::locate(X, Y++); cout << " " << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << "        ";
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << (char)219 << "   " << (char)219 << (char)219 << (char)219 << "       ";
    rlutil::locate(X, Y++); cout << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "  " << (char)219 << (char)219 << (char)219 << (char)219 << "       ";
}

void DibujarJugadaNoExitosa (int X , int Y){

    rlutil::locate(X + 2, Y++); cout << "°ßßÛ°Û°Û°Ûßß°ÛßÛ°ÛßÜ°ÛßÛ    ";
    rlutil::locate(X + 2, Y++); cout << "°°°Û°Û°Û°Û°Û°ÛßÛ°Û°Û°ÛßÛ    ";
    rlutil::locate(X + 2, Y++); cout << "°ßß°°ßßß°ßßß°ß°ß°ßß°°ß°ß    ";
    Y++;
    rlutil::locate(X + 10, Y++); cout << "°ÛßÛ°ÛßÛ                    ";
    rlutil::locate(X + 10, Y++); cout << "°Û°Û°Û°Û                    ";
    rlutil::locate(X + 10, Y++); cout << "°ß°ß°ßßß                    ";
    Y++;
    rlutil::locate(X, Y++); cout << "°Ûßß°Û°Û°ßÛß°ßÛß°ÛßÛ°Ûßß°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°Ûßß°ÜßÜ°°Û°°°Û°°Û°Û°ßßÛ°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°ßßß°ß°ß°ßßß°°ß°°ßßß°ßßß°ß°ß";
}

void DibujarNegativo(int X, int Y) {
    rlutil::locate(X, Y++); cout << " ÛÛÛÛÛ ÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "°°ÛÛÛ °°ÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °°ÛÛÛ ÛÛÛ  ";
    rlutil::locate(X, Y++); cout << "  °°ÛÛÛÛÛ   ";
    rlutil::locate(X, Y++); cout << "   ÛÛÛ°ÛÛÛ  ";
    rlutil::locate(X, Y++); cout << "  ÛÛÛ °°ÛÛÛ ";
    rlutil::locate(X, Y++); cout << " ÛÛÛÛÛ ÛÛÛÛÛ";
}

void DibujarJugadaExitosa(int X, int Y) {
    rlutil::locate(X + 2, Y++); cout << "°ßßÛ°Û°Û°Ûßß°ÛßÛ°ÛßÜ°ÛßÛ    ";
    rlutil::locate(X + 2, Y++); cout << "°°°Û°Û°Û°Û°Û°ÛßÛ°Û°Û°ÛßÛ    ";
    rlutil::locate(X + 2, Y++); cout << "°ßß°°ßßß°ßßß°ß°ß°ßß°°ß°ß    ";
    Y++;
    rlutil::locate(X, Y++); cout << "°Ûßß°Û°Û°ßÛß°ßÛß°ÛßÛ°Ûßß°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°Ûßß°ÜßÜ°°Û°°°Û°°Û°Û°ßßÛ°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°ßßß°ß°ß°ßßß°°ß°°ßßß°ßßß°ß°ß";
}

void DibujarJugadaGanadora(int X, int Y) {
    rlutil::locate(X + 4, Y++); cout << "°ßßÛ°Û°Û°Ûßß°ÛßÛ°ÛßÜ°ÛßÛ";
    rlutil::locate(X + 4, Y++); cout << "°°°Û°Û°Û°Û°Û°ÛßÛ°Û°Û°ÛßÛ";
    rlutil::locate(X + 4, Y++); cout << "°ßß°°ßßß°ßßß°ß°ß°ßß°°ß°ß";
    rlutil::locate(X, Y++); cout << "°Ûßß°ÛßÛ°ÛßÛ°ÛßÛ°ÛßÜ°ÛßÛ°ÛßÜ°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°Û°Û°ÛßÛ°Û°Û°ÛßÛ°Û°Û°Û°Û°ÛßÜ°ÛßÛ";
    rlutil::locate(X, Y++); cout << "°ßßß°ß°ß°ß°ß°ß°ß°ßß°°ßßß°ß°ß°ß°ß";
}

void DibujarCreditosPagina1(int X, int Y) {

    rlutil::locate(X + 20, Y++); cout << "°Û°°°ÛßÛ°Ûßß";
    rlutil::locate(X + 20, Y++); cout << "°Û°°°Û°Û°ßßÛ";
    rlutil::locate(X + 20, Y++); cout << "°ßßß°ßßß°ßßß";
    Y++;
    rlutil::locate(X, Y++); cout << "°Ûßß°ÛßÛ°ÛßÜ°ßÛß°Ûßß°ßÛß°Ûßß°ÛßÛ°ÛßÜ°ÛßÛ°ÛßÜ°Ûßß°Ûßß";
    rlutil::locate(X, Y++); cout << "°Û°°°Û°Û°Û°Û°°Û°°Ûßß°°Û°°Û°°°ÛßÛ°Û°Û°Û°Û°ÛßÜ°Ûßß°ßßÛ";
    rlutil::locate(X, Y++); cout << "°ßßß°ßßß°ßß°°ßßß°ß°°°ßßß°ßßß°ß°ß°ßß°°ßßß°ß°ß°ßßß°ßßß";
}

void DibujarCreditosPagina3(int X, int Y) {
    rlutil::locate(X, Y++); cout << "°ÛßÜ°Ûßß°Ûßß°ÛßÛ°ÛßÛ°ÛßÛ°Ûßß°ßÛß°ÛÜÛ°ßÛß°Ûßß°ÛßÛ°ßÛß°ÛßÛ°Ûßß";
    rlutil::locate(X, Y++); cout << "°ÛßÜ°Ûßß°Û°°°Û°Û°Û°Û°Û°Û°Û°°°°Û°°Û°Û°°Û°°Ûßß°Û°Û°°Û°°Û°Û°ßßÛ";
    rlutil::locate(X, Y++); cout << "°ß°ß°ßßß°ßßß°ßßß°ß°ß°ßßß°ßßß°ßßß°ß°ß°ßßß°ßßß°ß°ß°°ß°°ßßß°ßßß";

    Y += 2;
    DibujarRectangulo(X + 6, Y, X + 8, Y + 19, rlutil::DARKGREY);
    DibujarRectangulo(X + 8, Y, X + 55, Y + 19, rlutil::BLACK);
    DibujarRectangulo(X + 6, Y + 19, X + 55, Y + 25, rlutil::WHITE);
    Y++;
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::WHITE);

    for (int i = 0; i < 19; i++){
            rlutil::locate(X + 6, Y + i - 1); cout << i + 1 << endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(X + 8, Y++); cout << "//Juego inventado por Angel Simon. <--" << endl;
    Y++;
    rlutil::locate(X + 8, Y++); cout << "//Parte del arte ASCII hecha ASCII ART ARCHIVE" << endl;
    rlutil::locate(X + 8, Y++); cout << "//Copyright Injosoft" << endl;
    Y++;
    rlutil::locate(X + 8, Y++); cout << "//Desarrollado en el IDE Code::Blocks" << endl;
    rlutil::locate(X + 8, Y++); cout << "//creado por "<<'"'<<"The Code::Blocks team"<<'"'<< endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    Y++;
    rlutil::locate(X + 9, Y++); cout << "if ";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '(';
    rlutil::setColor(rlutil::GREEN); cout << "Aprobado";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << "){";
    rlutil::setColor(rlutil::GREEN);

    rlutil::locate(X + 9, Y++); cout << "   Felicidad ";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '=';
    rlutil::setColor(rlutil::LIGHTBLUE); cout << " true";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << ';';

    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(X + 9, Y++); cout << "   Llanto ";

    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '=';
    rlutil::setColor(rlutil::LIGHTBLUE); cout << " false";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << ';';

    rlutil::locate(X + 9, Y++);
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '}';
    rlutil::locate(X + 9, Y++);
    rlutil::setColor(rlutil::LIGHTBLUE); cout << "else";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '{';

    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(X + 9, Y++); cout << "   Felicidad ";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '=';
    rlutil::setColor(rlutil::LIGHTBLUE); cout << " false";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << ';';

    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(X + 9, Y++); cout << "   Llanto ";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '=';
    rlutil::setColor(rlutil::LIGHTBLUE); cout << " true";
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << ';';
    rlutil::locate(X + 9, Y++);
    rlutil::setColor(rlutil::LIGHTMAGENTA); cout << '}';

    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(X+7, Y += 2); cout << "|CB|Sr|Cccc|Bl|Bm|C/V++|C/V++m|C|D|D|Fi|Cfl|Ts|";
    Y++;
    rlutil::locate(X+6, Y++);    cout << "_________________________________________________";

    rlutil::locate(X+53, Y++); cout << "³^";
    rlutil::locate(X+53, Y);   cout << '³';
    rlutil::locate(X+53, Y+1); cout << '³';
    rlutil::locate(X+53, Y+2); cout << "³v";

    rlutil::setColor(rlutil::DARKGREY);
    rlutil::locate(X+54, Y); cout << '²';

    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(X+7, Y++);    cout << "Process terminated with status -1073741510";


    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);

    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::BLACK);
}

void DibujarNombreUTN (int X , int Y){
    rlutil::locate(X, Y++); cout << "ÛÛÛÛÛ  ÛÛÛÛÛ ÛÛÛÛÛÛÛÛÛÛÛ ÛÛÛÛÛÛ   ÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "°°ÛÛÛ  °°ÛÛÛ °Û°°°ÛÛÛ°°°Û°°ÛÛÛÛÛÛ °°ÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ   °ÛÛÛ °   °ÛÛÛ  °  °ÛÛÛ°ÛÛÛ °ÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ   °ÛÛÛ     °ÛÛÛ     °ÛÛÛ°°ÛÛÛ°ÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ   °ÛÛÛ     °ÛÛÛ     °ÛÛÛ °°ÛÛÛÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °ÛÛÛ   °ÛÛÛ     °ÛÛÛ     °ÛÛÛ  °°ÛÛÛÛÛ ";
    rlutil::locate(X, Y++); cout << " °°ÛÛÛÛÛÛÛÛ      ÛÛÛÛÛ    ÛÛÛÛÛ  °°ÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "  °°°°°°°°      °°°°°    °°°°°    °°°°° ";
}

void DibujarENFRENDADOS(int X , int Y){

    rlutil::locate ( X , Y++); cout << "ÛÛÛÛÛÛÛ»ÛÛÛ»   ÛÛ»ÛÛÛÛÛÛÛ»ÛÛÛÛÛÛ» ÛÛÛÛÛÛÛ»ÛÛÛ»   ÛÛ»";
    rlutil::locate(X , Y++);   cout << "ÛÛÉÍÍÍÍ¼ÛÛÛÛ»  ÛÛºÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»ÛÛÉÍÍÍÍ¼ÛÛÛÛ»  ÛÛº";
    rlutil::locate(X , Y++);   cout << "ÛÛÛÛÛ»  ÛÛÉÛÛ» ÛÛºÛÛÛÛÛ»  ÛÛÛÛÛÛÉ¼ÛÛÛÛÛ»  ÛÛÉÛÛ» ÛÛº";
    rlutil::locate(X , Y++);   cout << "ÛÛÉÍÍ¼  ÛÛºÈÛÛ»ÛÛºÛÛÉÍÍ¼  ÛÛÉÍÍÛÛ»ÛÛÉÍÍ¼  ÛÛºÈÛÛ»ÛÛº";
    rlutil::locate(X , Y++);   cout << "ÛÛÛÛÛÛÛ»ÛÛº ÈÛÛÛÛºÛÛº     ÛÛº  ÛÛºÛÛÛÛÛÛÛ»ÛÛº ÈÛÛÛÛº";
    rlutil::locate(X , Y++);   cout << "ÈÍÍÍÍÍÍ¼ÈÍ¼  ÈÍÍÍ¼ÈÍ¼     ÈÍ¼  ÈÍ¼ÈÍÍÍÍÍÍ¼ÈÍ¼  ÈÍÍÍ¼";
    rlutil::locate(X , Y++);   cout << "                                                    ";
    rlutil::locate(X , Y++);   cout << "     ÛÛÛÛÛÛ»  ÛÛÛÛÛ» ÛÛÛÛÛÛ»  ÛÛÛÛÛÛ» ÛÛÛÛÛÛÛ»      ";
    rlutil::locate(X , Y++);   cout << "     ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛÉÍÍÍÛÛ»ÛÛÉÍÍÍÍ¼      ";
    rlutil::locate(X , Y++);   cout << "     ÛÛº  ÛÛºÛÛÛÛÛÛÛºÛÛº  ÛÛºÛÛº   ÛÛºÛÛÛÛÛÛÛ»      ";
    rlutil::locate(X , Y++);   cout << "     ÛÛº  ÛÛºÛÛÉÍÍÛÛºÛÛº  ÛÛºÛÛº   ÛÛºÈÍÍÍÍÛÛº      ";
    rlutil::locate(X , Y++);   cout << "     ÛÛÛÛÛÛÉ¼ÛÛº  ÛÛºÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛº      ";
    rlutil::locate(X , Y++);   cout << "     ÈÍÍÍÍÍ¼ ÈÍ¼  ÈÍ¼ÈÍÍÍÍÍ¼  ÈÍÍÍÍÍ¼ ÈÍÍÍÍÍÍ¼      ";
}

void DibujarDisenioMenu(int X, int Y, int Seleccion) {
    ///Pergamino
    rlutil::locate(X, Y++); cout << " _____                                  _____ ";
    rlutil::locate(X, Y++); cout << "( ___ )                                ( ___ )";
    rlutil::locate(X, Y++); cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |   |                                  |   | ";
    rlutil::locate(X, Y++); cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
    rlutil::locate(X, Y++); cout << "(_____)                                (_____)";

    switch(Seleccion){
    case 3:
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(X + 17,Y - 8); cout << "    Jugar     ";
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(X + 17,Y - 7); cout << " Estadisticas ";
        rlutil::locate(X + 17,Y - 6); cout << "   Creditos   ";
        rlutil::locate(X + 17,Y - 5); cout << "    Salir     ";
        break;
    case 2:
        rlutil::locate(X + 17,Y - 8); cout << "    Jugar     ";
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(X + 17,Y - 7); cout << " Estadisticas ";
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(X + 17,Y - 6); cout << "   Creditos   ";
        rlutil::locate(X + 17,Y - 5); cout << "    Salir     ";
        break;
    case 1:
        rlutil::locate(X + 17,Y - 8); cout << "    Jugar     ";
        rlutil::locate(X + 17,Y - 7); cout << " Estadisticas ";
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(X + 17,Y - 6); cout << "   Creditos   ";
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(X + 17,Y - 5); cout << "    Salir     ";
        break;
    case 0:
        rlutil::locate(X + 17,Y - 8); cout << "    Jugar     ";
        rlutil::locate(X + 17,Y - 7); cout << " Estadisticas ";
        rlutil::locate(X + 17,Y - 6); cout << "   Creditos   ";
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(X + 17,Y - 5); cout << "    Salir     ";
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        break;
    }
}

void DibujarEquipoDocente(int X, int Y){

    rlutil::locate(X, Y++); cout << "°Ûßß°ÜßÜ°Û°Û°ßÛß°ÛßÛ°ÛßÛ°°°ÛßÜ°ÛßÛ°Ûßß°Ûßß°ÛßÛ°ßÛß°Ûßß°";
    rlutil::locate(X, Y++); cout << "°Ûßß°Û Û°Û°Û°°Û°°Ûßß°Û°Û°°°Û°Û°Û°Û°Û°°°Ûßß°Û°Û°°Û°°Ûßß°";
    rlutil::locate(X, Y++); cout << "°ßßß°°ß °ßßß°ßßß°ß°°°ßßß°°°ßß°°ßßß°ßßß°ßßß°ß°ß°°ß°°ßßß°";
}

void DibujarMonitorDocentes(int X, int Y) {

    rlutil::locate(X, Y++);
    cout << "  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";

    for (int i = 0 ; i < 13; i++){

        rlutil::locate(X, Y++); cout << "  ÛÛ                                                 ÛÛ";

    }

    rlutil::locate(X, Y++);
    cout << "  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";

    rlutil::locate(X, Y++);
    cout << "                        ÛÛÛÛÛÛÛÛÛÛ                     ";

    rlutil::locate(X, Y++);
    cout << "ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
}

void DibujarDisenioMonitorDocente (int PosicionX , int PosicionY){
    rlutil::setBackgroundColor(rlutil::GREY);

    for (int y = 21; y < 34; y++) {
        rlutil::locate(9, y);
        cout << "                                                 ";
    }

    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::BLACK);
    for (int y = 21; y < 22; y++) {
        rlutil::locate(9, y);
        cout << "__________|__________|__________|__________|_____";
    }

    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::BLACK);
    for (int y = 22; y < 23; y++) {
        rlutil::locate(9, y);
        cout << " <- -> |                                | Google ";
    }
    for (int y = 22; y < 23; y++) {
        rlutil::locate(18, y);
        cout << "https://bit.ly/4mTOFjE";
    }
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::BLACK);
    for (int y = 24; y < 25; y++) {
        rlutil::locate(10, y);
        cout << " ¨Quienes conforman el equipo docente? | Buscar";
    }
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::setColor(rlutil::BLACK);
    for (int y = 26; y < 33; y++) {
        rlutil::locate(10, y);
        cout << "                                |              ";
    }

    rlutil::locate (11 , 26); cout << " - Daniel Kloster";
    rlutil::locate (11 , 27); cout << " - Brian Lara Campos";
    rlutil::locate (11 , 28); cout << " - Jose Alberto Rodriguez";
    rlutil::locate (11 , 29); cout << " - Maximiliano Sar Fernandez";
    rlutil::locate (11 , 30); cout << " - Alejandro Gomez Nieto";
    rlutil::locate (11 , 31); cout << " - Marina Chavez";
    rlutil::locate (11 , 32); cout << " - Veronica Carbonari";

    rlutil::locate (48,26);   cout << "UTN";
    rlutil::locate (44 , 27); cout << "­Inscribete!";
    rlutil::locate (44 , 31); cout << "25/3 - 10/07";
    rlutil::locate (43 , 29); cout << "Estas a tiempo";
}

void DibujarMandoDeConsola(int X, int Y) {
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(X, Y++); cout << "  ÛÛ                                   ";
    rlutil::locate(X, Y++); cout << "  ÛÛÛÛ                                 ";

    // Cuerpo principal del control
    rlutil::locate(X, Y++); cout << "    ÛÛ   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "    ÛÛ   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "    ÛÛÛÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ ÛÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "         ÛÛÛ     ÛÛÛÛÛÛÛÛÛÛÛÛÛ ÛÛÛ ÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "         ÛÛÛÛÛ ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ ÛÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "         ÛÛÛÛÛÛÛÛÛÛÛ  ÛÛÛ  ÛÛÛÛÛÛÛÛÛÛÛÛ";
    rlutil::locate(X, Y++); cout << "         ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ";
}

void DibujarDisenioMonitorLosCodificadores (int X , int Y){
    rlutil::setBackgroundColor(rlutil::BLUE);
    for (int y = 12; y < 25; y++) {
        rlutil::locate(9, y);
        cout << "                                                 ";
    }
    rlutil::setBackgroundColor(rlutil::BLUE);
    for (int y = 14; y < 15; y++) {
        rlutil::locate(9, y);
        cout << "                                                 ";
    }

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    for (int y = 12; y < 13; y++) {
        rlutil::locate(9, y);
        cout << "__________|__________|__________|__________|_____";
    }

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    for (int y = 13; y < 14; y++) {
        rlutil::locate(9, y);
        cout << " <- -> |                                 | Steam ";
    }

    for (int y = 13; y < 14; y++) {
        rlutil::locate(17, y);
        cout << "store.steampowered.com/thecoders";
    }

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(22 , 15);
    cout << "   ELIJA SU PERSONAJE   ";

    rlutil::setBackgroundColor(rlutil::BLUE);
    for (int y = 17; y < 24; y++) {
        rlutil::locate(9, y);
        cout << "                                                 ";
    }

    rlutil::locate(9 , 17); cout << "INTEGRANTES DEL EQUIPO:";
    rlutil::locate(9 , 19); cout << " - Durazzini, Sebastian Andres   - Legajo: 33177";
    rlutil::locate(9 , 20); cout << " - Figueroa, Oscar Facundo       - Legajo: 32426";
    rlutil::locate(9 , 21); cout << " - Martinez Olmedo, Alejo        - Legajo: 32349";
    rlutil::locate(9 , 22); cout << " - Raho, Pablo Daniel            - Legajo: 33245";

    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    for (int y = 24; y < 25; y++) {
        rlutil::locate(9, y);
        cout << "                                                 ";
    }
}
