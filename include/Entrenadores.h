#ifndef ENTRENADORES_H
#define ENTRENADORES_H

#include "Hash.h"
#include "IteradorPersonas.h"

class Entrenadores {
private:
    Hash* tabla;

public:
    Entrenadores();
    ~Entrenadores();
    void insert(Entrenador*);
    Entrenador* find(long int);
    void listarEntrenadores(IteradorPersonas&);
    void cantEntrenadoresPostAnioAndPromedioSalario(int, int&, float&);
};

#endif // ENTRENADORES_H
