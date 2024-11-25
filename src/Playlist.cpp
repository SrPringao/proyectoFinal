#include "Playlist.hpp"

Playlist::Playlist()
{
     this->canciones = vector<Cancion*>(); //vector vacio
}

Playlist::Playlist(vector<Cancion*> canciones, string titulo, int duracion) : Multimedia(titulo,duracion)
{
    this->canciones = canciones;
}

void Playlist::agregarCancion(Cancion* cancion)
{
    canciones.push_back(cancion);
}

void Playlist::eliminarCancion(string nombre)
{
    for (int i = 0; i < canciones.size(); i++)
    {
        if (canciones[i]->getTitulo() == nombre)
        {
            canciones.erase(canciones.begin() + i);
            return;
        }
    }
    cout << "Cancion no encontrada" << endl;
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
