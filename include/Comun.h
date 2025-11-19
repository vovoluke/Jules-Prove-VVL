#ifndef COMUN_H
#define COMUN_H

#include "Socio.h"

class Comun : public Socio {
private:
    float extra;

public:
    Comun();
    ~Comun();
    Comun(long int, String, float, String, Entrenador*, float);
    float getExtra();
    float cuotaMensual() override;
};

#endif // COMUN_H
