#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
using namespace std;
class Usuario
{
	private:
		string nombre, contrasena;
	public:
		void iniciarSesion();
		void iniciarSesionSTAFF();
		void menuSecundario();

};


#endif // USUARIO_H
