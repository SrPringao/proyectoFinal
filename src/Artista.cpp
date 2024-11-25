#include "Artista.hpp"

Artista::Artista()
{
    this->regalias = 0;
    this->canciones = vector<Cancion>();
}

Artista::Artista(string nombre, int edad, string genero, string pais, float regalias) : Usuario(nombre, edad, genero, pais)
{
    this->regalias = regalias;
}

void Artista::mostrarInfo()
{
    cout<<"Tipo de usuario: Artista"<<endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Genero: " << genero << endl;
    cout << "Pais: " << pais << endl;
    cout << "Regalias: " << regalias << endl;
}