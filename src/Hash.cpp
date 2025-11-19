#include "../include/Hash.h"
#include <cstddef> // For NULL

int Hash::hashFunc(long int key) {
    return key % TABLE_SIZE;
}

Hash::Hash() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        tabla[i] = NULL;
    }
}

Hash::~Hash() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Nodo* actual = tabla[i];
        while (actual != NULL) {
            Nodo* aBorrar = actual;
            actual = actual->sig;
            delete aBorrar->entrenador;
            delete aBorrar;
        }
    }
}

void Hash::insertar(Entrenador* entrenador) {
    int index = hashFunc(entrenador->getCedula());
    Nodo* nuevoNodo = new Nodo{entrenador, NULL};

    if (tabla[index] == NULL) {
        tabla[index] = nuevoNodo;
    } else {
        nuevoNodo->sig = tabla[index];
        tabla[index] = nuevoNodo;
    }
}

Entrenador* Hash::find(long int cedula) {
    int index = hashFunc(cedula);
    Nodo* actual = tabla[index];
    while (actual != NULL) {
        if (actual->entrenador->getCedula() == cedula) {
            return actual->entrenador;
        }
        actual = actual->sig;
    }
    return NULL;
}

void Hash::inOrder(std::function<void(Entrenador*)> func) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Nodo* actual = tabla[i];
        while (actual != NULL) {
            func(actual->entrenador);
            actual = actual->sig;
        }
    }
}
