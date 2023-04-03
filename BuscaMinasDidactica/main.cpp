#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"

using namespace std;

int main()
{
    const int FILASTABLERO = 5;//establece el numero del tablero
    const int COLUMNASTABLERO = 5;//establece la cantidad de ancho del tablero del juego
    const int MINASENTABLERO = 3;//indica la cantidad de minas a encotrar en el tabelro
    const bool MODODESARROLLADOR = true;//cambia la interfaz del juego
    const int VIDASTABLERO = 3;//colocamos en la variable la cantidad de veces que podemos encontrar una mina
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);//invocamos la primera funcion del juego relacionada con la configuracion
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    juego.dibujarPortada("portada.txt");//trae la funcion que nos permite tener el primer menu del juego
    srand(getpid());
    int opciones;//permite colocar el parametro para la cantidad de opciones que tendra el juego
    bool repetir = true;//establecemos el ciclo que estaria funcionando con las funciones o repite el nuevamente el ciclo de ellecion
    do
    {
        system("cls");//relacionada a la  sd
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1://primera funcion del ciclo que nos brinda las opciones previo al juego
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2://nos brinda un la opcion en donde podemos utilizar el juego en modo desarrollador y ver la cantidad de los datos string y enteros en el tablero
            {
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar();

                system("pause");
                break;
            }
        case 3: repetir = false;//repite el cliclo
                break;
        }
    } while (repetir);//invocamos la funcion para que nuevamente la funcion vuelva a origen y nos proporcione el ciclo para repetor funcion
    system("cls");
    juego.dibujarPortada("creditos.txt");//exporta los datos string establecidos con los ciclos en las funciones y asi poder tener los titulos y lineas correspondientes
    return 0;
}
