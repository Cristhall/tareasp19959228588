#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>
#include <conio.h>

const int CANTIDAD_NOMBRES = 5;
const int CANTIDAD_MATERIAS = 5;
const int MAX_LONGITUD_NOMBRES = 100;
const int MAX CALIFICACION = 100;
const int MIN_CALIFICACION = 0;

void menuPrincipal();
int busquedaAleatorios(int minimo, int maximo);
void ingresoDeNombres (float alumnos, CANTIDAD_NOMBRES);
void ingresoDeMaterias(CANTIDAD_MATERIAS);

int main()
{
    menuPrincipal();
    srand((unsigned)time(0));
    float matriz[CANTIDAD_NOMBRES][CANTIDAD_MATERIAS+1];
    char alumnos[CANTIDAD_NOMBRES][MAX_LONGITUD_NOMBRES];

    getch();
    return 0;
}
void menuPrincipal()
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMENU CALIFICACIONES UMG" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\t1. Ingreso de nombres" << endl;
        cout << "\t2. Ingreso de materias" << endl;
        cout << "\t3. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            ingresoDeNombres();
            break;
        case 2:
            ingresoDeMaterias();
            break;

        case 3: repetir = false;
                break;
        }
    }while (repetir);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_CALIFICACION - MIN_CALIFICACION));
}
void ingresoDeNombres (float alumnos, CANTIDAD_NOMBRES)
{
    for (int i=0; i<=CANTIDAD_NOMBRES; i++)
    {
        cout << "Escriba el nombre del alumno; " << endl;
        cin >> alumnos[];
        ingresoDeMaterias();
    }break;
}
void ingresoDeMaterias(CANTIDAD_MATERIAS)
{
    for (int i=0; i<=CANTIDAD_MATERIAS; i++)
    {
        cout << "Escriba las materias: " << endl;
        cin >> alumnos[];
        busquedaAleatorios();
    }break;
}
