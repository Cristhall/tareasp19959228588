#include "Administracion.h"
#include "Usuario.h"
#include "Bitacora.h"
#include "Aplicaciones.h"
#include "InfoEmpleados.h"
#include <ctime>
#include <fstream>
#include <iomanip>
Bitacora llamarBitacora2;
Aplicaciones funcionesAplicaciones;
InfoEmpleados InformacionEm;
Usuario ingresoUsuario;
void Administracion::menuGeneralSTAFF(string n)
{
    system("cls");
    int choice1;
    nombre = n;
	do
    {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1). Catalogos "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). LOG OUT"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        catalogosSTAFF(nombre);
		break;
	case 2:
	    procesoSTAFF(nombre);
		break;
	case 3:
	    infomesSTAFF(nombre);
		break;
    case 4:
		return;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
	system("cls");
    }while(choice1!= 8);
}
void Administracion::catalogosSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Catalogos - 1200 |"<<endl;
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Usuarios "<<endl;
	cout<<"\t\t\t 2. Empleados "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                ingresoUsuario.menuSecundario();
                break;
            case 2:
                InformacionEm.menu(nombre);
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!=3);
}
void Administracion::procesoSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Procesos  - 1300 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Puestos "<<endl;
	cout<<"\t\t\t 2. Aplicaciones "<<endl;
	cout<<"\t\t\t 3. Pagos "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger: 1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:

                break;
            case 2:
                funcionesAplicaciones.menu(nombre);
                break;
            case 3:

                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 4);
}
void Administracion::infomesSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout << "\n\t\t\t Usuario: " << nombre << "\n\n";
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Informes  - 1400 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Planilla "<<endl;
	cout<<"\t\t\t 2. Bitacora "<<endl;
	cout<<"\t\t\t 3. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "APE");
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1800", "REA");
                llamarBitacora2.visualizarBitacora();
                break;
            case 3:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 3);
}
