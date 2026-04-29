///TODAS LAS FUNCIONES ENCARGADAS DEL CONTROL DE LAS SALAS (o ROOMS) DEL JUEGO
#include <iostream>
#include "Salas.h"
#include "FuncionesMatematicas.h"
#include "FuncionesGraficas.h"
#include "rlutil.h"
using namespace std;

void MostrarMenu( string &MejorJugador, int &MejorPuntaje){
    int Seleccion = 3, Tecla;

    while(true){
    rlutil::hidecursor();
    system("cls");
    DibujarMargen( 1, 1, 64, 40);
    DibujarENFRENDADOS(7,2);

    DibujarDisenioMenu(10,20, Seleccion);

    ///MANEJO DE LAS TECLAS
    Tecla = rlutil::getkey();
    switch(Tecla){
        case (rlutil::KEY_UP):
            Seleccion += 1;
            break;
        case (rlutil::KEY_DOWN):
            Seleccion -= 1;
            break;
    }

    Seleccion = Clamp(Seleccion, 0, 3);

    ///MANEJO DE LA SELECCION
    if (Tecla == rlutil::KEY_ENTER) SeleccionarOpciones(Seleccion,MejorJugador, MejorPuntaje);
    }
}

void SeleccionarOpciones( int Seleccion,string &MejorJugador, int &MejorPuntaje){
    switch (Seleccion){
    case 3:///JUGAR
        Jugar(MejorJugador, MejorPuntaje);
        break;
    case 2:///ESTADISTICAS
        system("cls");
        DibujarMargen( 1, 1, 64, 40);
        DibujarRectangulo(3, 2, 64, 39, rlutil::CYAN);
        DibujarRectangulo(3, 33, 64, 39, rlutil::GREEN);
        DibujarMVP(14,3);
        DibujarCartelMVP(6,12);
        DibujarTheBestPlayer(19,14);
        rlutil::locate(20,24);
        cout << "Mejor jugador: " << MejorJugador << endl;
        rlutil::locate(20,26);
        cout << "Mejor puntaje: " << MejorPuntaje << endl;
        DibujarPasto( 3, 64, 38, 4);
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::BLACK);
        rlutil::anykey();
        break;
    case 1:///CREDITOS
        Creditos();
        break;
    case 0:///SALIR
        rlutil::locate( 3,41);
        cout << "Saliendo del juego...." << endl;
        exit(0);
    }
}

void Creditos(){
    int Pagina = 1;
    int PaginaMax = 3;
    int Key;

    rlutil::hidecursor();

    while(true){
    switch(Pagina){
        case 1:
            system ("cls");
            DibujarMargen( 1, 1, 64, 40);

            ///DIBUJADO DE LA PAGINA
            DibujarCreditosPagina1(7 , 3);
            DibujarMonitorDocentes (5,11);
            DibujarDisenioMonitorLosCodificadores (32 , 2);
            rlutil::setBackgroundColor(rlutil::BROWN);
            DibujarMandoDeConsola (24 , 28);

            rlutil::locate(30,38);
            cout << "PAG " << Pagina << "/" << PaginaMax;
            break;
        case 2:
            system ("cls");
            DibujarMargen( 1, 1, 64, 40);

            ///DIBUJADO DE LA PAGINA
            DibujarLogoUTN(5 , 2);
            DibujarNombreUTN(22 , 4);
            DibujarEquipoDocente( 6 , 16);
            DibujarMonitorDocentes(5 , 20);
            DibujarDisenioMonitorDocente (32 , 27);
            rlutil::setBackgroundColor(rlutil::BROWN);

            rlutil::locate(30,38);
            cout << "PAG " << Pagina << "/" << PaginaMax;
            break;
        case 3:
            system ("cls");
            DibujarMargen( 1, 1, 64, 40);

            ///DIBUJADO DE LA PAGINA
            DibujarCreditosPagina3(3, 3);
            rlutil::locate(30,38);
            cout << "PAG " << Pagina << "/" << PaginaMax;
            break;
            }

    Key = rlutil::getkey();
    ///VERIFICAMOS SI LA TECLA QUE ACABAMOS DE PRECIONAR ES "IZQ" "DER" o "ESCAPE"

    switch(Key){
    case rlutil::KEY_LEFT:
        Pagina--;
        break;
    case rlutil::KEY_RIGHT:
        Pagina++;
        break;
    case rlutil::KEY_ESCAPE:
        rlutil::showcursor();
        return;
        break;
    }
    Pagina = Clamp( Pagina, 1, PaginaMax); ///Mantenemos el rango de las paginas
    }
}

