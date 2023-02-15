#include<iostream>

using namespace std;
int main()
{
    const int NUMERONOTAS = 5; //Es mejor esta opción porque se puede definir el tipo
    double notas[NUMERONOTAS]; //VECTOR: Indicamos la cantidad de posiciones
    for (int i = 0; i <= NUMERONOTAS; i++ )
    {
        cout << "Ingrese la nota " << i + 1 << " :";
        cin >> notas[i];
    }
    double suma = 0; //Acumlulador
    for (int i = 0; i <= NUMERONOTAS; i++ )
    {
        suma = suma + notas[i];
        cout << "Nota: " << i + 1 << " Calificación: "<< notas[i] << endl;
    }
    double promedioNotas = suma / NUMERONOTAS;

    string letra = " ";
    if (promedioNotas = 100)
    {
        letra = "A";
    }
    else if (promedioNotas >= 80)
    {
        letra = "B";
    }
    else if (promedioNotas >= 70)
    {
        letra = "C";
    }
    else if (promedioNotas >= 60)
    {
        letra = "D";
    }
    else
    {
        letra = "E";
    }
    cout << "Total notas: " << suma << endl;
    cout << "Promedio notas: " << promedioNotas << endl;
    cout << "Por el promedio obtenido usted merce una: " << letra << endl;

    return 0;
}
