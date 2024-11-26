#pragma once

#include <iostream>

using namespace std;

class Multimedia
{
    public:
        Multimedia();
        Multimedia(string, int);

        string getTitulo();
        void setTitulo(string);

        int getDuracion();
        void setDuracion(int);

        virtual void mostrarInfo();

    protected:
        string titulo;
        int duracion;
};
