#include <iostream>

#include "Usuario.hpp"
#include "Playlist.hpp"
#include "Cancion.hpp"
#include "Artista.hpp"
#include "Multimedia.hpp"

using namespace std;

int main() {
    cout << "Bienvenido" << endl;
    cout << "Menu" << endl;
    cout << "1. Crear usuario" << endl;
    cout << "2. Eliminar usuario" << endl;
    cout << "3. Crear playlist" << endl;
    cout << "4. Eliminar playlist" << endl;
    cout << "5. Agregar cancion a playlist" << endl;
    cout << "6. Eliminar cancion de playlist" << endl;
    cout << "7. Mostrar playlists" << endl;
    cout << "8. Buscar cancion" << endl;
    cout << "9. Salir" << endl;

    int opcion;
    cin >> opcion;
    switch(opcion){
        case 1: {
            cout << "Ingrese el nombre del usuario" << endl;
            string nombre;
            cin >> nombre;
            Usuario* usuario = new Usuario(nombre);

            cout << usuario->getNombre() << endl;
            break;
        }
        // case 2:
        //     cout << "Ingrese el nombre del usuario" << endl;
        //     string nombre;
        //     cin >> nombre;
        //     usuario->eliminarUsuario(nombre);
        //     break;
        // case 3:
        //     cout << "Ingrese el nombre de la playlist" << endl;
        //     string nombre;
        //     cin >> nombre;
        //     Playlist* playlist = new Playlist(nombre);
        //     usuario->agregarPlaylist(playlist);
        //     break;
        // case 4:
        //     cout << "Ingrese el nombre de la playlist" << endl;
        //     string nombre;
        //     cin >> nombre;
        //     usuario->eliminarPlaylist(nombre);
        //     break;
        // case 5:
        //     cout << "Ingrese el nombre de la playlist" << endl;
        //     string nombre;
        //     cin >> nombre;
        //     Playlist* playlist = usuario->buscarPlaylist(nombre);
        //     cout << "Ingrese el nombre de la cancion" << endl;
        //     string nombreCancion;
        //     cin >> nombreCancion;
        //     Cancion* cancion = usuario->buscarCancion(nombreCancion);
        //     playlist->agregarCancion(cancion);
        //     break;
        // case 6:
        //     cout << "Ingrese el nombre de la playlist" << endl;
        //     string nombre;
        //     cin >> nombre;
        //     Playlist* playlist = usuario->buscarPlaylist(nombre);
        //     cout << "Ingrese el nombre de la cancion" << endl;
        //     string nombreCancion;
        //     cin >> nombreCancion;
        //     playlist->eliminarCancion(nombreCancion);
        //     break;
        // case 7:
        //     usuario->mostrarPlaylists();
        //     break;
        // case 8:
        //     cout << "Ingrese el nombre de la cancion" << endl;
        //     string nombreCancion;
        //     cin >> nombreCancion;
        //     usuario->buscarCancion(nombreCancion);
        //     break;
        case 9:
            cout << "Adios" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }

    return 0;
}