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
void Administracion::menuGeneralSTAFF(string n)
{
    system("cls");
    int choice1;
    Usuario ingresoUsuario;
    nombre = n;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1). Informacion personal laboral "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). Catalogo Usuarios"<<endl;  //Relacion para CRUD DE USUARIOS
	cout<<"\t\t\t 5). Catalogo Empleados"<<endl; //Relacion para CRUD DE EMPLEADOS
	cout<<"\t\t\t 6). Aplicaciones"<<endl;
	cout<<"\t\t\t 7). Bitacora"<<endl;
	cout<<"\t\t\t 8). LOG OUT"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5-6 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        infopersonalSTAFF(nombre);
		break;
	case 2:
	    procesoSTAFF(nombre);
		break;
	case 3:
	    infomesSTAFF(nombre);
		break;
	case 4:
	    ingresoUsuario.menuSecundario();
		break;
	case 5:
	    InformacionEm.menu(nombre);
		break;
    case 6:
	    funcionesAplicaciones.menu(nombre);
		break;
    case 7:
	    llamarBitacora2.ingresoBitacora(nombre,"1800", "REA");
	    llamarBitacora2.visualizarBitacora();
		break;
    case 8:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
	system("cls");
    }while(choice1!= 8);
}
void Administracion::infopersonalSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Informacion personal laboral - 1200 |"<<endl;
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Datos - puestos de trabajo "<<endl;
	cout<<"\t\t\t 2. Datos - Empleados amonestados "<<endl;
	cout<<"\t\t\t 3. Datos - Rendimiento "<<endl;
	cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1200", "RDPT");
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1200", "RDEA");
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"1200", "RDR");
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 4);
}
void Administracion::procesoSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Proceso  -1300 |"<<endl;
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Crear y eliminar accion Diciplinaria "<<endl;
	cout<<"\t\t\t 2. Actualizar puestos de trabajo "<<endl;
	cout<<"\t\t\t 3. Revisar observaciones "<<endl;
	cout<<"\t\t\t 4. Editar rendimiento de empelado "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1300", "INS O DEL AD");
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1300", "UPDP");
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"1300", "RO");
                break;
            case 4:
                llamarBitacora2.ingresoBitacora(nombre,"1300", "ERE");
                break;
            case 5:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 5);
}
void Administracion::infomesSTAFF(string n)
{
    nombre = n;
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Informes  - 1400 |"<<endl;
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. aprobar pago a empleado "<<endl;
	cout<<"\t\t\t 2. revisar y aprobar horas extra "<<endl;
	cout<<"\t\t\t 3. revisar horas laboradas "<<endl;
	cout<<"\t\t\t 4. Enviar observacion a trabajador "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "APE");
                break;
            case 2:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "AHE");
                break;
            case 3:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "RHL");
                break;
            case 4:
                llamarBitacora2.ingresoBitacora(nombre,"1400", "EOT");
                break;
            case 5:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 5);
}
