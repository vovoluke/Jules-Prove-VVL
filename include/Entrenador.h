#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include "Persona.h"
#include "Fecha.h"

class Entrenador : public Persona {
private:
    float salarioBase;
    Fecha anioComienzo;

public:
    Entrenador();
    ~Entrenador();
    Entrenador(long int, std::string, float, Fecha);
    float getSalarioBase();
    Fecha getAnioComienzo();
    std::string tipoPersona() override;
};

#endif // ENTRENADOR_H
