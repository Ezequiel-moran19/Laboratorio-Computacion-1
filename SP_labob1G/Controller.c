#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "movie.h"
#include "menu.h"

/** \brief Guarda los datos de las (modo texto).
 *
 * \param path char*
 * \param pArrayListPost LinkedList*
 * \return int
 *
 */
int controller_cargarDesdeTexto(char* path,LinkedList* pArrayListPeliculas)
{
    int ok = 0;
	FILE* f;

	if(pArrayListPeliculas != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL && parser_movieFromText(f, pArrayListPeliculas))
		{
			printf("\nArchivo cargado exitosamente\n");
			ok = 1;
		}
		else
		{
			printf("\nError al cargar el archivo\n");
		}
	}

	fclose(f);

	return ok;
}

int controller_guardarModoTexto(char* path,LinkedList* pArrayListPeliculas)
{
    int ok = 0;
    FILE* fArchivo;
    int id;
    char titulo[50];
    char genero[50];
    int rating;
    Movie* pMovie= NULL;

    if (path != NULL && pArrayListPeliculas != NULL )
    {
        fArchivo = fopen(path, "w");
        if (fArchivo == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        fprintf(fArchivo,"id,titulo,genero,rating\n");

        for (int i = 0; i < ll_len(pArrayListPeliculas); i++)
        {
            pMovie = ll_get(pArrayListPeliculas, i);
            if(	mov_getId( pMovie, &id )
            &&  mov_getTitulo( pMovie, titulo)
            &&  mov_getGenero( pMovie, genero)
            &&  mov_getRating( pMovie, &rating))
            {
                fprintf(fArchivo,"%d,%s,%s,%d\n",id,titulo,genero,rating);
                ok = 1;
            }
        }
        system("cls");
        printf("\nGuardado!!!\n");
        system("pause");
    }
    fclose(fArchivo);
    return ok;
}

int controller_imprimirLista(LinkedList* pArrayListPeliculas)
{
    int ok=0;
    int tam;
    Movie* pMovie= NULL;
    if(pArrayListPeliculas!=NULL)
    {
        tam=ll_len(pArrayListPeliculas);
        printf(" ______________________________________________________________________________________\n");
		printf("|                                                                                      |\n");
		printf("|		                LISTADO DE PELICULAS                                  |\n");
		printf("|_____________________________________________________________________________________|\n");
		printf("|    Id 	         Titulo       	                     Genero          Rating   |\n");
		printf("|_____________________________________________________________________________________|\n");

        for(int i = 0; i < tam; i++)
        {
            pMovie=(Movie*)ll_get(pArrayListPeliculas,i);
            mostrarPeliculas(pMovie);
        }
        ok=1;
    }
    return ok;
}

void* mov_AsignarRating(void* peliculas)
{
    Movie* pMovie = (Movie*)peliculas;
    void* ok = NULL;
    float rating;
    if(peliculas != NULL)
    {
        rating =  rand()%(10 - 1 + 1) + 1;
        mov_setRating(pMovie, rating);
        ok=(void*)pMovie;
    }
    return ok;
}


int controller_mapRating(LinkedList* pArrayListPeliculas)
{
    int ok = 0;
    pArrayListPeliculas = ll_map(pArrayListPeliculas, mov_AsignarRating);

    if(pArrayListPeliculas != NULL)
    {
        controller_imprimirLista(pArrayListPeliculas);
        printf("Rating asignados con exito\n");
        ok = 1;
    }
    return ok;
}

void generoPeliculaAletorea(void* peliculas)
{
	Movie* pMovie = NULL;
	int randGenero;
    char genero[20];
    if(peliculas != NULL)
    {
    	pMovie = (Movie*) peliculas;
    	mov_getGenero(pMovie, genero);
		randGenero = rand()% 4 + 1;
		switch(randGenero)
		{
		case 1:
			strcpy(genero, "drama");
			mov_setGenero(pMovie, genero);
			break;
        case 2:
            strcpy(genero, "comedia");
            mov_setGenero(pMovie, genero);
            break;
        case 3:
            strcpy(genero, "accion");
            mov_setGenero(pMovie, genero);
            break;
        case 4:
            strcpy(genero, "terror");
            mov_setGenero(pMovie, genero);
            break;
        }
    }
}

int controller_mapGenero(LinkedList* pArrayListPeliculas)
{
    int ok = 0;
    pArrayListPeliculas = ll_map(pArrayListPeliculas, generoPeliculaAletorea);

    if(pArrayListPeliculas != NULL)
    {
        controller_imprimirLista(pArrayListPeliculas);
        printf("Rating asignados con exito\n");
        ok = 1;
    }
    return ok;
}

int controller_filtrarGenero(LinkedList* pArrayListPeliculas)
{
    int ok = 0;
    int opcion;
    char confirma;
    char archivo[20];
    LinkedList* newlist=NULL;

    if(pArrayListPeliculas != NULL)
    {
         switch(menuOpcionesFiltroGenero(&opcion))
        {
            case 1:
                pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_GeneroDrama);
                controller_imprimirLista(pArrayListPeliculas);
                if(utn_getCharacter(&confirma,"\n¿Quiere guardar la lista en un nuevo archivo )? [s/n]: \n","Quiere guardar la lista en un nuevo archivo?",'n','s',2)==0 && confirma=='s')
                {
                    utn_getString(archivo, "Ingrese el nombre del archivo[ moviesDrama.csv ]: ","Error reingrese el nombre del archivo[ generoDrama.csv ]\n",1,20,5);
                    controller_guardarModoTexto("movieDrama.csv", newlist);
                }
                break;
            case 2:
                pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_GeneroComedia);
                if(utn_getCharacter(&confirma,"\nQuiere guardar la lista en un nuevo archivo? [s/n]: \n","Quiere guardar la lista en un nuevo archivo?",'n','s',2)==0 && confirma=='s')
                {
                    utn_getString(archivo, "Ingrese el nombre del archivo[ movieComedia.csv : ","Error reingrese el nombre del archivo[ generoAdventure.csv ]\n",1,20,5);
                    controller_guardarModoTexto("movieComedia.csv", newlist);
                }
                break;
            case 3:
                pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_GeneroAccion);
                if(utn_getCharacter(&confirma,"\nQuiere guardar la lista en un nuevo archivo ? [s/n]: \n","Quiere guardar la lista en un nuevo archivo?",'n','s',2)==0 && confirma=='s')
                {
                    utn_getString(archivo, "Ingrese el nombre del archivo[ movieAccion.csv ]: ","Error reingrese el nombre del archivo[ generoAdventure.csv ]\n",1,20,5);
                    controller_guardarModoTexto("movieAccion.csv", newlist);
                }
                break;
            case 4:
                pArrayListPeliculas = ll_filter(pArrayListPeliculas, filtrar_GeneroTerror);
                if(utn_getCharacter(&confirma,"\nQuiere guardar la lista en un nuevo archivo ? [s/n]: \n","Quiere guardar la lista en un nuevo archivo?",'n','s',2)==0 && confirma=='s')
                {
                    utn_getString(archivo, "Ingrese el nombre del archivo[ movieTerror.csv ]: ","Error reingrese el nombre del archivo[ generoComedy.csv ]\n",1,20,5);
                    controller_guardarModoTexto("movieTerror.csv", newlist);
                }
                break;
         }
        ok=1;
    }

   return ok;
}

