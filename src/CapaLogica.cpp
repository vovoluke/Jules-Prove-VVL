#include "../include/CapaLogica.h"

CapaLogica::CapaLogica() {}
void CapaLogica::registrarEntrenador(Entrenador* entrenador, tipoError& error) {}
void CapaLogica::registrarSocio(Socio* socio, long int cedulaEntrenador, tipoError& error) {}
void CapaLogica::listarEntrenadores(IteradorEntrenadores& iter) {}
void CapaLogica::listarSocios(IteradorSocios& iter) {}
Socio* CapaLogica::listarSocio(long int cedula) { return nullptr; }
float CapaLogica::calcularMontoMesSocio(int anio, long int cedula) { return 0.0; }
float CapaLogica::calcularTotalMesSocios(int anio) { return 0.0; }
int CapaLogica::cantBecadosDespuesFecha(Fecha fecha) { return 0; }
void CapaLogica::cantEntrenadoresAndPromedioSalarios(int anio, int& cant, float& prom) {}
void CapaLogica::socioConMayorCuota(long int anio, IteradorSocios& iter) {}
