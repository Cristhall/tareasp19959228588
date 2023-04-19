#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class Usuario
{
	private:
		string nombre, contrasena; //atributos de la clase usuario
	public:
		void iniciarSesion(); //funcion para iniciar sesion
		void menuCRUD(); //funcion de menu secudario para modificaciones
		void insertar(); // funcion para insertar o crear un usuario
		void menuReportes(); //funcion para modificar al usuario

};


#endif // USUARIO_H
