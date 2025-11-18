#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha();
    Fecha(int, int, int);
    Fecha(const Fecha&);
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const Fecha&);
    bool operator<(const Fecha&);
    bool operator>(const Fecha&);
    Fecha operator++();
    Fecha operator++(int);
    Fecha operator+(int);
    int operator-(const Fecha&);
    bool esValida();
};

#endif // FECHA_H
