#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "UTN_lib.h"
#include "menu.h"


int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int ok = 0;
	FILE* f = NULL;

	if(path != NULL && pArrayListJugador != NULL)
	{
		f = fopen(path,"r");
		if (f != NULL)
		{
			parser_JugadorFromText(f, pArrayListJugador);

		    ok = 1;
		}
		fclose(f);
	}
	return ok;
}

int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{

	int ok = 0;

	if(path != NULL && pArrayListJugador != NULL)
	{
		FILE* file =fopen(path, "rb");

		if(file == NULL)
		{
			printf("ERROR");
		}
		else
		{
			parser_JugadorFromBinary(file, pArrayListJugador);
			ok = 1;
		}

		fclose(file);
	}
	return ok;
}


int controller_agregarJugador(LinkedList* pArrayListJugador, int* nextId)
{
	int ok = 0;
	char confirma;
	char nombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacional[30];
	Jugador* newJugador = jug_new();

	if(newJugador == NULL && nextId)
	{
		printf("No se pudo obtener memoria\n");
	}
	else
	{
		if( pArrayListJugador != NULL)
		{
			printf(" ______________________________________________________________________________ \n");
			printf("|                                                                              |\n");
			printf("|                             ***ALTA JUGADOR***                               |\n");
			printf("|______________________________________________________________________________|\n\n");
			newJugador->id = *nextId;
			if(cargaString(nombreCompleto, 100,"Ingrese Nombre\n","ERROR (Rango->0,50)\n")
			&& utn_getNumeroInt(&auxEdad,"Ingrese edad\n","ERROR (Rango->17,45)\n",17,45,2)==0)
			jug_posiciones(auxPosicion);
		    jug_nacionalidades(auxNacional);
		    {
				jug_setNombreCompleto(newJugador, nombreCompleto);
			    jug_setEdad(newJugador, auxEdad);
			    jug_setPosicion(newJugador, auxPosicion);
				jug_setNacionalidad(newJugador, auxNacional);
				printf(" __________________________________________________________________________ \n");
				printf("|                                                                          |\n");
				printf("|                           ***NUEVO JUGADOR***                            |\n");
				printf("|__________________________________________________________________________|\n\n");
				jug_mostrarUnJugador(newJugador);
				if(utn_getCharacter(&confirma,"\n¿DE VERDAD QUIERES AGREGAR AL JUGADOR? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
				{
					ll_add(pArrayListJugador, newJugador);
					(*nextId)++;
					printf("\n********************\n");
					printf("\n   CARGA EXITOSA   \n\n");
					printf("********************\n");
					ok = 1;
				}
				else
				{
					printf("\n********************\n");
					printf("\n  CARGA CANCELADA \n\n");
					printf("********************\n");
				}
		    }
		}
	}
	return ok;
}


int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int ok = 0;
	char salir;
	int id;
	char nombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacional[30];
	Jugador* pJugador = NULL;
	int index = 0;

	if(pArrayListJugador != NULL)
	{
		printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                             ***MODIFICAR JUGADOR***                               |\n");
		printf("|___________________________________________________________________________________|\n\n");

		controller_listarJugadores(pArrayListJugador);
		if( utn_getNumeroInt(&id,"Ingrese id\n","\nReingrese Opcion ('1' a '3000')\n",1,3000,2)==0
		&& jug_buscarIdJugador(pArrayListJugador, &index, id))
		{

			do{
				pJugador = (Jugador*) ll_get(pArrayListJugador, index);

				if(pJugador == NULL)
				{
					printf("Jugador no encontrado\n");
				}
				else
				{
					jug_mostrarUnJugador(pJugador);
					switch(menuModificaciones())
					{
						case 1:
							jug_mostrarUnJugador(pJugador);
							printf("_____________________________________________________________________________________________________________ \n\n");
							if(cargaString(nombre, 50,"Ingrese Nombre: ","ERROR (Rango->0,50)\n"))
							{
								jug_setNombreCompleto(pJugador, nombre);
								printf("Nombre modificado con exito!\n\n");
							}
							break;
						case 2:
							jug_mostrarUnJugador(pJugador);
							printf("_____________________________________________________________________________________________________________ \n\n");
							if(utn_getNumeroInt(&auxEdad,"Ingrese edad: ","ERROR (Rango->1,45)\n",1,45,2)==0)
							{
								jug_setEdad(pJugador, auxEdad);
								printf("Edad modificado con exito!\n");
							}
							break;

						case 3:
							jug_mostrarUnJugador(pJugador);
							printf("_____________________________________________________________________________________________________________ \n\n");
							    jug_posiciones(auxPosicion);

								jug_setPosicion(pJugador, auxPosicion);
								printf("Posicion modificado con exito!\n");

							break;
						case 4:
							jug_mostrarUnJugador(pJugador);
							printf("_____________________________________________________________________________________________________________ \n\n");
						        jug_nacionalidades(auxNacional);
								jug_setNacionalidad(pJugador, auxNacional);
								printf("Posicion modificado con exito!\n");
							break;
						case 5:
							confirmarSalida(&salir);
							break;
					}
				}

			}while(salir != 's');
		}

		ok = 1;
	}
	return ok;
}

int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int ok = 0;
	char confirma = 'n';
	int jugId;
	int index;
	Jugador* pJugado = NULL;

	if(pArrayListJugador != NULL)
	{
		printf(" ________________________________________________________________________ \n");
		printf("|                                                                        |\n");
		printf("|                          ***ELIMINAR JUGADOR***                        |\n");
		printf("|________________________________________________________________________|\n\n");

		if(controller_listarJugadores(pArrayListJugador))
		{
			if(utn_getNumeroInt(&jugId, "Ingrese el id que desea remover: \n","\nReingrese Opcion ('1' a '2000')\n",1,2000,2)==0
		    && jug_buscarIdJugador(pArrayListJugador, &index, jugId))
	        {
			    pJugado = (Jugador*) ll_get(pArrayListJugador, index);

				if(pJugado == NULL)
				{
					printf("Jugadores no encontrado\n");
				}
				else
				{
					printf(" ________________________________________________________________________ \n");
					printf("|                                                                        |\n");
					printf("|                          ***ELIMINAR JUGADOR***                        |\n");
					printf("|________________________________________________________________________|\n\n");
					jug_mostrarUnJugador(pJugado);

					if(utn_getCharacter(&confirma,"Confirma baja? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma =='s')
					{
						index = ll_indexOf(pArrayListJugador, pJugado);
						ll_remove(pArrayListJugador, index);
						printf("\n********************\n");
						printf("\n   CARGA EXITOSA   \n\n");
						printf("********************\n");
						ok = 1;
					}
					else
					{
						printf("\n********************\n");
						printf("\n   BAJA CANCELADA  \n\n");
						printf("********************\n");

					}
				}
		   }
		   else
		   {
				printf("\n\nRevise el dato ingresado y vuelva a intentar\n.");
		   }
		}
	}
	return ok;
}

int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int ok = 0;
	int tam;
	Jugador* pJugador = NULL;

	if(pArrayListJugador != NULL)
	{
		tam = ll_len(pArrayListJugador);
		printf(" ____________________________________________________________________________________________________________\n");
		printf("|                                                                                                            |\n");
		printf("|			                LISTADO DE JUGADORES                                                 |\n");
		printf("|____________________________________________________________________________________________________________|\n");
		printf("|  ID 	          NOMBRECOMPLETO       EDAD               POSICION          NACIONALIDAD          SELECCION  |\n");
		printf("|____________________________________________________________________________________________________________|\n");

		for(int i=0; i < tam; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_mostrarUnJugador(pJugador);
			ok = 1;
		}
	}
	else
    {
        printf("Primero debe cargar jugadores\n");
    }
	return ok;

}

int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int ok = 0;
		int criterio = -1;

		if(pArrayListJugador != NULL)
		{
			ll_sort(pArrayListJugador, jug_ordenarPorId, criterio);
			printf("Listado de jugadores fueron ordenado con Exito!!\n");
			ok = 1;
		}
		else
		{
			printf("Primero debe cargar Jugadores\n");
		}
		return ok;

}

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{

	  int ok = 0;
	  FILE* fArchivo;
	  int id;
	  char nombreCompleto[100];
	  int edad;
	  char posicion[30];
	  char nacionalidad[30];
	  int idSeleccion;
	  Jugador *pJugador;

	  if (path != NULL && pArrayListJugador != NULL )
	  {
		  fArchivo = fopen(path, "w");
		  if(fArchivo == NULL )
		  {
			  printf("No se pudo abrir el archivo\n");
		  }
		  fprintf(fArchivo, "Id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		  for (int i = 0; i < ll_len(pArrayListJugador); i++)
		  {
			  pJugador = ll_get(pArrayListJugador, i);
			  if( jug_getId(pJugador, &id)
			  &&  jug_getNombreCompleto(pJugador, nombreCompleto)
			  &&  jug_getEdad(pJugador, &edad)
			  &&  jug_getPosicion(pJugador, posicion)
			  &&  jug_getNacionalidad(pJugador, nacionalidad)
			  &&  jug_getIdSeleccion(pJugador, &idSeleccion))
			  {
				  fprintf(fArchivo, "%d,%s,%d,%s,%s,%d\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
				  ok = 1;
			  }
		  }
		  printf("\nGuardado!!!\n");
	  }
	  fclose(fArchivo);
	  return ok;
}

int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int ok = 0;
	FILE* pFile= NULL;
	Jugador* pJugador = NULL;
	int tamLista;

	if (path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "wb");
		tamLista = ll_len(pArrayListJugador);
		for (int i = 0; i < tamLista; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if (pJugador != NULL)
			{
				fwrite(pJugador, sizeof(Jugador), 1, pFile);
			}
		}
		fclose(pFile);
		ok = 1;
	}
	return ok;

}

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	FILE* f = NULL;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
		  parser_SeleccionFromText(f, pArrayListSeleccion);
	      ok = 1;
		}
		fclose(f);
	}
	return ok;
}

