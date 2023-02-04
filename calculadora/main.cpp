#include <iostream>

using namespace std;

// Universidad Mariano Gálvez de Guatemala
// Ingeniería en Sistemas de Información y Ciencias de la Computación
// Cristhall Mishell Rodríguez Ortiz
// Carné: 9959 - 22 - 8588
// Simulación de una calculadora
// Se utilizan operaciones básicas: suma, resta, multiplicación y división, con dos valores nada más.

int main()
{
    // Se ingresan valores
    int numero1, numero2, opcion, total;
    cout << "Escriba el primer numero: ";
    cin >> numero1;
    cout << "Escriba el segundo numero: ";
    cin >> numero2;

    // Se pide la acción que se desea realizar
    cout << " 1 suma" << endl;
    cout << " 2 resta" << endl;
    cout << " 3 multiplicacion" << endl;
    cout << " 4 division" << endl;
    cout << "Escriba una opcion: ";
    cin >> opcion;

    // Operación a realizar dependiendo de la opción que se escoge.
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

    // Respuesta de operación
    cout << "El total es: "<<total<<endl;
    system("pause");
    return 0;
}
