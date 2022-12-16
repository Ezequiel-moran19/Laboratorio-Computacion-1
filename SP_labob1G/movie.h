#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct
{
    int id;
    char titulo[80];
    char genero[80];
    float rating;
}Movie;

int menuPrincipal();

Movie* new_movies();

Movie* movie_newParam(char* id_peli,char* titulo, char* genero,char* duracion);

void mov_delete(Movie* this);
//Setter
int mov_setId(Movie* this, int id);
int mov_getId(Movie* this, int* id);
int mov_setTitulo(Movie* this,char* titulo);
int mov_getTitulo(Movie* this,char* titulo);
int mov_setGenero(Movie* this,char* genero);
int mov_getGenero(Movie* this,char* genero);
int mov_setRating(Movie* this,int duracion);
int mov_getRating(Movie* this,int* duracion);

int mostrarPeliculas(Movie* pMovie);
int filtrar_GeneroDrama(void* pelicula);
int filtrar_GeneroComedia(void* pelicula);
int filtrar_GeneroAccion(void* pelicula);
int filtrar_GeneroTerror(void* pelicula);

#endif // MOVIE_H_INCLUDED
