#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "menu.h"
#include "UTN_lib.h"

int main()
{
	setbuf(stdout,NULL);
    char salir = 'n';
    int nextId = 371;
    char aucConfe[50];
    int flagCarga =0;
    int flagPunto6 =0;
    int flagPunto8 =0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
        switch(menuPrincipal())
        {
            case 1:
            	if((ll_isEmpty(listaJugadores) && ll_isEmpty(listaSelecciones))==1)
            	{
            		 controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            		 controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
            		 flagCarga = 1;
            	}
            	else
				{
					printf("Ya realizo la cargar\n");
				}
                break;
            case 2:
            	if(flagCarga)
            	{
            		if(!controller_agregarJugador(listaJugadores, &nextId))
					{
						printf("No se pudo realizar el Alta\n");
					}
					else
					{
						printf("Alta realizado con exito!!!\n");
					}
            	}
            	else
            	{
            		printf("Primero cargue los jugadores y las selecciones\n");
            	}
				break;
			case 3:
				if(flagCarga)
				{
					controller_editarJugador(listaJugadores);
				}
				else
            	{
            		printf("Primero cargue los jugadores y las selecciones\n");
            	}
				break;
			case 4:
				if(flagCarga)
				{
					controller_removerJugador(listaJugadores);
				}
				else
				{
					printf("Primero cargue los jugadores y las selecciones\n");
				}
				break;
		    case 5:
		    	if(flagCarga)
				{
		    		controller_Listados(listaJugadores, listaSelecciones);
				}
				else
				{
					printf("Primero cargue los jugadores y las selecciones\n");
				}
		    	break;
			case 6:
				if(flagCarga)
				{
					controller_convocar_quitar(listaJugadores, listaSelecciones);
					flagPunto6=1;
				}
				else
				{
					printf("Primero cargue los jugadores y las selecciones\n");
				}
				break;
			case 7:
				if(flagCarga)
				{
					controller_ordenarAmbasEstructuras(listaJugadores, listaSelecciones);
				}
				else
				{
					printf("Primero cargue los jugadores y las selecciones\n");
				}
				break;
			case 8:
				if(flagPunto6)
				{
					selec_confederaciones(aucConfe);
					controller_generarArchivoBinario("confederacion.bin", listaJugadores, listaSelecciones, aucConfe);
					flagPunto8 =1;
				}
				else
				{
					printf("Primero realice la carga de convocados\n");
				}
				break;
			case 9:
				if(flagPunto8)
				{
					controller_cargarYListarArchivoBinario("confederacion.bin", listaJugadores, listaSelecciones, aucConfe);
				}
				else
				{
					printf("Para poder leer el archivo primero debe generarlo\n");
				}

				break;
			case 10:
				if(flagCarga)
				{
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
				    controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
				}
				else
				{
					printf("Para poder guardar los archivos primero debe cargue los jugadores y las selecciones\n");
				}

				break;
			case 11:
				confirmarSalida(&salir);
				break;
        }
        system("pause");
    }while(salir != 's');

    return 0;
}
