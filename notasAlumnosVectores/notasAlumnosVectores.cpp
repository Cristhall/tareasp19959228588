#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

//Ingeniería en Sistemas de Información y Ciencias de la Computación
//LaboratorioP122023
//Programa de gestion de calificaciones de alumnos
//Cristhall Mishell Rodríguez Ortiz
//9959 22 8588
//Notas alumnos con variables

void menuPrincipal();
void ingresoMaterias();
void ingresarNombres();
void ingresarNotas();
int main()
{

    menuPrincipal();
    return 0;
}

// Implementación de Funciones
void menuPrincipal()
{
    system("cls");
    int opciones;
    bool repetir = true;
    do
    {
        cout << "\tMENÚ PRICIPAL" << endl << endl;
        cout << "\tBIENVENIDO" << endl << endl;
        cout << "\t1. Ingresar Nombres y calificaciones" << endl;
        cout << "\t2. SALIR" << endl;
        cin >> opciones;
        switch (opciones)
        {
            case 1: ingresarNombres();
                break;
            case 2: repetir = false;
                break;
        }
    }while (repetir);
    system ("pause>nul");
}
void ingresarNombres()
{
    system("cls");
    const int CANTIDADNOMBRES = 5;
    const int APELLIDOS = 5;
    string nombres[CANTIDADNOMBRES];
    string ape[APELLIDOS];
    // Solicitar notas
    for (int i = 0; i <=CANTIDADNOMBRES; i++)
    {
        cout << "-----------------------------------" << endl;
        cout << setw(20) << "ALUMNO\n\n";
        cout << "\t" << i + 1 << ". Nombre: ";
        cin >> nombres[i];
        for (int j=0; j<=APELLIDOS; j++)
        {
            cout << "\n" << setw(21) << "Apellido: ";
            cin >> ape[j];
            break;
        }
        cout << "\n";
        ingresarNotas();
    }
    system ("pause>nul");
}
void ingresarNotas()
{
    const int cantidadNotas = 5;
    double notas[cantidadNotas], promedioFinal, promedioX;
    // Solicitar notas
    for (int i = 0; i < cantidadNotas; i++)
    {
        cout << "\tIngrese la nota del " << i + 1 << " curso: ";
        // Guardar en el arreglo
        cin >> notas[i];
        promedioFinal = promedioFinal + notas[i];
        promedioX = promedioFinal / 5;
    }
    cout << "\n\t\tPromedio Final: " << promedioX << endl;
    if (promedioX >= 60)
    {
        cout << "\t\tAPROBADO" << endl;
    }
    else
    {
        cout << "\t\tREPROBADO" << endl;
    }
    system ("pause>nul");
}


