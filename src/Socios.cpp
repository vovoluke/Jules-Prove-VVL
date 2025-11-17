#include "../include/Socios.h"
#include "../include/Becado.h"

Socios::Socios() {
    arbol = new ABB();
}

Socios::~Socios() {
    delete arbol;
}

bool Socios::member(long int cedula) {
    return arbol->member(cedula);
}

void Socios::insert(Socio* socio) {
    arbol->insertar(socio);
}

Socio* Socios::find(long int cedula) {
    return arbol->find(cedula);
}

void Socios::listarSocios(IteradorSocios& iter) {
    arbol->inOrder([&iter](Socio* s) {
        iter.insertar(s);
    });
}

float Socios::cuotaMensualSocio(int mes, long int cedula) {
    Socio* s = find(cedula);
    if (!s) return 0.0;

    float cuota = s->cuotaMensual();

    if (mes == 1 || mes == 2) {
        if (dynamic_cast<Becado*>(s)) {
            cuota *= 0.70; // 30% discount
        } else {
            cuota *= 0.80; // 20% discount
        }
    }
    return cuota;
}

float Socios::calcularTotalMesSocios(int mes) {
    float total = 0.0;
    arbol->inOrder([&](Socio* s) {
        total += cuotaMensualSocio(mes, s->getCedula());
    });
    return total;
}

Socio* Socios::socioConMayorCuota(int mes) {
    Socio* socioMax = nullptr;
    float maxCuota = -1.0;

    arbol->inOrder([&](Socio* s) {
        float cuota = cuotaMensualSocio(mes, s->getCedula());
        if (cuota > maxCuota) {
            maxCuota = cuota;
            socioMax = s;
        }
    });
    return socioMax;
}

int Socios::cantBecadosDespuesFecha(Fecha fecha) {
    int count = 0;
    arbol->inOrder([&](Socio* s) {
        Becado* b = dynamic_cast<Becado*>(s);
        if (b && b->getFechaOtorgada() > fecha) {
            count++;
        }
    });
    return count;
}
