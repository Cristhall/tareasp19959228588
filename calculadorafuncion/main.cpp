#include <iostream>

using namespace std;

// Universidad Mariano G�lvez de Guatemala
// Ingenier�a en Sistemas de Informaci�n y Ciencias de la Computaci�n
// Cristhall Mishell Rodr�guez Ortiz
// Carn�: 9959 - 22 - 8588
// Simulaci�n de una calculadora con funciones
// Se utilizan operaciones b�sicas: suma, resta, multiplicaci�n y divisi�n, con dos valores nada m�s.


//Definici�n de prototipos de funci�n

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
    //Saludos con explicaci�n de lo que se debe hacer
    titulo();

    // Se ingresan valores
    int numero1, numero2, opcion, total;
    escribir();
    cin >> numero1 >> numero2;

    // Se pide la acci�n que se desea realizar
    obasicas();
    operaciones(opcion);
    cin >> opcion;

    // Operaci�n a realizar dependiendo de la opci�n que se escoga.
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

    // Respuesta de operaci�n
    resultado(total);
    system("pause");
    return 0;
}

//Implementaci�n de funciones

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
