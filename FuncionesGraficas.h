#pragma once
#include <iostream>
using namespace std;

///PRINCIPALES FUNCIONES GRAFICAS:
void Encorchar(int resultado);
void Sangria();
void DibujarDado(int n, int x, int y);
void DibujarMargen( int x1, int y1, int x2, int y2);
void DibujarRectangulo(int x1, int y1, int x2, int y2 , int Color);
void DibujarSombraRectangulo(int x1, int y1, int x2, int y2);
void MostrarDados(int v[], int tam, int x, int y);
void DibujarDado12(int n, int x, int y);
void DibujarPantallaDeJuego(string Jugador1, string Jugador2, int PuntajeJ1, int PuntajeJ2, int DadosStockJ1, int DadosStockJ2, int Ronda);
void ResumenJugada(string UltimoJugador, int Resultado, int DadosSeleccionados[], int CantidadDeDadosSeleccionados, int NumeroObjetivo, int DadosStockJugador, int DadosStockContrincante,  int PuntajeJugador);

///ARTE ASCII ENTRE OTROS:
void DibujarLogoUTN( int X , int Y);
void DibujarTituloDeResumenPartida(int n, int X, int Y);
void DibujarCreditosPagina1(int X, int Y);
void DibujarCreditosPagina3(int X, int Y);
void DibujarSubtituloDeResumenPartida(int n, int X, int Y);
void DibujarJugadaNoExitosa (int X , int Y);
void DibujarNegativo(int X, int Y);
void DibujarJugadaExitosa(int X, int Y);
void DibujarJugadaGanadora(int X, int Y);
void DibujarNombreUTN (int X , int Y);
void DibujarEquipoDocente(int X, int Y);
void DibujarMonitorDocentes(int X, int Y);
void DibujarDisenioMonitorDocente (int X , int Y);
void DibujarMandoDeConsola(int X, int Y);
void DibujarDisenioMonitorLosCodificadores (int X , int Y);
void DibujarENFRENDADOS(int X , int Y);
void DibujarDisenioMenu(int X, int Y, int Seleccion);
void DibujarMenu (int X , int Y);
void DibujarPasto(int x1,int x2, int y, int altura);
void DibujarEmpateJugadoresElegirPosiciones (int X , int Y);
void DibujarMonitorEmpate(int X, int Y);
void DibujarCaritaTristeYTexto (int X , int Y);
void DibujarCodigoQR (int x, int y);
void DibujarTextoInformacionError (int X , int Y);
void DibujarTituloRonda1 (int X , int Y);
void DibujarTituloRonda2 (int X , int Y);
void DibujarTituloRonda3 (int X , int Y);
void DibujarTrofeo (int x , int y);
void DibujarTituloGanador (int X , int Y);
void DibujarMarcoDecorativo (int X , int Y);
void DibujarSeleccionDeJugadores (int X , int Y);
void DibujarMarcoSeleccionJugadores (int X , int Y);
void DibujarMVP(int X, int Y);
void DibujarCartelMVP (int X ,int Y);
void DibujarTheBestPlayer (int x , int y);
void DibujarPasto (int X1 , int X2 , int Y, int Altura);
void DibujarPantallaEmpate();
