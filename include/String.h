#ifndef STR_H
#define STR_H

#include "boolean.h"

class String {
private:
    char* cadena;

public:
    String();
    String(const char* s);
    String(const String&);
    ~String();
    String operator=(const String&);
    boolean operator==(const String&);
    boolean operator<(const String&);
    String operator+(const String&);
    void scan();
    void print();
    const char* getCadena() const;
};

#endif // STR_H
