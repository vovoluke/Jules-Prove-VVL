#include "../include/Becado.h"

Becado::Becado() : Socio(), porcentaje(0.0), fechaOtorgada() {}

Becado::~Becado() {}

Becado::Becado(long int ci, String n, float cb, String dom, Entrenador* e, float p, Fecha fo) : Socio(ci, n, cb, dom, e), porcentaje(p), fechaOtorgada(fo) {}

float Becado::getPorcentaje() {
    return porcentaje;
}

Fecha Becado::getFechaOtorgada() {
    return fechaOtorgada;
}

void Becado::setFechaOtorgada(Fecha fo) {
    fechaOtorgada = fo;
}

float Becado::cuotaMensual() {
    float cuotaBase = getCuotaBase();
    float descuento = 0;
    Fecha fechaLimite(28, 2, 2025);

    if (fechaOtorgada > fechaLimite) {
        descuento = cuotaBase * (porcentaje / 100);
    } else {
        descuento = cuotaBase * ((porcentaje / 2) / 100);
    }

    float total = cuotaBase - descuento;
    return total;
}
