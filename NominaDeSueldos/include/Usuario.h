#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
using namespace std;
class Usuario
{
	private:
		string nombre, contrasena;
		string nombre2, accion;
		char* date_time;
	public:
		void iniciarSesion();
		void iniciarSesionSTAFF();
		void menuSecundario();
		void insertar();
		void modificar();
		void borrar();
		void cambioScore (int valScore);

};


#endif // USUARIO_H
