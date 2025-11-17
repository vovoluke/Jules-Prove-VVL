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
    Becado(long int, std::string, float, std::string, Entrenador*, float, Fecha);
    float getPorcentaje();
    Fecha getFechaOtorgada();
    float cuotaMensual() override;
};

#endif // BECADO_H
