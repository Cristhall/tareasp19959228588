#ifndef COMPETENCIA_H
#define COMPETENCIA_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <string.h>

using namespace std;

// Constantes
const int NUMERO_ALUMNOS = 5;
const int NUMERO_ACTIVIDADES = 4;
const int MAX_1P_CALIFICACION = 50;
const int MIN_CALIFICACION = 0;
const int MAX_LONGITUD_CADENA = 150;

// Funciones
void menuPrincipal();
void ligas();
int busquedaAleatorios(int minimo, int maximo);
void imprimirLineaMatriz();
void imprimirLineaMatriz2();
void imprimirMatriz1(float nacionalMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void imprimirMatriz2(float metropolitanaMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void imprimirMatriz3(float primeraDivisionMatriz[NUMERO_ALUMNOS+1][NUMERO_ACTIVIDADES+1]);
void impresionResultadoTorneo();

#endif // COMPETENCIA_H
