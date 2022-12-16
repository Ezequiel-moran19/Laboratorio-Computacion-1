#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Seleccion.h"
#include "menu.h"
#include "UTN_lib.h"

Seleccion* selec_new()
{
	Seleccion* nSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	if(nSeleccion != NULL)
	{
		nSeleccion->id = 0;
		strcpy(nSeleccion->pais, "");
		strcpy(nSeleccion->confederacion, "");
		nSeleccion->convocados = 0;
	}
	return nSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* nSeleccion = NULL;
	nSeleccion= selec_new();

	if(nSeleccion != NULL)
	{
		nSeleccion->id = atoi(idStr);
		strcpy(nSeleccion->pais, paisStr);
		strcpy(nSeleccion->confederacion, confederacionStr);
		selec_setConvocados(nSeleccion, atoi(convocadosStr));
	}
     return nSeleccion;
}

//destructor
void selec_delete(Seleccion* this)
{
   if(this != NULL)
   {
	   free(this);
   }
}

int selec_getId(Seleccion* this,int* id)
{
    int ok = 0;
    if(this != NULL && id != NULL)
    {
		*id = this->id;
        ok = 1;
    }
	return ok;
}

int selec_getPais(Seleccion* this,char* pais)
{
    int ok = 0;
	if (this != NULL && pais!=NULL)
	{
		strcpy(pais,this->pais);
		ok=1;
	}
	return ok;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int ok = 0;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		ok = 1;
	}
	return ok;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int ok = 0;
	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		ok = 1;
	}
	return ok;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int ok = 0;
	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		ok = 1;
	}
    return ok;
}

int selec_ordenarPorConfederacion(void* punteroUno, void* punteroDos)
{
    int ok;
    char auxNombreUno[100];
    char auxNombreDos[100];
    Seleccion* auxConfederacionUno = (Seleccion*)punteroUno;
    Seleccion* auxConfederacionDos = (Seleccion*)punteroDos;

    if(auxConfederacionUno!=NULL && auxConfederacionDos!=NULL)
    {
    	selec_getConfederacion(auxConfederacionUno,auxNombreUno);
    	selec_getConfederacion(auxConfederacionDos,auxNombreDos);

    	if(strcmp(auxNombreUno,auxNombreDos) > 0)
    	{
    		ok=-1;
    	}
    	else if(strcmp(auxNombreUno,auxNombreDos) < 0)
    	{
    		ok=1;
    	}
    	auxConfederacionUno=NULL;
    	auxConfederacionDos=NULL;
    }
    return ok;
}

int seleccionBuscarId(Seleccion* this,int* resultado)
{
    int ok = 0;

    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        ok = 1;
    }
    return ok;
}

int selec_buscarIdSeleccion(LinkedList* pArrayListSeleccion, int* posicionId, int id)
{
    int retorno = 0;
    int auxId = 0;
    Seleccion* pSeleccion = NULL;

    if(pArrayListSeleccion != NULL && posicionId != NULL && id >= 1)
    {
    	*posicionId = -1;
        for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
        {
        	pSeleccion = ll_get(pArrayListSeleccion, i);

            if(pSeleccion != NULL)
            {
            	selec_getId(pSeleccion, &auxId);

                if(id == auxId)
                {
                    *posicionId = i;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

int selec_validarSeleccion(LinkedList* pArrayListSeleccion, int id)
{
    int valido = 0;
    int indice;

    if(selec_buscarIdSeleccion(pArrayListSeleccion,&indice ,id))
    {
        if(indice != -1)
        {
        	valido = 1;
        }
    }
    return valido;
}

int cargarConfederacion(LinkedList *pArrayListSeleccion, int id, char desc[])
{
	int ok = 0;
	int idSeleccion;
	char confe[100];
	Seleccion *pSeleccion = NULL;
	int tam = ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion != NULL && desc != NULL)
	{
		ok = 1;
		for(int i = 0; i < tam; i++)
		{
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if (selec_getId(pSeleccion, &idSeleccion) && idSeleccion == id)
			{
				selec_getConfederacion(pSeleccion, confe);
				strcpy(desc, confe);
				break;
			}
		}
	}
	return ok;
}

int selec_confederaciones(char* confe)
{
    int ok = 0;
    if(confe != NULL)
    {
        switch(menuOpcionesConfes())
            {
            case 1:
                strcpy(confe,"CAF");
                break;
            case 2:
                strcpy(confe,"AFC");
                break;
            case 3:
                strcpy(confe,"CONMEBOL");
                break;
            case 4:
                strcpy(confe,"CONCACAF");
                break;
            case 5:
				strcpy(confe,"UEFA");
				break;
            }
        ok = 1;
    }
    return ok;
}

int selec_mostrarUnaSeleccion(Seleccion* pSeleccion)
{
	int ok = 0;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(pSeleccion != NULL)
	{
		if( selec_getId(pSeleccion, &id)
		&&  selec_getPais(pSeleccion, pais)
		&&  selec_getConfederacion(pSeleccion, confederacion)
		&&  selec_getConvocados(pSeleccion, &convocados))
		{
			printf ("   %-7d %-15s           %-15s            %-6d  \n",
			id, pais, confederacion, convocados);
		}
	}
   return ok;
}
