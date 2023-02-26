//En este programa se crean tres matrices de tres facultades, estas competiran para ver que facultad tiene el promedio mayor.
//Califiaciones: primer, segundo y tercer parcial, actividades, zona, por facultad alumno con promedio mayor y un promedio general uniendo las tres facultades.
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
const int NUMERO_ALUMNOS = 10;
const int NUMERO_ACTIVIDADES = 5;
const int MAX_1P_CALIFICACION = 20;
const int MIN_CALIFICACION = 0;
const int MAX_2P_CALIFICACION = 25;
const int MAX_3P_CALIFICACION = 35;
const int NUMERO_FACULTADES = 3;

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
void impresionResultadosTorneo();
void promedioMayorIngenieria();
void promedioMayorAdmon();
void promedioMayorArquitectura();
void promedioGeneralPorFacultad();
void promedioGeneralUniversidad();

// Vectores y Matrices
string ingenieria[NUMERO_ALUMNOS] = {"JOSELINE_ORTIZ","DANIELA_HERNÁNDEZ","KARMEN_AGUILAR","DANIEL_GARCIA","MARIA_MORALES","JOSE_ORELLANA","LUIS_SALGUERO","ERWIN_LUZ","CARLOS_FUENTES","ADAN_CORTEZ"};
string administracion[NUMERO_ALUMNOS] = {"MIGUEL_CASTILLO","ANGEL_CHACON","PABLO_PAZ","SOFIA_MELGAR","MISHELL_MAYEN","LESLI_ARIAS","ESTER_LOPEZ","JIMENA_CARDENAS","ROSA_MORALES","LUCIA_SOLIS"};
string arquitectura[NUMERO_ALUMNOS] = {"MARTA_LOPEZ","YEIDEN_ALVARADO","KEIDEN_ALVARADO","DIEGO_CASTILLO","HEBER_DUBON","JULIA_CHUN","EVA_DIAZ","JOSUE_PÉREZ","PABLO_MANSILLA","LINDA_FLORES"};
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
int sumaArquitectura[NUMERO_ALUMNOS];
float ingenieriaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];  //Matriz de 11 x 6
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
        cout << "\n\n\t\t\tTORNEO UMG" << endl;
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
                cout << "\t\tAlUMNO CON PROMEDIO MAYOR POR FACULTAD: " << endl << endl;
                promedioMayorIngenieria();
                promedioMayorAdmon();
                promedioMayorArquitectura();
                cout << endl;
                cout << "\n\t\tPROMEDIO GENERAL POR FACULTAD: " << endl << endl;
                promedioGeneralPorFacultad();
                promedioGeneralUniversidad();
                impresionResultadosTorneo();
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
    cout << ("+_______________________");
    for (int x=0; x < NUMERO_ACTIVIDADES + 1; x++)
    {
        cout << "___________";
    }
    cout<< ("+\n");
}
void imprimirMatrizIngenieria(float ingenieriaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tFACULTAD DE INGENIERIA\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "ALUMNO" << setw(10) << "|" << setw(5);

    for (int x=0; x < 3; x++)
    {
        cout << "P" << setw(2) << x + 1 << setw(5) << "|" << setw(5);
    }
    cout << setw(7) << "ACT" << setw(5) <<"|";
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
    imprimirLineaMatriz2();
}
void imprimirMatrizAdmon(float administracionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tFACULTAD DE ADMINISTRACION\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "ALUMNO" << setw(10) << "|" << setw(5);

    for (int x=0; x < 3; x++)
    {
        cout << "P" << setw(2) << x + 1 << setw(5) << "|" << setw(5);
    }
    cout << setw(7) << "ACT" << setw(5) <<"|";
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
    imprimirLineaMatriz2();
}
void imprimirMatrizArquitectura(float arquitecturaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    cout << endl << "\t\t\t\tFACULTAD DE ARQUITECTURA\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "ALUMNO" << setw(10) << "|" << setw(5);

    for (int x=0; x < 3; x++)
    {
        cout << "P" << setw(2) << x + 1 << setw(5) << "|" << setw(5);
    }
    cout << setw(7) << "ACT" << setw(5) <<"|";
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
    imprimirLineaMatriz2();
}
void promedioMayorIngenieria()
{
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if(sumaIngeniera[i] > mayor)
        {
            mayor = sumaIngeniera[i];
        }
    }
    cout << "\t\tPromedio mayor de Ingenieria: " << fixed << setprecision(2) << mayor << endl;
}
void promedioMayorAdmon()
{
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if(sumaAdmon[i] > mayor1)
        {
            mayor1 = sumaAdmon[i];
        }
    }
    cout << "\t\tPromedio mayor de Administración: " << fixed << setprecision(2) << mayor1 << endl;
}
void promedioMayorArquitectura()
{
    for (int i=0; i<NUMERO_ALUMNOS; i++)
    {
        if(sumaArquitectura[i] > mayor2)
        {
            mayor2 = sumaArquitectura[i];
        }
    }
    cout << "\t\tPromedio mayor de Arquitectura: " << fixed << setprecision(2) << mayor2 << endl;
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
    cout << "\t\tPromedio General Facultad Ingenieria: " << fixed << setprecision(2) << promedioGeneralInge << endl;
    cout << "\t\tPromedio General Facultad Administración: " << fixed << setprecision(2) << promedioGeneralAdmon << endl;
    cout << "\t\tPromedio General Facultad Arquitectura: " << fixed << setprecision(2) << promedioGeneralArqui << endl;
}
void impresionResultadosTorneo()
{
    if (promedioGeneralInge > promedioGeneralAdmon && promedioGeneralArqui)
    {
        cout << "\n\t\tLa facultad ganadora es: INGENIERIA con " << mayor << endl;
    }
    else if (promedioGeneralAdmon > promedioGeneralInge && promedioGeneralArqui)
    {
        cout << "\n\t\tLa facultad ganadora es: ADMINISTRACION con " << mayor1 << endl;
    }
    else if (promedioGeneralArqui > promedioGeneralInge && promedioGeneralAdmon)
    {
        cout << "\n\t\tLa facultad ganadora es: ARQUITECTURA con " << mayor2 << endl;
    }
}
void promedioGeneralUniversidad()
{
    int promedioUniversidad = (promedioGeneralInge + promedioGeneralAdmon + promedioGeneralArqui) / 3;
    cout << "\n\t\tEl promedio general de la universidad es de: " << fixed << setprecision(2) << promedioUniversidad << endl;
}

//Lectura de un vector:
//int limite = (sizeof(edades)/sizeof(edades[0]));
//for (int i = 0; i < limite; i++)
//cout<<edades[i]<<endl;

