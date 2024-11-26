
#include <iostream>
#include <vector>

#include "Usuario.hpp"
#include "Playlist.hpp"
#include "Cancion.hpp"
#include "Artista.hpp"
#include "Multimedia.hpp"

using namespace std;

void listarUsuarios();
void listarPlaylists();
int seleccionarUsuario();
int seleccionarPlaylist();
void menu();

vector<Usuario *> usuarios;
vector<Playlist *> catalogo;

int main()
{
    cout << "\n------Bienvenido------" << endl;
    int opcion;
    usuarios.push_back(new Artista("Juan", 25, "Pop", "MX", 1000));
    usuarios.push_back(new Usuario("Maria", 30, "Femenino", "MX"));
    usuarios.push_back(new Artista("Pedro", 20, "Masculino", "MX", 1000));
    usuarios.push_back(new Usuario("Ana", 25, "Femenino", "MX"));
    usuarios.push_back(new Artista("Luis", 35, "Masculino", "MX", 1000));
    
    catalogo.push_back(new Playlist(vector<Cancion *>(), "Playlist 1", 0));
    catalogo.push_back(new Playlist(vector<Cancion *>(), "Playlist 2", 0));
    catalogo.push_back(new Playlist(vector<Cancion *>(), "Playlist 3", 0));
    catalogo.push_back(new Playlist(vector<Cancion *>(), "Playlist 4", 0));
    catalogo.push_back(new Playlist(vector<Cancion *>(), "Playlist 5", 0));

    catalogo[0]->agregarCancion(new Cancion("Boda", 3, "Album 1", "Pop", dynamic_cast<Artista *>(usuarios[0])));
    catalogo[0]->agregarCancion(new Cancion("Cancion 2", 4, "Siempre", "Rock", dynamic_cast<Artista *>(usuarios[0])));
    catalogo[0]->agregarCancion(new Cancion("Cancion 3", 5, "Nunca", "Pop", dynamic_cast<Artista *>(usuarios[0])));
    catalogo[0]->agregarCancion(new Cancion("Cancion 4", 6, "Quizas", "Rock", dynamic_cast<Artista *>(usuarios[0])));
    do
    {
        menu();
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            system("clear");
            cout << "Creacion de Usuario" << endl;
            cout << "Elige que tipo de usuario deseas crear: " << endl;
            cout << "1. Usuario" << endl;
            cout << "2. Artista\n" << endl;
            int tipoUsuario;
            cin.ignore();
            cout<<"Opcion: "; 
            cin >> tipoUsuario; 

            if (tipoUsuario == 1)
            {
                Usuario *usuario = new Usuario();
                cin >> *usuario;
                usuarios.push_back(usuario);
                cout << "Usuario creado exitosamente." << endl;
            }
            else if (tipoUsuario == 2)
            {
                Artista* artista= new Artista();
                cin >> *artista;
                usuarios.push_back(artista);



                cout << "Artista creado exitosamente." << endl;
            }
            else
            {
                cout << "Opcion invalida." << endl;
            }

            break;
        }
        case 2:
        {
            int userIndex = seleccionarUsuario();

            if (userIndex >= 0 && userIndex < usuarios.size())
            {

                string nombre = usuarios[userIndex]->getNombre();
                usuarios.erase(usuarios.begin() + userIndex); // Eliminar del vector
                cout << "Usuario " << nombre << " eliminado exitosamente." << endl;
                break;
            }
        }
        case 3:
        {
            cout << "Buscar Usuario o Artsta" << endl;
            cout << "Ingrese el nombre del usuario: ";
            string nombre;
            cin >> nombre;

            bool encontrado = false;
            for (int i = 0; i < usuarios.size(); ++i)
            {
                if (usuarios[i]->getNombre() == nombre)
                {
                    cout << "\n------Usuario encontrado...------" << endl;

                    cout << "Menu de usuario" << endl;
                    cout << "1. Mostrar info" << endl;
                    cout << "2. Agregar playlist" << endl;
                    cout << "3. Eliminar playlist" << endl;
                    cout << "4. Salir" << endl;

                    int opcionUsuario;
                    cout<<"Opcion: ";
                    cin >> opcionUsuario;

                    switch (opcionUsuario)
                    {
                    case 1:
                    {
                        usuarios[i]->mostrarInfo();
                        break;
                    }
                    case 2:
                    {
                        cout << "Ingrese el nombre de la playlist: ";
                        string nombre;
                        cin >> nombre;
                        Playlist *playlist = new Playlist(vector<Cancion *>(), nombre, 0);
                        (*usuarios[i])+ playlist;
                        //usuarios[i]->agregarPlaylist(playlist);
                        break;
                    }
                    case 3:
                    {
                        cout << "Ingrese el nombre de la playlist: ";
                        string nombre;
                        cin >> nombre;
                        //usuarios[i]->eliminarPlaylist(nombre);
                        (*usuarios[i])- nombre;
                    }
                    break;
                    default:
                        cout << "Opcion invalida" << endl;

                        break;
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "Usuario no encontrado" << endl;
            }
            break;
        }
        case 4:
        {
            Playlist *playlist = new Playlist();
            cin >> *playlist;
            catalogo.push_back(playlist);
            cout << "Playlist creada exitosamente." << endl;
            
            break;
        }
        case 5:
        {
            if (catalogo.empty())
            {
                cout << "\nNo hay playlists registradas para eliminar." << endl;
            }

            cout << "Eliminar Playlist" << endl;

            for (int i = 0; i < catalogo.size(); ++i)
            {
                cout << i + 1 << ". " << catalogo[i]->getTitulo() << endl;
            }
            cout << "Ingrese el numero de la playlist que desea eliminar: ";
            int playlistIndex;
            cin >> playlistIndex;
            if (playlistIndex < 1 || playlistIndex > catalogo.size())
            {
                cout << "Indice invalido." << endl;
                break;
            }
            catalogo.erase(catalogo.begin() + playlistIndex - 1);

            break;
        }
        case 6:
        {
            if (catalogo.empty())
            {
                cout << "\nNo hay playlists registradas para agregar canciones." << endl;
                break;
            }
            cout << "Elije la playlist" << endl;
            for (int i = 0; i < catalogo.size(); ++i)
            {
                cout << i + 1 << ". " << catalogo[i]->getTitulo() << endl;
            }
            int playlistIndex;
            cin >> playlistIndex;
            int artistaIndex = seleccionarUsuario();
            if (artistaIndex < 0)
            {
                cout << "Artista no encontrado." << endl;
                break;
            }
            Cancion *cancion = new Cancion();
            cin >> *cancion;
            
            (*catalogo[playlistIndex - 1]) + cancion;
            //catalogo[playlistIndex - 1]->agregarCancion(cancion);
            cout << "Cancion agregada exitosamente." << endl;
            catalogo[playlistIndex - 1]->mostrarInfo();

            break;
        }
        case 7:
        {
            cout << "Elije la playlist" << endl;
            for (int i = 0; i < catalogo.size(); ++i)
            {
                cout << i + 1 << ". " << catalogo[i]->getTitulo() << endl;
            }
            int playlistIndex;
            cin >> playlistIndex;
            cout << "Ingrese el nombre de la cancion" << endl;
            string nombreCancion;
            cin >> nombreCancion;
            catalogo[playlistIndex - 1]->eliminarCancion(nombreCancion);
            catalogo[playlistIndex - 1]->mostrarInfo();

            break;
        }
        case 8:
        {
            listarPlaylists();
            break;
        }
       case 9:
            {
                if (catalogo.empty()) // Validación inicial
                {
                    cout << "No hay playlists registradas." << endl;
                    break;
                }
                cout << "Ingrese el nombre de la cancion: ";
                string nombreCancion;
                getline(cin, nombreCancion); // Permite nombres con espacios

                bool encontrado = false; 

                // Iterar sobre cada playlist en el catálogo
                for (int i = 0; i < catalogo.size(); ++i)
                {
                    vector<Cancion *> canciones = catalogo[i]->getCanciones();

                    // Buscar en las canciones de la playlist
                    for (int j = 0; j < canciones.size(); ++j)
                    {
                        if (canciones[j]->getTitulo() == nombreCancion) // Compara el nombre de la canción
                        {
                            cout << "\nCancion encontrada en la playlist: " 
                                << catalogo[i]->getTitulo() << endl;
                            canciones[j]->mostrarInfo(); // Muestra la información de la canción
                            encontrado = true;
                            break;
                        }
                    }
                    if (encontrado)
                    {
                        break; }
                }

                if (!encontrado) // Mensaje si no se encontró la canción
                {
                    cout << "Cancion no encontrada en ninguna playlist." << endl;
                }
                break;
            }
        case 10:
        {
            cout << "Adios" << endl;
            break;
        }
        default:
        {
            cout << "Opcion invalida" << endl;
            break;
        }
        }
    } while (opcion != 10);

    return 0;
}

