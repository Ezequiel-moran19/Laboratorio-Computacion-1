#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int validoAnio(int anio)
{
    int ok;
    int anioActual = 2022;
    if(anio < 1950 || anio > anioActual)
    {
        ok = 0;
        printf("Anio invalido\n");
    }
    else
    {
        ok = 1;
    }
    return ok;
}
int validoAnioBisiesto(int anio)
{
    int ok = 0;
    if(validoAnio(anio))
    {
        if(anio % 4 == 0)
        {
            ok = 2;
        }
        else
        {
            ok = 1;
        }
    }
    return ok;

}
int validoMes(int mes)
{
    int ok;
    if(mes < 1 || mes > 12)
    {
        ok = 0;
        printf("Mes invalido\n");
    }
    else
    {
        ok = 1;
    }
    return ok;
}

int validoDia(int dia)
{
    int ok;
    if(dia < 1 || dia > 31)
    {
        ok = 0;
        printf("Dia invalido\n");
    }
    else
    {
        ok = 1;
    }
    return ok;
}
int validoDiaMes(int mes, int dia, int anio)
{
    int ok = 1;
    if(validoDia(dia) && validoMes(mes) && validoAnio(anio))
    {
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if(dia > 30)
            {
                printf("Este mes solo tiene 30 dias\n");
                ok = 0;
            }
        }
        else
        {
            if(mes == 2)
            {
                if((validoAnioBisiesto(anio)) == 2)
                {
                    if(dia > 29)
                    {
                        printf("Este mes solo tiene 29 dias.\n");
                        ok = 0;
                    }
                }
                else
                {
                    if(dia > 28)
                    {
                        printf("Este mes solo tiene 28 dias.\n");
                        ok = 0;
                    }
                }
            }
            else
            {
                if(dia > 31)
                {
                    printf("Este mes solo tiene 31 dias.\n");
                    ok = 0;
                }
            }
        }
    }
    return ok;
}

int pidoValidoFecha(eFecha* fecha)
{
    int ok = 1;
    eFecha nuevaFecha;

    printf("Ingrese dia:");
    scanf("%d", &nuevaFecha.dia);
    while(!validoDia(nuevaFecha.dia))
    {
        printf("Ingreso Invalido\n Reingrese dia:");
        scanf("%d", &nuevaFecha.dia);
    }
    printf("Ingrese mes:");
    scanf("%d", &nuevaFecha.mes);
    while(!validoMes(nuevaFecha.mes))
    {
        printf("Ingreso Invalido\n Reingrese mes:");
        scanf("%d", &nuevaFecha.mes);
    }
    printf("Ingrese anio:");
    scanf("%d", &nuevaFecha.anio);
    while(!validoAnio(nuevaFecha.anio))
    {
        printf("Ingreso Invalido\n Reingrese anio:");
        scanf("%d", &nuevaFecha.anio);
    }
    while(!validoDiaMes(nuevaFecha.mes, nuevaFecha.dia, nuevaFecha.anio))
    {
        printf("Ingreso Invalido. Reintente\n");
        ok = 0;
        break;
    }
    *fecha = nuevaFecha;
    return ok;
}

