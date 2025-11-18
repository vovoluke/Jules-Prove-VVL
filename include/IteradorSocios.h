#ifndef ITERADORSOCIOS_H
#define ITERADORSOCIOS_H

#include "Socio.h"

class IteradorSocios {
private:
    struct Nodo {
        Socio* socio;
        Nodo* sig;
    };
    Nodo* inicio;
    Nodo* actual;

public:
    IteradorSocios();
    ~IteradorSocios();
    void insertar(Socio*);
    bool hayMasSocios();
    Socio* proximoSocio();
};

#endif // ITERADORSOCIOS_H
