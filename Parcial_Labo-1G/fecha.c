#include <stdio.h>
#include <stdlib.h>
#include "UTN_lib.h"
#include "fecha.h"

int validoAnioBisiesto(int anio)
{
    int ok = 0;
    if(anio && anio % 4 == 0)
    {
        ok = 2;
    }else{
        ok = 1;
    }
    return ok;
}

int validoDiaMes(int mes, int dia, int anio)
{
    int ok = 1;
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if(dia > 30)
        {
            printf("Este mes solo tiene 30 dias\n");
            ok = 0;
        }
    }

    else if(mes == 2 && validoAnioBisiesto(anio) != 2)
    {
        if(dia > 29)
        {
            printf("Este mes solo tiene 29 dias.\n");
            ok = 0;
        }
        else if(dia > 28)
        {
            printf("Este mes solo tiene 28 dias.\n");
            ok = 0;
        }
    }
    return ok;
}

int pidoValidoFecha(eFecha* fecha)
{
    int ok = 1;
    eFecha nuevaFecha;
    if(utn_getNumeroInt(&nuevaFecha.dia,"Ingrese dia\n","ERROR (Rango->0,31)\n",1,31,2)==0
    && utn_getNumeroInt(&nuevaFecha.mes,"Ingrese mes\n","ERROR (Rango->0,12)\n",1,12,2)==0
    && utn_getNumeroInt(&nuevaFecha.anio,"Ingrese anio\n","ERROR (Rango->1900,2022)\n",1900,2022,2)==0)
    {
        while(!validoDiaMes(nuevaFecha.mes, nuevaFecha.dia, nuevaFecha.anio))
        {
            printf("Ingreso Invalido. Reintente\n");
            ok = 0;
            break;
        }
    }
    *fecha = nuevaFecha;
    return ok;
}

