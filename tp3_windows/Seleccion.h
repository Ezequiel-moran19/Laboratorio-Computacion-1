#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);
int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int selec_ordenarPorConfederacion(void* punteroUno, void* punteroDos);
int selec_mostrarUnaSeleccion(Seleccion* pSeleccion);
int seleccionBuscarId(Seleccion* this,int* resultado);
int selec_buscarIdSeleccion(LinkedList* pArrayListSeleccion, int* posicionId, int id);
int selec_validarSeleccion(LinkedList* pArrayListSeleccion, int id);
int cargarConfederacion(LinkedList *pArrayListSeleccion, int id, char desc[]);
int selec_confederaciones(char* confe);

#endif // selec_H_INCLUDED
