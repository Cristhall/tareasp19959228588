#include "competencia.h"

//Variables
float promedioGeneral1 = 0, promedioGeneral2 = 0, promedioGeneral3 = 0;

// Vectores y Matrices
char nacional[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"GUATEMALA", "ESCUINTLA", "PETEN", "ALTA_VERAPAZ","IZABAL"};
char metropolitana[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"LEONES", "CELTICS", "LAKERS", "NETS", "AGUILAS"};
char primeraDivision[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"RAPTORS", "ALEGRIA", "AZUCAREROS", "CHUSITOS", "CASITAS"};
int ligaMetropolitana[NUMERO_ALUMNOS]; //promedios primera liga
int ligaNacional[NUMERO_ALUMNOS]; // promedios segunda liga
int ligaPrimeraDivision[NUMERO_ALUMNOS]; // promedios tercera liga
float nacionalMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];  //Matriz de 6 x 6
float metropolitanaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];
float primeraDivisionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1];

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
                ligas();
                imprimirMatriz1(nacionalMatriz);
                imprimirMatriz2(metropolitanaMatriz);
                imprimirMatriz3(primeraDivisionMatriz);
                cout << endl;
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
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + (rand()%(MAX_1P_CALIFICACION - MIN_CALIFICACION)); //Rango de 0 - 50 puntos
}
void ligas()
{
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        float ligaNacional = 0;
        float ligaMetropolitana = 0;
        float ligaPrimeraDivision = 0;
        for ( int x=0; x < NUMERO_ACTIVIDADES; x++)
        {
            int calificacionNacional = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            ligaNacional += (float)calificacionNacional;
            nacionalMatriz[y][x] = calificacionNacional;

            int calificacionMetro = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            ligaMetropolitana += (float)calificacionMetro;
            metropolitanaMatriz[y][x] = calificacionMetro;

            int calificacionPrimera = busquedaAleatorios(MIN_CALIFICACION, MAX_1P_CALIFICACION);
            ligaPrimeraDivision += (float)calificacionPrimera;
            primeraDivisionMatriz[y][x] = calificacionPrimera;
        }
        float promedioNotasNacional = ligaNacional / NUMERO_ACTIVIDADES;
        nacionalMatriz[y][NUMERO_ACTIVIDADES]=promedioNotasNacional;

        float promedioNotasMetro = ligaMetropolitana / NUMERO_ACTIVIDADES;
        metropolitanaMatriz[y][NUMERO_ACTIVIDADES]=promedioNotasMetro;

        float promedioNotasPrimera = ligaPrimeraDivision / NUMERO_ACTIVIDADES;
        primeraDivisionMatriz[y][NUMERO_ACTIVIDADES]=promedioNotasPrimera;
    }
}
void imprimirLineaMatriz() //Formato de separación de información
{
    //Linea de separación para la matriz
    cout << ("+---------------------------------");
    for (int x=0; x < NUMERO_ACTIVIDADES + 1; x++)
    {
        cout << "------------";
    }
    cout<< ("+\n");
}
void imprimirLineaMatriz2() //Formato de separación de información
{
    //Linea separaciones de matrices
    cout << ("+_________________________________");
    for (int x=0; x < NUMERO_ACTIVIDADES + 1; x++)
    {
        cout << "____________";
    }
    cout<< ("+\n");
}
void imprimirMatriz1(float nacionalMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    float totalGeneral = 0;
    float promedioMayor = nacionalMatriz[0][NUMERO_ACTIVIDADES];
    float promedioMenor = nacionalMatriz[0][NUMERO_ACTIVIDADES];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, nacional[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, nacional[0], MAX_LONGITUD_CADENA);
    cout << endl << "\t\t\t\tLIGA NACIONAL\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(10) << "ZONA" << setw(8) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << nacional[y] << setw(5) << "|" << setw(5);

        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion = nacionalMatriz[y][x];
                cout << setw(6) << calificacion << setw(6) << "|";

            }
        float promedio = nacionalMatriz[y][NUMERO_ACTIVIDADES]; //DUDOSA
        totalGeneral += nacionalMatriz[y][NUMERO_ACTIVIDADES];
        promedioGeneral1 = totalGeneral / NUMERO_ALUMNOS;
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, nacional[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, nacional[y], MAX_LONGITUD_CADENA);
        }
        cout << setw(13) << fixed << setprecision(2) << promedio << setw(5) << "!\n";

        imprimirLineaMatriz();
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << setw(7) << promedioMayor << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << setw(7) << promedioMenor << endl;
    cout << "\n\t\tPromedio General Liga Nacional: " << fixed << setprecision(2) << promedioGeneral1 << endl;
    imprimirLineaMatriz2();
}
void imprimirMatriz2(float metropolitanaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    float totalGeneral = 0;
    float promedioMayor = metropolitanaMatriz[0][NUMERO_ACTIVIDADES];
    float promedioMenor = metropolitanaMatriz[0][NUMERO_ACTIVIDADES];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, metropolitana[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, metropolitana[0], MAX_LONGITUD_CADENA);
    cout << endl << "\t\t\t\tLIGA METROPOLITANA\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(10) << "ZONA" << setw(8) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << metropolitana[y] << setw(5) << "|" << setw(5);

        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion = metropolitanaMatriz[y][x];
                cout << setw(6) << calificacion << setw(6) << "|";

            }
        float promedio = metropolitanaMatriz[y][NUMERO_ACTIVIDADES]; //DUDOSA
        totalGeneral += metropolitanaMatriz[y][NUMERO_ACTIVIDADES];
        promedioGeneral2 = totalGeneral / NUMERO_ALUMNOS;
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, metropolitana[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, metropolitana[y], MAX_LONGITUD_CADENA);
        }
        cout << setw(13) << fixed << setprecision(2) << promedio << setw(5) << "!\n";

        imprimirLineaMatriz();
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << setw(7) << promedioMayor << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << setw(7) << promedioMenor << endl;
    cout << "\n\t\tPromedio General Liga Metropolitana: " << fixed << setprecision(2) << promedioGeneral2 << endl;
    imprimirLineaMatriz2();
}
void imprimirMatriz3(float primeraDivisionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1])
{
    float totalGeneral = 0;
    float promedioMayor = primeraDivisionMatriz[0][NUMERO_ACTIVIDADES];
    float promedioMenor = primeraDivisionMatriz[0][NUMERO_ACTIVIDADES];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, primeraDivision[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, primeraDivision[0], MAX_LONGITUD_CADENA);
    cout << endl << "\t\t\t\tLIGA PRIMERA DIVISION\n" << endl;
    imprimirLineaMatriz();
    cout << setw(20) << "EQUIPO" << setw(10) << "|" << setw(5);

    cout << setw(7) << "2010" << setw(5) <<"|";
    cout << setw(7) << "2011" << setw(5) <<"|";
    cout << setw(7) << "2012" << setw(5) <<"|";
    cout << setw(7) << "2014" << setw(5) <<"|";
    cout << setw(10) << "ZONA" << setw(8) <<"|\n";

    imprimirLineaMatriz();
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        cout << setw(25) << primeraDivision[y] << setw(5) << "|" << setw(5);

        for (int x=0;x < NUMERO_ACTIVIDADES; x++)
            {
                int calificacion = primeraDivisionMatriz[y][x];
                cout << setw(6) << calificacion << setw(6) << "|";

            }
        float promedio = primeraDivisionMatriz[y][NUMERO_ACTIVIDADES]; //DUDOSA
        totalGeneral += primeraDivisionMatriz[y][NUMERO_ACTIVIDADES];
        promedioGeneral3 = totalGeneral / NUMERO_ALUMNOS;
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, primeraDivision[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, primeraDivision[y], MAX_LONGITUD_CADENA);
        }
        cout << setw(13) << fixed << setprecision(2) << promedio << setw(5) << "!\n";

        imprimirLineaMatriz();
    }
    cout << "\n\t\tPromedio mayor: " << setw(9) << alumnoPromedioMayor << "  con " << setw(7) << promedioMayor << endl;
    cout << "\n\t\tPromedio menor: " << setw(9) << alumnoPromedioMenor << "  con " << setw(7) << promedioMenor << endl;
    cout << "\n\t\tPromedio General Liga Primera Division: " << fixed << setprecision(2) << promedioGeneral3 << endl;
    imprimirLineaMatriz2();
}
void impresionResultadoTorneo()
{
    cout << "\n\t\t------ Liga ganadora según promedio general de cada liga" << endl;
    if (promedioGeneral1 > promedioGeneral2 && promedioGeneral1 > promedioGeneral3)
    {
        cout << "\n\t\tLa liga ganadora es: LIGA NACIONAL con: " << fixed << setprecision(2) << promedioGeneral1 << endl;
    }
    else if (promedioGeneral2 > promedioGeneral1 && promedioGeneral2 > promedioGeneral3)
    {
        cout << "\n\t\tLa liga ganadora es: LIGA METROPOLITANA con: " << fixed << setprecision(2) << promedioGeneral2 << endl;
    }
    else if (promedioGeneral3 > promedioGeneral1 && promedioGeneral3 > promedioGeneral2)
    {
        cout << "\n\t\tLa liga ganadora es: LIGA PRIMERA DIVISION con: " << fixed << setprecision(2) << promedioGeneral3 << endl;
    }
    else
    {
        cout << "\n\t\tExisten ligas con el mismo promedio" << endl;
    }
}
