///TODAS LAS FUNCIONES ENCARGADAS DE LA PARTE MATEMATICA
#include "FuncionesMatematicas.h"
#include <iostream>
#include "rlutil.h"

using namespace std;

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  for( i=0; i<tam; i++ ){
        v[i]= AleatorioConLimite(limite);
  }
}

int AleatorioConLimite(int limite){
    return (rand()%limite)+1;
}

void Esperar(int tiempo){
    for(int i= 0; i < tiempo; i++){
            for(int x = 0; x < tiempo; x++){
                for(int y = 0; y < tiempo; y++){
                }
            }
    }
}

void mostrarVector(int v[], int tam){
    int i;
    Sangria ();
    for(i=0;i<tam;i++){
        Encorchar(v[i]);
    }
    cout << endl;
}

int SumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

void IngresoConValidacionNombre(int x, int y, string &nombre){
    const int MaximoDeCaracteres = 10;
    string texto = "";
    do {
        getline(cin, texto);

        if (texto.empty()) {
            rlutil::locate(x, y);
        }
        else{
            if (texto.size() <= MaximoDeCaracteres) break;
            else {
                rlutil::locate(x, y);
                cout << "MAX 10 Caracteres";
                Esperar(800);
                rlutil::locate(x, y);
                cout << "                         ";
                rlutil::locate(x, y);
            }
        }

    } while (true);
    nombre = texto;
}

void IngresoConValidacionINT(int x,int y,int &variable, int CantidadDeDigitos){
    string StringDeLimpieza = "";

    ///Modificamos la "String de limpieza" para que borre los digitos que nosotros queramos ingresar.
    for(int i = 0; i < CantidadDeDigitos; i++){
        StringDeLimpieza += " ";
    }
    ///CIN del entero:
    do{
        cin >> noskipws; ///Desactivamos el skip a espacios en blanco del CIN
        rlutil::locate(x, y); cout << StringDeLimpieza;
        rlutil::locate(x, y); cin >> variable;

        if(cin.fail() == true){
            cin.clear();
        }
        else{
            break;
        }
        cin.ignore(1000, '\n');///ignoramos los anteriores saltos de linea

    }while(true);
    cin >> skipws; ///Activamos el skip a espacios en blanco del CIN
}

int ElegirDados( int DadosTirados[], int DadosStock, int DadosElegidos[], int NumeroObjetivo){
    int Seleccion, SumaDeDados = 0, indiceDadosElegidos = 0;
    int PosicionesSeleccionadas[11] = {};

    rlutil::showcursor();
    Sangria();
    cout << "Elige los dados: " << endl;
    int Y_Texto = whereY();

    rlutil::locate(3, Y_Texto + 4); cout << "Ingrese << 0 >> para finalizar la seleccion de dados";

    rlutil::locate(3, Y_Texto); cout << "Dado N(1/"<<DadosStock<<"): ";
    IngresoConValidacionINT( 17, Y_Texto, Seleccion, 47);

    rlutil::locate(3, Y_Texto); cout << "                              ";
    while(/*SumaDeDados != NumeroObjetivo &&*/ Seleccion != 0){
        if(Seleccion >= 0 && Seleccion <= DadosStock){
            if (DadosTirados[Seleccion -1] == 0){///Si esto ocurre es porque anteriormente nosotros lo seteamos en 0 por ende esta pidiendo un dado repetido
                rlutil::locate(3, Y_Texto); cout << "No puedes reutilizar un dado >:c" << endl;
                Esperar(1000);
            }
            else{
                DadosElegidos[indiceDadosElegidos] = DadosTirados[Seleccion -1];
                /*SumaDeDados += DadosTirados[Seleccion -1];*/
                DadosTirados[Seleccion -1] = 0;

                ///Mostramos los dados que vamos seleccionando usando un vector
                PosicionesSeleccionadas[indiceDadosElegidos] = Seleccion;
                rlutil::locate(3, Y_Texto + 1); cout << "Dados Seleccionados: ";
                rlutil::locate(3, Y_Texto + 2); mostrarVector(PosicionesSeleccionadas,indiceDadosElegidos + 1);
                /*if(Seleccion != 0)*/ indiceDadosElegidos++;
                /*if (SumaDeDados > NumeroObjetivo || indiceDadosElegidos == DadosStock) break;*/
            }
        }
        else{
            rlutil::locate(3, Y_Texto);
            cout << "No existe ese dado >:c" << endl;
            Esperar(1000);
        }
            rlutil::locate(3, Y_Texto); cout << "                                  ";
            rlutil::locate(3, Y_Texto); cout << "Dado N(1/"<<DadosStock<<"): ";
            IngresoConValidacionINT( 17, Y_Texto, Seleccion, 47);
            rlutil::locate(3, Y_Texto); cout << "                                  ";
    }
    rlutil::hidecursor();
    return indiceDadosElegidos; ///Esto lo hacemos por que nos da, directamente la cantidad de Dados elegidos
}

int Clamp(int Num, int Min, int Max){
    if (Num > Max){
        Num = Max;
    }
    else if(Num < Min){
        Num = Min;
    }
    return Num;
}

int whereY(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); ///Es el manejo de la informacion de la salida de datos de toda la consola
    return csbi.dwCursorPosition.Y + 1;
}
