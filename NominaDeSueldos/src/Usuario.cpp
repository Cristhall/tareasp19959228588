#include "Usuario.h"
#include "Administracion.h"
#include "Empleados.h"
#include "Bitacora.h"
#include "usuariosAdmon.h"
#include "usuariosEmpleados.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
#define ADMINISTRADOR "administrador"
#define CONTRAADMON "1234"
string nameUsuario, codigo;
Administracion funcionAdmon;
Empleados funcionEmpleados;
Bitacora llamarBitacora;
usuariosAdmon menuUsuariosAdmon;
usuariosEmpleados menuUsuariosEmpleados;
void Usuario::iniciarSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("nombresUsuarios.txt",ios::in); //Verificacion de LOGIN DE EMPLEADOS O ADMINISTRACION
	cout<<"\n----------------------------------------------------------------------------------------------------------------------";
    cout<<"\n--------------------------------------------------- Iniciar Sesion - 700 ---------------------------------------------"<<endl;
    cout<<"\n\t\tUsuario: ";
    cin>>nameUsuario;
    cout << "\t\tContrasena: ";
    cin >> codigo;
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(nameUsuario==nombre && codigo == contrasena)
        {
            llamarBitacora.ingresoBitacora(nameUsuario,"700", "LOGIN");
            funcionEmpleados.menuGeneralEmpleados(nameUsuario);
            return;
            found++;
        }
        else
        {
            if (nameUsuario==ADMINISTRADOR && codigo==CONTRAADMON)
            {
                llamarBitacora.ingresoBitacora(nameUsuario,"700", "LOGIN");
                funcionAdmon.menuGeneralSTAFF(nameUsuario);
                return;
                found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        llamarBitacora.ingresoBitacora(nameUsuario,"700", "NO LOGIN");
        cout<<"\n\t\t\t El usuario o contraseña sin incorrectos..." << endl;
        system("pause");
    }
    file.close();
}
void Usuario::menuSecundario()
{
    int opcion;
	do
    {
	system("cls");
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t |          PROGRAMA EMPRESARIAL STAFF - Catalogo Usuarios            |"<<endl;
	cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Administrativo"<<endl;
	cout<<"\t\t\t 2. Empleados"<<endl;
	cout<<"\t\t\t 3. Regresar"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            //menuUsuariosAdmon.menuAdmon(nameUsuario);
            break;
        case 2:
            //menuUsuariosEmpleados.menuEmpleados(nameUsuario);
            break;
        case 3:
            return;
        default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        system ("pause");
        break;
        }
    }while(opcion!=3);
}
