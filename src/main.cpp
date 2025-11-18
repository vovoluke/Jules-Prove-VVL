#include "../include/CapaLogica.h"
#include "../include/Comun.h"
#include "../include/Becado.h"
#include <iostream>

void imprimirSocio(Socio* s) {
    if (s) {
        std::cout << "Cedula: " << s->getCedula() << ", Nombre: ";
        s->getNombre().print();
        std::cout << ", Tipo: ";
        s->tipoPersona().print();
        std::cout << std::endl;
        if (s->getEntrenador()) {
            std::cout << "  Entrenador: ";
            s->getEntrenador()->getNombre().print();
            std::cout << std::endl;
        }
    }
}

void imprimirEntrenador(Entrenador* e) {
    if (e) {
        std::cout << "Cedula: " << e->getCedula() << ", Nombre: ";
        e->getNombre().print();
        std::cout << ", Salario: " << e->getSalarioBase() << ", Comienzo: "
                  << e->getAnioComienzo().getAnio() << std::endl;
    }
}

int main() {
    CapaLogica logica;
    tipoError error;

    // --- Pruebas ---
    std::cout << "--- Registrando Entrenadores ---" << std::endl;
    Entrenador* e1 = new Entrenador(1, "Juan Perez", 30000, Fecha(1, 1, 2020));
    logica.registrarEntrenador(e1, error);
    if (error == OK) std::cout << "Entrenador 'Juan Perez' registrado." << std::endl;

    Entrenador* e2 = new Entrenador(2, "Maria Garcia", 32000, Fecha(1, 5, 2018));
    logica.registrarEntrenador(e2, error);
    if (error == OK) std::cout << "Entrenador 'Maria Garcia' registrado." << std::endl;

    std::cout << "\n--- Registrando Socios ---" << std::endl;
    Socio* s1 = new Comun(101, "Carlos Sanchez", 1000, "Calle Falsa 123", nullptr, 500);
    logica.registrarSocio(s1, 1, error);
    if (error == OK) std::cout << "Socio 'Carlos Sanchez' registrado." << std::endl;

    Socio* s2 = new Becado(102, "Ana Lopez", 1200, "Avenida Siempreviva 742", nullptr, 50, Fecha(15, 3, 2026));
    logica.registrarSocio(s2, 2, error);
    if (error == OK) std::cout << "Socio 'Ana Lopez' registrada." << std::endl;

    std::cout << "\n--- Listando Entrenadores ---" << std::endl;
    IteradorEntrenadores itE;
    logica.listarEntrenadores(itE);
    while (itE.hayMasEntrenadores()) {
        imprimirEntrenador(itE.proximoEntrenador());
    }

    std::cout << "\n--- Listando Socios ---" << std::endl;
    IteradorSocios itS;
    logica.listarSocios(itS);
    while (itS.hayMasSocios()) {
        imprimirSocio(itS.proximoSocio());
    }

    std::cout << "\n--- Buscando Socio 101 ---" << std::endl;
    Socio* socioEncontrado = logica.listarSocio(101);
    if (socioEncontrado) {
        std::cout << "Socio encontrado:" << std::endl;
        imprimirSocio(socioEncontrado);
    } else {
        std::cout << "Socio no encontrado." << std::endl;
    }

    std::cout << "\n--- Calculando Cuotas (Mes 1) ---" << std::endl;
    float cuotaS1 = logica.calcularMontoMesSocio(1, 101);
    std::cout << "Cuota de Carlos Sanchez (Comun) en Enero: $" << cuotaS1 << std::endl;
    float cuotaS2 = logica.calcularMontoMesSocio(1, 102);
    std::cout << "Cuota de Ana Lopez (Becado) en Enero: $" << cuotaS2 << std::endl;

    std::cout << "\n--- Cantidad de Becados post 1/1/2026 ---" << std::endl;
    int cantBecados = logica.cantBecadosDespuesFecha(Fecha(1, 1, 2026));
    std::cout << "Cantidad: " << cantBecados << std::endl;

    std::cout << "\n--- Entrenadores desde 2019 y promedio salarial ---" << std::endl;
    int cantE = 0;
    float promS = 0.0;
    logica.cantEntrenadoresAndPromedioSalarios(2019, cantE, promS);
    std::cout << "Cantidad: " << cantE << ", Promedio Salarial: $" << promS << std::endl;

    return 0;
}
