#include "../include/ABB.h"
#include <cstddef> // For NULL

ABB::ABB() : raiz(NULL) {}

ABB::~ABB() {
    destruir(raiz);
}

void ABB::destruir(Nodo* nodo) {
    if (nodo) {
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo->socio; // Also delete the socio
        delete nodo;
    }
}

int ABB::altura(Nodo* n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int ABB::getBalance(Nodo* n) {
    if (n == NULL)
        return 0;
    return altura(n->izq) - altura(n->der);
}

ABB::Nodo* ABB::rightRotate(Nodo* y) {
    Nodo* x = y->izq;
    Nodo* T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = std::max(altura(y->izq), altura(y->der)) + 1;
    x->altura = std::max(altura(x->izq), altura(x->der)) + 1;

    return x;
}

ABB::Nodo* ABB::leftRotate(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = std::max(altura(x->izq), altura(x->der)) + 1;
    y->altura = std::max(altura(y->izq), altura(y->der)) + 1;

    return y;
}

void ABB::insertar(Socio* socio) {
    raiz = insertar(raiz, socio);
}

ABB::Nodo* ABB::insertar(Nodo* nodo, Socio* socio) {
    if (nodo == NULL) {
        Nodo* temp = new Nodo();
        temp->socio = socio;
        temp->izq = NULL;
        temp->der = NULL;
        temp->altura = 1;
        return temp;
    }

    if (socio->getCedula() < nodo->socio->getCedula())
        nodo->izq = insertar(nodo->izq, socio);
    else if (socio->getCedula() > nodo->socio->getCedula())
        nodo->der = insertar(nodo->der, socio);
    else
        return nodo; // Duplicate cedula not allowed

    nodo->altura = 1 + std::max(altura(nodo->izq), altura(nodo->der));

    int balance = getBalance(nodo);

    // Left Left Case
    if (balance > 1 && socio->getCedula() < nodo->izq->socio->getCedula())
        return rightRotate(nodo);

    // Right Right Case
    if (balance < -1 && socio->getCedula() > nodo->der->socio->getCedula())
        return leftRotate(nodo);

    // Left Right Case
    if (balance > 1 && socio->getCedula() > nodo->izq->socio->getCedula()) {
        nodo->izq = leftRotate(nodo->izq);
        return rightRotate(nodo);
    }

    // Right Left Case
    if (balance < -1 && socio->getCedula() < nodo->der->socio->getCedula()) {
        nodo->der = rightRotate(nodo->der);
        return leftRotate(nodo);
    }

    return nodo;
}

Socio* ABB::find(long int cedula) {
    return find(raiz, cedula);
}

Socio* ABB::find(Nodo* nodo, long int cedula) {
    if (nodo == NULL || nodo->socio->getCedula() == cedula)
        return nodo ? nodo->socio : NULL;

    if (cedula < nodo->socio->getCedula())
        return find(nodo->izq, cedula);
    else
        return find(nodo->der, cedula);
}

bool ABB::member(long int cedula) {
    return member(raiz, cedula);
}

bool ABB::member(Nodo* nodo, long int cedula) {
    if (nodo == NULL)
        return false;
    if (nodo->socio->getCedula() == cedula)
        return true;
    if (cedula < nodo->socio->getCedula())
        return member(nodo->izq, cedula);
    else
        return member(nodo->der, cedula);
}

void ABB::inOrder(std::function<void(Socio*)> func) {
    inOrder(raiz, func);
}

void ABB::inOrder(Nodo* nodo, std::function<void(Socio*)> func) {
    if (nodo != NULL) {
        inOrder(nodo->izq, func);
        func(nodo->socio);
        inOrder(nodo->der, func);
    }
}
