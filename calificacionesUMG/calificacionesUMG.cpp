#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <string.h>

using namespace std;

// Constantes
const int NUMERO_ALUMNOS = 5;
const int NUMERO_MATERIAS = 5;

// Vectores
string alumnos[NUMERO_ALUMNOS];
string materias[NUMERO_MATERIAS] = {"PROGRAMACIÓN_I","PROCESO_ADMINISTRATIVO","DERECHO_INFORMÁTICO","CÁLCULO_I","FÍSICA_I"};
int notas[NUMERO_MATERIAS];

// Funciones
void menuPrincipal();
void ingresoAlumnos();
void ingresoCalificaciones();
int promedio();

int main()
{
    menuPrincipal();
    system("pause");
    return 0;
}
void menuPrincipal()
{
    int opciones;
    bool repetir = true; //Para que regrese a menú
    do
    {
        system("cls");
        cout << "\n\n\t\t\tCALIFICACIONES UMG" << endl;
        cout << "\t\t-------------------------------\n\n";
        cout << "\t1. INGRESO DE CALIFICACIONES" << endl;
        cout << "\t2. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            ingresoAlumnos();
            break;
        case 2: repetir = false;
                break;
        }
    }while (repetir);
}
void ingresoAlumnos()
{
    system("cls");
    for(int i = 0; i < NUMERO_ALUMNOS; i++)
    {
        cout <<"\n\tIngrese el nombre del alumno: \n\t " <<  i + 1 << ".\t";
        cin >> alumnos[i];
        ingresoCalificaciones();
        promedio();
    }
    system("pause>nul");
}
void ingresoCalificaciones()
{
    cout << "\n";
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        cout << "\tCalificación " << materias[i] << ": ";
        cin >> notas[i];
    }
    system("pause>nul");
}
int promedio()
{
    int suma = 0, promedioTotal;
    for (int i=0; i<=NUMERO_MATERIAS; i++)
    {
        suma += notas[i];
    }
    promedioTotal = suma / NUMERO_MATERIAS;
    cout <<"\n\tPROMEDIO: " << promedioTotal << endl;
    cout << "\t--------------------------" << endl;
    return suma, promedioTotal;
    system("pause>nul");
}

//Lectura de un vector:
//int limite = (sizeof(edades)/sizeof(edades[0]));
//for (int i = 0; i < limite; i++)
//cout<<edades[i]<<endl;
