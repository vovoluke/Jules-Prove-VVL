#include "../include/IteradorSocios.h"
#include <cstddef> // For NULL

IteradorSocios::IteradorSocios() : inicio(NULL), actual(NULL) {}

IteradorSocios::~IteradorSocios() {
    Nodo* current = inicio;
    while (current != NULL) {
        Nodo* next = current->sig;
        delete current;
        current = next;
    }
}

void IteradorSocios::insertar(Socio* socio) {
    Nodo* nuevo = new Nodo{socio, inicio};
    inicio = nuevo;
    actual = inicio; // Reset 'actual' to the beginning
}

bool IteradorSocios::hayMasSocios() {
    return actual != NULL;
}

Socio* IteradorSocios::proximoSocio() {
    if (!hayMasSocios()) {
        return NULL;
    }
    Socio* socio = actual->socio;
    actual = actual->sig; // Simply advance the pointer
    return socio;
}