int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	int id;
	char pais[30];
	Seleccion* pSeleccion = NULL;
	int index = 0;

	if(pArrayListSeleccion != NULL)
	{
		printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                             ***MODIFICAR SELECCION***                               |\n");
		printf("|___________________________________________________________________________________|\n\n");

		if( utn_getNumeroInt(&id,"Ingrese id\n","\nReingrese Opcion ('1' a '32')\n",1,32,2)==0)
		{
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index);

			if(pSeleccion == NULL)
			{
				printf("Seleccion no encontrada\n");
			}
			else
			{
				selec_mostrarUnaSeleccion(pSeleccion);
				if(menuModificarSeleciones())
				{
					selec_mostrarUnaSeleccion(pSeleccion);
					printf("______________________________________ \n\n");
					if(cargaString(pais, 50,"Ingrese PAIS\n","ERROR (Rango->0,50)\n"))
					{
						 strcpy(pSeleccion->pais, pais);
						 printf("Pais modificado con exito!\n");
					}

				}
			}
		}

		ok = 1;
	}
	return ok;
}

int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	int tam;
	Seleccion* pSeleccion= NULL;
	if(pArrayListSeleccion != NULL)
	{
		tam = ll_len(pArrayListSeleccion);
		printf(" _______________________________________________________________________\n");
		printf("|                                                                       |\n");
		printf("|			LISTADO DE SELECCIONES                          |\n");
		printf("|_______________________________________________________________________|\n");
		printf("|  ID 	    PAIS        	  CONFEDERACION             CONVOCADOS  |\n");
		printf("|_______________________________________________________________________|\n");

		for(int i=0; i < tam; i++)
		{
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_mostrarUnaSeleccion(pSeleccion);
			ok = 1;
		}
	 }
	 else
	 {
		printf("\nNo hay Seleciones en el sistema\n");
	 }
	return ok;

}

