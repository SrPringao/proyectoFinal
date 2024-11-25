#pragma once

// #include "Playlist.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Playlist; 

class Usuario
{
    public:
        Usuario();
        Usuario(string, int, string, string);

        void agregarPlaylist(Playlist*);
        void eliminarPlaylist(string);

        void mostrarPlaylists();
        virtual void mostrarInfo();

        string getNombre();
        void setNombre(string);

        int getEdad();
        void setEdad(int);

        string getGenero();
        void setGenero(string);

        string getPais();
        void setPais(string);

    protected:
        string nombre;
        int edad;
        string genero;
        string pais;
        vector<Playlist*> playlists;

};