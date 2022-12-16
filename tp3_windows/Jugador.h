#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);
int jug_setId(Jugador* this,int id);
int jug_setEdad(Jugador* this,int edad);
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_setPosicion(Jugador* this,char* posicion);
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

int jug_getId(Jugador* this,int* id);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getPosicion(Jugador* this,char* posicion);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);
int jug_getEdad(Jugador* this,int* edad);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int jug_mostrarUnJugador(Jugador* pArrayJugadores);
int jug_ordenarPorNacionalidad(void* punteroUno, void* punteroDos);
int jug_ordenarPorEdad(void* punteroUno, void* punteroDos);
int jug_ordenarPorId(void* punteroUno, void* punteroDos);
int jug_ordenarPorNombre(void* punteroUno, void* punteroDos);
int jugadorBuscarId(Jugador* this,int* resultado);
int jug_buscarIdJugador(LinkedList* pArrayListJugador, int* posicionId, int id);
int jug_validarJugador(LinkedList* pArrayListJugador, int id);
int jug_posiciones(char* puesto);
int jug_nacionalidades(char* nacio);



#endif // jug_H_INCLUDED
