//Este ejemplo pretende mostrar el nivel de adaptaci�n de C a C++, utilizando matrices o arreglos bidimensionales
//Ingenier�a en Sistemas de Informaci�n y Ciencias de la Computaci�n
//Catedr�: Programaci�n 1
//Catedr�tico: Ingeniero Estuardo del �guila
//Grupo # 4
//Equipo:
//Maria Fernanda Mart�nes Gonz�lez 9959 22 7981
//Melvin Alberto Gonz�lez V�squez 9959 22 3148
//Luis Alejandro Contreras Paredez 9959 22 473
//Cristhall Mishell Rodr�guez Ortiz 9959 22 8588
//Fecha de Creaci�n: 16 de febrero 2023

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

//Constantes
const int NUMERO_ALUMNOS = 10;
const int NUMERO_MATERIAS = 3;
const int MAX_CALIFICACION = 100;
const int MIN_CALIFICACION = 0;
const int MAX_LONGITUD_CADENA = 100;

//Definici�n de prototipos de funci�n
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]);
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]);
int main()
{
    cout<<"\n";
    cout<<"\t\tCONTROL DE NOTAS\n\n";
    srand((unsigned)time(0));  //Creaci�n de n�meros Random
    float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]; //Matrix de 3 x 4
    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"VALERY", "DANIEL","CARLOS","MAX", "MARVIN","OSCAR","CAMILA","EDUARDO","ADRIAN","DAYANA"}; //Vector alumnos ya definido
    llenarMatriz(matriz);
    imprimirMatriz(matriz, alumnos);

    system ("pause");
    return 0;
}
//Implementaci�n de funciones
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_CALIFICACION - MIN_CALIFICACION));
}
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1])
{
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        float sumaNotasAlumno = 0;
        for ( int x=0; x < NUMERO_MATERIAS; x++)
        {
            int calificacionAlumno = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotasAlumno += (float)calificacionAlumno;
            matriz[y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / NUMERO_MATERIAS;
        matriz[y][NUMERO_MATERIAS]=promedioNotasAlumno;
    }
}
void imprimirLineaMatriz() //Formato de separaci�n de informaci�n
{
    cout << ("+--------------------");
    for (int x=0; x < NUMERO_MATERIAS + 1; x++)
    {
        cout << "---------";
    }
    cout<< ("+\n");
}
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{
    float promedioMayor = matriz[0][NUMERO_MATERIAS];
    float promedioMenor = matriz[0][NUMERO_MATERIAS];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout << setw(8) << "Alumno";

    for (int x=0; x < NUMERO_MATERIAS; x++)
    {
        cout << setw(7) << "Cal" << setw(4) << x + 1 << "!" ;
    }
    cout << setw(12) << "Promedio" << setw(3) <<"!\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(8) << alumnos[y];

        for (int x=0;x < NUMERO_MATERIAS; x++)
            {
                int calificacion = matriz[y][x];
                cout <<  setw(11) << calificacion;

            }
        float promedio = matriz[y][NUMERO_MATERIAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAX_LONGITUD_CADENA);
        }
        cout << setw(13) << fixed << setprecision(2) << promedio << setw(5) << "!\n";

        imprimirLineaMatriz();
    }
    cout << "Promedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << setw(7) << promedioMayor << endl;
    cout << "Promedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << setw(7) << promedioMenor << endl;
}
