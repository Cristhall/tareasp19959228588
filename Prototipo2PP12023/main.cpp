//Creador: Cristhall Msihell Rodríguez Ortiz
//Carné: 9959 22 8588
//Carrera: Ingeniería en Sistemas de Información y Ciencias de la Computación

#include <iostream>
#include "Usuario.h"

using namespace std;

int main()
{
    Usuario ingresoUsuario;
    int opcion;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |      INGRESO DE SESION     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Administrador"<<endl;
	cout<<"\t\t\t 2. Empleados"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
	case 1:
		ingresoUsuario.admon();
		break;
	case 2:
		ingresoUsuario.trabajador();
		break;
	case 3:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(opcion!=3);
    return 0;
}
