#include "Calculos.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;

void Calculos::calculoSueldo(string i, string n, string p)
{
    fstream file, file1;
    puesto2 = p;
    id = i;
    nombre = n;
    file1.open("PuestosEmpleados.txt", ios::app | ios::out);
    file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< puesto2 << "\n";
    file1.close();
    file.open("PuestoDeTrabajo.txt", ios::in);
    file >> puesto >> salarioBase;
    while(!file.eof())
    {
        if(puesto2==puesto)
        {
            salario2=salarioBase;
        }
        file >> puesto >> salarioBase;
    }
    verPago(salario2);
}
void Calculos::verPago(int s)
{
    fstream file;
    salario = s;
    igss = salario * 0.0483;
    irtra = salario * 0.01;
    hExtras = 0;
    cHExtras = 0;
    if (salario<=30000 && salario>=0.00)
    {
        isr = salario * 0.05;
    }
    else
    {
        isr = salario * 0.07;

    }
    bonificacion = 250;
    salarioTotal = (salario + bonificacion) - (hExtras+igss+irtra+isr);
    file.open("PlanillaDeSueldos.txt", ios::app | ios::out);
    file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< bonificacion <<std::left<<std::setw(15)<< cHExtras <<std::left<<std::setw(15)<< hExtras <<std::left<<std::setw(15)<< igss <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< salarioTotal << "\n";
    file.close();
}
