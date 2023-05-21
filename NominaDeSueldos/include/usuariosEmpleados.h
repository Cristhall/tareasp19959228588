#ifndef USUARIOSEMPLEADOS_H
#define USUARIOSEMPLEADOS_H
#include <iostream>
using namespace std;

class usuariosEmpleados
{
    public:
        void menuEmpleados(string n);
		void insertar();
		void modificar();
		void buscar();
		void desplegar();
		void borrar();
    private:
        string nombre, contrasena;
        string nombre2;
};

#endif // USUARIOSEMPLEADOS_H
