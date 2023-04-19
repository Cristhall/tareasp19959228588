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
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Nombre: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa contraseña: ";
	cin>>contrasena;
	cout<<"\t\t\tIngresa fecha de nacimiento (sin espacios): ";
	cin>>fecha;
	cout<<"\t\t\tIngresa direccion: ";
	cin>>direccion;
	cout<<"\t\t\tIngresa telefono: ";
	cin>>telefono;
	file.open("nombresUsuarios.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< telefono << "\n";
	file.close();
}
void Usuario::iniciarSesion() //funcion para iniciar sesion
{
    system("cls"); //limpia la pantalla
	fstream file; //libreria para trabajar con un archivo
	string codigo;
	string nameUsuario;
	int found=0; //contador y varible opcion para respuesta
	file.open("nombresUsuarios.txt",ios::in); //se abre el archivo
	if(!file)
	{
		cout<<"\n\t\t\tNo hay ningun usuario registrado...";
		file.close();
	}
    else{
		cout<<"\n----------------------------------------------------------------------------------------------------------------";
        cout<<"\n--------------------------------------------------- Iniciar Sesion ---------------------------------------------"<<endl;
		cout<<"\n\t\tUsuario: "; //solicita usuario
		cin>>nameUsuario;
		cout << "\t\tContraseña: "; //solicita contraseña
		cin >> codigo;
		file >> nombre >> contrasena >> fecha >> direccion >> telefono; //indica el orden del archivo
		while(!file.eof()) //ciclo que permite buscar al usuario
		{
			if(nameUsuario == nombre && codigo == contrasena) //condicional que dice que el usuario y la contraseña deben ser el mismo
			{
				found++; //si el nombre o usuario no son correctos el contador aumenta
				menuGeneral();
			}
			file >> nombre >> contrasena >> fecha >> direccion >> telefono; //se ordena el archivo
		}
		if(found==0) //si el contador es mayor a 0 es porque no se encuentra el usuario
		{
			cout<<"\n\t\t\t El usuario o contraseña sin incorrectos...";
		}
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
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nombre >> contrasena >> fecha >> direccion >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Usuario: "<<nombre<<endl;
			cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
			cout<<"\t\t\t Fecha de nacimiento: "<<fecha<<endl;
			cout<<"\t\t\t Direccion usuario: "<<direccion<<endl;
			cout<<"\t\t\t Telefono usuario: "<<telefono<<endl << endl;
			file >> nombre >> contrasena >> fecha >> direccion >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system ("pause");
	file.close();
}
void Usuario::altas()
{
    cout << "\n\n\t\tAÚN NO HAY INFORMACIÓN DISPONIBLE\n\n";
    system ("pause");
}
void Usuario::bajas()
{
    cout << "\n\n\t\tAÚN NO HAY INFORMACIÓN DISPONIBLE\n\n";
    system ("pause");
}
void Usuario::modificacion()
{
    system("cls");
	fstream file,file1;
	string name;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n\t\tIngrese el nombre del usuario a modificar: ";
		cin>>name;
		file1.open("Record.txt",ios::app | ios::out);
		file >> nombre >> contrasena >> fecha >> direccion >> telefono;
		while(!file.eof())
		{
			if(name!=nombre)
			{
			 file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Nombre: ";
                cin>>nombre;
                cout<<"\t\t\tIngresa contraseña: ";
                cin>>contrasena;
                cout<<"\t\t\tIngresa fecha de nacimiento (sin espacios): ";
                cin>>fecha;
                cout<<"\t\t\tIngresa direccion: ";
                cin>>direccion;
                cout<<"\t\t\tIngresa telefono: ";
                cin>>telefono;
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< telefono << "\n";
				found++;
			}
			file >> nombre >> contrasena >> fecha >> direccion >> telefono;

		}
		system ("pause");
		file1.close();
		file.close();
		remove("nombresUsuarios.txt");
		rename("Record.txt","nombresUsuarios.txt");
	}
}
void Usuario::consultas()
{
    system("cls");
	fstream file;
	int found=0;
	file.open("nombresUsuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string name;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\n\t\tIngrese el usuario a buscar: ";
		cin>>name;
		file >> nombre >> contrasena >> fecha >> direccion >> telefono;
		while(!file.eof())
		{
			if(name==nombre)
			{
				cout<<"\n\n\t\t\t Usuario: "<<nombre<<endl;
				cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
				cout<<"\t\t\t Fecha nacimiento: "<<fecha<<endl;
				cout<<"\t\t\t Direccion: "<<direccion<<endl;
				cout<<"\t\t\t Teléfono: "<<telefono<<endl << endl;
				found++;
			}
			file >> nombre >> contrasena >> fecha >> direccion >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		system("pause");
		file.close();
	}
}
