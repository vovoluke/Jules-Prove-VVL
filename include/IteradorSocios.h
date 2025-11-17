#ifndef ITERADORSOCIOS_H
#define ITERADORSOCIOS_H

#include "Socio.h"

class IteradorSocios {
private:
    struct Nodo {
        Socio* socio;
        Nodo* sig;
    };
    Nodo* actual;

public:
    IteradorSocios();
    void insertar(Socio*);
    bool hayMasSocios();
    Socio* proximoSocio();
};

#endif // ITERADORSOCIOS_H
