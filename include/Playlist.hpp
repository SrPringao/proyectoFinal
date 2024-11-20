#pragma once

#include "Cancion.hpp"
#include "Multimedia.hpp"

#include <iostream>
#include <vector>

using namespace std;
class Cancion; 

class Playlist:public Multimedia
{
    public:
        Playlist();

        void agregarCancion(Cancion*);
        void eliminarCancion(string);

        void mostrarInfo() override;

    protected:
        vector<Cancion*> canciones;


};