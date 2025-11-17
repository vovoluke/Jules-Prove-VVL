#ifndef SOCIO_H
#define SOCIO_H

#include "Persona.h"
#include "Entrenador.h"

class Socio : public Persona {
private:
    float cuotaBase;
    std::string domicilio;
    Entrenador* entrenador;

public:
    Socio();
    ~Socio();
    Socio(long int, std::string, float, std::string, Entrenador*);
    float getCuotaBase();
    std::string getDomicilio();
    Entrenador* getEntrenador();
    virtual float cuotaMensual() = 0; // Pure virtual function
    std::string tipoPersona() override;
};

#endif // SOCIO_H
