#ifndef NOMINA_H
#define NOMINA_H


class Nomina
{
    public:
        calculoSalario(int s, h, c, ah, a, dj, bt);
    private:
        string nombre, apellido, puesto;
        int sueldo, noHoraExtra, vaHoraExtra, comisiones, toDevengado, bonoIncentivo, toDevenMasBono;
        int ISR, cAhorro, IGSS, anticipo, descuentosJudi, bancoTraba, toDescuentos;

};

#endif // NOMINA_H
