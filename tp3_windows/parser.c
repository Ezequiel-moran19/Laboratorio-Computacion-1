#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int ok = 0;
	int cant = 0;
	char id[100];
	char nombreCompleto[100];
	char edad[100];
	char posicion[100];
	char nacionalidad[100];
	char idSeleccion[100];
	char falsaLectura[1000];

	Jugador* pJugador = NULL;
	fscanf(pFile, "%s", falsaLectura);

	while(!feof(pFile))
	{
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		pJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

		if(pJugador == NULL)
		{
			printf("falló la carga del usuario con id: %s\n", id);
		}

		ll_add(pArrayListJugador, pJugador);
		cant++;
		ok = 1;
	}
	printf("\n Se agregaron %d jugadores al Sistema\n", cant);
	return ok;

}

int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int ok = 0;
	int total = 0;
	Jugador* pJugador = NULL;
	int cant = 0;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		ll_clear(pArrayListJugador);
		while(!feof(pFile))
		{
			pJugador = jug_new();
			if(pJugador == NULL)
			{
				printf("No se consiguió memoria\n");
			}
			else
			{
				cant = fread(pJugador, sizeof(Jugador), 1, pFile);
				if(cant < 1)
				{
					break;
				}

				ll_add(pArrayListJugador, pJugador);
				total++;
				ok = 1;
			}
		}
	}
	printf("\n Se agregaron %d jugaores al Sistema.\n", total);
	return ok;

}

int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	int cant = 0;
	char id[100];
	char pais[50];
	char confederacion[50];
	char convocados[50];
	char falsaLectura[1000];
	Seleccion* pSeleccion = NULL;

	fscanf(pFile, "%s", falsaLectura);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
		pSeleccion = selec_newParametros(id, pais, confederacion, convocados);

		if(pSeleccion == NULL)
		{
			printf("falló la carga del usuario con id: %s\n", id);
		}

		ll_add(pArrayListSeleccion, pSeleccion);
		cant++;
		ok = 1;
	}
	printf("\n Se agregaron %d selecciones al Sistema\n", cant);

	return ok;

}


