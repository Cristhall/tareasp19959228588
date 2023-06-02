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
			cout<<"\n\n\t\t\t Id              :  "<<id<<endl;
            cout<<"\t\t\t Nombre          :  "<<nombre<<endl;
            cout<<"\t\t\t Salario Base    :  Q"<<salario<<endl;
            cout<<"\t\t\t Bonificacion    :  Q"<<bonificacion<<endl;
            cout<<"\t\t\t Horas laboradas :  "<<hTrabajadas<<endl;
            cout<<"\t\t\t Monto por horas :  Q"<<montoHTr<<endl;
            cout<<"\t\t\t IGSS            :  Q"<<igss<<endl;
            cout<<"\t\t\t ISR             :  Q"<<isr<<endl;
            cout<<"\t\t\t Salario Total   :  Q"<<salarioTotal<<endl;
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
				cout<<"\n\n\t\t\t Id              :  "<<id<<endl;
                cout<<"\t\t\t Nombre          :  "<<nombre<<endl;
                cout<<"\t\t\t Salario Base    :  Q"<<salario<<endl;
                cout<<"\t\t\t Bonificacion    :  Q"<<bonificacion<<endl;
                cout<<"\t\t\t Horas laboradas :  "<<hTrabajadas<<endl;
                cout<<"\t\t\t Monto por horas :  Q"<<montoHTr<<endl;
                cout<<"\t\t\t IGSS            :  Q"<<igss<<endl;
                cout<<"\t\t\t ISR             :  Q"<<isr<<endl;
                cout<<"\t\t\t Salario Total   :  Q"<<salarioTotal<<endl;
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
void Planilla::modificarPlanilla(string n)
{
    system("cls");
    nombre2 = n;
	cout << "\n\t\t\t Usuario: " << nombre2 << "\n\n";
	fstream file,file1;
	string participant_id;
	int horas, limite = 160;
	cout<<"\n-------------------------Modificar Planilla de Sueldos-------------------------"<<endl;
	file.open("PlanillaDeSueldos.txt",ios::in);
	cout<<"\n\t Ingrese Id del empleado: ";
    cin>>participant_id;
    cout<<"\t ---------Mes: 160 horas" << endl;
    cout <<"\t Horas laboradas en el mes:";
    cin>>hLaboradas;
    file1.open("Record.txt",ios::app | ios::out);
    file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;
    while(!file.eof())
    {
        if(participant_id!=id)
        {
            file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< hTrabajadas <<std::left<<std::setw(15)<< montoHTr <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salarioTotal << "\n";
        }
        else
        {
            if(hLaboradas<limite)
            {
                hTrabajadas = hLaboradas;
                horas = limite - hLaboradas;
                montoHTr = salario/30/8*1.5*horas;
                salarioTotal = (salario + bonificacion) - (montoHTr+igss+isr);
            }
            else
            {
                if(hLaboradas>limite)
                {
                    hTrabajadas = hLaboradas;
                    horas = hLaboradas - limite;
                    montoHTr = salario/30/8*1.5*horas;
                    salarioTotal = (salario+bonificacion+montoHTr) - (igss+isr);
                }
                else
                {
                    if(hLaboradas==limite)
                    {
                        hTrabajadas = hLaboradas;
                        montoHTr = 0;
                        salarioTotal = (salario+bonificacion) - (igss+isr);
                    }
                }
            }
            file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< hTrabajadas <<std::left<<std::setw(15)<< montoHTr <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salarioTotal << "\n";
        }
        file >> id >> nombre >> salario >> bonificacion >> hTrabajadas >> montoHTr >> igss >> isr >> salarioTotal;

    }
    file1.close();
    file.close();
    remove("PlanillaDeSueldos.txt");
    rename("Record.txt","PlanillaDeSueldos.txt");
    system("pause");
}

