#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "UTN_lib.h"

int menuPrincipal()
{
	int opcion;
	if(utn_getNumeroInt(&opcion,
    " ___________________________ \n"
    "|                           |\n"
    "|        MENU PRINCIPAL     |\n"
    "|___________________________|\n"
    "|                           |\n"
    "|1-CARGA DE ARCHIVOS        |\n"
    "|2-IMPRIMIR LISTA           |\n"
    "|3-ASIGNAR RATING           |\n"
    "|4-ASIGNAR GENERO           |\n"
    "|5-FILTRAR POR GENERO       |\n"
    "|6-ORDENAR PELICULAS        |\n"
    "|7-GUARDAR PELICULAS        |\n"
    "|8-SALIR                    |\n"
    "|___________________________|\n"
    "Ingrse una opcion:",
    "\nReingrese Opcion ('1' a '8')\n",1,8,2)==0){}
	return opcion;
}

int menuOpcionesFiltroGenero(int* pOpc)
{
    int error = 1;
    int auxOpcion;
    if(pOpc != NULL)
    {
        if(utn_getNumeroInt(&auxOpcion,
        " __________________ \n"
        "|                  |\n"
        "|  FILTRAR GENERO  |\n"
        "|__________________|\n"
        "|                  |\n"
        "|1-Drama           |\n"
        "|2-Comedia         |\n"
        "|3-Accion          |\n"
        "|4-Terror          |\n"
        "|__________________|\n"
        "Ingrse una opcion:","\nReingrese Opcion ('1' a '4')\n",1,4,2)==0){}
        *pOpc = auxOpcion;
    }
    return error;
}
