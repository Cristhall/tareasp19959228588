#ifndef EMPLEADOS_H
#define EMPLEADOS_H
#include <iostream>
using namespace std;

class Empleados
{
    public:
        void menuGeneralEmpleados(string n);
        void infopersonalEmpleados(string n);
        void procesoEmpleados(string n);
        void informesEmpleados(string n);
    private:
        string nombre2, accion, date_time;
};

#endif // EMPLEADOS_H