int ordenGeneroRating(void* pelicula1, void* pelicula2)
{
    int ok = 0;

    if( (stricmp(((Movie*)pelicula1)->genero, ((Movie*)pelicula2)->genero) > 0) ||
      ( (stricmp(((Movie*)pelicula1)->genero, ((Movie*)pelicula2)->genero) == 0) &&
                (((Movie*)pelicula1)->rating < ((Movie*)pelicula2)->rating )))
    {
        ok = 1;
    }

    if( (stricmp(((Movie*)pelicula1)->genero, ((Movie*)pelicula2)->genero) < 0 ) ||
      ( (stricmp(((Movie*)pelicula1)->genero, ((Movie*)pelicula2)->genero) == 0 ) &&
                (((Movie*)pelicula1)->rating > ((Movie*)pelicula2)->rating )))
    {
        ok = -1;
    }
    return ok;
}

int ordenar_generoRating(LinkedList* pArrayListPeliculas)
{
    int ok = 0;

    if ( pArrayListPeliculas != NULL )
    {
        ok = 1;
        system("cls");
        printf(" _______________________________\n");
        printf("| ORDENAR POR GENERO Y DURACION |\n");
        printf("|_______________________________|\n");
        ll_sort( pArrayListPeliculas, ordenGeneroRating, 1);
        controller_imprimirLista(pArrayListPeliculas);
    }
    return ok;
}

int controller_guardarDatos6(LinkedList* listado, char* nombreArchivo)
{
    int ok=0;

    if(listado!=NULL && nombreArchivo!=NULL)
    {
        controller_guardarModoTexto(nombreArchivo,listado);
        ok=1;
    }
    return ok;
}