void Jugar(string &MejorJugador, int &MejorPuntaje){
    string Nombre1, Nombre2, Jugador1, Jugador2, UltimoGanador;
    int Ronda = 1, Resultado = -1;
    int DadosStockJ1 = 6, DadosStockJ2 = 6, PuntajeJ1 = 0, PuntajeJ2 = 0;

    system("cls");

    DibujarMargen( 1, 1, 64, 40);
    rlutil::locate(3,2);

    ///Pedimos ingresar nombres
    rlutil::showcursor();
    cout << "Ingresar nombre jugador 1 (Max 10): ";
    IngresoConValidacionNombre(39, 2, Nombre1);
    rlutil::locate(3,3);
    cout << "Ingresar nombre jugador 2 (Max 10): ";
    IngresoConValidacionNombre(39, 3, Nombre2);
    rlutil::hidecursor();

    ElegirPosiciones(Nombre1, Nombre2, Jugador1, Jugador2);

    while(Ronda <= 3 && Resultado != 2){
        DibujarPantallaDeJuego(Jugador1, Jugador2, PuntajeJ1, PuntajeJ2, DadosStockJ1, DadosStockJ2, Ronda);
        Resultado = Tirada(Jugador1, UltimoGanador, DadosStockJ1, DadosStockJ2, PuntajeJ1);
        if (Resultado == 2) break;
        DibujarPantallaDeJuego(Jugador1, Jugador2, PuntajeJ1, PuntajeJ2, DadosStockJ1, DadosStockJ2, Ronda);
        Resultado = Tirada(Jugador2, UltimoGanador, DadosStockJ2, DadosStockJ1, PuntajeJ2);
        if (Resultado == 2) break;
        Ronda++;
    }
    if (Resultado != 2){
        if(PuntajeJ1 > PuntajeJ2){
            system("cls");
            DibujarMargen(1 , 1 , 64 , 40);
            DibujarTituloGanador (3 , 2);
            DibujarMarcoDecorativo (4,32);
            DibujarTrofeo (8 , 9);
            rlutil::locate(11,35);
            cout << "1§ Puesto -> Gano " << '"' << Jugador1 << '"' << " con " << PuntajeJ1 << " puntos";
            rlutil::locate(11,36);
            cout << "2§ Puesto -> Perdio " << '"' << Jugador2 << '"' << " con " << PuntajeJ2 << " puntos";
            rlutil::anykey();

            ///ACTUALIZAMOS ESTADISTICA
            if (PuntajeJ1 > MejorPuntaje){
                MejorJugador = Jugador1;
                MejorPuntaje = PuntajeJ1;
            }
        }
        else if (PuntajeJ1 == PuntajeJ2){
            system ("cls");
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::WHITE);
            DibujarPantallaEmpate();
            DibujarMargen(1 , 1 , 64 , 40);
            rlutil::anykey();
            rlutil::setBackgroundColor(rlutil::BROWN);
            rlutil::setColor(rlutil::BLACK);
        }
        else{
            system("cls");
            DibujarMargen(1 , 1 , 64 , 40);
            DibujarTituloGanador (3 , 2);
            DibujarMarcoDecorativo (4,32);
            DibujarTrofeo (8 , 9);
            rlutil::locate(11,35);
            cout << "1§ Puesto -> Gano " << '"'<< Jugador2 << '"' <<" con " << PuntajeJ2 << " puntos";
            rlutil::locate(11,36);
            cout << "2§ Puesto -> Perdio " << '"' << Jugador1 << '"' << " con " << PuntajeJ1 << " puntos";
            rlutil::anykey();

            ///ACTUALIZAMOS ESTADISTICA
            if (PuntajeJ2 > MejorPuntaje){
                MejorJugador = Jugador2;
                MejorPuntaje = PuntajeJ2;
            }
        }
    }
    else{
        if (UltimoGanador == Jugador1){
                system("cls");
                DibujarMargen(1 , 1 , 64 , 40);
                Sangria();
                cout << "Gano " << UltimoGanador << " con un puntaje de: " << PuntajeJ1 << endl;
                MejorJugador = UltimoGanador;
                MejorPuntaje = PuntajeJ1;
        }
        else {
                system("cls");
                DibujarMargen(1 , 1 , 64 , 40);
                Sangria();
                cout << "Gano " << UltimoGanador << " con un puntaje de: " << PuntajeJ2 << endl;
                MejorJugador = Jugador2;
                MejorPuntaje = PuntajeJ2;
        }
    }
}

