#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    bool esValida() const;
};

#endif
