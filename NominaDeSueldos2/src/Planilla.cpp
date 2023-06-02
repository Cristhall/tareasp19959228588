#include "Planilla.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Planilla::leerPlanilla(string n)
{
    system("cls");
    nombre2 = n;
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Planilla--------------------------"<<endl;
	file.open("PlanillaDeSueldos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id          : "<<id<<endl;
            cout<<"\t\t\t Nombre          : "<<nombre<<endl;
            cout<<"\t\t\t Salario Base    : "<<salario<<endl;
            cout<<"\t\t\t Bonificacion    : "<<bonificacion<<endl;
            cout<<"\t\t\t Horas laboradas : "<<hTrabajadas<<endl;
            cout<<"\t\t\t Monto por horas : "<<montoHTr<<endl;
            cout<<"\t\t\t IGSS            : "<<igss<<endl;
            cout<<"\t\t\t ISR             : "<<isr<<endl;
            cout<<"\t\t\t Salario Total   : "<<salarioTotal<<endl;
			file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	system("pause");
}
void Planilla::buscarPlanilla(string n)
{
    system("cls");
    nombre2 = n;
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int found=0;
	file.open("PlanillaDeSueldos.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Planilla buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de la Planilla buscada------------------------"<<endl;
		cout<<"\nIngrese Id del empleado que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id          : "<<id<<endl;
                cout<<"\t\t\t Nombre          : "<<nombre<<endl;
                cout<<"\t\t\t Salario Base    : "<<salario<<endl;
                cout<<"\t\t\t Bonificacion    : "<<bonificacion<<endl;
                cout<<"\t\t\t Horas laboradas : "<<hTrabajadas<<endl;
                cout<<"\t\t\t Monto por horas : "<<montoHTr<<endl;
                cout<<"\t\t\t IGSS            : "<<igss<<endl;
                cout<<"\t\t\t ISR             : "<<isr<<endl;
                cout<<"\t\t\t Salario Total   : "<<salarioTotal<<endl;
				found++;
			}
			file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Planilla no encontrada...";
		}
		file.close();
	}
	system("pause");
}
void Planilla::imprimirPlanilla(string n)
{
    system("cls");
    nombre2 = n;
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int horas, limite = 160;
	cout<<"\n-------------------------Impresion de Boleta de Pago-------------------------"<<endl;
	file.open("PlanillaDeSueldos.txt",ios::in);
	cout<<"\n\t Ingrese Id del empleado: ";
    cin>>participant_id;
    cout<<"\t ---------Mes: 160 horas" << endl;
    cout <<"\t Horas laboradas en el mes:";
    cin>>hTrabajadas;
    cout<<"\t Fecha de pago: ";
    cin>>fecha;
    file1.open("BitacoraDePagos.txt",ios::app | ios::out);
    file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
    while(!file.eof())
    {
        if(participant_id==id)
            {
                if(hTrabajadas<limite)
                {
                    horas = limite - hTrabajadas;
                    montoHTr = salario/30/8*1.5*horas;
                    salarioTotal = (salario + bonificacion) - (montoHTr+igss+isr);
                }
                else
                {
                    if(hTrabajadas>limite)
                    {
                        horas = hTrabajadas - limite;
                        montoHTr = salario/30/8*1.5*hTrabajadas;
                        salarioTotal = (salario+bonificacion+montoHTr) - (igss+isr);
                    }
                    else
                    {
                        if(hTrabajadas==limite)
                        {
                            montoHTr = 0;
                            salarioTotal = (salario+bonificacion) - (igss+isr);
                        }
                    }
                }
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< hTrabajadas <<std::left<<std::setw(15)<< montoHTr <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salarioTotal <<std::left<<std::setw(15)<< fecha << "\n";
            }
        file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;

    }
    file1.close();
    file.close();
    system("pause");
}
void Planilla::leerBitacoraPagos(string n)
{
    system("cls");
    nombre2 = n;
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles Bitacora de Pagos -------------------------"<<endl;
	file.open("BitacoraDePagos.txt",ios::in);
	cout<<"\n\t\t\t"<<std::left<<std::setw(15)<< "Id" <<std::left<<std::setw(15)<< "Nombre" <<std::left<<std::setw(15)<< "Salario Base" <<std::left<<std::setw(15)<< "Bonificacion" <<std::left<<std::setw(15)<< "Horas Trabajadas" <<std::left<<std::setw(15)<< "Monto por Horas" <<std::left<<std::setw(15)<< "IGSS" <<std::left<<std::setw(15)<< "ISR" <<std::left<<std::setw(15)<< "Salario Total" <<std::left<<std::setw(15)<< "Fecha\n\n";
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal >> fecha;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id          : "<<id<<endl;
			cout<<"\t\t\t Nombre          : "<<nombre<<endl;
			cout<<"\t\t\t Salario Base    : "<<salario<<endl;
			cout<<"\t\t\t Bonificacion    : "<<bonificacion<<endl;
			cout<<"\t\t\t Horas laboradas : "<<hTrabajadas<<endl;
			cout<<"\t\t\t Monto por horas : "<<montoHTr<<endl;
			cout<<"\t\t\t IGSS            : "<<igss<<endl;
			cout<<"\t\t\t ISR             : "<<isr<<endl;
			cout<<"\t\t\t Salario Total   : "<<salarioTotal<<endl;
			cout<<"\t\t\t Fecha           : "<<fecha<<endl;
			file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal >> fecha;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	system("pause");
}
