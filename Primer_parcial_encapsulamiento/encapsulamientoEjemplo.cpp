#include <iostream>
using namespace std;

class Pajaro //Definición de la clase
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
    string mNombre; //Se define un parámetro que esta arriba, pero no se podrá usar, aplicaciónd de encapsulamiento.
};



int main()
{
    //Creación de un objeto utilizando las funciones de la clase Pajaro
    Pajaro PajaroUno("Águila", "Canto1");
    cout << PajaroUno.getNombre() << endl;
    PajaroUno.setNombre("Alejandro");
    cout << PajaroUno.getNombre() << endl;
    PajaroUno.Cantar();

    return 0;
}
