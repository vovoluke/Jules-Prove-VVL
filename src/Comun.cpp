#include "../include/Comun.h"

Comun::Comun() : Socio(), extra(0.0) {}

Comun::~Comun() {}

Comun::Comun(long int ci, String n, float cb, String dom, Entrenador* e, float ex) : Socio(ci, n, cb, dom, e), extra(ex) {}

float Comun::getExtra() {
    return extra;
}

float Comun::cuotaMensual() {
    float cuotaBase = getCuotaBase();
    float total = 0;

    if (extra > cuotaBase) {
        total = extra;
    } else if (extra <= (cuotaBase * 0.75) && extra > (cuotaBase * 0.25)) {
        total = cuotaBase + extra;
    } else if (extra <= (cuotaBase * 0.25)) {
        total = cuotaBase + (extra / 2);
    } else { // This case handles extra between 75% and 100%
        total = cuotaBase + extra;
    }
    return total;
}
