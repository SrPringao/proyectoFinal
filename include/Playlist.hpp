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
        Playlist(vector<Cancion*>, string, int);

        void agregarCancion(Cancion*);
        void eliminarCancion(string);

        void mostrarInfo() override;

        //sobrecarga de operador mas para agregar una cancion
        void operator+(Cancion* cancion);

        friend istream& operator>>(istream& input, Playlist& playlist);
        

    protected:
        vector<Cancion*> canciones;

};