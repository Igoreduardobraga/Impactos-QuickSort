#ifndef REGISTRO_H
#define REGISTRO_H

class Registro{
    public:
        Registro() {  };
        char string;
        int key = 0;
        bool operator<=(const Registro& outroRegistro);
        bool operator<(const Registro& outroRegistro);
        bool operator>=(const Registro& outroRegistro);
        bool operator>(const Registro& outroRegistro);
};

#endif