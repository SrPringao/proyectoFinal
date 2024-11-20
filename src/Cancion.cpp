#include "Cancion.hpp"

Cancion::Cancion()
{
    this->genero = "";
    this->album = "";
    this->artista = nullptr;
}

Cancion::Cancion(string titulo, int duracion,string album, string genero, Artista* artista) : Multimedia(titulo,duracion) {
    this->genero = genero;
    this->album = album;
    this->artista = artista;
}


void Cancion::mostrarInfo() {
    cout << "Titulo: " << getTitulo() << endl;
    cout << "Genero: " << genero << endl;
    cout << "Album: " << album << endl;
    cout << "Artista: " << artista->getNombre() << endl;
}

string Cancion::getGenero() {
    return genero;
}

void Cancion::setGenero(string genero) {
    this->genero = genero;
}

string Cancion::getAlbum() {
    return album;
}

void Cancion::setAlbum(string album) {
    this->album = album;
}

Artista* Cancion::getArtista() {
    return artista;
}

void Cancion::setArtista(Artista* artista) {
    this->artista = artista;
}
