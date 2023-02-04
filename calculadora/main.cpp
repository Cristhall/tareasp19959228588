#include <iostream>

using namespace std;

// Universidad Mariano G�lvez de Guatemala
// Ingenier�a en Sistemas de Informaci�n y Ciencias de la Computaci�n
// Cristhall Mishell Rodr�guez Ortiz
// Carn�: 9959 - 22 - 8588
// Simulaci�n de una calculadora
// Se utilizan operaciones b�sicas: suma, resta, multiplicaci�n y divisi�n, con dos valores nada m�s.

int main()
{
    // Se ingresan valores
    int numero1, numero2, opcion, total;
    cout << "Escriba el primer numero: ";
    cin >> numero1;
    cout << "Escriba el segundo numero: ";
    cin >> numero2;

    // Se pide la acci�n que se desea realizar
    cout << " 1 suma" << endl;
    cout << " 2 resta" << endl;
    cout << " 3 multiplicacion" << endl;
    cout << " 4 division" << endl;
    cout << "Escriba una opcion: ";
    cin >> opcion;

    // Operaci�n a realizar dependiendo de la opci�n que se escoge.
        switch (opcion)
        {
            case 1: total = numero1 + numero2;
                break;
            case 2: total = numero1 - numero2;
                break;
            case 3: total = numero1 * numero2;
                break;
            case 4: total = numero1 / numero2;
                break;
            default:
                break;
        }

    // Respuesta de operaci�n
    cout << "El total es: "<<total<<endl;
    system("pause");
    return 0;
}
