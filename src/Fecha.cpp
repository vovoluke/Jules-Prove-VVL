#include "../include/Fecha.h"

Fecha::Fecha() {}
Fecha::Fecha(int dia, int mes, int anio) {}
Fecha::Fecha(const Fecha& other) {}
int Fecha::getDia() { return 0; }
int Fecha::getMes() { return 0; }
int Fecha::getAnio() { return 0; }
bool Fecha::operator==(const Fecha& other) { return false; }
bool Fecha::operator<(const Fecha& other) { return false; }
Fecha Fecha::operator++() { return *this; }
Fecha Fecha::operator++(int) { return *this; }
Fecha Fecha::operator+(int dias) { return *this; }
int Fecha::operator-(const Fecha& other) { return 0; }
bool Fecha::esValida() { return false; }
