#include <iostream>

using namespace std;

// Universidad Mariano Gálvez de Guatemala
// Ingeniería en Sistemas de Información y Ciencias de la Computación
// Cristhall Mishell Rodríguez Ortiz
// Carné: 9959 - 22 - 8588
// Simulación de una calculadora con funciones
// Se utilizan operaciones básicas: suma, resta, multiplicación y división, con dos valores nada más.


//Definición de prototipos de función

void titulo (void);
void escribir(void);
void resultado(int total);
void operaciones(int opcion);
void obasicas(void);
int sumar(int numero1, int numero2);
int restar (int numero1, int numero2);
int multiplicacion (int numero1, int numero2);
int division (int numero1, int numero2);

int main()
{
    //Saludos con explicación de lo que se debe hacer
    titulo();

    // Se ingresan valores
    int numero1, numero2, opcion, total;
    escribir();
    cin >> numero1 >> numero2;

    // Se pide la acción que se desea realizar
    obasicas();
    operaciones(opcion);
    cin >> opcion;

    // Operación a realizar dependiendo de la opción que se escoga.
        switch (opcion)
        {
            case 1: total = sumar(numero1, numero2);
                break;
            case 2: total = restar(numero1, numero2);
                break;
            case 3: total = multiplicacion(numero1, numero2);
                break;
            case 4: total = division(numero1, numero2);
                break;
            default:
                break;
        }

    // Respuesta de operación
    resultado(total);
    system("pause");
    return 0;
}

//Implementación de funciones

void titulo(void)
{
    cout << "CALCULADORA CON OPERACIONES BASICAS" << endl;
    return;
}
void escribir(void)
{
    cout << "Escriba dos numeros" << endl;
    return;
}
void resultado(int total)
{
    cout << "El total es: " << total << endl;
    return;
}
void obasicas(void)
{
    cout << "OPCIONES:" << endl;
    cout << " 1 suma" << endl;
    cout << " 2 resta" << endl;
    cout << " 3 multiplicacion" << endl;
    cout << " 4 division" << endl;
    return;
}
void operaciones (int opcion)
{
    cout << "Elija una opcion: " << endl;
}
int sumar(int numero1, int numero2)
{
    return (numero1 + numero2);
}
int restar (int numero1, int numero2)
{
    return (numero1 - numero2);
}
int multiplicacion (int numero1, int numero2)
{
    return (numero1 * numero2);
}
int division (int numero1, int numero2)
{
    return (numero1 / numero2);
}
