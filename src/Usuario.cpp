#include "Usuario.hpp"
#include "Playlist.hpp"

Usuario::Usuario()
{
    this->nombre = "";
    this->edad = 0;
    this->genero = "";
    this->pais = "";
}

Usuario::Usuario(string nombre, int edad, string genero, string pais)
{
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
    this->pais = pais;
}

string Usuario::getNombre()
{
    return nombre;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::mostrarInfo()
{
    cout << "Tipo de usuario: Usuario" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Genero: " << genero << endl;
    cout << "Pais: " << pais << endl;
    
}

int Usuario::getEdad()
{
    return edad;
}

void Usuario::setEdad(int edad)
{
    this->edad = edad;
}

string Usuario::getGenero()
{
    return genero;
}

void Usuario::setGenero(string genero)
{
    this->genero = genero;
}

string Usuario::getPais()
{
    return pais;
}

void Usuario::setPais(string pais)
{
    this->pais = pais;
}

void Usuario::agregarPlaylist(Playlist* playlist)
{
    playlists.push_back(playlist);
}

void Usuario::eliminarPlaylist(string nombre)
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if (playlists[i]->getTitulo() == nombre)
        {
            playlists.erase(playlists.begin() + i);
            cout << "Playlist eliminada" << endl;
            return;
        }
    }
    cout << "Playlist no encontrada" << endl;
}

void Usuario::mostrarPlaylists()
{
    if (playlists.empty())
    {
        cout << "No hay playlists registradas." << endl;
        return;
    }
    cout << "Playlists:" << endl;
    for (int i = 0; i < playlists.size(); i++)
    {
        cout << i + 1 << ". " << playlists[i]->getTitulo() << endl;
    }
}

void Usuario::operator+(Playlist* playlist) {
    playlists.push_back(playlist);
}

void Usuario::operator-(string nombre)
{
    for (int i = 0; i < playlists.size(); i++)
    {
        if (playlists[i]->getTitulo() == nombre)
        {
            playlists.erase(playlists.begin() + i);
            cout << "Playlist eliminada" << endl;
            return;
        }
    }
    cout << "Playlist no encontrada" << endl;
}

istream& operator>>(istream& input, Usuario& usuario)
{
    cout << "Nombre: ";
    input >> usuario.nombre;
    cout << "Edad: ";
    input >> usuario.edad;
    cout << "Genero: ";
    input >> usuario.genero;
    cout << "Pais: ";
    input >> usuario.pais;

    return input;
}