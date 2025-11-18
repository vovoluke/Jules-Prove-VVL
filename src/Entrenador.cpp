#include "../include/Entrenador.h"

Entrenador::Entrenador() : Persona(), salarioBase(0.0), anioComienzo() {}

Entrenador::~Entrenador() {}

Entrenador::Entrenador(long int ci, String n, float sb, Fecha ac) : Persona(ci, n), salarioBase(sb), anioComienzo(ac) {}

float Entrenador::getSalarioBase() {
    return salarioBase;
}

Fecha Entrenador::getAnioComienzo() {
    return anioComienzo;
}

void Entrenador::setAnioComienzo(Fecha ac) {
    anioComienzo = ac;
}

String Entrenador::tipoPersona() {
    return String("Entrenador");
}
