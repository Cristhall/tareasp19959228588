#include <iostream>
using namespace std;

class Pajaro //Definici�n de la clase
{
public:
    string mCanto;
    Pajaro (string Nombre, string tipoCanto)
    {
        mCanto = tipoCanto;
        mNombre = Nombre;
    }
    //Get y Set para poder usar el nombre que esta en privado.
    string getNombre()
    {
        return mNombre;
    }
    void setNombre (string pNombre)
    {
        mNombre = pNombre;
    }
    void Cantar()
    {
        cout << mCanto << endl;
    }
private:
    string mNombre; //Se define un par�metro que esta arriba, pero no se podr� usar, aplicaci�nd de encapsulamiento.
};



int main()
{
    //Creaci�n de un objeto utilizando las funciones de la clase Pajaro
    Pajaro PajaroUno("�guila", "Canto1");
    cout << PajaroUno.getNombre() << endl;
    PajaroUno.setNombre("Alejandro");
    cout << PajaroUno.getNombre() << endl;
    PajaroUno.Cantar();

    return 0;
}
