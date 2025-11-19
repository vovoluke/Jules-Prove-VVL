#ifndef ITERADORPERSONAS_H
#define ITERADORPERSONAS_H

#include "Persona.h"

class IteradorPersonas {
private:
    struct Nodo {
        Persona* persona;
        Nodo* sig;
    };
    Nodo* inicio;
    Nodo* actual;

public:
    IteradorPersonas();
    ~IteradorPersonas();
    void insertar(Persona*);
    bool hayMasPersonas();
    Persona* proximaPersona();
};

#endif // ITERADORPERSONAS_H
