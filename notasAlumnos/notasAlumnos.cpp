#include <iostream>
#include <string.h>

using namespace std;

//Ingeniería en Sistemas de Información y Ciencias de la Computación
//LaboratorioP122023
//Programa de gestion de calificaciones de alumnos
//Cristhall Mishell Rodríguez Ortiz
//9959 22 8588

void menuPrincipal();
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
    int i;
    char primero [50], segundo[50],tercero[50],cuarto[50],quinto[50];
    cout << "\tIngrese Nombres y Apellidos del Alumno" << endl;
    cout << "\t1. ";
    cin >> primero;
    cin.getline(primero,50,'\n');
    ingresarNotas();
    cout << "\t2. ";
    cin >> segundo;
    cin.getline(segundo,50,'\n');
    ingresarNotas();
    cout << "\t3. ";
    cin >> tercero;
    cin.getline(tercero,50,'\n');
    ingresarNotas();
    cout << "\t4. ";
    cin >> cuarto;
    cin.getline(cuarto,50,'\n');
    ingresarNotas();
    cout << "\t5. ";
    cin >> quinto;
    cin.getline(quinto,50,'\n');
    ingresarNotas();
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
    cout << "\t\tPromedio Final: " << promedioX << endl;
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


