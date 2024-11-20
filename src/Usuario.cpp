#include "Usuario.hpp"

Usuario::Usuario()
{
    this->nombre = "";
}

Usuario::Usuario(string nombre)
{
    this->nombre = nombre;
}

string Usuario::getNombre()
{
    return nombre;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

