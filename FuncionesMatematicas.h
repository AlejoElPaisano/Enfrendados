#pragma once
#include <iostream>
using namespace std;

void cargarAleatorio(int v[], int tam, int limite);
int AleatorioConLimite(int limite);
void Esperar(int tiempo);
void mostrarVector(int v[], int tam);
int ElegirySumarDados(int v[], int DadosStock, int NumeroObjetivo, int &ContadorDados);
void Encorchar(int resultado);
void Sangria();
int whereY();
int Clamp(int Num, int Min, int Max);
int SumarVector(int v[], int tam );
int ElegirDados( int DadosTirados[], int DadosStock, int DadosElegidos[], int NumeroObjetivo);
void IngresoConValidacionINT(int x,int y,int &variable, int CantidadDeDigitos);
void IngresoConValidacionNombre(int x, int y, string &nombre);
