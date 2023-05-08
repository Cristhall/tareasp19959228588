#include "Empleados.h"
#include "Usuario.h"
#include <ctime>
#include <fstream>
#include <iomanip>
void Empleados::menuGeneralEmpleados(string n)
{
    system("cls");
    nombre2 = n;
    int choice2;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados  |"<<endl;
	cout<<"\t\t\t-------------------------------------"<<endl;
	cout<<"\t\t\t 1). Informacion personal laboral "<<endl;
	cout<<"\t\t\t 2). Procesos"<<endl;
	cout<<"\t\t\t 3). Informes"<<endl;
	cout<<"\t\t\t 4). LOG OUT"<<endl;
		cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4 "<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice2;

        switch(choice2)
        {
            case 1:
                infopersonalEmpleados(nombre2);
                break;
            case 2:
                procesoEmpleados(nombre2);
                break;
            case 3:
                informesEmpleados(nombre2);
                break;
            case 4:
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
	system("cls");
    }while(choice2!= 4);
}
void Empleados::infopersonalEmpleados(string n)
{
    fstream file1;
    file1.open("Bitacora.txt", ios::app);
    nombre2 = n;
    time_t now = time(0);
    date_time = ctime(&now);
    int choice;
    do {
	system("cls");
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados - Informacion personal laboral  |"<<endl;
	cout<<"\t\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Informacion Personal "<<endl;
	cout<<"\t\t\t 2. Puesto en la empresa "<<endl;
	cout<<"\t\t\t 3. Procesos Diciplinarios "<<endl;
	cout<<"\t\t\t 4. Rendimiento "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                accion = "RIE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "RPE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "RPD";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "RR";
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
void Empleados::procesoEmpleados(string n)
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
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados -   Proceso   |"<<endl;
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Solicitar nuevo puesto "<<endl;
	cout<<"\t\t\t 2. Revisar procesos diciplinarios "<<endl;
	cout<<"\t\t\t 3. Solicitar horas extras "<<endl;
	cout<<"\t\t\t 4. Servicio de ayuda "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                accion = "SNP";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "RPD"; //Hay un duplicado, en el menu anterior hay una opcion de proceso disciplinario
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "SHE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "RDE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 5:
                accion = "SOS";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            default:
                cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    }while(choice!= 5);
}
void Empleados::informesEmpleados(string n)
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
	cout<<"\t\t\t |   PROGRAMA EMPRESARIAL Empleados -   Informes   |"<<endl;
	cout<<"\t\t\t-----------------------------------------------"<<endl;
	cout<<"\t\t\t 1. visualizar nomina de pago "<<endl;
	cout<<"\t\t\t 2. visualizar pagos extras "<<endl;
	cout<<"\t\t\t 3. Visualizar horas laboradas "<<endl;
	cout<<"\t\t\t 4. Visualizar descuentos aplicados "<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:1-2-3-4-5 "<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
                accion = "VNP";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 2:
                accion = "VPE";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 3:
                accion = "VHL";
                file1<<std::left<<std::setw(20)<< nombre2 <<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
                file1.close();
                break;
            case 4:
                accion = "VDA";
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
