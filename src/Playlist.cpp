#include "Playlist.hpp"

Playlist::Playlist()
{
     this->canciones = vector<Cancion*>(); //vector vacio
}

void Playlist::agregarCancion(Cancion* cancion)
{
    canciones.push_back(cancion);
}

void Playlist::mostrarInfo()
{
    cout << "Playlist: " << getTitulo() << endl;
    for (int i = 0; i < canciones.size(); i++)
    {
        cout << i+1 << ". ";
        canciones[i]->mostrarInfo();
    }
}
