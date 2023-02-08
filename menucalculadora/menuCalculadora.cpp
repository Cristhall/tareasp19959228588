// Fecha de creación: 6 de febrero de 2023 - autor: crodriguezo
// Este programa tiene como objetivo mostrar el curso de funciones a traves de una calculadora
// Modificaciones: 1) Nuevo Menú. 2) Nuevas operaciones extendidas.
#include <iostream>
#include <stdlib.h> // También se usa <cstdlib>
#include <math.h>

using namespace std;

// Definición de prototipos
void menuPrincipal();
void menuOperacionesBasicas();
void menuOperacionesExtendidas();
void factorial();
void sumar();
void restar();
void multiplicar();
void dividir();
void raizCuadrada();
void valorE();
void xPotencia();
void hipotenusa();
void ecuacionesSegundoGrado();

int main ()
{
    menuPrincipal();
    return 0;
}
// Implementación de funciones

void xPotencia()
{
    system("cls");
    int x, y, z;
    cout << "\n\tPotencias" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese el número que quiere elevar: ";
    cin >> x;
    cout << "\n\tIngrese la potencia del número: ";
    cin >> y;
    cout << "\n\t----------------------" << endl;
    z = pow(x, y);
    cout << "\tPotencia de: " << x << "^" << y <<  endl;
    cout << "\tResultado: " << z << endl;
    system("pause>nul");
}
void valorE()
{
    system("cls");
    int x;
    float y;
    cout << "\n\tValor Euler" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese la potencia del número: ";
    cin >> x;
    cout << "\n\t----------------------" << endl;
    y = exp(x);
    cout << "\tValor euler: e^" << x <<  endl;
    cout << "\tResultado: " << y << endl;
    system("pause>nul");
}
void hipotenusa()
{
    system("cls");
    int primerCateto, segundoCateto, A, B, suma;
    float resultado;
    cout << "\n\tHpotenusa" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese el primer cateto: ";
    cin >> primerCateto;
    cout << "\n\tIngrese el segundo cateto: ";
    cin >> segundoCateto;
    cout << "\n\t----------------------" << endl;
    if (primerCateto && segundoCateto < 0)
    {
        cout << "\tERROR! Los números deben ser positivos";
    }else
    {
    resultado = (sqrt(pow(primerCateto,2) + pow(segundoCateto,2)));
    cout << "\tLa hipotenusa es: " << resultado << endl;
    }
    system("pause>nul");
}
void ecuacionesSegundoGrado()
{
    system("cls");
    int a,b,c,d,e;
    double x1, x2, raiz,r1,real, imaginario;
    cout << "\n\tEcuaciones de Segundo Grado" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese la primera variable: ";
    cin >> a;
    cout << "\n\tIngrese la segunda variable: ";
    cin >> b;
    cout << "\n\tIngrese la tercera variable: ";
    cin >> c;
    cout << "\n\t----------------------" << endl;
    d = pow(b,2)-4*a*c;
    e = 2*a;
    if (a == 0)
    {
        cout << "\tDebe un ingresar un número > a 0" << endl;
        cout << "\tNo se puede resolver el problema" << endl;
    }
    else
    {
        if (d == 0)
        {
            r1 = (-b)/e;
            cout << "\tLa ecuación tiene solo una raíz" << endl;
            cout << "\tX = " << r1 << endl;
        }
        else
        {
            if (d > 0)
            {
                raiz = sqrt(d);
                x1 = (-b+raiz) / (e);
                x2 = (-b-raiz) / (e);
                cout << "\tLas soluciones son: " << endl;
                cout << "\tX1 = " << x1 << endl;
                cout << "\tX2 = " << x2 << endl;
            }
            else
            {
                cout << "\tRaíz con valor negativo" << endl;
                cout << "\tNo se puede resolver este problema" << endl;
            }
        }
    }

    system("pause>nul");
}
void raizCuadrada()
{
    system("cls");
    int x;
    float y;
    cout << "\n\tRaíz Cuadrada" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese el Número: ";
    cin >> x;
    cout << "\n\t----------------------" << endl;
    if (x < 0)
    {
        cout << "\tERROR! Debe ser un número positivo...";
    }else
    {
        y = sqrt(x);
        cout << "\tLa Raíz Cuadrada es: " << y << endl;
    }
    system("pause>nul");
}
void factorial()
{
    system("cls");
    int numeroIngresado, i;   //lowerCamelCase
    float resultadoFactorial;
    cout << "\n\tCalculo del Factorial" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\tIngrese el Número: ";
    cin >> numeroIngresado;
    cout << "\n\t----------------------" << endl;
    resultadoFactorial = 1;
    for (i=1; i<=numeroIngresado; i++)
    {
        resultadoFactorial = resultadoFactorial * i;
    }
    cout << "\t" << numeroIngresado << "! = " << resultadoFactorial << endl;
    system("pause>nul");
}
void menuOperacionesExtendidas()
{
    int opciones;
    bool repetir = true; //Para que regrese a menú
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Operaciones Extendidas" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\t1. Factorial" << endl;
        cout << "\t2. Raíz Cuadrada" << endl;
        cout << "\t3. Valor Euler" << endl;
        cout << "\t4. Potencias" << endl;
        cout << "\t5. Hipotenusa" << endl;
        cout << "\t6. Ecuaciones de Segundo Grado" << endl;
        cout << "\t7. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            factorial();
            break;
        case 2: raizCuadrada();
            break;
        case 3: valorE();
            break;
        case 4: xPotencia();
            break;
        case 5: hipotenusa();
            break;
        case 6: ecuacionesSegundoGrado();
            break;
        case 7: repetir = false;
                break;
        }
    }while (repetir);
}
void menuOperacionesBasicas()
{
    int opciones;
    bool repetir = true; //Para que regrese a menú
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Operaciones Básicas" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\t1. Sumar dos números" << endl;
        cout << "\t2. Restar dos números" << endl;
        cout << "\t3. Multiplicar dos números" << endl;
        cout << "\t4. Dividir dos números" << endl;
        cout << "\t5. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            sumar();
            break;
        case 2:
            restar();
            break;
        case 3:
            multiplicar();
            break;
        case 4:
            dividir();
            break;
        case 5: repetir = false;
                break;
        }
    }while (repetir);
}
void menuPrincipal()
{
    int opciones;
    bool repetir = true; //Para que regrese a menú
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMENU CALCULADORA" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\t1. Operaciones Básicas" << endl;
        cout << "\t2. Operaciones Extendidas" << endl;
        cout << "\t3. SALIR" << endl;
        cout << "\n\tIngrese una opción: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            menuOperacionesBasicas();
            break;
        case 2:
            menuOperacionesExtendidas();
            break;

        case 3: repetir = false;
                break;
        }
    }while (repetir);
}
void sumar()
{
    int primerNumero, segundoNumero;   //lowerCamelCase
    float resultadoSumar;
    cout << "\n\tIngrese primer Número: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Número: ";
    cin >> segundoNumero;
    cout << "\n\t----------------------" << endl;
    resultadoSumar = primerNumero + segundoNumero;
    cout << "\tResultado de la suma: " << resultadoSumar << endl;
    system("pause>nul");
}
void restar()
{
    int primerNumero, segundoNumero;   //lowerCamelCase
    float resultadoRestar;
    cout << "\n\tIngrese primer Número: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Número: ";
    cin >> segundoNumero;
    cout << "\n\t----------------------" << endl;
    resultadoRestar = primerNumero - segundoNumero;
    cout << "\tResultado de la resta: " << resultadoRestar << endl;
 system("pause>nul");
}
void multiplicar()
{
    int primerNumero, segundoNumero;   //lowerCamelCase
    float resultadoMulti;
    cout << "\n\tIngrese primer Número: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Número: ";
    cin >> segundoNumero;
    cout << "\n\t----------------------" << endl;
    resultadoMulti = primerNumero * segundoNumero;
    cout << "\tResultado de la multiplicación: " << resultadoMulti << endl;
    system("pause>nul");
}
void dividir()
{
    int primerNumero, segundoNumero;   //lowerCamelCase
    float resultadoDividir;
    cout << "\n\tIngrese primer Número: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Número: ";
    cin >> segundoNumero;
    cout << "\n\t----------------------" << endl;
    if (segundoNumero == 0)
    {
        cout << "\tSegundo numero no puede ser cero (0) ERROR" << endl;
    }else
    {
        resultadoDividir = primerNumero / segundoNumero;
        cout << "\tResultado de la división: " << resultadoDividir << endl;
    }
    system("pause>nul");
}
