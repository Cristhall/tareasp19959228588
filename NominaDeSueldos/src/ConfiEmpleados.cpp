#include "ConfiEmpleados.h"
#include "Usuario.h"
#include "Bitacora.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <conio.h>
using namespace std;
Bitacora llamarBitacora4;
void ConfiEmpleados::menu(string n)
{
    string nombre2;
    nombre2 = n;
    int choice;
	do
    {
	system("cls");

	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION Registro de Empleados - 1700  |"<<endl;
	cout<<"\t\t\t----------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Empleado"<<endl;
	cout<<"\t\t\t 2. Despliegue Empleados"<<endl;
	cout<<"\t\t\t 3. Modificar Empleado"<<endl;
	cout<<"\t\t\t 4. Buscar Empleado"<<endl;
	cout<<"\t\t\t 5. Borrar Empleado"<<endl;
	cout<<"\t\t\t 6. Regresar a menu anterior"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        llamarBitacora4.ingresoBitacora(nombre2,"1700", "INS");
        insertar();
		break;
	case 2:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "REA");
		desplegar();
		break;
	case 3:
		llamarBitacora4.ingresoBitacora(nombre2,"1700", "UPD");
		modificar();
		break;
	case 4:
	    llamarBitacora4.ingresoBitacora(nombre2,"1700", "SEA");
		buscar();
		break;
	case 5:
	    llamarBitacora4.ingresoBitacora(nombre2,"1700", "DEL");
		borrar();
		break;
	case 6:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void ConfiEmpleados::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles ConfiEmpleados ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Empleado         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Empleado     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono Empleado   : ";
	cin>>telefono;
	cout<<"\t\t\tIngresa Dirección Empleado : ";
	cin>>direccion;
	cout<<"\t\t\tIngresa Puesto Empleado  : ";
	cin>>puesto;
	cout<<"\t\t\tIngresa Sueldo Empleado  : ";
	cin>>sueldo;
	file.open("RegistroDeEmpleados.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< sueldo << "\n";
	file.close();
}
void ConfiEmpleados::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de ConfiEmpleadoss -------------------------"<<endl;
	file.open("RegistroDeEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Empleado: "<<id<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombre<<endl;
			cout<<"\t\t\t Telefono Empleado: "<<telefono<<endl;
			cout<<"\t\t\t Direccion Empleado: "<<direccion<<endl;
			cout<<"\t\t\t Puesto Empleado: "<<puesto<<endl;
			cout<<"\t\t\t Sueldo Empleado: "<<sueldo<<endl;
			file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void ConfiEmpleados::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles ConfiEmpleados-------------------------"<<endl;
	file.open("RegistroDeEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< sueldo << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Empleado: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Empleado: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono Empleado: ";
				cin>>telefono;
				cout<<"\t\t\tIngrese Direccion Empleado: ";
				cin>>direccion;
				cout<<"\t\t\tIngrese Puesto Empleado: ";
				cin>>puesto;
				cout<<"\t\t\tIngrese Sueldo Empleado: ";
				cin>>sueldo;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< sueldo << "\n";
				found++;
			}
			file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;

		}
		file1.close();
		file.close();
		remove("RegistroDeEmpleados.txt");
		rename("Record.txt","RegistroDeEmpleados.txt");
	}
}
void ConfiEmpleados::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("RegistroDeEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la ConfiEmpleados buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de ConfiEmpleados buscada------------------------"<<endl;
		cout<<"\nIngrese Id del empleado que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre Empleado: "<<nombre<<endl;
				cout<<"\t\t\t Telefono Empleado: "<<telefono<<endl;
				cout<<"\t\t\t Dirección Teléfono: "<<direccion<<endl;
				cout<<"\t\t\t Puesto Empleado: "<<puesto<<endl;
				cout<<"\t\t\t Sueldo Empleado: "<<sueldo<<endl;
				found++;
			}
			file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}
void ConfiEmpleados::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles ConfiEmpleados a Borrar-------------------------"<<endl;
	file.open("RegistroDeEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< puesto<<std::left<<std::setw(15)<< sueldo << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> telefono >> direccion >> puesto >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("RegistroDeEmpleados.txt");
		rename("Record.txt","RegistroDeEmpleados.txt");
	}
}
