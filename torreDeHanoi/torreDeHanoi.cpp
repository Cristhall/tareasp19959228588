//Torres de Hanoi: consiste en ir cambiando los discos de la torre 1 a la torre 3
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int num,char A,char C,char B);

int main()
{
        int n;
        char A,B,C;

        cout << "\n\t\tTORRES DE HANOI\n\n";
        cout << "\tReglas:\n\t1. Solo se puede mover un disco a la vez\n";
        cout << "\t2. Un disco de mayor tamaño no se puede colocar encima de uno más pequeño.\n";
        cout << "\t3. Solo se puede desplazar el disco que se encuentre arriba en cada varilla.\n\n";
        cout<<"\tLos clavijas son A B C\n";
        cout<<"\tNumero de discos: ";
        cin>>n;
        cout << "\tNúmero de movimientos: " << pow(2, n)-1 << endl;
        cout<<endl;
        hanoi(n,'A','C','B');
        cout << "\n\tLos discos se movieron a la 3er clavija (C) exitosamente" << endl;
        return 0;

}
void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"\tMueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;

    }
    else
    {
        hanoi(num-1,A,B,C);
        cout<<"\tMueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}
