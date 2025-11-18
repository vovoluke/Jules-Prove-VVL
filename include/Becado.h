#ifndef BECADO_H
#define BECADO_H

#include "Socio.h"
#include "Fecha.h"

class Becado : public Socio {
private:
    float porcentaje;
    Fecha fechaOtorgada;

public:
    Becado();
    ~Becado();
    Becado(long int, String, float, String, Entrenador*, float, Fecha);
    float getPorcentaje();
    Fecha getFechaOtorgada();
    void setFechaOtorgada(Fecha);
    float cuotaMensual() override;
};

#endif // BECADO_H
