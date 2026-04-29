#pragma once
#include <iostream>
using namespace std;

void MostrarMenu( string &MejorJugador, int &MejorPuntaje);
void SeleccionarOpciones( int Seleccion,string &MejorJugador, int &MejorPuntaje);
void Jugar(string &MejorJugador, int &MejorPuntaje);
void ElegirPosiciones(string Nombre1, string Nombre2, string &Jugador1, string &Jugador2);
int Tirada( string &JugadorTirada, string &UltimoGanador, int &DadosStockJ1, int &DadosStockJ2, int &PuntajeJ1);
int DefinicionDeJugada(string &JugadorTirada, int NumeroObjetivo, int DadosElegidos[], int ContadorDadosElegidos, int &DadosStockJ1, int &DadosStockJ2, string &UltimoGanador, int &PuntajeJugadorTirada);
void Creditos();
