//Creador: Cristhall Msihell Rodríguez Ortiz
//Carné: 9959 22 8588
//Carrera: Ingeniería en Sistemas de Información y Ciencias de la Computación

#include <iostream>
#include "Usuario.h"

using namespace std;

int main()
{
    Usuario ingresoUsuario;
    int opcion; //variables opcion para el menu de ingreso de login
	do //inicio de ciclo do while para trabajar con el menu
    {
	system("cls");
	//impresion de formato con las opciones
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |      INGRESO DE SESION     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Iniciar Sesion"<<endl;
	cout<<"\t\t\t 2. Crear cuenta"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion; //se almacena la respuesta

    switch(opcion) //inicio para saber que hacer segun la respuesta ingresada.
    {
	case 1:
		ingresoUsuario.iniciarSesion(); //si es 1 se llama con el objeto de la clase usuario a la funcion de iniciar sesion.
		break;
	case 2:
		ingresoUsuario.insertar(); //si es 2 se llama con el objeto de la clase usuario a la funcion de insertar o crear un usuario.
		break;
	case 3:
		exit(0); //se termina el programa
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; //indica que la opcion ingresada es invalida
	}
	getch(); //pausa
    }while(opcion!=3); //fin del ciclo do while
    return 0;
}
