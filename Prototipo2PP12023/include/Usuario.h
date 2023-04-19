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
		string nombre, contrasena, fecha, direccion, telefono; //atributos de la clase usuario
	public:
		void iniciarSesion(); //funcion para iniciar sesion
		void menuCRUD();
		void insertar(); //funcion para ingresar usuario
		void menuReportes();
		void menuGeneral();
		void altas();
		void bajas();
		void modificacion();
		void consultas();
};


#endif // USUARIO_H
