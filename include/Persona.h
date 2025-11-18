#ifndef PERSONA_H
#define PERSONA_H

#include "String.h"

class Persona {
private:
    long int cedula;
    String nombre;

public:
    Persona();
    virtual ~Persona();
    Persona(long int, String);
    long int getCedula();
    String getNombre();
    virtual String tipoPersona() = 0; // Pure virtual function
};

#endif // PERSONA_H
