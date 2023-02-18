//Este ejemplo pretende mostrar el nivel de adaptación de C a C++, utilizando matrices o arreglos bidimensionales
//Fecha de Creación: 16 de febrero 2023
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

const int NUMERO_ALUMNOS = 3;
const int NUMERO_MATERIAS = 3;
const int MAX_CALIFICACION = 100;
const int MIN_CALIFICACION = 0;
const int MAX_LONGITUD_CADENA = 100;

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]);
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]);
int main()
{
    cout<<"\n";
    cout<<"\t\tControl de notas\n\n";
    srand((unsigned)time(0));
    float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1];
    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"VALERY", "DANIEL","CARLOS"};
    llenarMatriz(matriz);
    imprimirMatriz(matriz, alumnos);

    system ("pause");
    return 0;
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_CALIFICACION - MIN_CALIFICACION));
}
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1])
{
    int y, x;
    for (y=0; y < NUMERO_ALUMNOS; y++)
    {
        float sumaNotasAlumno = 0;
        for (x=0; x < NUMERO_MATERIAS; x++)
        {
            int calificacionAlumno = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotasAlumno += (float)calificacionAlumno;
            matriz[y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / NUMERO_MATERIAS;
        matriz[y][NUMERO_MATERIAS]=promedioNotasAlumno;
    }
}
void imprimirLineaMatriz()
{
    int x;
    cout << ("+--------------------");
    for (x=0; x < NUMERO_MATERIAS + 1; x++)
    {
        cout << "---------";
    }
    cout<< ("+\n");

}
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz[0][NUMERO_MATERIAS];
    float promedioMenor = matriz[0][NUMERO_MATERIAS];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout << setw(8) << "Alumno";

    for (x=0; x < NUMERO_MATERIAS; x++)
    {
        cout << setw(7) << "Cal" << setw(4) << x + 1 << "!" ;
    }
    cout << setw(12) << "Promedio" << setw(3) <<"!\n";

    imprimirLineaMatriz();
    for (y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(8) << alumnos[y];

        float suma = 0;
        for (x=0;x < NUMERO_MATERIAS; x++)
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
        cout << setw(12) << fixed << setprecision(2) << promedio << setw(6) << "!\n";

        imprimirLineaMatriz();
    }
    cout << "Promedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << setw(7) << promedioMayor << endl;
    cout << "Promedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << setw(7) << promedioMenor << endl;
}
