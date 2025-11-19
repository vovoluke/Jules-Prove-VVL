#ifndef SOCIOS_H
#define SOCIOS_H

#include "ABB.h"
#include "IteradorPersonas.h"

class Socios {
private:
    ABB* arbol;

public:
    Socios();
    ~Socios();
    bool member(long int);
    void insert(Socio*);
    Socio* find(long int);
    void listarSocios(IteradorPersonas&);
    float cuotaMensualSocio(int, long int);
    float calcularTotalMesSocios(int); // Nueva función
    Socio* socioConMayorCuota(int); // Nueva función
    float cuotaMasAlta();
    int cantBecadosDespuesFecha(Fecha);
};

#endif // SOCIOS_H
