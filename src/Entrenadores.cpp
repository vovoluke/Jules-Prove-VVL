#include "../include/Entrenadores.h"

Entrenadores::Entrenadores() {
    tabla = new Hash();
}

Entrenadores::~Entrenadores() {
    delete tabla;
}

void Entrenadores::insert(Entrenador* entrenador) {
    tabla->insertar(entrenador);
}

Entrenador* Entrenadores::find(long int cedula) {
    return tabla->find(cedula);
}

void Entrenadores::listarEntrenadores(IteradorEntrenadores& iter) {
    tabla->inOrder([&iter](Entrenador* e) {
        iter.insertar(e);
    });
}

void Entrenadores::cantEntrenadoresPostAnioAndPromedioSalario(int anio, int& cant, float& prom) {
    int count = 0;
    float totalSalario = 0.0;

    tabla->inOrder([&](Entrenador* e) {
        if (e->getAnioComienzo().getAnio() >= anio) {
            count++;
            totalSalario += e->getSalarioBase();
        }
    });

    cant = count;
    if (cant > 0) {
        prom = totalSalario / cant;
    } else {
        prom = 0.0;
    }
}
