#ifndef PLANILLA_H
#define PLANILLA_H
#include <iostream>
using namespace std;

class Planilla
{
    public:
        void leerPlanilla(string n);
        void buscarPlanilla(string n);
        void imprimirPlanilla(string n);
        void leerBitacoraPagos(string n);

    private:
        int salario, bonificacion, hTrabajadas;
        double montoHTr, igss, isr, salarioTotal;
        string id, nombre, nombre2, fecha;
};

#endif // PLANILLA_H
