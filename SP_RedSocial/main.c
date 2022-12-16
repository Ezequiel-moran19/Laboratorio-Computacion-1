#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "Controller.h"
#include "post.h"

int main()
{
    LinkedList* listaPost = ll_newLinkedList();
    char salir = 'n';
    char archivo[50];
    int flagCarga=0;
    int flagEstadistica=0;

    do{
        switch(menuPrincipal())
        {
            case 1:
                if(ll_isEmpty(listaPost)==1)
            	{
                    utn_getString(archivo, "Ingrese el nombre del archivo[ posts.csv ]: ","Error reingrese el nombre del archivo[ posts.csv ]\n",1,50,5);
                    if(controller_cargarJugadoresDesdeTexto(archivo, listaPost))
                    {
                        flagCarga = 1;
                    }
            	}
            	else
				{
					printf("Ya realizo la cargar\n");
				}
                break;
            case 2:
                if(flagCarga == 1)
				{
					controller_imprimirLista(listaPost);
				}
				else
            	{
            		printf("Primero cargue el archivo\n");
            	}
				break;
			case 3:
			    if(flagCarga)
				{
					controller_map(listaPost);
					flagEstadistica=1;
				}
				else
            	{
            		printf("Primero cargue el archivo\n");
            	}
				break;
			case 4:
			    if(flagCarga && flagEstadistica)
				{
					controller_filtrarPorLikes(listaPost);
				}
				else
            	{
            		printf("Primero cargue el archivo y luego asigne las estadisticas\n");
            	}
				break;
		    case 5:
		        if(flagCarga && flagEstadistica)
				{
					controller_filtrarPorHeaters(listaPost);
				}
				else
            	{
            		printf("Primero cargue el archivo y luego asigne las estadisticas\n");
            	}
                break;
			case 6:
			   if(flagCarga && flagEstadistica)
				{
					 controller_ordenarPost(listaPost);
				}
				else
            	{
            		printf("Primero cargue el archivo y luego asigne las estadisticas\n");
            	}
				break;
			case 7:
			    if(flagCarga && flagEstadistica)
				{
                    controller_mostrarMasPopular(listaPost);
				}
				else
            	{
            		printf("Primero cargue el archivo y luego asigne las estadisticas\n");
            	}
				break;
			case 8:
                confirmarSalida(&salir);
				break;
        }
        system("pause");
    }while(salir != 's');

    return 0;
}
