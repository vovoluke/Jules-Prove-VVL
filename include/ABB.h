#ifndef ABB_H
#define ABB_H

#include "Socio.h"

class ABB {
private:
    struct Nodo {
        Socio* socio;
        Nodo* izq;
        Nodo* der;
    };
    Nodo* raiz;

public:
    ABB();
    ~ABB();
    void insertar(Socio*);
    bool member(long int);
    Socio* find(long int);
};

#endif // ABB_H
