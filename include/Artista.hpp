#pragma once

#include "Usuario.hpp"
#include "Cancion.hpp"


#include <vector>
#include <iostream>

class Cancion; 

class Artista:public Usuario
{
    public:
        Artista();

        void agregarCancion(Cancion*);
        void verCanciones();

    protected:
        float regalias;
        vector<Cancion> canciones;
};
