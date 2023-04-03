#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class persona
{
	private:
		string id,name,phone,college,address;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
};


#endif // FUNCIONES_H
