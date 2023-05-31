#include "Puestos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void Puestos::ingresarPuesto(string n)
{
    system("cls");
    nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------";
	cout<<"\n----------------------------------------------- Agregar detalles de Puesto --------------------------------------------"<<endl;
	cout<<"\n\n\t\t\tIngresa nombre del puesto   : ";
	cin>>puesto;
	cout<<"\t\t\tIngrese el salario base         : ";
	cin>>salarioBase;
	file.open("PuestoDeTrabajo.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< puesto <<std::left<<std::setw(15)<< salarioBase << "\n";
	file.close();
	system("pause");
}
void Puestos::modificarPuesto(string n)
{
    system("cls");
	nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file,file1;
	string puesto2;
	int found=0;
	cout<<"\n-------------------------------------------Modificacion Detalles de un Puesto------------------------------------------"<<endl;
	file.open("PuestoDeTrabajo.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el puesto que quiere modificar: ";
		cin>>puesto2;
		file1.open("Record.txt",ios::app | ios::out);
		file >> puesto >> salarioBase;
		while(!file.eof())
		{
			if(puesto2!=puesto)
			{
			 file1<<std::left<<std::setw(15)<< puesto <<std::left<<std::setw(15)<< salarioBase << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese el nombre del puesto : ";
				cin>>puesto;
				cout<<"\t\t\tIngrese el salario base       : ";
				cin>>salarioBase;
				file1<<std::left<<std::setw(15)<< puesto <<std::left<<std::setw(15)<< salarioBase << "\n";
				found++;
			}
			file >> puesto >> salarioBase;

		}
		file1.close();
		file.close();
		remove("PuestoDeTrabajo.txt");
		rename("Record.txt","PuestoDeTrabajo.txt");
	}
	system("pause");
}
void Puestos::visualizarPuesto(string n)
{
    system("cls");
    nombre = n;
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------------------------Tabla de Detalles de Puestos ----------------------------------------------"<<endl;
	file.open("PuestoDeTrabajo.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> puesto >> salarioBase;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\tNombre Puesto  : "<<puesto<<endl;
			cout<<"\t\t\tSalario Base       : "<<salarioBase<<endl;
			file >> puesto >> salarioBase;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	cout << endl;
	system("pause");
}
