#include "../include/CapaLogica.h"

CapaLogica::CapaLogica() {
    diccioSocios = new Socios();
    diccioEntrenadores = new Entrenadores();
}

CapaLogica::~CapaLogica() {
    delete diccioSocios;
    delete diccioEntrenadores;
}

// Requerimiento 1
void CapaLogica::registrarEntrenador(Entrenador* entrenador, tipoError& error) {
    if (diccioEntrenadores->find(entrenador->getCedula())) {
        error = ERROR_ENTRENADOR_YA_EXISTE;
    } else if (diccioSocios->member(entrenador->getCedula())) {
        error = ERROR_SOCIO_YA_EXISTE;
    } else {
        diccioEntrenadores->insert(entrenador);
        error = OK;
    }
}

// Requerimiento 2
void CapaLogica::registrarSocio(Socio* socio, long int cedulaEntrenador, tipoError& error) {
    if (diccioSocios->member(socio->getCedula())) {
        error = ERROR_SOCIO_YA_EXISTE;
    } else if (diccioEntrenadores->find(socio->getCedula())) {
        error = ERROR_ENTRENADOR_YA_EXISTE;
    } else {
        Entrenador* e = diccioEntrenadores->find(cedulaEntrenador);
        if (e) {
            socio->setEntrenador(e);
            diccioSocios->insert(socio);
            error = OK;
        } else {
            error = ERROR_ENTRENADOR_NO_EXISTE;
        }
    }
}

// Requerimiento 3
void CapaLogica::listarEntrenadores(IteradorEntrenadores& iter) {
    diccioEntrenadores->listarEntrenadores(iter);
}

// Requerimiento 4
void CapaLogica::listarSocios(IteradorSocios& iter) {
    diccioSocios->listarSocios(iter);
}

// Requerimiento 5
Socio* CapaLogica::listarSocio(long int cedula) {
    return diccioSocios->find(cedula);
}

// Requerimiento 6
float CapaLogica::calcularMontoMesSocio(int mes, long int cedula) {
    return diccioSocios->cuotaMensualSocio(mes, cedula);
}

// Requerimiento 7
float CapaLogica::calcularTotalMesSocios(int mes) {
    return diccioSocios->calcularTotalMesSocios(mes);
}

// Requerimiento 8
int CapaLogica::cantBecadosDespuesFecha(Fecha fecha) {
    return diccioSocios->cantBecadosDespuesFecha(fecha);
}

// Requerimiento 9
void CapaLogica::cantEntrenadoresAndPromedioSalarios(int anio, int& cant, float& prom) {
    diccioEntrenadores->cantEntrenadoresPostAnioAndPromedioSalario(anio, cant, prom);
}

// Requerimiento 10
void CapaLogica::socioConMayorCuota(int mes, IteradorSocios& iter) {
    Socio* s = diccioSocios->socioConMayorCuota(mes);
    if (s) {
        iter.insertar(s);
    }
}
