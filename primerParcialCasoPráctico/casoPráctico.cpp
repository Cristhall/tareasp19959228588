//Ingeniería en sistemas de información y ciencias de la computación
//Primer Parcial
//Programación I
//Cristhall Mishell Rodríguez Ortiz
//9959 22 8588
//Este trabajo consiste en la modernización de la tecnología en una corporación de deportes.
//Se reutilizo código, razón pir la cual solo se cambiaron nombre a la hora de imprimir y no de las variables, constantes, funciones, vetores y matrices.


#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <string.h>

using namespace std;

// Constantes
const int NUMERO_ALUMNOS = 5;
const int NUMERO_ACTIVIDADES = 5;
const int MAX_1P_CALIFICACION = 50;
const int MIN_CALIFICACION = 0;
const int MAX_2P_CALIFICACION = 50;
const int MAX_3P_CALIFICACION = 50;
const int NUMERO_FACULTADES = 3;
const int MAX_LONGITUD_CADENA = 150;

//Variables
int suma2;
float promedioGeneralInge, promedioGeneralAdmon, promedioGeneralArqui;
int mayor, mayor1, mayor2;

// Funciones
void menuPrincipal();
void ingresoCalificaciones();
void sumaIndividual();
int busquedaAleatorios(int minimo, int maximo);
int busquedaAleatorios1(int minimo, int maximo);
int busquedaAleatorios2(int minimo, int maximo);
void facultadIngenieria();
void facultadAdmon();
void facultadArquitectura();
void zona();
void imprimirLineaMatriz();
void imprimirLineaMatriz2();
void imprimirMatrizIngenieria(float ingenieriaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void imprimirMatrizAdmon(float administracionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void imprimirMatrizArquitectura(float arquitecturaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void promedioGeneralPorFacultad();
void generalDeInge();
void generalDeAdmon();
void generalDeArqui();
void impresionResultadoTorneo();

// Vectores y Matrices
char ingenieria[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"GUATEMALA", "ESCUINTLA", "PETEN", "ALTA_VERAPAZ","IZABAL"};
char administracion[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"LEONALE", "CELTICS", "LAKERS", "NETS", "AGUILAS"};
char arquitectura[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"RAPTORS", "ALEGRIA", "AZUCAREROS", "CHUSITOS", "CASITAS"};
int inge[NUMERO_ALUMNOS]; //notas del primer parcial
int inge1[NUMERO_ALUMNOS];//notas del segundo parcial
int inge2[NUMERO_ALUMNOS]; //notas del tercer parcial
int acti[NUMERO_ALUMNOS]; //notas de actividades
int sumaIngeniera[NUMERO_ALUMNOS];
int admon[NUMERO_ALUMNOS];
int admon1[NUMERO_ALUMNOS];
int admon2[NUMERO_ALUMNOS];
int acti1[NUMERO_ALUMNOS];
int sumaAdmon[NUMERO_ALUMNOS];
int arqui[NUMERO_ALUMNOS];
int arqui1[NUMERO_ALUMNOS];
int arqui2[NUMERO_ALUMNOS];
int acti2[NUMERO_ALUMNOS];
int torneo[NUMERO_FACULTADES];
int torneo2[NUMERO_FACULTADES];
int sumaArquitectura[NUMERO_ALUMNOS];
float ingenieriaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];  //Matriz de 6 x 6
float administracionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];
float arquitecturaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];


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
        cout << "\n\n\t\t\tTORNEO DE LIGAS" << endl;
        cout << "\t\t-------------------------------\n\n";
        cout << "\t1. EMPEZAR TORNEO" << endl;
        cout << "\t2. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            system("cls");
            int a;
            cout << "\n\tIngrese \"1\" para continuar y \"2\" para salir: ";
            cin >> a;
            while (a == 1)
            {
                system ("cls");
                srand(time(NULL));
                ingresoCalificaciones();
                imprimirMatrizIngenieria(ingenieriaMatriz);
                imprimirMatrizAdmon(administracionMatriz);
                imprimirMatrizArquitectura(arquitecturaMatriz);
                cout << endl;
                cout << "\n\t\tPROMEDIO GENERAL POR LIGA: " << endl << endl;
                promedioGeneralPorFacultad();
                impresionResultadoTorneo();
                cout << endl;
                imprimirLineaMatriz2();
                cout << "\n\t¿Desea realizar otra prueba? \"1\" para continuar y \"2\" para salir: ";
                cin >> a;
            }
            break;
        case 2: repetir = false;
                break;
        }
    }while (repetir);
}
void ingresoCalificaciones()
{
    facultadIngenieria();
    facultadAdmon();
    facultadArquitectura();
    zona();
    system("pause>nul");
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_1P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 20 puntos
}
int busquedaAleatorios1(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_2P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 25 puntos
}
int busquedaAleatorios2(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_3P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 35 puntos
}
void facultadIngenieria()
{
    for(int i = 0; i < NUMERO_ALUMNOS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            inge[i] = numero; //Se agrega numeros Random al vector
            ingenieriaMatriz[i][0] = inge[i]; //Se agrega el vector del primer parcial a la matriz
            int numero1 = busquedaAleatorios1(MIN_CALIFICACION, MAX_2P_CALIFICACION);
            inge1[i] = numero1; //Se agrega los numeros Random al vector
            ingenieriaMatriz[i][1] = inge1[i]; //Se agrega el vector del segundo parcial a la matriz
            int numero2 = busquedaAleatorios2(MIN_CALIFICACION, MAX_3P_CALIFICACION);
            inge2[i] = numero2; //Se agregan los numeros random al vector.
            ingenieriaMatriz[i][2] = inge2[i]; //Se agrega el vector del tercer parcial a la matriz
            int numero3 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION); //Rango de 0 - 20 puntos
            acti[i] = numero3; //Se incluyen los numeros random al vector
            ingenieriaMatriz[i][3] = acti[i]; //Se agrega el vector de actividades a la matriz
        }
    }
}
void facultadAdmon()
{
    for(int i = 0; i < NUMERO_ALUMNOS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero4 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            admon[i] = numero4; //Se agrega numeros Random al vector
            administracionMatriz[i][0] = admon[i]; //Se agrega el vector del primer parcial a la matriz
            int numero5 = busquedaAleatorios1(MIN_CALIFICACION, MAX_2P_CALIFICACION);
            admon1[i] = numero5; //Se agrega los numeros Random al vector
            administracionMatriz[i][1] = admon1[i]; //Se agrega el vector del segundo parcial a la matriz
            int numero6 = busquedaAleatorios2(MIN_CALIFICACION, MAX_3P_CALIFICACION);
            admon2[i] = numero6; //Se agregan los numeros random al vector.
            administracionMatriz[i][2] = admon2[i]; //Se agrega el vector del tercer parcial a la matriz
            int numero7 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION); //Rango de 0 - 20 puntos
            acti1[i] = numero7; //Se incluyen los numeros random al vector
            administracionMatriz[i][3] = acti1[i]; //Se agrega el vector de actividades a la matriz
        }
    }
}
void facultadArquitectura()
{
    for(int i = 0; i < NUMERO_ALUMNOS; i++)
    {
        for (int x=0; x < 1; x++)
        {
            int numero8 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            arqui[i] = numero8; //Se agrega numeros Random al vector
            arquitecturaMatriz[i][0] = arqui[i]; //Se agrega el vector del primer parcial a la matriz
            int numero9 = busquedaAleatorios1(MIN_CALIFICACION, MAX_2P_CALIFICACION);
            arqui1[i] = numero9; //Se agrega los numeros Random al vector
            arquitecturaMatriz[i][1] = arqui1[i]; //Se agrega el vector del segundo parcial a la matriz
            int numero10 = busquedaAleatorios2(MIN_CALIFICACION, MAX_3P_CALIFICACION);
            arqui2[i] = numero10; //Se agregan los numeros random al vector.
            arquitecturaMatriz[i][2] = arqui2[i]; //Se agrega el vector del tercer parcial a la matriz
            int numero11 = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION); //Rango de 0 - 20 puntos
            acti2[i] = numero11; //Se incluyen los numeros random al vector
            arquitecturaMatriz[i][3] = acti2[i]; //Se agrega el vector de actividades a la matriz
        }
    }
}
void sumaIndividual()
{
        for(int i=0; i<NUMERO_ALUMNOS; i++)
    {
        //Suma de las calificaciones para encontrar la zona
        sumaIngeniera[i] = inge[i] + inge1[i] + inge2[i] + acti[i];

        sumaAdmon[i] = admon[i] + admon1[i] + admon2[i] + acti1[i];
        sumaArquitectura[i] = arqui[i] + arqui1[i] + arqui2[i] + acti2[i];
    }
}
void zona()
{
    sumaIndividual();
    for(int i=0; i < NUMERO_ALUMNOS; i++)
    {
        for(int x=0; x<1; x++)
        {
            ingenieriaMatriz[i][4] = sumaIngeniera[i]; //Se incluye loz valores de zona en la matriz
            administracionMatriz[i][4] = sumaAdmon[i];
            arquitecturaMatriz[i][4] = sumaArquitectura[i];
        }
    }
}
void imprimirLineaMatriz() //Formato de separación de información
{
    //Linea de separación para la matriz
    cout << ("+----------------------");
    for (int x=0; x < NUMERO_ACTIVIDADES + 1; x++)
    {
        cout << "-----------";
    }
    cout<< ("+\n");
}
void imprimirLineaMatriz2() //Formato de separación de información
{
    //Linea separaciones de matrices
    cout << ("+_______________________________");
    for (int x=0; x < NUMERO_ACTIVIDADES + 1; x++)
    {
        cout << "___________";
    }
    cout<< ("+\n");
}
void imprimirMatrizIngenieria(float ingenieriaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tLIGA NACIONAL\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(8) << "ZONA" << setw(5) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << ingenieria[y] << setw(5) << "|" << setw(7);
        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion = ingenieriaMatriz[y][x];
                cout << setw(6) << calificacion << setw(6) << "|"; //Se imprime completamente la matriz
            }
        cout << endl;
        imprimirLineaMatriz();
    }
    generalDeInge();
    imprimirLineaMatriz2();
}
void imprimirMatrizAdmon(float administracionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tFACULTAD DE ADMINISTRACION\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(8) << "ZONA" << setw(5) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << administracion[y] << setw(5) << "|" << setw(7);
        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion1 = administracionMatriz[y][x];
                cout << setw(6) << calificacion1 << setw(6) << "|"; //Se imprime completamente la matriz
            }
        cout << endl;
        imprimirLineaMatriz();
    }
    generalDeAdmon();
    imprimirLineaMatriz2();
}
void imprimirMatrizArquitectura(float arquitecturaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tFACULTAD DE ARQUITECTURA\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(8) << "ZONA" << setw(5) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << arquitectura[y] << setw(5) << "|" << setw(7);
        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion2 = arquitecturaMatriz[y][x];
                cout << setw(6) << calificacion2 << setw(6) << "|"; //Se imprime completamente la matriz
            }
        cout << endl;
        imprimirLineaMatriz();
    }
    generalDeArqui();
    imprimirLineaMatriz2();
}
void promedioGeneralPorFacultad()
{
    float suma=0, suma1=0, suma2=0;
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
    suma += sumaIngeniera[i];
    promedioGeneralInge = suma / NUMERO_ALUMNOS;
    suma1 += sumaAdmon[i];
    promedioGeneralAdmon = suma1 / NUMERO_ALUMNOS;
    suma2 += sumaArquitectura[i];
    promedioGeneralArqui = suma2 / NUMERO_ALUMNOS;
    }
    cout << "\t\tPromedio General liga Nacional: " << fixed << setprecision(2) << promedioGeneralInge << endl;
    cout << "\t\tPromedio General Liga Metropolitana: " << fixed << setprecision(2) << promedioGeneralAdmon << endl;
    cout << "\t\tPromedio General Liga Primera Division: " << fixed << setprecision(2) << promedioGeneralArqui << endl;
}
void generalDeInge()
{
    float mayor, menor;
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, ingenieria[0], MAX_LONGITUD_CADENA);
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMenor, ingenieria[0], MAX_LONGITUD_CADENA);
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if (sumaIngeniera[i] > mayor)
        {
            mayor = sumaIngeniera[i];
            memcpy(alumnoPromedioMayor, ingenieria[i], MAX_LONGITUD_CADENA);
            torneo[0] = mayor;
        }
        if (sumaIngeniera[i] < menor)
        {
            menor = sumaIngeniera[i];
            memcpy(alumnoPromedioMenor, ingenieria[i], MAX_LONGITUD_CADENA);
            torneo2[0] = menor;
        }
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << mayor << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << menor << endl;
}
void generalDeAdmon()
{
    float mayor1, menor1;
    char alumnoPromedioMayor1[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor1, administracion[0], MAX_LONGITUD_CADENA);
    char alumnoPromedioMenor1[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMenor1, administracion[0], MAX_LONGITUD_CADENA);
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if (sumaAdmon[i] > mayor1)
        {
            mayor1 = sumaAdmon[i];
            memcpy(alumnoPromedioMayor1, administracion[i], MAX_LONGITUD_CADENA);
            torneo[1] = mayor1;
        }
        if (sumaAdmon[i] < menor1)
        {
            menor1 = sumaAdmon[i];
            memcpy(alumnoPromedioMenor1, administracion[i], MAX_LONGITUD_CADENA);
            torneo2[1] = menor1;
        }
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor1 << "  con " << mayor1 << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor1 << "  con " << menor1 << endl;
}
void generalDeArqui()
{
    float mayor2, menor2;
    char alumnoPromedioMayor2[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor2, arquitectura[0], MAX_LONGITUD_CADENA);
    char alumnoPromedioMenor2[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMenor2, arquitectura[0], MAX_LONGITUD_CADENA);
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if (sumaArquitectura[i] > mayor2)
        {
            mayor2 = sumaArquitectura[i];
            memcpy(alumnoPromedioMayor2, arquitectura[i], MAX_LONGITUD_CADENA);
            torneo[2] = mayor2;
        }
        if (sumaArquitectura[i] < menor2)
        {
            menor2 = sumaArquitectura[i];
            memcpy(alumnoPromedioMenor2, arquitectura[i], MAX_LONGITUD_CADENA);
            torneo2[2] = menor2;
        }
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor2 << "  con " << mayor2 << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor2 << "  con " << menor2 << endl;
}
void impresionResultadoTorneo()
{
    cout << "\n\t\t------ Liga ganadora según promedio mayor de cada Liga" << endl;
    if (torneo[0] > torneo[1])
    {
        if (torneo[1] > torneo[2])
        {
            cout << "\n\t\tLIGA GANADORA: LIGA NACIOANL con " << torneo[0] << endl;
        }
        else
        {
            cout << "\n\t\tLIGA GANADORA: LIGA PRIMERA DIVISION con " << torneo[2] << endl;
        }
    }
    else
    {
        if (torneo[1] > torneo[2])
        {
            cout << "\n\t\tLIGA GANADORA: LIGA METROPOLITANA con " << torneo[1] << endl;
        }
        else
        {
            cout << "\n\t\tLIGA GANADORA: LIGA PRIMERA DIVISION con " << torneo[2] << endl;
        }
    }
}

