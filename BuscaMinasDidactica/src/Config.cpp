#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero) //  Se llama la clase config y se crean los 5 parametros
{
    //  this-> distingue entre los par�metros y los atributos con el mismo nombre.
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;

        //permite modificar el n�mero de filas del tablero, y muestra el valor actual de filas del tablero utilizando la funci�n get()
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        // Segun lo que el usuario seleccione el programa actualizara los datos
        if (opciones!=6)
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones)
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false;
                break;
        }
        system("pause");
    } while (repetir);
}
int Config::getfilasTablero()
{
    return this->filasTablero; // Devuelve el valor actual del atributo filasTablero
}
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero; //establece el valor del atributo filasTablero con el valor pasado como par�metro filasTablero.
}
int Config::getcolumnasTablero()
{
    return this->columnasTablero; // Devuelve el valor actual del atributo columnasTablero
}
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero; //establece el valor del atributo columnasTablero con el valor pasado como par�metro columnasTablero.
}
int Config::getminasTablero()
{
    return this->minasTablero; // Devuelve el valor actual del atributo minasTablero
}
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero; //establece el valor del atributo minasTablero con el valor pasado como par�metro minasTablero.
}
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero; // Devuelve el valor actual del atributo mododesarrolladorTablero
}
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero; //establece el valor del atributo mododesarrolladorTablero con el valor pasado como par�metro mododesarrolladorTablero.
}
int Config::getvidasTablero()
{
    return this->vidasTablero;// Devuelve el valor actual del atributo vidasTablero
}
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero; //establece el valor del atributo vidasTablero con el valor pasado como par�metro vidasTablero.
}
