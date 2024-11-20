#include "Multimedia.hpp"
Multimedia::Multimedia()
{
    titulo = "Sin titulo";
    duracion = 120;
}

Multimedia::Multimedia(string titulo, int duracion)
{
    this->titulo = titulo;
    this->duracion = duracion;

}

string Multimedia::getTitulo(){
return titulo;
}

void Multimedia::setTitulo(string titulo)
{
    this->titulo = titulo;
}

int Multimedia::getDuracion()
{
    return duracion;
}

void Multimedia::setDuracion(int duracion)
{
    this->duracion = duracion;
}

void Multimedia::mostrarInfo()
{
    cout << "Titulo: " << titulo;
    cout << "Duracion: " << duracion<< endl << endl;
}
