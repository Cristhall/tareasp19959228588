#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <string.h>

using namespace std;

// Constantes
const int NUMERO_ALUMNOS = 5;
const int NUMERO_MATERIAS = 5;
const int MAX_1P_CALIFICACION = 20;
const int MIN_CALIFICACION = 0;
const int MAX_2P_CALIFICACION = 25;
const int MAX_3P_CALIFICACION = 35;

//Variables
int suma2;


// Funciones
void menuPrincipal();
void ingresoAlumnos();
void ingresoCalificaciones();
int promedioGeneral();
void sumaIndividual();
int busquedaAleatorios(int minimo, int maximo);
int busquedaAleatorios1(int minimo, int maximo);
int busquedaAleatorios2(int minimo, int maximo);
void primerParcial();
void segundoParcial();
void tercerParcial();
void actividades();
void zona();
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_ALUMNOS+1][NUMERO_MATERIAS+2]);

// Vectores
string alumnos[NUMERO_ALUMNOS]; //vector de los nombres de alumnos
string materias[NUMERO_MATERIAS] = {"PROGRAMACION_I","PROCESO_ADMINISTRATIVO","DERECHO_INFORMATICO","CALCULO_I","FISICA_I"};
int notas[NUMERO_MATERIAS]; //notas del primer parcial
int notas1[NUMERO_MATERIAS];//notas del segundo parcial
int notas2[NUMERO_MATERIAS]; //notas del tercer parcial
int acti[NUMERO_MATERIAS]; //notas de actividades
int sumaPorCurso[NUMERO_MATERIAS]; //suma individual por curso.
float matriz[NUMERO_ALUMNOS+1][NUMERO_MATERIAS+2];  //Matriz de 6 x 7

int main()
{
    menuPrincipal();
    system("pause");
    return 0;
}
//Implementación de funciones
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
            srand(time(NULL));
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
        imprimirMatriz(matriz);
        promedioGeneral();
    }
    system("pause>nul");
}
void ingresoCalificaciones()
{
    primerParcial();
    segundoParcial();
    tercerParcial();
    actividades();
    zona();
    system("pause>nul");
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_1P_CALIFICACION - MIN_CALIFICACION));
}
void primerParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            notas[i] = numero;
            matriz[0][0] = notas[0];
            matriz[1][0] = notas[1];
            matriz[2][0] = notas[2];
            matriz[3][0] = notas[3];
            matriz[4][0] = notas[4];
        }
    }
}
int busquedaAleatorios1(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_2P_CALIFICACION - MIN_CALIFICACION));
}
void segundoParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero1 = busquedaAleatorios1(MIN_CALIFICACION, MAX_2P_CALIFICACION);
            notas1[i] = numero1;
            matriz[0][1] = notas1[0];
            matriz[1][1] = notas1[1];
            matriz[2][1] = notas1[2];
            matriz[3][1] = notas1[3];
            matriz[4][1] = notas1[4];
        }
    }
}
int busquedaAleatorios2(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_3P_CALIFICACION - MIN_CALIFICACION));
}
void tercerParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero2 = busquedaAleatorios2(MIN_CALIFICACION, MAX_3P_CALIFICACION);
            notas2[i] = numero2;
            matriz[0][2] = notas2[0];
            matriz[1][2] = notas2[1];
            matriz[2][2] = notas2[2];
            matriz[3][2] = notas2[3];
            matriz[4][2] = notas2[4];
        }
    }
}
void actividades()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero3 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            acti[i] = numero3;
            matriz[0][3] = acti[0];
            matriz[1][3] = acti[1];
            matriz[2][3] = acti[2];
            matriz[3][3] = acti[3];
            matriz[4][3] = acti[4];
        }
    }
}
void sumaIndividual()
{
        for(int i=0; i<5; i++)
    {
        sumaPorCurso[i] = notas[i] + notas1[i] + notas2[i] + acti[i];
    }
}
void zona()
{
    sumaIndividual();
    for(int i=0; i < NUMERO_MATERIAS; i++)
    {
        for(int x=0; x<1; x++)
        {
            matriz[0][4] = sumaPorCurso[0];
            matriz[1][4] = sumaPorCurso[1];
            matriz[2][4] = sumaPorCurso[2];
            matriz[3][4] = sumaPorCurso[3];
            matriz[4][4] = sumaPorCurso[4];
        }
    }
}
int promedioGeneral()
{
    float suma = 0, promedioTotal;
    for (int i=0; i<=NUMERO_MATERIAS; i++)
    {
        suma += notas[i];
        suma += notas1[i];
        suma += notas2[i];
        suma += acti[i];
    }
    promedioTotal = suma / NUMERO_MATERIAS;
    cout <<"\n\tPROMEDIO: " << fixed << setprecision(2) << promedioTotal << endl;
    cout << "__________________________________" << endl << endl;
    return suma, promedioTotal;
    system("pause>nul");
}
void imprimirLineaMatriz() //Formato de separación de información
{
    cout << ("+----------------------");
    for (int x=0; x < NUMERO_MATERIAS + 1; x++)
    {
        cout << "-----------";
    }
    cout<< ("+\n");
}
void imprimirMatriz(float matriz[NUMERO_ALUMNOS+1][NUMERO_MATERIAS+2])
{
    imprimirLineaMatriz();
    cout << setw(20) << "CLASE" << setw(10) << "|" << setw(5);

    for (int x=0; x < 3; x++)
    {
        cout << "P" << setw(2) << x + 1 << setw(5) << "|" << setw(5);
    }
    cout << setw(7) << "ACT" << setw(5) <<"|";
    cout << setw(8) << "ZONA" << setw(5) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_MATERIAS; y++)
    {
        cout << setw(25) << materias[y] << setw(5) << "|" << setw(7);
        for (int x=0;x < NUMERO_MATERIAS; x++)
            {
                int calificacion = matriz[y][x];
                cout << setw(6) << calificacion << setw(6) << "|";
            }
        cout << endl;
        imprimirLineaMatriz();
    }
}


//Lectura de un vector:
//int limite = (sizeof(edades)/sizeof(edades[0]));
//for (int i = 0; i < limite; i++)
//cout<<edades[i]<<endl;

