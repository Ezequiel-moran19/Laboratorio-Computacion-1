#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_cargarDesdeTexto(char* path,LinkedList* pArrayListPeliculas);

int controller_guardarModoTexto(char* path,LinkedList* pArrayListPeliculas);

int controller_imprimirLista(LinkedList* pArrayListPeliculas);

void* mov_AsignarRating(void* peliculas);

void* mov_AsignarGenero(void* peliculas);

int controller_mapRating(LinkedList* pArrayListPeliculas);

int controller_mapGenero(LinkedList* pArrayListPeliculas);

void generoPeliculaAletorea(void* this);

int controller_filtrarGenero(LinkedList* pArrayListPeliculas);

int ordenGeneroRating(void* pelicula1, void* pelicula2);

int ordenar_generoRating(LinkedList* pArrayListPeliculas);

int controller_guardarDatos6(LinkedList* listado, char* nombreArchivo);

#endif // CONTROLLER_H_INCLUDED
