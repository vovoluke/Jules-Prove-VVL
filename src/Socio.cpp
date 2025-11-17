#include "../include/Socio.h"

Socio::Socio() {}
Socio::~Socio() {}
Socio::Socio(long int cedula, std::string nombre, float cuotaBase, std::string domicilio, Entrenador* entrenador) {}
float Socio::getCuotaBase() { return 0.0; }
std::string Socio::getDomicilio() { return ""; }
Entrenador* Socio::getEntrenador() { return nullptr; }
std::string Socio::tipoPersona() { return "Socio"; }