void ElegirPosiciones(string Nombre1, string Nombre2, string &Jugador1, string &Jugador2){
    int PuntajePlayer1, PuntajePlayer2, NumeroDado;

    do{
        system("cls");
        rlutil::hidecursor();
        DibujarMargen( 1, 1, 64, 40);
        DibujarSeleccionDeJugadores(8,2);
        rlutil::locate(3,19);
        cout << Nombre1 << " lanza un dado: " << endl;
        Esperar(1000);
        NumeroDado = AleatorioConLimite(6);
        DibujarDado(NumeroDado, 32, 21);
        PuntajePlayer1 = NumeroDado;


        rlutil::locate(3,25);
        cout << "Precione cualquier tecla continuar";
        rlutil::anykey();
        rlutil::locate(3,25);
        cout << "                                  "; ///Borramos lo de precionar tecla
        rlutil::locate(3,25);
        cout << Nombre2 << " lanza un dado:" << endl;
        Esperar(1000);
        NumeroDado = AleatorioConLimite(6);
        DibujarDado(NumeroDado, 32, 27); ///DibujarDado
        PuntajePlayer2 = NumeroDado;
        Esperar(1000);

        if (PuntajePlayer1 == PuntajePlayer2){
                system("cls");

                ///DIBUJADO DE LA PANTALLA DE EMPATE
                DibujarMargen( 1, 1, 64, 40);
                DibujarMonitorEmpate(3,10);
                DibujarRectangulo(7,11,60,36, rlutil::LIGHTBLUE);
                DibujarEmpateJugadoresElegirPosiciones(8,3);
                DibujarCodigoQR(9,25);
                DibujarCaritaTristeYTexto(9,12);
                DibujarTextoInformacionError(28,25);

                Esperar(1000);
                rlutil::anykey();
        }
    }while(PuntajePlayer1 == PuntajePlayer2);

    if(PuntajePlayer1 > PuntajePlayer2){
        Jugador1 = Nombre1;
        Jugador2 = Nombre2;
    }
    else{
        Jugador1 = Nombre2;
        Jugador2 = Nombre1;
    }

    ///MOSTRAMOS EL RESULTADO
    DibujarMarcoSeleccionJugadores(4,33);
    rlutil::locate(6,34);
    cout << "- El jugador 1 es: " << Jugador1;
    rlutil::locate(6,36);
    cout << "- El jugador 2 es: " << Jugador2;

    Esperar(1000);
    rlutil::locate(16,38);
    cout << "Precione cualquier tecla continuar";
    rlutil::anykey();
}

