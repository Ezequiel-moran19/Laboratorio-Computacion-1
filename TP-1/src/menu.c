#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "menu.h"
#include "calculos.h"

int menuPrincipal(float* pHosp, float* pCom, float* pTransp, int* pA, int* pD, int* pM, int* pDel)
{
    int opcion;
    if(pHosp != NULL && pCom != NULL && pTransp != NULL && pA != NULL && pD != NULL && pM != NULL  && pDel != NULL)
   	{
		system("cls");
		printf(" ____________________________________\n");
		printf("|                                    |\n");
		printf("|           MENU PRINCIPAL           |\n");
		printf("|____________________________________|\n\n");
		printf("1.Ingreso de los Costos de mantenimiento \n");
		printf("    Costo de hospedaje -> %.2f\n", *pHosp);
		printf("    Costo de comida -> %.2f\n", *pCom);
		printf("    Costo de Transporte -> %.2f\n", *pTransp);

		printf("2.Carga de jugadores \n");
		printf("    Arqueros -> %d\n", *pA );
		printf("    Defensores -> %d\n", *pD);
		printf("    Mediocampistas -> %d\n", *pM);
		printf("    Delanteros -> %d\n", *pDel);

		printf("3-Realizar todos los calculos \n");
		printf("4.Informar todos los resultados \n");
		printf("5.Salir \n\n");

		printf("Ingrese Opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);
   	}
    return opcion;
}

int subMenuConfederaciones(){
	int opcion;
    if(utn_getNumeroInt(&opcion,
	" ________________________________ \n"
	"|                                |\n"
	"|    **MENU CONFEDERACIONES**    |\n"
	"|________________________________|\n"
	"|                                |\n"
	"|1-AFC [Liga de Asia]            |\n"
	"|2-CAF [Liga de Africa]          |\n"
	"|3-CONCACAF [Liga del Norte]     |\n"
	"|4-CONMEBOL [Liga de Sudamerica] |\n"
	"|5-UEFA [Liga Europea]           |\n"
	"|6-OFC [Liga de Oceania]         |\n"
	"|________________________________|\n"
	"Ingrse una opcion:",
	 "\nReingrese Opcion ('1' a '6')\n",1,6,2)==0){}
	return opcion;
}


int cargarLiga(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6)
{
	int ok=0;
	if(p1 != NULL && p2 != NULL && p3 != NULL && p4 != NULL && p5 != NULL && p6 != NULL)
	{
		 switch(subMenuConfederaciones())
		    {
		    case 1:
		        (*p1)++;
		        break;
		    case 2:
		        (*p2)++;
		        break;
		    case 3:
		        (*p3)++;
		        break;
		    case 4:
		        (*p4)++;
		        break;
		    case 5:
		         (*p5)++;
		        break;
		    case 6:
		        (*p6)++;
		        break;
		    }
		 ok = 1;
	}
   return ok;
}

int mostrarPomedios(float* pL1, float* pL2, float* pL3, float* pL4, float* pL5, float* pL6)
{
	int ok=0;
	if(pL1 != NULL && pL2 != NULL && pL3 != NULL && pL4 != NULL && pL5 != NULL && pL6)
	{
	    printf(" _____________________________________________ \n");
		printf("|                                             |\n");
		printf("|   *** INFORME DE TODOS LOS RESULTADOS ***   |\n");
		printf("|_____________________________________________|\n\n");
		printf("Porcentaje AFC %.2f\n",*pL1);
		printf("Porcentaje CAF %.2f\n",*pL2);
		printf("Porcentaje CONCACAF %.2f\n",*pL3);
		printf("Porcentaje CONMEBOL %.2f\n",*pL4);
		printf("Porcentaje UEFA %.2f\n",*pL5);
		printf("Porcentaje OFC %.2f\n",*pL6);
		ok=1;
	}
   return ok;
}

int informarResultados(int* pFlagM, int* pFlagJ, int* pFlagC)
{
    int ok = 0;
    if(pFlagM!= NULL && pFlagJ != NULL && pFlagC != NULL)
    {
        if(*pFlagC)
        {
            *pFlagC = 0;
            *pFlagJ = 0;
            *pFlagM = 0;
        }
        else if(*pFlagJ)
        {
            printf("Para ingresar a informes, debe realizar los calculos)\n\n");
        }
        else if(*pFlagM)
        {
            printf("Para ingresar a informes, cargue al menos un jugador y luego realice los calculos)\n\n");
        }
        else
        {
            printf("Para ingresar a informes, deber ingresar los costos, cargar jugadores y realizar los calculos\n\n");
        }
        ok = 1;
    }
    return ok;
}
