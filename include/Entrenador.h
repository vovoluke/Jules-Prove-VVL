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
    Entrenador(long int, String, float, Fecha);
    float getSalarioBase();
    Fecha getAnioComienzo();
    void setAnioComienzo(Fecha);
    String tipoPersona() override;
};

#endif // ENTRENADOR_H
