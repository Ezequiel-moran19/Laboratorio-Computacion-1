
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int division(float* pResultado, int operador1, int operador2)
{
   	float result;
   	int ok= -1;

   	if(pResultado!= NULL && operador2!=0)
   	{
   		result= (float) operador1 / operador2;
   		(*pResultado) = result;
   		ok= 0;
   	}

   	return ok;
}


float calcularCostos(float* pN1, float* pN2, float* pN3)
{
    float ok;
    ok = *pN1 + *pN2 + *pN3;
    return ok;
}

int banderaMantenimiento(int* pFlag)
{
    int ok = 0;
    if(pFlag != NULL)
    {
        *pFlag= 1;
        ok = 1;
    }

    return ok;
}


int banderaJugador(int* pFlagMantenimiento, int* pFlagJugador)
{
    int ok = 0;

    if(pFlagMantenimiento != NULL && pFlagJugador != NULL)
    {
        if(*pFlagMantenimiento == 1)
        {
            *pFlagJugador = 1;
        }

        else
        {
            printf("Antes de ingresar un jugador debe ingresar los gastos del punto 1)\n");
        }

        ok =1;
    }

    return ok;
}

int banderaCalcular( int* pFlagM, int* pFlagJ, int* pFlagC)
{
    int ok = 0;
    if(pFlagM != NULL && pFlagJ !=NULL && pFlagC != NULL)
    {
        if(*pFlagJ)
        {
            printf("Calculos realizados con exito!!!!\n\n");
            *pFlagC = 1;
        }
        else if(*pFlagM)
        {
            printf("Para realizar los calculos, antes debe cargar los jugadores.\n\n");

        }
        else
        {
            printf("Para realizar los calculos, debe cargar los costos y jugadores.\n\n");
        }
        ok = 1;
    }

    return ok;
}





