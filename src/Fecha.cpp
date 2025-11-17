#include "../include/Fecha.h"
#include <stdexcept>

// Helper function to check for leap years
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Helper function to get days in a month
int diasEnMes(int mes, int anio) {
    if (mes < 1 || mes > 12) return 0;
    if (mes == 2) {
        return esBisiesto(anio) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

Fecha::Fecha() : dia(1), mes(1), anio(1900) {}

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
    if (!esValida()) {
        // In a real application, a more specific exception would be better.
        throw std::invalid_argument("Fecha invalida");
    }
}

Fecha::Fecha(const Fecha& otra) : dia(otra.dia), mes(otra.mes), anio(otra.anio) {}

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

bool Fecha::esValida() {
    if (anio < 0 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }
    return dia <= diasEnMes(mes, anio);
}

bool Fecha::operator==(const Fecha& otra) {
    return anio == otra.anio && mes == otra.mes && dia == otra.dia;
}

bool Fecha::operator<(const Fecha& otra) {
    if (anio < otra.anio) return true;
    if (anio > otra.anio) return false;
    if (mes < otra.mes) return true;
    if (mes > otra.mes) return false;
    return dia < otra.dia;
}

bool Fecha::operator>(const Fecha& otra) {
    return !(*this < otra) && !(*this == otra);
}

Fecha Fecha::operator++() { // Pre-increment
    dia++;
    if (dia > diasEnMes(mes, anio)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
    return *this;
}

Fecha Fecha::operator++(int) { // Post-increment
    Fecha temp = *this;
    ++(*this);
    return temp;
}

Fecha Fecha::operator+(int dias) {
    Fecha nuevaFecha = *this;
    for (int i = 0; i < dias; ++i) {
        ++nuevaFecha;
    }
    return nuevaFecha;
}

// Calculates the total number of days from a reference date (e.g., 0/1/1)
long days(const Fecha& f) {
    long y = f.getAnio();
    long m = f.getMes();
    long d = f.getDia();
    m = (m + 9) % 12;
    y = y - m / 10;
    return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);
}

int Fecha::operator-(const Fecha& otra) {
    return days(*this) - days(otra);
}
