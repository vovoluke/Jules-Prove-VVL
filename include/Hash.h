#ifndef HASH_H
#define HASH_H

#include "Entrenador.h"
#include "String.h"
#include <functional>

class Hash {
private:
    static const int TABLE_SIZE = 37;
    struct Nodo {
        Entrenador* entrenador;
        Nodo* sig;
    };
    Nodo* tabla[TABLE_SIZE];

    int hashFunc(long int key);

public:
    Hash();
    ~Hash();
    void insertar(Entrenador*);
    Entrenador* find(long int);
    void inOrder(std::function<void(Entrenador*)>);
};

#endif // HASH_H
