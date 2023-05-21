#ifndef CONFIEMPLEADOS_H
#define CONFIEMPLEADOS_H
#include <iostream>
using namespace std;

class ConfiEmpleados
{
    private:
		string id,nombre,telefono,direccion,puesto;
		int sueldo;
	public:
		void menu(string n);
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // CONFIEMPLEADOS_H
