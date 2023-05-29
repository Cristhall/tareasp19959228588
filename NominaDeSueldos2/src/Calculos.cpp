#include "Calculos.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;

void Calculos::verPago(string id, string nombre, int n)
{
    system("cls");
    fstream file;
    salario = n;
    string fecha;
    igss = salario * 0.0483;
    irtra = salario * 0.01;
    hExtras = 0;
    if (salario<=30000 && salario>=0.00)
    {
        isr = salario * 0.05;
    }
    else
    {
        isr = salario * 0.07;

    }

    bono = 250;
    salariototal = (salario + bono) - (hExtras+igss+irtra+isr);
    system("cls");
    cout << "\n\n\t    --- DETALLE DE PAGO --- " <<endl;
    cout<<"\t-------------------------------"<<endl;
    cout << "\n" << endl;
    cout << "\tBoleta de pago correspondiente al "<< fecha << endl;
    cout << "\tEmpleado - "<< id << endl;
    cout << "\n" << endl;
    cout << "\tsalario neto         - " << salario << endl;
    cout << "\tbonificacion         - " << bono << endl;
    cout << "\tDescuesntos aplicados " << endl;
    cout << "\t* descuento de IGSS  - " << igss << endl;
    cout << "\t* descuento de IRTRA - " << irtra << endl;
    cout << "\t* descuento de ISR   - " << isr << endl;
    cout<<"\t-------------------------------"<<endl;
    cout << "\tTOTAL A PAGAR      - " << salariototal << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    system ("pause");
    file.open("RegistroSalarioEmpleados.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bono <<std::left<<std::setw(15)<< hExtras<<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salariototal << "\n";
	file.close();
}
