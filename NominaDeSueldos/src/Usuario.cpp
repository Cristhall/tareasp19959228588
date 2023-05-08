#include "Usuario.h"
#include "Administracion.h"
#include "Empleados.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <ctime>

using namespace std;
#define ADMINISTRADOR "administrador"
#define CONTRAADMON "1234"
string nameUsuario, codigo;
Administracion funcionAdmon;
Empleados funcionEmpleados;
void Usuario::iniciarSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("nombresUsuarios.txt",ios::in);
	file1.open("Bitacora.txt", ios::app | ios::out);
	cout<<"\n----------------------------------------------------------------------------------------------------------------";
    cout<<"\n--------------------------------------------------- Iniciar Sesion ---------------------------------------------"<<endl;
    cout<<"\n\t\tUsuario: ";
    cin>>nameUsuario;
    cout << "\t\tContrasena: ";
    cin >> codigo;
    file >> nombre >> contrasena;
    nombre2 = nameUsuario;
    time_t now = time(0);
    date_time = ctime(&now);
    if(nameUsuario==nombre && codigo == contrasena)
        {
            accion = "LOGIN";
            file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
            file1.close();
            funcionEmpleados.menuGeneralEmpleados(nombre2);
            return;
            found++;
        }
    else
    {
        if (nameUsuario==ADMINISTRADOR && codigo==CONTRAADMON)
        {
            accion = "LOGIN";
            file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
            file1.close();
            funcionAdmon.menuGeneralSTAFF(nameUsuario);
            return;
            found++;
        }
    }
    file >> nombre >> contrasena;
    if(found==0)
    {
        accion = "NO LOGIN";
        file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
        file1.close();
        cout<<"\n\t\t\t El usuario o contraseña sin incorrectos..." << endl;
        system("pause");
    }
    file.close();
}
void Usuario::insertar()//creamos la funcion que permite crear usuarios
{
	system("cls");
	fstream file, file1;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa la contraseña: ";
	cin>>contrasena;
	file.open("nombresUsuarios.txt", ios::app | ios::out);
	file1.open("Bitacora.txt", ios::app);
	nombre2 = nameUsuario;
	accion = "Ins";
	time_t now = time(0);
    date_time = ctime(&now);
	file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
	file1.close();
	file.close();
}
void Usuario::menuSecundario()
{
    int opcion;
	do
    {
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Modificacion de Usuario ----------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Cambiar usuario o contrase�a"<<endl;
	cout<<"\t\t\t 2. Borrar cuenta"<<endl;
	cout<<"\t\t\t 3. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            modificar();
            break;
        case 2:
            borrar();
            break;
        case 3:
            return;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=3);
}
void Usuario::modificar()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name;
    cout<<" Ingrese la contraseña: ";
    cin>>c2;
    file1.open("Record.txt",ios::app | ios::out);
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(name!=nombre && c2!=contrasena){
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
        }
        else{
            cout << "\n\tQue desea modificar?" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contraseña" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese su nombre de usuario: ";
                cin>>nombre;
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
                nameUsuario = nombre;
                found++;
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contrase�a: ";
                    cin>>contrasena;
                    codigo = contrasena;
                }
            file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
            found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close();
    file.close();
    remove("nombresUsuarios.txt");
    rename("Record.txt","nombresUsuarios.txt");
}
void Usuario::borrar()//creamos la funcion de borrar para luego se usada en otras funciones
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0;
	cout<<"\n------------------------- Borrar Cuenta -------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el usuario para borrar: ";
		cin>>name;
		cout<<" Ingrese la contrase�a: ";
		cin>>c2;
		file1.open("Record.txt",ios::app | ios::out);//abrimos archivo a utilizar
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			if(name!= nombre && c2 != contrasena)
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
			}//se imprimen los datos en el log del usuario
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de Usuario exitoso";
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("nombresUsuarios.txt");//usamos el archivo de texto para eliminar los datos ingresados
		rename("Record.txt","nombresUsuarios.txt");
		exit(0);
	}
}
