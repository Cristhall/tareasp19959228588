#include "Administracion.h"
#include "Usuario.h"
#include <ctime>
#include <fstream>
#include <iomanip>
void Administracion::menuGeneralSTAFF(string n)
{
    system("cls");
    int choice1;
    Usuario ingresoUsuario;
    nombre2 = n;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1). Informacion personal laboral "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). Crear Usuarios"<<endl;
	cout<<"\t\t\t 5). Modificar Usuarios"<<endl;
	cout<<"\t\t\t 6). LOG OUT"<<endl;
    cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5-6 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice1;

    switch(choice1)
    {
    case 1:
        infopersonalSTAFF(nombre2);
		break;
	case 2:
	    procesoSTAFF(nombre2);
		break;
	case 3:
	    infomesSTAFF(nombre2);
		break;
	case 4:
	    ingresoUsuario.insertar();
		break;
	case 5:
	    ingresoUsuario.menuSecundario();
		break;
    case 6:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
	system("cls");
    }while(choice1!= 6);
}
void Administracion::infopersonalSTAFF(string n)
{
    fstream file1;
    file1.open("Bitacora.txt", ios::app);
    nombre2 = n;
    time_t now = time(0);
    date_time = ctime(&now);
    int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF - Informacion personal laboral  |"<<endl;
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Datos - Empleados "<<endl;
	cout<<"\t\t\t 2. Datos - puestos de trabajo "<<endl;
	cout<<"\t\t\t 3. Datos - Empleados amonestados "<<endl;
	cout<<"\t\t\t 4. Datos - Rendimiento "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                accion = "RDE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "RDP";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "RDEA";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "RDR";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 5:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 5);
}
void Administracion::procesoSTAFF(string n)
{
    fstream file1;
    file1.open("Bitacora.txt", ios::app);
    nombre2 = n;
    time_t now = time(0);
    date_time = ctime(&now);
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Proceso   |"<<endl;
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
                accion = "INS O DEL AD";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "UPDP";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "RO";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "ERE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
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
    fstream file1;
    file1.open("Bitacora.txt", ios::app);
    nombre2 = n;
    time_t now = time(0);
    date_time = ctime(&now);
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL STAFF -   Informes   |"<<endl;
	cout<<"\t\t\t-----------------------------------------------"<<endl;
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
                accion = "APE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "AHE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "RHL";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "EOT";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 5:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 5);
}
