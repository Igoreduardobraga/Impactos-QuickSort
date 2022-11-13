#include "Registro.hpp"

bool Registro::operator<=(const Registro& outroRegistro) {
    return (this->key <= outroRegistro.key);
}

bool Registro::operator<(const Registro& outroRegistro) {
    return (this->key < outroRegistro.key);
}

bool Registro::operator>=(const Registro& outroRegistro) {
    return (this->key >= outroRegistro.key);
}

bool Registro::operator>(const Registro& outroRegistro) {
    return (this->key > outroRegistro.key);
}
