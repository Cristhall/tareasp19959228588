#ifndef USUARIOSADMON_H
#define USUARIOSADMON_H
#include <iostream>
using namespace std;

class usuariosAdmon
{
    public:
        void menuAdmon(string n);
		void insertar();
		void modificar();
		void buscar();
		void desplegar();
		void borrar();

    private:
        string nombre, contrasena;
        string nombre2;
};

#endif // USUARIOSADMON_H
