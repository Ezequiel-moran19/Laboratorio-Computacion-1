#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <ctype.h>
#include "Jugador.h"
#include "Controller.h"
#include "UTN_lib.h"
#include "menu.h"

Jugador* jug_new()
{
	Jugador* nuevoJugador;
	nuevoJugador = (Jugador*) malloc(sizeof(Jugador));

    if(nuevoJugador != NULL)
    {
    	nuevoJugador->id = 0;
        strcpy(nuevoJugador->nombreCompleto, "");
        nuevoJugador->edad = 0;
        strcpy(nuevoJugador->posicion, "");
        strcpy(nuevoJugador->nacionalidad, "");
        nuevoJugador->idSeleccion = 0;
    }
    return nuevoJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	pJugador = NULL;
	pJugador = jug_new();

        if(pJugador != NULL)
        {
        	jug_setId(pJugador, atoi(idStr));
        	jug_setNombreCompleto(pJugador, nombreCompletoStr);
            jug_setEdad(pJugador, atoi(edadStr));
            jug_setPosicion(pJugador, posicionStr);
            jug_setNacionalidad(pJugador, nacionalidadStr);
            jug_setIdSeleccion(pJugador, atoi(idSelccionStr));
        }
    return pJugador;
}

//destructor
void jug_delete(Jugador* this)
{
    if(this != NULL)
	{
    	free(this);
	}
}
int jug_mostrarUnJugador(Jugador* pJugador)
{

	int ok = 0;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

    if(pJugador != NULL)
    {
      jug_getId(pJugador, &id);
      jug_getNombreCompleto(pJugador, nombreCompleto);
      jug_getEdad(pJugador, &edad);
      jug_getPosicion(pJugador, posicion);
      jug_getNacionalidad(pJugador, nacionalidad);
      jug_getIdSeleccion(pJugador, &idSeleccion);
      printf("   %d  %26s       %d    %20s        %12s               %d\n",
    		id,nombreCompleto,edad, posicion,nacionalidad, idSeleccion );
    	ok = 1;
    }
   return ok;
}

// Setters
int jug_setId(Jugador* jug, int id)
{
    int todoOk = 0;

    if(jug != NULL && id > 0)
    {
        jug->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int jug_setNombreCompleto(Jugador* this, char* nombreCompleto)
{
    int todoOk = 0;

    if(this != NULL && nombreCompleto != NULL && strlen(nombreCompleto) < 100 && strlen(nombreCompleto) > 3)
    {
        strcpy(this->nombreCompleto, nombreCompleto);
        strlwr(this->nombreCompleto);
        this->nombreCompleto[0] = toupper(this->nombreCompleto[0]);
        todoOk = 1;
    }
    return todoOk;
}

int jug_setEdad(Jugador* this, int edad)
{
    int todoOk = 0;

    if(this != NULL && edad > 0)
    {
    	this->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}

int jug_setPosicion(Jugador* this, char* posicion)
{
    int todoOk = 0;

    if(this != NULL && posicion != NULL && strlen(posicion) < 30 && strlen(posicion) >3 )
    {
    	strcpy(this->posicion, posicion);
		strlwr(this->posicion);
		this->posicion[0] = toupper(this->posicion[0]);
        todoOk = 1;
    }
    return todoOk;
}

int jug_setNacionalidad(Jugador* this, char* nacionalidad)
{
    int todoOk = 0;

    if(this != NULL && nacionalidad != NULL && strlen(nacionalidad) < 30 && strlen(nacionalidad) > 3)
    {
        strcpy(this->nacionalidad, nacionalidad);
        strlwr(this->nacionalidad);
        this->nacionalidad[0] = toupper(this->nacionalidad[0]);
        todoOk = 1;
    }
    return todoOk;
}

int jug_setIdSeleccion(Jugador* this, int idSeleccion)
{
    int todoOk = 0;

    if(this != NULL && idSeleccion >= 0)
    {
    	this->idSeleccion = idSeleccion;
        todoOk = 1;
    }
    return todoOk;
}

// Getters
int jug_getId(Jugador* this, int* id)
{
    int ok = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        ok = 1;
    }
    return ok;
}

int jug_getNombreCompleto(Jugador* this, char* nombreCompleto)
{
    int todoOk = 0;

    if(this != NULL && nombreCompleto != NULL)
    {
        strcpy(nombreCompleto, this->nombreCompleto);
        todoOk = 1;
    }
    return todoOk;
}

int jug_getEdad(Jugador* this,int* edad)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *edad = this->edad;
        todoOk = 1;
    }
    return todoOk;
}

