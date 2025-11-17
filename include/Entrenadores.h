#ifndef ENTRENADORES_H
#define ENTRENADORES_H

#include "Hash.h"
#include "IteradorEntrenadores.h"

class Entrenadores {
private:
    Hash* tabla;

public:
    Entrenadores();
    ~Entrenadores();
    void insert(Entrenador*);
    Entrenador* find(long int);
    void listarEntrenadores(IteradorEntrenadores&);
    void cantEntrenadoresPostAnioAndPromedioSalario(int, int&, float&);
};

#endif // ENTRENADORES_H