int Tirada( string &JugadorTirada, string &UltimoGanador, int &DadosStockJ1, int &DadosStockJ2, int &PuntajeJ1){
    int Dado12Caras1 = 0, Dado12Caras2 = 0, NumeroObjetivo, ContadorDadosElegidos = 0;
    int VectorDados[12] = {};
    int VectorDadosElegidos[12] = {};

    ///LANZAMIENTO DE LOS 2 DADOS DE 12 CARAS
    rlutil::locate(3,5);
    Sangria();
    cout << JugadorTirada << " lanza 2 dados de 12 caras: " << endl;

    int DadoPosicionY = whereY() + 1;

    Esperar(1000);
    Dado12Caras1 = AleatorioConLimite(12);
    DibujarDado12(Dado12Caras1, 22, DadoPosicionY);

    Esperar(1000);
    Dado12Caras2 = AleatorioConLimite(12);
    DibujarDado12(Dado12Caras2, 38, DadoPosicionY);

    rlutil::locate( 3,whereY() + 3);

    ///DEFINICION DE NUMERO OBJETIVO
    NumeroObjetivo = Dado12Caras1 + Dado12Caras2;
    Esperar(1000);
    Sangria();
    cout << "El numero objetivo de "<< JugadorTirada <<" es: " << NumeroObjetivo << endl;

    ///SE TIRAN LOS DADOS STOCK DE 6 CARAS
    cargarAleatorio(VectorDados, DadosStockJ1, 6);
    MostrarDados(VectorDados, DadosStockJ1, 11, whereY() + 1);

    ///ELEGIMOS LOS DADOS, LOS PONEMOS EN UN VECTOR Y SACAMOS LA CANTIDAD DE DADOS
    ContadorDadosElegidos = ElegirDados( VectorDados, DadosStockJ1, VectorDadosElegidos, NumeroObjetivo);
    Sangria();

    ///DEFINIMOS EL RESULTADO DE LA PARTIDA (0,1 o 2)
    return DefinicionDeJugada( JugadorTirada, NumeroObjetivo, VectorDadosElegidos, ContadorDadosElegidos, DadosStockJ1, DadosStockJ2, UltimoGanador, PuntajeJ1);
}

int DefinicionDeJugada(string &JugadorTirada, int NumeroObjetivo, int DadosElegidos[], int ContadorDadosElegidos, int &DadosStockJ1, int &DadosStockJ2, string &UltimoGanador, int &PuntajeJugadorTirada){

    int SumaDeDados = SumarVector(DadosElegidos, ContadorDadosElegidos);

    if(SumaDeDados == NumeroObjetivo && ContadorDadosElegidos == DadosStockJ1){///Jugada GANADORA
        cout << "Jugada Ganadora" << endl;
        UltimoGanador = JugadorTirada;
        PuntajeJugadorTirada += 10000;
        ResumenJugada( JugadorTirada, 2, DadosElegidos, ContadorDadosElegidos, NumeroObjetivo, DadosStockJ1, DadosStockJ2, PuntajeJugadorTirada);
        return 2;
    }
    else if(SumaDeDados == NumeroObjetivo){///Jugada EXITOSA
        Sangria();
        cout << "Jugada Exitosa" << endl;
        UltimoGanador = JugadorTirada;
        PuntajeJugadorTirada += NumeroObjetivo;
        DadosStockJ1 -= ContadorDadosElegidos;
        DadosStockJ2 += ContadorDadosElegidos;
        Sangria();
        ResumenJugada( JugadorTirada, 1, DadosElegidos, ContadorDadosElegidos, NumeroObjetivo, DadosStockJ1, DadosStockJ2, PuntajeJugadorTirada);
        return 1;
    }
    else{///Jugada NO EXITOSA
        Sangria();
        cout << "Jugada No Exitosa" << endl;
        if(DadosStockJ2 > 1){
            DadosStockJ1++;
            DadosStockJ2--;
        }
        ResumenJugada( JugadorTirada, 0, DadosElegidos, ContadorDadosElegidos, NumeroObjetivo, DadosStockJ1, DadosStockJ2, PuntajeJugadorTirada);
        return 0;
    }
}
