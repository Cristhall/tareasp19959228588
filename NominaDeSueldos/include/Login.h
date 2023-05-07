#ifndef LOGIN_H
#define LOGIN_H
#include<iostream>
using namespace std;
class Login
{
    public:
        void iniciarSesion();
    private:
        string nombre, contrasena, fecha, accion;
};

#endif // LOGIN_H
