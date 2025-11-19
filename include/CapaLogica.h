#ifndef CAPALOGICA_H
#define CAPALOGICA_H

#include "Socios.h"
#include "Entrenadores.h"
#include "tipoError.h"
#include "IteradorPersonas.h"

class CapaLogica {
private:
    Socios* diccioSocios;
    Entrenadores* diccioEntrenadores;

public:
    CapaLogica();
    ~CapaLogica();
    void registrarEntrenador(Entrenador*, tipoError&);
    void registrarSocio(Socio*, long int, tipoError&);
    void listarEntrenadores(IteradorPersonas&);
    void listarSocios(IteradorPersonas&);
    Socio* listarSocio(long int);
    float calcularMontoMesSocio(int, long int);
    float calcularTotalMesSocios(int);
    int cantBecadosDespuesFecha(Fecha);
    void cantEntrenadoresAndPromedioSalarios(int, int&, float&);
    void socioConMayorCuota(int, IteradorPersonas&);
};

#endif // CAPALOGICA_H
