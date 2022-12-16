#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayList)
{
    int ok = 0;
	FILE* f = NULL;

	if(path != NULL && pArrayList != NULL)
	{
		f = fopen(path,"r");
		if (f != NULL)
		{
			parser_FromText(f, pArrayList);

		    ok = 1;
		}
		fclose(f);
	}
	return ok;
}

int controller_guardarPostModoTexto(char* path, LinkedList* pArrayList)
{
    int ok = 0;
    FILE* fArchivo;
    int id;
    char user[100];
    int likes;
    int dislikes;
    int followers;
    ePost* pPost= NULL;

    if (path != NULL && pArrayList != NULL )
    {
        fArchivo = fopen(path, "w");
        if (fArchivo == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        fprintf( fArchivo, "id,user,likes,dislikes,followers\n" );

        for (int i = 0; i < ll_len(pArrayList); i++)
        {
            pPost = ll_get(pArrayList, i);
            if( g_getId( pPost, &id)
            &&  g_getUser( pPost, user)
            &&  g_getLikes( pPost, &likes)
            &&  g_getDislikes(pPost, &dislikes)
            &&  g_getFollowers(pPost,&followers))
            {
                fprintf(fArchivo, "%d,%s,%d,%d,%d\n", id,user, likes, dislikes,followers);
                ok = 1;
            }
        }
        printf("Guardado!!!\n");
    }
    fclose(fArchivo);
    return ok;
}

int controller_imprimirLista(LinkedList* pArrayList)
{
    int ok=0;
    ePost* pPost= NULL;
    if(pArrayList!=NULL)
    {
        system("cls");
        printf(" ______________________________________________________________________________________________\n");
		printf("|                                                                                              |\n");
		printf("|		   	                LISTADO DE POSTEOS                                     |\n");
		printf("|______________________________________________________________________________________________|\n");
        printf("|   Id           User                  Likes                  Dislikes            Followers    |\n");
		printf("|______________________________________________________________________________________________|\n");
        for(int i = 0 ; i<ll_len(pArrayList); i++)
        {
            pPost=(ePost*)ll_get(pArrayList,i);
            mostrar_Post(pPost);
        }
        ok=1;
    }
    return ok;
}

void* asignarEstadisticaLikes(void* post)
{
    ePost* pPost = (ePost*)post;
    void* ok = NULL;
    int likes;
    if(post != NULL)
    {
        likes = rand()%(5000 - 600 + 1) + 600;
        s_setLikes(pPost, likes);
         ok=(void*)pPost;
    }
    return ok;
}

void* asignarEstadisticaDislikes(void* post)
{
    ePost* pPost = (ePost*)post;
    void* ok = NULL;
    int dislikes;
    if(post != NULL)
    {
        dislikes = rand()%(3500 - 300 + 1) + 300;
        s_setDislikes(pPost, dislikes);
        ok=(void*)pPost;
    }
    return ok;
}

void* asignarEstadisticaFlollwers(void* post)
{
    ePost* pPost = (ePost*)post;
    void* ok = NULL;
    int follows;
    if(post != NULL)
    {
        follows = rand()%(20000 - 10000 + 1) + 10000;
        s_setFollowers(pPost, follows);
        ok=(void*)pPost;
    }
    return ok;
}

int controller_map(LinkedList* pArrayList)
{
    int ok = 0;
    pArrayList = ll_map(pArrayList, asignarEstadisticaLikes);
    pArrayList = ll_map(pArrayList, asignarEstadisticaDislikes);
    pArrayList = ll_map(pArrayList, asignarEstadisticaFlollwers);

    if(pArrayList != NULL)
    {
        controller_imprimirLista(pArrayList);
        printf("\nEstadisticas asignadas!!!\n");
        ok = 1;
    }
    return ok;
}

int controller_filtrarPorLikes(LinkedList* pArrayList)
{
    int ok = 0;
    char auxiliar[20];
    LinkedList* pLInk = ll_newLinkedList();
    if(pArrayList != NULL)
    {
        pLInk = ll_filter(pArrayList,filtrar_masCantidadlikes);
        strcpy(auxiliar, "postMasLikes.csv");

        if(pLInk != NULL)
        {
            controller_imprimirLista(pLInk);
            controller_guardarPostModoTexto(auxiliar, pLInk);
            printf("\nLa informacion fue guardada en el archivo [postMasLikes.csv]!!!\n");
            ok = 1;
        }
    }
    return ok;
}

int controller_filtrarPorHeaters(LinkedList* pArrayList)
{
    int ok = 0;
    char auxiliar[20];

    if (pArrayList != NULL)
    {
        pArrayList = ll_filter(pArrayList,filtrar_masCantidadHaters);
        strcpy(auxiliar, "postMasHeaters.csv");

        if(pArrayList != NULL)
        {
            controller_imprimirLista(pArrayList);
            controller_guardarPostModoTexto(auxiliar, pArrayList);
            printf("\nLa informacion fue guardada en el archivo [postMasHeaters.csv]!!!\n");
            ok = 1;
        }
    }
    return ok;
}

int compararFollow(void* a,void* b)
{
    int ok = 0;
    if(((ePost*)a)->followers < ((ePost*)b)->followers)
    {
        ok = -1;
    }
    return ok;
}

int controller_ordenarPost(LinkedList* pArrayList)
{
    int ok = 0;
    if(pArrayList != NULL)
    {
        ll_sort(pArrayList, compararFollow, 0);
        controller_imprimirLista(pArrayList);
        printf("\nPosteos ordenados!!!!\n");
        ok = 1;
    }
    return ok;
}

int controller_mostrarMasPopular(LinkedList* pArrayList)
{
    int ok = 0;
    int likesActuales = 0;
    int mayorCantidad = 0;
    char user[50];
    int tam;
    ePost* pPost = NULL;
    if(pArrayList != NULL)
    {
        tam = ll_len(pArrayList);
        for(int i=0; i< tam; i++)
        {
        	pPost=(ePost*)ll_get(pArrayList,i);
        	g_getLikes(pPost, &likesActuales);

            if(likesActuales > mayorCantidad)
            {
            	mayorCantidad = likesActuales;
            	strcpy(user, pPost->user);
            }
        }
        printf("\nNOmbre Del usuario: %s cantidad de Likes = %d\n\n",user,mayorCantidad);
        ok = 1;
    }
    return ok;
}

