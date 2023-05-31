#ifndef CALCULOS_H
#define CALCULOS_H
#include <iostream>
using namespace std;

class Calculos
{
    public:
        void calculoSueldo(string i, string n, string p);
        void verPago(int s);

    private:
        int salario, salario2, cHExtras, salarioBase, bonificacion, salarioTotal;
        double igss, isr, irtra, hExtras;
        string id, nombre, puesto, puesto2, fecha;
};

#endif // CALCULOS_H
