#pragma once

#include "Multimedia.hpp"
#include "Artista.hpp"

#include <iostream>

class Artista;
using namespace std;

class Cancion:public Multimedia
{
    protected:
        string genero;
        string album;
        Artista* artista;
    public:
        Cancion();
        Cancion(string,int,string,string, Artista*);

        void mostrarInfo() override;

        string getGenero();
        void setGenero(string);

        string getAlbum();
        void setAlbum(string);

        Artista* getArtista();
        void setArtista(Artista*);
        
        friend istream& operator>>(istream& input, Cancion& cancion);

    
};