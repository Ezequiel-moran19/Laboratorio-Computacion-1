#include <time.h>
#include <string.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "Controller.h"
#include "movie.h"

int main()
{
    srand(time(NULL));
    LinkedList* listaPelis = ll_newLinkedList();
    char salir = 'n';
    char archivo[20];

    do{
        switch(menuPrincipal())
        {
            case 1:
                utn_getString(archivo, "Ingrese el nombre del archivo[ movies.csv ]: ","Error reingrese el nombre del archivo[ movies.csv ]\n",1,20,5);
                controller_cargarDesdeTexto("movies.csv",listaPelis);
              break;
            case 2:
                   controller_imprimirLista(listaPelis);
				break;
			case 3:
                   controller_mapRating(listaPelis);
				break;
			case 4:
                   controller_mapGenero(listaPelis);
				break;
		    case 5:
                   controller_filtrarGenero(listaPelis);
                break;
			case 6:
                   ordenar_generoRating(listaPelis);
				break;
			case 7:
                  controller_cargarDesdeTexto("listaOrdenada.csv",listaPelis);
				break;
            case 8:
                confirmarSalida(&salir);
				break;
        }
        system("pause");
    }while(salir != 's');

    return 0;
}