int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	int criterio = -1;

	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, criterio);
		printf("Listado de selecciones ordenado por confederacion con Exito!!\n");

		ok = 1;
	}
	else
	{
		printf("Primero debe cargar Jugadores\n");
	}
	return ok;
}

int controller_ordenarAmbasEstructuras(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	 int ok = 0;
	 int criterio;
	 if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	 {
		 ok = pidoValidoNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
		while(!ok)
		{
			ok = pidoValidoNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
		}
		 switch(menuPcionesOrdenamiento())
		 {
		 	case 1:
				 ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, criterio);
				 controller_listarJugadores(pArrayListJugador);
				 printf("Listado de nacionalidades ordenadas con Exito!!\n");
			break;
			case 2:
				 ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, criterio);
				 controller_listarSelecciones(pArrayListSeleccion);
				 printf("Listado de confederaciones ordenadas con Exito!!\n");
				break;
			case 3:
				 ll_sort(pArrayListJugador, jug_ordenarPorEdad, criterio);
				 controller_listarJugadores(pArrayListJugador);
				 printf("Listado de edades ordenada con Exito!!\n");
				break;
			case 4:
				 ll_sort(pArrayListJugador, jug_ordenarPorNombre, criterio);
				 controller_listarJugadores(pArrayListJugador);
				 printf("Listado de nombres ordenado con Exito!!\n");
				break;
			}
		 ok = 1;
     }
	 else
	 {
	      printf("\nNo hay suficientes jugadores ingresados en sistema para la acción seleccionado.\n");
	 }
	 return ok;
}

