#ifndef SOCIOS_H
#define SOCIOS_H

#include "ABB.h"
#include "IteradorSocios.h"

class Socios {
private:
    ABB* arbol;

public:
    Socios();
    ~Socios();
    bool member(long int);
    void insert(Socio*);
    Socio* find(long int);
    void listarSocios(IteradorSocios&);
    float cuotaMensualSocio(int, long int);
    float cuotaMasAlta();
    int cantBecadosDespuesFecha(Fecha);
};

#endif // SOCIOS_H
