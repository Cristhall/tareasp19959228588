#ifndef INFOEMPLEADOS_H
#define INFOEMPLEADOS_H
#include <iostream>
using namespace std;

class InfoEmpleados
{
    private:
		string id,nombre,telefono,direccion,puesto,sueldo;
		string nombre2;
	public:
		void menu(string n);
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};

#endif // INFOEMPLEADOS_H
