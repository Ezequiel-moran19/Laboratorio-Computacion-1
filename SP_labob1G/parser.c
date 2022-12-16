#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "movie.h"

int parser_movieFromText(FILE* pFile, LinkedList* pArrayList)
{
    int ok = 0;
	int cant = 0;
    char id[100];
	char titulo[100];
	char genero[100];
	char rating[100];
	char falsaLectura[1000];
	Movie* pMovie;

	fscanf(pFile, "%s", falsaLectura);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, genero, rating);

		pMovie = movie_newParam(id, titulo, genero, rating);

		if(pMovie == NULL)
		{
			printf("falló la carga del usuario con id: %s\n", id);
		}
		ll_add(pArrayList, pMovie);
		cant++;
		ok = 1;
	}
	printf("\n Se agregaron %d Movie al Sistema\n", cant);
    return ok;


}