void listarUsuarios()
{
    cout << "Usuarios registrados:" << endl;
    for (size_t i = 0; i < usuarios.size(); ++i)
    {
        cout << i + 1 << ". " << usuarios[i]->getNombre();
        if (dynamic_cast<Artista *>(usuarios[i]))
        {
            cout << " (Artista)";
        }
        cout << endl;
    }
}

void listarPlaylists()
{
    if (catalogo.empty())
    {
        cout << "\nNo hay playlists registradas." << endl;
        return;
    }

    cout << "Playlists registradas:" << endl;
    for (size_t i = 0; i < catalogo.size(); ++i)
    {
        cout << i + 1 << ". " << catalogo[i]->getTitulo() << endl;
    }
}

int seleccionarUsuario()
{
    if (usuarios.empty())
    {
        cout << "No hay usuarios registrados." << endl;
        return -1;
    }

    listarUsuarios();
    cout << "Seleccione el numero del usuario: ";
    int index;
    cin >> index;

    if (index < 1 || index > usuarios.size())
    {
        cout << "Indice invalido." << endl;
        return -1;
    }
    return index - 1;
}

int seleccionarPlaylist()
{
    listarPlaylists();
    cout << "Seleccione el numero de la playlist: ";
    int index;
    cin >> index;

    if (index < 1 || index > catalogo.size())
    {
        cout << "Indice invalido." << endl;
        return -1;
    }
    return index - 1;
}

void menu()
{
    cout << "\nMenu" << endl;
        cout << "1. Crear usuario" << endl;
        cout << "2. Eliminar usuario" << endl;
        cout << "3. Buscar usuario" << endl;
        cout << "\n4. Crear playlist" << endl;
        cout << "5. Eliminar playlist" << endl;
        cout << "6. Agregar cancion a playlist" << endl;
        cout << "7. Eliminar cancion de playlist" << endl;
        cout << "\n8. Mostrar playlists" << endl;
        cout << "9. Buscar cancion" << endl;
        cout << "10. Salir" << endl;
}