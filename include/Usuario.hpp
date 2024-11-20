#pragma once

// #include "Playlist.hpp"
#include <iostream>
#include <vector>

using namespace std;

// class Playlist; 

class Usuario
{
    public:
        Usuario();
        Usuario(string);

        // void agregarPlaylist(Playlist*);
        // void eliminarPlaylist(string);

        void mostrarPlaylists();

        string getNombre();
        void setNombre(string);

    protected:
        string nombre;
        // vector<Playlist> playlists;

};