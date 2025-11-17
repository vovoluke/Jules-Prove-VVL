#ifndef CAPALOGICA_H
#define CAPALOGICA_H

#include "Socios.h"
#include "Entrenadores.h"
#include "tipoError.h"

class CapaLogica {
private:
    Socios* diccioSocios;
    Entrenadores* diccioEntrenadores;

public:
    CapaLogica();
    void registrarEntrenador(Entrenador*, tipoError&);
    void registrarSocio(Socio*, long int, tipoError&);
    void listarEntrenadores(IteradorEntrenadores&);
    void listarSocios(IteradorSocios&);
    Socio* listarSocio(long int);
    float calcularMontoMesSocio(int, long int);
    float calcularTotalMesSocios(int);
    int cantBecadosDespuesFecha(Fecha);
    void cantEntrenadoresAndPromedioSalarios(int, int&, float&);
    void socioConMayorCuota(long int, IteradorSocios&);
};

#endif // CAPALOGICA_H
