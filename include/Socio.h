#ifndef SOCIO_H
#define SOCIO_H

#include "Persona.h"
#include "Entrenador.h"

class Socio : public Persona {
private:
    float cuotaBase;
    String domicilio;
    Entrenador* entrenador;

public:
    Socio();
    ~Socio();
    Socio(long int, String, float, String, Entrenador*);
    float getCuotaBase();
    String getDomicilio();
    Entrenador* getEntrenador();
    void setEntrenador(Entrenador*);
    virtual float cuotaMensual() = 0; // Pure virtual function
    String tipoPersona() override;
};

#endif // SOCIO_H