int controller_guardarSeleccionesModoTexto(char *path, LinkedList *pArrayListSeleccion)
{
	 int ok = 0;
	 FILE* fArchivo;
	 int id;
	 char pais[30];
	 char confederacion[30];
	 int convocados;
	 Seleccion *pSeleccion;

	 if (path != NULL && pArrayListSeleccion != NULL )
	 {
		 fArchivo = fopen(path, "w");
		 if(fArchivo == NULL )
		 {
			  printf("No se pudo abrir el archivo\n");
		 }
		 fprintf(fArchivo, "Id,pais,confederacion,convocados,nacionalidad\n");

		 for (int i = 0; i < ll_len(pArrayListSeleccion); i++)
	     {
			  pSeleccion = ll_get(pArrayListSeleccion, i);
			  if( selec_getId(pSeleccion, &id)
			  &&  selec_getPais(pSeleccion, pais)
			  &&  selec_getConfederacion(pSeleccion, confederacion)
			  &&  selec_getConvocados(pSeleccion, &convocados) )

		     {
			    fprintf(fArchivo, "%d,%s,%s,%d\n", id, pais, confederacion, convocados);
			    ok = 1;
		     }
	    }
	    printf("\nGuardado!!!\n");
	 }
	 fclose(fArchivo);
	return ok;
}

int controller_listarConvocados(LinkedList* pArrayListJugador)
{
	int ok = 0;
	Jugador* pJugador;
	int idSeleccion;
	int flag =0;
	int tam;

	if(pArrayListJugador != NULL )
	{
		tam = ll_len(pArrayListJugador);
		printf(" _________________________________________________________________________________________________________________\n");
		printf("|                                                                                                                 |\n");
		printf("|						  LISTADO DE CONVOCADOS                                           |\n");
		printf("|_________________________________________________________________________________________________________________|\n");
		printf("|  ID 	    NOMBRECOMPLETO       	  EDAD            POSICION              NACIONALIDAD        SELECCION     |\n");
		printf("|_________________________________________________________________________________________________________________|\n");
		for(int i=0; i < tam; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getIdSeleccion(pJugador, &idSeleccion);
			if(idSeleccion != 0)
			{
				jug_mostrarUnJugador(pJugador);
				flag=1;
				ok = 1;
			}
		}
		ok = 1;
	}
	if(!flag)
	{
		printf("No hay jugadores convocado en ninguna seleccion\n");
	}
	return ok;
}

int controller_listarSeleccionesDisponiblesAConvocar(LinkedList* pArrayListSeleccion)
{
    int ok = 0;
    Seleccion* pSeleccion;
    int convocados;
    int tam;

    if(pArrayListSeleccion != NULL )
    {
    	tam = ll_len(pArrayListSeleccion);
    	printf(" _______________________________________________________________________\n");
		printf("|                                                                       |\n");
		printf("|			LISTADO DE SELECCIONES                          |\n");
		printf("|_______________________________________________________________________|\n");
		printf("|  ID 	    PAIS        	  CONFEDERACION             CONVOCADOS  |\n");
		printf("|_______________________________________________________________________|\n");

        for(int i=0; i < tam ; i++)
        {
        	pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
        	selec_getConvocados(pSeleccion, &convocados);
            if(convocados <= 22)
            {
                selec_mostrarUnaSeleccion(pSeleccion);
            }
        }
        ok = 1;
    }
    else
    {
        printf("Primero debe cargar una seleccion\n");
    }
    return ok;
}


