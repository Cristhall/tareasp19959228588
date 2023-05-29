#include "Usuario.h"
#include "Administracion.h"
#include "Empleados.h"
#include "Bitacora.h"
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
Bitacora llamarBitacora;
void Usuario::iniciarSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("nombresUsuarios.txt",ios::in);
	cout<<"\n----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n--------------------------------------------------- Iniciar Sesion - 700 ---------------------------------------------"<<endl;
    cout<<"\n\t\tUsuario: ";
    cin>>nameUsuario;
    cout << "\t\tContrasena: ";
    cin >> codigo;
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(nameUsuario==nombre && codigo == contrasena)
        {
            llamarBitacora.ingresoBitacora(nameUsuario,"700", "LOGIN");
            funcionEmpleados.menuGeneralEmpleados(nameUsuario);
            return;
            found++;
        }
        else
        {
            if (nameUsuario==ADMINISTRADOR && codigo==CONTRAADMON)
            {
                llamarBitacora.ingresoBitacora(nameUsuario,"700", "LOGIN");
                funcionAdmon.menuGeneralSTAFF(nameUsuario);
                return;
                found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        llamarBitacora.ingresoBitacora(nameUsuario,"700", "NO LOGIN");
        cout<<"\n\t\t\t El usuario o contraseña sin incorrectos..." << endl;
        system("pause");
    }
    file.close();
}
void Usuario::menuSecundario()
{
    char x;
    int opcion;
	do
    {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
	cout<<"\t\t\t------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Catalogo Usuarios - 1500 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Insertar Usuario"<<endl;
	cout<<"\t\t\t 2. Modificar Usuario"<<endl;
	cout<<"\t\t\t 3. Buscar Usuario"<<endl;
	cout<<"\t\t\t 4. Desplegar Usuarios"<<endl;
	cout<<"\t\t\t 5. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            do
            {
                llamarBitacora.ingresoBitacora(nameUsuario,"1500", "INS");
                insertar();
                cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
                cin>>x;
            }while(x=='y'||x=='Y');
            break;
        case 2:
            llamarBitacora.ingresoBitacora(nameUsuario,"1500", "UPD");
            modificar();
            break;
        case 3:
            llamarBitacora.ingresoBitacora(nameUsuario,"1500", "SER");
            buscar();
            break;
        case 4:
            llamarBitacora.ingresoBitacora(nameUsuario,"1500", "REA");
            desplegar();
            break;
        case 5:
            llamarBitacora.ingresoBitacora(nameUsuario,"1500", "DEL");
            borrar();
            break;
        case 6:
            return;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=6);
}
void Usuario::insertar()//creamos la funcion que permite crear usuarios
{
	system("cls");
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------- Agregar Nuevo Usuario -----------------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa la contraseña: ";
	cin>>contrasena;
	file.open("nombresUsuarios.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
	file.close();
}
void Usuario::modificar()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
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
    remove("nombresUsuarios.txt");
    rename("Record.txt","nombresUsuarios.txt");
}
void Usuario::desplegar()
{
    system("cls");
	fstream file;
	int total=0;
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
	cout<<"\n-------------------------Tabla de Detalles de Usuarios -------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
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
void Usuario::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
	file.open("nombresUsuarios.txt",ios::in);
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
void Usuario::borrar()//creamos la funcion de borrar para luego se usada en otras funciones
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0;
	cout << "\n\t\t\t Usuario: " << nameUsuario << "\n\n";
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
