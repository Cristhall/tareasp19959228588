#ifndef APLICACIONES_H
#define APLICACIONES_H
#include <iostream>
using namespace std;

class Aplicaciones
{
    private:
		string id,nombre,estado;
		string nombre2;
	public:
		void menu(string n);
		void insertar(string n);
		void desplegar(string n);
		void modificar(string n);
		void buscar(string n);
		void borrar(string n);
};

#endif // APLICACIONES_H