int controller_Listados(LinkedList *pArrayListJugador, LinkedList *pArrayLisSeleccion)
{
	int ok = 0;
	char salir = 'n';
	if (pArrayListJugador != NULL && pArrayLisSeleccion != NULL) {
		do {
			switch (menuListados()) {
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayLisSeleccion);
				break;
			case 3:
				controller_listarConvocados(pArrayListJugador);
				break;
			case 4:
				confirmarSalida(&salir);
				break;
			}
			system("pause");
		} while (salir != 's');
		ok = 1;
	}
	return ok;

}

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int todoOk = 0;
	int tamJ = ll_len(pArrayListJugador);
	int tamS = ll_len(pArrayListSeleccion);
	int id;
	int idS;
	int convocado;
	Jugador* pJugador;
	Seleccion* pSeleccion;
	int idJugador;
	int idSeleccion;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
	    controller_listarJugadores(pArrayListJugador);
		if(utn_getNumeroInt(&idJugador,"Ingrese id: ","\nReingrese Opcion ('1' a '3000')\n",1,3000,2)==0
		&& jug_validarJugador(pArrayListJugador, idJugador))
		{
			controller_listarSeleccionesDisponiblesAConvocar(pArrayListSeleccion);
			utn_getNumeroInt(&idSeleccion, "Ingrese el id seleccion: ","\nReingrese Opcion ('1' a '32')\n",1,32,2);
		}

		for(int i = 0; i < tamJ; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(pJugador, &id);
			if((id == idJugador))
			{
				jug_setIdSeleccion(pJugador, idSeleccion);
				break;
			}
		}

		for(int j = 0; j < tamS; j++)
		{
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);
			selec_getId(pSeleccion, &idS);
			if((idS == idSeleccion))
			{
				selec_getConvocados(pSeleccion, &convocado);
				convocado++;
				selec_setConvocados(pSeleccion, convocado);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int controller_quitarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int ok = 0;
	int idJug;
	int id;
	int idJugSelec;
	int posicion;
	int posicionSelec;
	int convocado;
	Jugador* pJugador;
	Seleccion* pSeleccion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		controller_listarConvocados(pArrayListJugador);
	    utn_getNumeroInt(&id, "Ingrese el id jugador: \n","\nReingrese Opcion ('1' a '2000')\n",1,2000,2);

	    jug_buscarIdJugador(pArrayListJugador, &posicion, id);

	    if(posicion != -1)
	    {
	    	 pJugador = (Jugador*) ll_get(pArrayListJugador, posicion);

	    	 jug_getId(pJugador, &idJug);

	    	 jug_getIdSeleccion(pJugador, &idJugSelec);

	    	 if(idJug == id)
			 {
	    		 selec_buscarIdSeleccion(pArrayListSeleccion, &posicionSelec, idJugSelec);
	    		 if(posicionSelec != -1)
	    		 {
	    			 pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, posicionSelec);
	    			 selec_getConvocados(pSeleccion, &convocado);
	    			 convocado--;
	    			 selec_setConvocados(pSeleccion, convocado);
	    			 jug_setIdSeleccion(pJugador, 0);
	    			ok = 1;
	    		 }
			 }
	    }
	}
	return ok;
}

int controller_convocar_quitar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	char salir = 'n';
	int ok = 0;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		do{

		  switch(menuPuntoSeis())
		  {
			case 1:
				 controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion);
				break;
			case 2:
				 controller_quitarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
				break;
			case 3:
				confirmarSalida(&salir);
				break;
		   }
		}while(salir != 's');
		ok = 1;
	}
	return ok;
}

int controller_generarArchivoBinario(char *path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char *confe)
{
	int ok = 0;
	int idSelecJugador;
	char confeAux[50];
	int tam = ll_len(pArrayListJugador);
	Jugador* pJugador = NULL;

	if(path != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL && confe != NULL)
	{
		LinkedList* pLinkedAux = ll_newLinkedList();
		for(int i =0; i < tam; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getIdSeleccion(pJugador, &idSelecJugador);
			if(idSelecJugador > 0)
			{
				cargarConfederacion(pArrayListSeleccion, idSelecJugador, confeAux);
				if(strcmp(confeAux, confe)==0)
				{
					ll_add(pLinkedAux, pJugador);
					controller_guardarJugadoresModoBinario(path, pLinkedAux);
				}
			}
		}
		ok = 1;
	}
	return ok;
}

int controller_cargarYListarArchivoBinario(char *path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char *confe)
{
	int ok = 0;

	if(path != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL && confe != NULL)
	{
		LinkedList* pListJug = ll_clone(pArrayListJugador);
        controller_cargarJugadoresDesdeBinario(path, pListJug);
        controller_listarConvocados(pListJug);
		ok = 1;
	}
	return ok;
}
