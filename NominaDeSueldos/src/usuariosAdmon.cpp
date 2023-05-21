#include "usuariosAdmon.h"
#include "Bitacora.h"
#include "Usuario.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
string nameUsuario, codigo;
Bitacora llamarBitacora5;
void usuariosAdmon::menuAdmon(string n)
{
    nombre2 = n;
    int opcion;
	do
    {
	system("cls");
	cout<<"\t\t\t---------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |          PROGRAMA EMPRESARIAL STAFF - Catalogo usuariosAdmons Administracion - 1500            |"<<endl;
	cout<<"\t\t\t---------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Insertar usuario"<<endl;
	cout<<"\t\t\t 2. Modificar Usuario"<<endl;
	cout<<"\t\t\t 3. Desplegar usuarios"<<endl;
	cout<<"\t\t\t 4. Buscar usuario"<<endl;
	cout<<"\t\t\t 5. Eliminar usuario"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            llamarBitacora5.ingresoBitacora(nombre2,"1500", "INS");
            insertar();
            break;
        case 2:
            llamarBitacora5.ingresoBitacora(nombre2,"1500", "UPD");
            modificar();
            break;
        case 3:
            llamarBitacora5.ingresoBitacora(nombre2,"1500", "REA");
            desplegar();
            break;
        case 4:
            llamarBitacora5.ingresoBitacora(nombre2,"1500", "SEA");
            buscar();
            break;
        case 5:
            llamarBitacora5.ingresoBitacora(nombre2,"1500", "DEL");
            borrar();
            break;
        case 6:
            return;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=3);
}
void usuariosAdmon::insertar()//creamos la funcion que permite crear usuarios
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
    cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
    cin>>nombre;
    cout<<"\t\t\tIngresa la contraseña: ";
    cin>>contrasena;
    file.open("nombresUsuariosAdministracion.txt", ios::app | ios::out);
    file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
    file.close();
}
void usuariosAdmon::modificar()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("nombresUsuariosAdministracion.txt",ios::in);
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
                    cout<<" Ingrese la contrasena: ";
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
    remove("nombresUsuariosAdministracion.txt");
    rename("Record.txt","nombresUsuariosAdministracion.txt");
}
void usuariosAdmon::desplegar()
{
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Usuarios -------------------------"<<endl;
	file.open("nombresUsuariosAdministracion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre: "<<nombre<<endl;
			cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
			file >> nombre >> contrasena;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system("pause");
	file.close();
}
void usuariosAdmon::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("nombresUsuariosAdministracion.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del usuario buscado------------------------"<<endl;
		cout<<"\nIngrese el nombre del usuario que quiere buscar: ";
		cin>>participant_id;
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			if(participant_id==nombre)
			{
				cout<<"\n\n\t\t\t Nombre: "<<nombre<<endl;
				cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
				found++;
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file.close();
	}
}
void usuariosAdmon::borrar()//creamos la funcion de borrar para luego se usada en otras funciones
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0;
	cout<<"\n------------------------- Borrar Cuenta -------------------------"<<endl;
	file.open("nombresUsuariosAdministracion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el usuario para borrar: ";
		cin>>name;
		cout<<" Ingrese la contrasena: ";
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
				cout << "\n\t\t\tBorrado de usuario exitoso";
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("nombresUsuariosAdministracion.txt");//usamos el archivo de texto para eliminar los datos ingresados
		rename("Record.txt","nombresUsuariosAdministracion.txt");
	}
	return;
}


