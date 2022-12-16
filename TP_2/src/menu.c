#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "menu.h"

int menuPrincipal(){
	int opcion;
	if(utn_getNumeroInt(&opcion,
	" _________________________________________________ \n"
	"|                                                 |\n"
	"|                **MENU PRINCIPAL**               |\n"
	"|_________________________________________________|\n"
	"|                                                 |\n"
	"|1-ALTA JUGADOR                                   |\n"
	"|2-BAJA DE JUGADOR.                               |\n"
	"|3-MODIFICACION DE JUGADOR.                       |\n"
	"|4-INFORMES.                                      |\n"
	"|5-SALIR.                                         |\n"
	"|_________________________________________________|\n"
	"Ingrse una opcion:",
    "\nReingrese Opcion ('1' a '5')\n",1,5,2)==0){}
    return opcion;
}

int menuModificacion(){
  int opcion;
  if(utn_getNumeroInt(&opcion,
    " _____________________________________ \n"
	"|                                     |\n"
	"|       **CAMPO A MODIFICAR**         |\n"
	"|_____________________________________|\n"
	"|                                     |\n"
	"|1-Nombre                             |\n"
	"|2-Posicion                           |\n"
	"|3-Camiseta.                          |\n"
	"|4-Confederacion                      |\n"
    "|5-Salario.                           |\n"
    "|6-Anios de contrato                  |\n"
	"|5-SALIR.                             |\n"
	"|_____________________________________|\n"
    "Ingrse una opcion:",
    "ERROR (Rango 1->3)",1,5,2)==0){}
   return opcion;
}


int menuModificacionConfe(){
  int opcion;
  if(utn_getNumeroInt(&opcion,
    " __________________________________ \n"
	"|                                  |\n"
	"|      **CAMPO A MODIFICAR**       |\n"
	"|__________________________________|\n"
	"|                                  |\n"
	"|1-Nombre                          |\n"
	"|2-Region                          |\n"
	"|3-Anios de contrato.              |\n"
	"|4-SALIR.                          |\n"
	"|__________________________________|\n"
    "Ingrse una opcion:",
    "ERROR (Rango 1->3)",1,4,2)==0){}
   return opcion;
}

int menuInformes()
{
  int opcion;
  if(utn_getNumeroInt(&opcion,
  " ______________________________________________________________________________________________________ \n"
  "|                                                                                                      |\n"
  "|                                            **MENU INFORMES**                                         |\n"
  "|______________________________________________________________________________________________________|\n"
  "|                                                                                                      |\n"
  "|1-Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador  |\n"
  "|2-Listado de confederaciones con sus jugadores.                                                       |\n"
  "|3-Total y promedio de todos los salarios y cuántos jugadores cobran mas del salario promedio          |\n"
  "|4-Informar la confederación con mayor cantidad de años de contratos total.                            |\n"
  "|5-Informar porcentaje de jugadores por cada confederacion.                                            |\n"
  "|6-Informar cual es la region con mas jugadores y el listado de los mismos.                            |\n"
  "|7-SALIR.                                                                                              |\n"
  "|______________________________________________________________________________________________________|\n"
  "Ingrse una opcion:",
  "\nReingrese Opcion ('1' a '7')\n",1,7,2)==0){}
    return opcion;
}

int banderaAlta(int* pFlag)
{
    int ok = 0;
    if(pFlag != NULL)
    {
        *pFlag= 1;
        ok = 1;
    }
    return ok;
}

int banderaInformes(int* pFlagA, int* pFlagI)
{
    int ok = 0;
    if(pFlagA != NULL && pFlagI != NULL)
    {
        if(*pFlagA == 1)
        {
            *pFlagI = 1;
        }
        ok =1;
    }
    return ok;
}


