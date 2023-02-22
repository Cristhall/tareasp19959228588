//En este programa se crea una matriz donde se impriman las calificaciones de UMG.
//Califiaciones: primer, segundo y tercer parcial, actividades, zona y promedio.
//Carrera: Ingeniería en Sistemas
//Curso: Programación 1
//Creador: Cristhall Mishell Rodríguez Ortiz
//Carné: 9959 22 8588


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

// Vectores y Matriz
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
        //Se le permite al usuario ingresar el nombre de los alumnos
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
    return minimo + (rand()%(MAX_1P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 20 puntos
}
void primerParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            notas[i] = numero; //Se agrega numeros Random al vector
            matriz[i][0] = notas[i]; //Se agrega el vector del primer parcial a la matriz
        }
    }
}
int busquedaAleatorios1(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_2P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 25 puntos
}
void segundoParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero1 = busquedaAleatorios1(MIN_CALIFICACION, MAX_2P_CALIFICACION);
            notas1[i] = numero1; //Se agrega los numeros Random al vector
            matriz[i][1] = notas1[i]; //Se agrega el vector del segundo parcial a la matriz
        }
    }
}
int busquedaAleatorios2(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_3P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 35 puntos
}
void tercerParcial()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero2 = busquedaAleatorios2(MIN_CALIFICACION, MAX_3P_CALIFICACION);
            notas2[i] = numero2; //Se agregan los numeros random al vector.
            matriz[i][2] = notas2[i]; //Se agrega el vector del tercer parcial a la matriz
        }
    }
}
void actividades()
{
    for(int i = 0; i < NUMERO_MATERIAS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero3 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION); //Rango de 0 - 20 puntos
            acti[i] = numero3; //Se incluyen los numeros random al vector
            matriz[i][3] = acti[i]; //Se agrega el vector de actividades a la matriz
        }
    }
}
void sumaIndividual()
{
        for(int i=0; i<5; i++)
    {
        //Suma de las calificaciones para encontrar la zona
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
            matriz[i][4] = sumaPorCurso[i]; //Se incluye loz valores de zona en la matriz
        }
    }
}
int promedioGeneral()
{
    //Calculo del promedio al sumar las zonas de todos los cursos
    float suma = 0, promedioTotal;
    for (int i=0; i<=NUMERO_MATERIAS; i++)
    {
        suma += notas[i];
        suma += notas1[i];
        suma += notas2[i];
        suma += acti[i];
    }
    //Impresion del promedio
    promedioTotal = suma / NUMERO_MATERIAS;
    cout <<"\n\tPROMEDIO: " << fixed << setprecision(2) << promedioTotal << endl;
    cout << "__________________________________" << endl << endl;
    return suma, promedioTotal;
    system("pause>nul");
}
void imprimirLineaMatriz() //Formato de separación de información
{
    //Linea de separación para la matriz
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
                cout << setw(6) << calificacion << setw(6) << "|"; //Se imprime completamente la matriz
            }
        cout << endl;
        imprimirLineaMatriz();
    }
}


//Lectura de un vector:
//int limite = (sizeof(edades)/sizeof(edades[0]));
//for (int i = 0; i < limite; i++)
//cout<<edades[i]<<endl;

