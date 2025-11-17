#ifndef ABB_H
#define ABB_H

#include "Socio.h"
#include <algorithm> // For std::max
#include <functional> // For std::function

class ABB {
private:
    struct Nodo {
        Socio* socio;
        Nodo* izq;
        Nodo* der;
        int altura;
    };
    Nodo* raiz;

    int altura(Nodo*);
    int getBalance(Nodo*);
    Nodo* rightRotate(Nodo*);
    Nodo* leftRotate(Nodo*);
    Nodo* insertar(Nodo*, Socio*);
    Socio* find(Nodo*, long int);
    bool member(Nodo*, long int);
    void destruir(Nodo*);
    void inOrder(Nodo*, std::function<void(Socio*)>); // Updated

public:
    ABB();
    ~ABB();
    void insertar(Socio*);
    bool member(long int);
    Socio* find(long int);
    void inOrder(std::function<void(Socio*)>); // Updated
};

#endif // ABB_H
