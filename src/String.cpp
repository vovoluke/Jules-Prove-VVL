#include "../include/String.h"
#include <iostream>
#include <string.h>

const int MAX = 80;

String::String() {
    cadena = new char[1];
    cadena[0] = '\0';
}

String::String(const char* s) {
    int largo = strlen(s);
    cadena = new char[largo + 1];
    strcpy(cadena, s);
}

String::String(const String& otro) {
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}

String::~String() {
    delete[] cadena;
}

String String::operator=(const String& otro) {
    if (this != &otro) {
        delete[] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char[largo + 1];
        strcpy(cadena, otro.cadena);
    }
    return *this;
}

boolean String::operator==(const String& otro) {
    return (boolean)(strcmp(cadena, otro.cadena) == 0);
}

boolean String::operator<(const String& otro) {
    return (boolean)(strcmp(cadena, otro.cadena) < 0);
}

String String::operator+(const String& otro) {
    String aux;
    delete[] aux.cadena; // Delete the default allocated string
    int largo1 = strlen(cadena);
    int largo2 = strlen(otro.cadena);
    aux.cadena = new char[largo1 + largo2 + 1];
    strcpy(aux.cadena, cadena);
    strcat(aux.cadena, otro.cadena);
    return aux;
}

void String::scan() {
    char aux[MAX];
    char c = std::cin.get();
    int i = 0;
    while (c != '\n' && i < MAX - 1) {
        aux[i] = c;
        i++;
        c = std::cin.get();
    }
    aux[i] = '\0';
    delete[] cadena;
    cadena = new char[i + 1];
    strcpy(cadena, aux);
}

void String::print() {
    std::cout << cadena;
}

const char* String::getCadena() const {
    return cadena;
}
