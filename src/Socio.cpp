#include "../include/Socio.h"

Socio::Socio() : Persona(), cuotaBase(0.0), domicilio(""), entrenador(nullptr) {}

Socio::~Socio() {}

Socio::Socio(long int ci, String n, float cb, String dom, Entrenador* e) : Persona(ci, n), cuotaBase(cb), domicilio(dom), entrenador(e) {}

float Socio::getCuotaBase() {
    return cuotaBase;
}

String Socio::getDomicilio() {
    return domicilio;
}

Entrenador* Socio::getEntrenador() {
    return entrenador;
}

void Socio::setEntrenador(Entrenador* e) {
    entrenador = e;
}

String Socio::tipoPersona() {
    return String("Socio");
}
