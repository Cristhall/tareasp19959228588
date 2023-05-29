#ifndef CALCULOS_H
#define CALCULOS_H
#include <iostream>
using namespace std;

class Calculos
{
    public:
        void verPago(string id, string nombre, int n);

    private:
        int salario;
        double igss, isr, irtra, hExtras, salariototal;
        int bono;
        string id, nombre;
};

#endif // CALCULOS_H
