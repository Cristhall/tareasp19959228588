#include "Usuario.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <string>
using namespace std;
#define ADMINISTRADOR 'cristhall'
#define CONTRASENAADMON 1234

void Usuario::insertar() //funcion para crear usuario
{
	system("cls");
	fstream file; //libreria para trabajar con un archivo
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: "; //se solicita el usuario
	cin>>nombre;
	cout<<"\t\t\tIngresa la contraseña: "; //se solicita la contraseña
	cin>>contrasena;
	file.open("nombresUsuarios.txt", ios::app | ios::out); //se abre o crea el archivo
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena << "\n"; //se guarda informacion en el archivo
	file.close(); //se cierra el archivo
}
void Usuario::iniciarSesion() //funcion para iniciar sesion
{
    system("cls"); //limpia la pantalla
	fstream file; //libreria para trabajar con un archivo
	string codigo;
	string nameUsuario;
	int found=0; //contador y varible opcion para respuesta
	file.open("nombresUsuarios.txt",ios::in); //se abre el archivo
		cout<<"\n----------------------------------------------------------------------------------------------------------------";
        cout<<"\n--------------------------------------------------- Iniciar Sesion ---------------------------------------------"<<endl;
		cout<<"\n\t\tUsuario: "; //solicita usuario
		cin>>nameUsuario;
		cout << "\t\tContraseña: "; //solicita contraseña
		cin >> codigo;
		file >> nombre >> contrasena; //indica el orden del archivo
		while(!file.eof()) //ciclo que permite buscar al usuario
		{
			if(nameUsuario == nombre && codigo == contrasena) //condicional que dice que el usuario y la contraseña deben ser el mismo
			{
				found++; //si el nombre o usuario no son correctos el contador aumenta
				menuGeneral();
			}
			file >> nombre >> contrasena; //se ordena el archivo
		}
		if(found==0) //si el contador es mayor a 0 es porque no se encuentra el usuario
		{
			cout<<"\n\t\t\t El usuario o contraseña sin incorrectos...";
		}
		file.close(); //se cierra el archivo
}
void Usuario::menuGeneral()
{
    int opcion;
    do{
        system("cls"); //se limpia la pantalla
        cout<<"\n----------------------------------------------------------------------------------------------------";
        cout<<"\n---------------------------------------------- BIENVENIDO ------------------------------------------"<<endl;
        cout << "\n\n\t\tUsuario: " << nombre << endl << endl; //imprime el nombre dle usuario que esta jugando
        //opciones para realizar determinada accion
        cout << "\t\t1. Catálogos" << endl;
        cout << "\t\t2. Informes" << endl;
        cout << "\t\t3. Cerrar Sesion" << endl;
        cout<<"\t\t-------------------------------"<<endl;
        cout << "\t\tIngrese una opción: "; //se solicita la opcion
        cin >> opcion; //se guarda la opcion
            switch(opcion) //inicio de cilo swith para las acciones a tomar dependiendo de la opcion ingresada
            {
                case 1:
                    menuCRUD();
                    break;
                case 2:
                    menuReportes();
                    break;
                case 3:
                    return; //regresa al menu de inicio de sesion
                default:
                    cout << "\n\t\tOpcion inválida" << endl; //mensaje si la opcion ingresada no se encuentra
                    system("pause");
                    break;
            }
        }while(opcion!=3); //fin del ciclo hasta que seleccione la opcion de salir
}
void Usuario::menuCRUD()
{
    int opcion;
    do{
        system("cls"); //se limpia la pantalla
        cout<<"\n---------------------------------------------------------------------------------------------------";
        cout<<"\n---------------------------------------------- CATÁLOGOS ------------------------------------------"<<endl;
        cout << "\n\n\t\tUsuario: " << nombre << endl << endl; //imprime el nombre dle usuario que esta jugando
        //opciones para realizar determinada accion
        cout << "\t\t1. Altas" << endl;
        cout << "\t\t2. Bajas" << endl;
        cout << "\t\t3. Modificacion" << endl;
        cout << "\t\t4. Consulta" << endl;
        cout << "\t\t5. Regresar a menú" << endl;
        cout<<"\t\t-------------------------------"<<endl;
        cout << "\t\tIngrese una opción: "; //se solicita la opcion
        cin >> opcion; //se guarda la opcion
            switch(opcion) //inicio de cilo swith para las acciones a tomar dependiendo de la opcion ingresada
            {
                case 1:
                    altas();
                    break;
                case 2:
                    bajas();
                    break;
                case 3:
                    modificacion();
                    break;
                case 4:
                    consultas();
                    break;
                case 5:
                    return; //regresa al menu de inicio de sesion
                default:
                    cout << "\n\t\tOpcion inválida" << endl; //mensaje si la opcion ingresada no se encuentra
                    system("pause");
                    break;
            }
        }while(opcion!=5); //fin del ciclo hasta que seleccione la opcion de salir
}
void Usuario::menuReportes()
{

}
void Usuario::altas()
{

}
void Usuario::bajas()
{

}
void Usuario::modificacion()
{

}
void Usuario::consultas()
{

}
