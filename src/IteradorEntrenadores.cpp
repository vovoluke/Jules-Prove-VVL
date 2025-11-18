#include "../include/IteradorEntrenadores.h"
#include <cstddef> // For NULL

IteradorEntrenadores::IteradorEntrenadores() : inicio(NULL), actual(NULL) {}

IteradorEntrenadores::~IteradorEntrenadores() {
    Nodo* current = inicio;
    while (current != NULL) {
        Nodo* next = current->sig;
        delete current;
        current = next;
    }
}

void IteradorEntrenadores::insertar(Entrenador* entrenador) {
    Nodo* nuevo = new Nodo{entrenador, inicio};
    inicio = nuevo;
    actual = inicio; // Reset 'actual' to the beginning
}

bool IteradorEntrenadores::hayMasEntrenadores() {
    return actual != NULL;
}

Entrenador* IteradorEntrenadores::proximoEntrenador() {
    if (!hayMasEntrenadores()) {
        return NULL;
    }
    Entrenador* entrenador = actual->entrenador;
    actual = actual->sig; // Simply advance the pointer
    return entrenador;
}
