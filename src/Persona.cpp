#include "../include/Persona.h"

Persona::Persona() : cedula(0), nombre("") {}

Persona::~Persona() {}

Persona::Persona(long int ci, String n) : cedula(ci), nombre(n) {}

long int Persona::getCedula() {
    return cedula;
}

String Persona::getNombre() {
    return nombre;
}