int jug_getPosicion(Jugador* this,char* posicion)
{

    int todoOk = 0;

    if(this != NULL && posicion!= NULL)
    {
        strcpy(posicion, this->posicion);
        todoOk = 1;
    }
    return todoOk;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
    int todoOk = 0;

    if(this != NULL && nacionalidad!= NULL)
    {
        strcpy(nacionalidad, this->nacionalidad);
        todoOk = 1;
    }
    return todoOk;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
    int todoOk = 0;

    if(this != NULL && idSeleccion != NULL)
    {

        *idSeleccion = this->idSeleccion;
        todoOk = 1;
    }
    return todoOk;
}

//Otras funciones

int jug_ordenarPorNacionalidad(void* punteroUno, void* punteroDos)
{
    int ok;
    char auxNacionalidadUno[50];
    char auxNacionalidadDos[50];
    Jugador* auxJugadorUno = (Jugador*)punteroUno;
    Jugador* auxJugadorDos = (Jugador*)punteroDos;

    if(auxJugadorUno!=NULL && auxJugadorDos!=NULL)
    {
    	jug_getNacionalidad(auxJugadorUno,auxNacionalidadUno);
    	jug_getNacionalidad(auxJugadorDos,auxNacionalidadDos);

    	if(strcmp(auxNacionalidadUno,auxNacionalidadDos)<0)
    	{
    		ok=-1;
    	}
    	else if(strcmp(auxNacionalidadUno,auxNacionalidadDos)>0)
    	{
    		ok=1;
    	}

    	auxJugadorUno=NULL;
    	auxJugadorDos=NULL;
    }

    return ok;
}

int jug_ordenarPorEdad(void* punteroUno, void* punteroDos)
{
	int ok;
	int auxIdUno;
	int auxIdDos;
	Jugador* auxJugadorUno = (Jugador*)punteroUno;
	Jugador* auxJugadorDos = (Jugador*)punteroDos;

	if(auxJugadorUno!=NULL && auxJugadorDos!=NULL)
	{
		jug_getEdad(auxJugadorUno, &auxIdUno);
		jug_getEdad(auxJugadorDos, &auxIdDos);

		if(auxIdUno>auxIdDos)
		{
			ok=1;
		}
		else if(auxIdUno<auxIdDos)
		{
			ok=-1;
		}
		auxJugadorUno=NULL;
		auxJugadorDos=NULL;
	}

	return ok;
}

int jug_ordenarPorId(void* punteroUno, void* punteroDos)
{
	int ok;
	int auxIdUno;
	int auxIdDos;
	Jugador* auxJugadorUno = (Jugador*)punteroUno;
	Jugador* auxJugadorDos = (Jugador*)punteroDos;

	if(auxJugadorUno!=NULL && auxJugadorDos!=NULL)
	{
		jug_getId(auxJugadorUno, &auxIdUno);
		jug_getId(auxJugadorDos, &auxIdDos);

		if(auxIdUno>auxIdDos)
		{
			ok=1;
		}
		else if(auxIdUno<auxIdDos)
		{
			ok=-1;
		}
		auxJugadorUno=NULL;
		auxJugadorDos=NULL;
	}

	return ok;
}

int jug_ordenarPorNombre(void* punteroUno, void* punteroDos)
{
    int ok;
    char auxNombreUno[50];
    char auxNombreDos[50];
    Jugador* auxJugadorUno = (Jugador*)punteroUno;
    Jugador* auxJugadorDos = (Jugador*)punteroDos;

    if(auxJugadorUno!=NULL && auxJugadorDos!=NULL)
    {
    	jug_getNombreCompleto(auxJugadorUno,auxNombreUno);
    	jug_getNombreCompleto(auxJugadorDos,auxNombreDos);

    	if(strcmp(auxNombreUno,auxNombreDos)<0)
    	{
    		ok=-1;
    	}
    	else if(strcmp(auxNombreUno,auxNombreDos)>0)
    	{
    		ok=1;
    	}
    	auxJugadorUno=NULL;
    	auxJugadorDos=NULL;
    }

    return ok;
}

int jugadorBuscarId(Jugador* this,int* resultado)
{
    int ok = 0;

    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;

        ok = 1;
    }
    return ok;
}

