#ifndef HASH_H
#define HASH_H

#include "Entrenador.h"

class Hash {
private:
    struct Nodo {
        Entrenador* entrenador;
        Nodo* sig;
    };
    Nodo** tabla;
    int capacidad;

public:
    Hash();
    ~Hash();
    void insertar(Entrenador*);
    bool member(std::string);
    Entrenador* find(std::string);
};

#endif // HASH_H
