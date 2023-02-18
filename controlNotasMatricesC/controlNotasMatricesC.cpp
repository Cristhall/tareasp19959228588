// Este ejemplo pretende mostrar el nivel de adaptación de C a C++, utilizando matrices o arreglos bidimensionales
// Fecha de creación: 15 de febrero de 2023
#include <stdio.h>  //libreria de C
#include <stdlib.h> //Libreria de C
#include <unistd.h> //Libreria de C
#include <string.h> //Viene de la iostream

// matriz de 3 x 3
#define NUMERO_ALUMNOS 3  //Esta era la forma de C, en C++ se usa la otra forma donde se define el tipo
#define NUMERO_MATERIAS 3
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAX_LONGITUD_CADENA 100

int busquedaAleatorios(int minimo, int maximo); //parámetros
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]); //prototipo de función
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]); //parametro, permite capturar datos del exterior de una función. traspaso de datos por valor
int main()
{
    srand(getpid()); //genera numeros que seran utilizados en la matriz, esto es para no ingresar valores.
    float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]; //El + 1 representa una fila más, por eso será de 3 x 4
    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"Mario","Carlos","Maria"}; //Esto es definir de una vez la constante, de los contrario se pueden ingresar
    llenarMatriz(matriz);
    imprimirMatriz(matriz, alumnos);
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1); //Solo es para generar numeros aleatorios
}
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1])
{
    int y, x; //los contadores se definian en el mismo foro, en C se definen afuera
    for (y=0; y < NUMERO_ALUMNOS; y++) // maneja las columnas, se irá fila por fila
    {
        float sumaNotasAlumno = 0;
        for (x=0; x < NUMERO_MATERIAS; x++)//anidado, irá cambiando
        {
            int calificacionAlumno = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION); //obtieneuna calificacion con el rango de 0 a 100
            sumaNotasAlumno += (float)calificacionAlumno; //+= suma + suma
            matriz[y][x] = calificacionAlumno;
        }
        //la suma ayudara para el promedio
        float promedioNotasAlumno = sumaNotasAlumno / NUMERO_MATERIAS;
        matriz [y][NUMERO_MATERIAS] = promedioNotasAlumno;
    }
}
void imprimirLineaMatriz()
{
    int x;
    printf("+---------------");
    for (x=0; x < NUMERO_MATERIAS + 1; x++)
    {
        printf("---------");
    }
    printf("+\n");
}
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{
    int y, x; //recordando: son contadores definidos a la manera de C
    float promedioMayor = matriz[0][NUMERO_MATERIAS]; //Obtener la columna 0 el primer valor
    float promedioMenor = matriz[0][NUMERO_MATERIAS];
    char alumnoPromedioMayor [MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor [MAX_LONGITUD_CADENA];
    memcpy (alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA); //esto es una copia de matrices en vectores. En C no se puede usar string
    memcpy (alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    printf("|  Alumno  |");
    for (x=0; x < NUMERO_MATERIAS; x++)
    {
        printf("Cal  %d   |", x + 1); //secuencia de formato: permite imprimir la calificacion
    }
    printf("Promedio  |\n");
    imprimirLineaMatriz();
    for (y=0; y < NUMERO_ALUMNOS; y++)
    {
        printf("%-11s|", alumnos[y]); //imprimir 10 caracteres.
        float suma = 0;
        for (x=0; x <  NUMERO_MATERIAS; x++)
        {
            int calificacion = matriz[y][x];
            printf ("%-9d|", calificacion);
        }
        float promedio = matriz[y][NUMERO_MATERIAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy (alumnoPromedioMayor, alumnos[y], MAX_LONGITUD_CADENA);

        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy (alumnoPromedioMenor, alumnos[y], MAX_LONGITUD_CADENA);
        }
        printf ("%0.2f     |\n", promedio);
        imprimirLineaMatriz();
    }
    printf ("Promedio Mayor: %s con %0.2f\n", alumnoPromedioMayor, promedioMayor);
    printf ("Promedio Menor: %s con %0.2f\n", alumnoPromedioMenor, promedioMenor);
}
