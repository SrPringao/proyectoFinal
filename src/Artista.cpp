#include "Artista.hpp"
#include <iostream>


Artista::Artista() : Usuario()
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

void Artista::agregarCancion(Cancion cancion)
{
    canciones.push_back(cancion);
}

void Artista::verCanciones()
{
    for (int i = 0; i < canciones.size(); ++i)
    {
        cout << i + 1 << ". " << canciones[i].getTitulo() << endl;
    }
}

void Artista::operator+(Cancion cancion)
{
    canciones.push_back(cancion);
    
}

istream& operator>>(istream& input, Artista& artista)
{
    cout << "Nombre: ";
    input >> artista.nombre;
    cout << "Edad: ";
    input >> artista.edad;
    cout << "Genero: ";
    input >> artista.genero;
    cout << "Pais: ";
    input >> artista.pais;
    cout << "Regalias: ";
    input >> artista.regalias;

    return input;
}

