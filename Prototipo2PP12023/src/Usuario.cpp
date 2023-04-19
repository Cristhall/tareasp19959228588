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
			}
			else{
                if (nameUsuario == ADMINISTRADOR && codigo == CONTRASENAADMON){
                    found++;
                }
			}
			file >> nombre >> contrasena; //se ordena el archivo
		}
		if(found==0) //si el contador es mayor a 0 es porque no se encuentra el usuario
		{
			cout<<"\n\t\t\t El usuario o contraseña sin incorrectos...";
		}
		file.close(); //se cierra el archivo
}
