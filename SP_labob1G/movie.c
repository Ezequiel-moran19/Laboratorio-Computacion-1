#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "movie.h"
#include "menu.h"

Movie* new_movies()
{
    Movie* nuevaPelicula = NULL;
	nuevaPelicula = (Movie*) malloc(sizeof(Movie));

    if(nuevaPelicula != NULL)
    {
    	nuevaPelicula->id = 0;
        strcpy(nuevaPelicula->titulo, " ");
        strcpy(nuevaPelicula->genero, " ");
        nuevaPelicula->rating = 0;
    }
    return nuevaPelicula;
}
Movie* movie_newParam(char* id_peli,char* titulo, char* genero,char* rating)
{
    Movie* nuevaPelicula;
	nuevaPelicula = NULL;
	nuevaPelicula = new_movies();

    if(nuevaPelicula != NULL)
    {
       mov_setId(nuevaPelicula, atoi(id_peli));
       mov_setTitulo(nuevaPelicula,titulo);
       mov_setGenero(nuevaPelicula, genero);
       mov_setRating(nuevaPelicula, atoi(rating));
    }
    return nuevaPelicula;
}

void mov_delete(Movie* pelis)
{
    if(pelis != NULL)
	{
    	free(pelis);
	}
}
//Setter
int mov_setId(Movie* this, int id)
{
	int ok=0;

	if(this!=NULL && id>0)
	{
		this->id=id;
	    ok=1;
	}
	return ok;
}

int mov_getId(Movie* this, int* id)
{
	int ok=0;
	if(this!=NULL && id!=NULL)
	{
	    *id=this->id;
		ok=1;
	}
	return ok;
}

int mov_setTitulo(Movie* this,char* titulo)
{
	int ok=0;

	if(this!=NULL && titulo!=NULL && strlen(titulo)<50 && strlen(titulo)>0)
	{
		strcpy(this->titulo,titulo);
	    ok=1;
	}
	return ok;
}

int mov_getTitulo(Movie* this,char* titulo)
{
	int ok=0;

	if(this!=NULL && titulo!=NULL && strlen(titulo)<50 && strlen(titulo)>0)
	{
		strcpy(titulo, this->titulo);
	    ok=1;
	}
	return ok;
}

int mov_setGenero(Movie* this,char* genero)
{
	int ok=0;

	if(this!=NULL && genero!=NULL && strlen(genero)<50 && strlen(genero)>0)
	{
		strcpy(this->genero, genero);
		ok=1;
	}
	return ok;
}

int mov_getGenero(Movie* this,char* genero)
{
	int ok=0;

	if(this!=NULL && genero!=NULL && strlen(genero)<50 && strlen(genero)>0)
	{
		strcpy(genero, this->genero);
		ok=1;
	}
	return ok;
}

int mov_setRating(Movie* this,int rating)
{
	int ok=0;

	if(this!=NULL && rating>=0)
	{
		this->rating=rating;
		ok=1;
	}
	return ok;
}

int mov_getRating(Movie* this,int* rating)
{
	int ok=0;

	if(this!=NULL && rating!=NULL)
	{
		*rating=this->rating;
		ok=1;
	}
	return ok;
}

int mostrarPeliculas(Movie* pMovie)
{
	int ok = 0;
	int id_peli;
    char titulo[100];
    char genero[100];
    int rating;

    if(pMovie != NULL)
    {
        mov_getId(pMovie, &id_peli);
        mov_getTitulo(pMovie, titulo);
        mov_getGenero(pMovie, genero);
        mov_getRating(pMovie, &rating);
        printf("     %d  %30s            %20s          %d\n",
    		id_peli, titulo, genero, rating);
    	ok = 1;
    }
   return ok;
}

int filtrar_GeneroDrama(void* pelicula)
{
    int ok = 0;
    Movie* pMovie = NULL;
    if(pelicula != NULL)
    {
        pMovie = (Movie*) pelicula;
        if(stricmp(pMovie->genero, "Drama") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}

int filtrar_GeneroComedia(void* pelicula)
{
    int ok = 0;
    Movie* pMovie = NULL;
    if(pelicula != NULL)
    {
        pMovie = (Movie*) pelicula;
        if(stricmp(pMovie->genero, "Comedia") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}

int filtrar_GeneroAccion(void* pelicula)
{
    int ok = 0;
    Movie* pMovie = NULL;
    if(pelicula != NULL)
    {
        pMovie = (Movie*) pelicula;

        if(stricmp(pMovie->genero, "Accion") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}

int filtrar_GeneroTerror(void* pelicula)
{
    int ok = 0;
    Movie* pMovie = NULL;
    if(pelicula != NULL)
    {
        pMovie = (Movie*) pelicula;
        if(stricmp(pMovie->genero, "Terror") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}