int jug_buscarIdJugador(LinkedList* pArrayListJugador, int* posicionId, int id)
{
    int ok = 0;
    int idAux = 0;
    Jugador* pJugador = NULL;

    if(pArrayListJugador != NULL && posicionId != NULL  && id >= 1)
    {
    	*posicionId = -1;
        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {
        	pJugador = ll_get(pArrayListJugador, i);

            if(pJugador != NULL)
            {
            	jugadorBuscarId(pJugador, &idAux);
                if(id == idAux)
                {
                  *posicionId = i;
                  ok = 1;
              }
          }
       }
    }
    return ok;
}

int jug_validarJugador(LinkedList* pArrayListJugador, int id)
{
    int valido = 0;
    int indice;

    if(jug_buscarIdJugador(pArrayListJugador,&indice ,id))
    {
        if(indice != -1)
        {
        	valido = 1;
        }
    }
    else
	{
		printf("No existe ese id en el sistema \n");
	}
    return valido;
}


int jug_posiciones(char* puesto)
{
    int ok = 0;
    int opcion;
    if(puesto != NULL)
    {
        switch(menuOpcionesPuestos(&opcion))
            {
            case 1:
                strcpy(puesto,"Portero");
                break;
            case 2:
                strcpy(puesto,"Defensa Central");
                break;
            case 3:
                strcpy(puesto,"Lateral izquierdo");
                break;
            case 4:
                strcpy(puesto,"Lateral derecho");
                break;
            case 5:
				strcpy(puesto,"Pivote");
				break;
            case 6:
				strcpy(puesto,"Mediocentro");
				break;
            case 7:
				strcpy(puesto,"Mediocentro ofensivo");
				break;
            case 8:
				strcpy(puesto,"Extremo izquiero");
				break;
            case 9:
				strcpy(puesto,"Extremo derecho");
				break;
            case 10:
				strcpy(puesto,"Mediapunta");
				break;
            case 11:
				strcpy(puesto,"Delantero centro");
				break;
            }
        ok = 1;
    }
    return ok;
}

int jug_nacionalidades(char* nacio)
{
    int ok = 0;
    int opcion;
    if(nacio != NULL)
    {
        switch(menuOpcionNacionalidades(&opcion))
            {
            case 1:
                strcpy(nacio,"Aleman");
                break;
            case 2:
                strcpy(nacio,"Arabe");
                break;
            case 3:
                strcpy(nacio,"Argentino");
                break;
            case 4:
                strcpy(nacio,"Austriaco");
                break;
            case 5:
				strcpy(nacio,"Belga");
				break;
            case 6:
				strcpy(nacio,"Brasilero");
				break;
            case 7:
				strcpy(nacio,"Canadiense");
				break;
            case 8:
				strcpy(nacio,"Camerunes");
				break;
            case 9:
				strcpy(nacio,"Sud Coreano");
				break;
            case 10:
				strcpy(nacio,"Costarricense");
				break;
            case 11:
				strcpy(nacio,"Croata");
				break;
            case 12:
				strcpy(nacio,"Dinamarques");
				break;
			case 13:
				strcpy(nacio,"Ecuatoriano");
				break;
			case 14:
				strcpy(nacio,"Espaniol");
				break;
			case 15:
				strcpy(nacio,"Estadounidense");
				break;
			case 16:
				strcpy(nacio,"Frances");
				break;
			case 17:
				strcpy(nacio,"Gales");
				break;
			case 18:
				strcpy(nacio,"Ghanes");
				break;
			case 19:
				strcpy(nacio,"Ingles");
				break;
			case 20:
				strcpy(nacio,"Irani");
				break;
			case 21:
				strcpy(nacio,"Japones");
				break;
			case 22:
				strcpy(nacio,"Marroqui");
				break;
			case 23:
				strcpy(nacio,"Mexicano");
				break;
			case 24:
				strcpy(nacio,"Nerlandes");
				break;
			case 25:
				strcpy(nacio,"Polaco");
				break;
			case 26:
				strcpy(nacio,"Portugues");
				break;
			case 27:
				strcpy(nacio,"Qatari");
				break;
			case 28:
				strcpy(nacio,"Senegales");
				break;
			case 29:
				strcpy(nacio,"Serbio");
				break;
			case 30:
				strcpy(nacio,"Suizo");
				break;
			case 31:
				strcpy(nacio,"Tunecino");
				break;
			case 32:
				strcpy(nacio,"Uruguayo");
				break;
            }
        ok = 1;
    }
    return ok;
}



