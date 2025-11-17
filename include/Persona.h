#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    long int cedula;
    std::string nombre;

public:
    Persona();
    virtual ~Persona();
    Persona(long int, std::string);
    long int getCedula();
    std::string getNombre();
    virtual std::string tipoPersona() = 0; // Pure virtual function
};

#endif // PERSONA_H
