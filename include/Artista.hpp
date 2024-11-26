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
        Artista(string, int, string, string, float);

        void mostrarInfo() override;

        void agregarCancion(Cancion);
        void verCanciones();

        //sobrecarga de operador mas para agregar una cancion
        
        void operator+(Cancion cancion);

        friend istream& operator>>(istream& input, Artista& artista);

    protected:
        float regalias;
        vector<Cancion> canciones;
};
