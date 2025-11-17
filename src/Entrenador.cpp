#include "../include/Entrenador.h"

Entrenador::Entrenador() {}
Entrenador::~Entrenador() {}
Entrenador::Entrenador(long int cedula, std::string nombre, float salarioBase, Fecha anioComienzo) {}
float Entrenador::getSalarioBase() { return 0.0; }
Fecha Entrenador::getAnioComienzo() { return Fecha(); }
std::string Entrenador::tipoPersona() { return "Entrenador"; }
