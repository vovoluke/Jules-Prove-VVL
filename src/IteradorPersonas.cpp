#include "../include/IteradorPersonas.h"
#include <cstddef> // For NULL

IteradorPersonas::IteradorPersonas() : inicio(NULL), actual(NULL) {}

IteradorPersonas::~IteradorPersonas() {
    Nodo* current = inicio;
    while (current != NULL) {
        Nodo* next = current->sig;
        delete current;
        current = next;
    }
}

void IteradorPersonas::insertar(Persona* persona) {
    Nodo* nuevo = new Nodo{persona, inicio};
    inicio = nuevo;
    actual = inicio; // Reset 'actual' to the beginning
}

bool IteradorPersonas::hayMasPersonas() {
    return actual != NULL;
}

Persona* IteradorPersonas::proximaPersona() {
    if (!hayMasPersonas()) {
        return NULL;
    }
    Persona* persona = actual->persona;
    actual = actual->sig; // Simply advance the pointer
    return persona;
}
