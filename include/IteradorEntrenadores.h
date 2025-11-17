#ifndef ITERADORENTRENADORES_H
#define ITERADORENTRENADORES_H

#include "Entrenador.h"

class IteradorEntrenadores {
private:
    struct Nodo {
        Entrenador* entrenador;
        Nodo* sig;
    };
    Nodo* actual;

public:
    IteradorEntrenadores();
    void insertar(Entrenador*);
    bool hayMasEntrenadores();
    Entrenador* proximoEntrenador();
};

#endif // ITERADORENTRENADORES_H
