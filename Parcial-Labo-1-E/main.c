#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"
#include "articulo.h"
#include "fecha.h"

#define TAM 5
#define TAMR 4

int main()
{
    char salir = 'n';
    int proxId = 1000;
	eArticulo lista[TAM];
	eRubro listaR[TAMR] ={ {1000, "ELECTRONICA"}, {1001, "BLANCO"}, {1002, "AUDIO"}, {1003, "VIDEO"} };

	inicializarArticulos(lista, TAM);
	//datos hardcodeados para testear el duncionamiento
	//hardcodearAticulos(lista, TAM, 3, &proxId);

	do{
		switch(menuPrincipal()){
		case 1:

		   if(!altaArticulos(lista, TAM, &proxId, listaR, TAMR)){
                 printf("No se pudo realizar el Alta\n");
		    }else{
		        printf("Alta realizado con exito!!!\n");
		    }
			break;
		 case 2:
			modificarArticulos(lista, TAM, listaR, TAMR);
			break;
		 case 3:
			bajaArticulos(lista, TAM, listaR, TAMR);
			break;
		 case 4:
		    listarArticulos(lista, TAM, listaR, TAMR);

			break;
		 case 5:
			listarRubros(listaR, TAMR);
			break;
         case 6:
			printf("6. ALTA VENTA:\n");
			break;

         case 7:
			printf("7. LISTAR VENTAS\n");
			break;

		 case 8:
			printf("8. INFORMES\n");
			break;

		 case 9:
			 confirmarSalida(&salir);
			break;
         default:
			printf("La opcion ingresada no es valida\n");
            break;
		}
	  system("pause");
	}while(salir != 's');

    return 0;
}


