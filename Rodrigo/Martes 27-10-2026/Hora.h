#ifndef HORA_H
#define HORA_H

class Hora {
private:
    int _hora;
    int _minuto;

public:
    Hora();
    Hora(int hora, int minuto);

    int getHora() const;
    int getMinuto() const;

    void setHora(int hora);
    void setMinuto(int minuto);

    bool esValida() const;
};

#endif
