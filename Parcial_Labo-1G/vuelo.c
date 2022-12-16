#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "vuelo.h"

int inicializarVuelos(eVuelos vuelos[], int tamVuelos)
{
    int ok = 0;
    if(vuelos && tamVuelos > 0)
    {
        for(int i = 0; i < tamVuelos; i++)
        {
            vuelos[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibreVuelos(eVuelos vuelos[], int tamVuelos, int* pId)
{
    int ok = 0;
    if(vuelos && pId && tamVuelos > 0 )
    {
        *pId = -1;
        for(int i = 0; i < tamVuelos; i++)
        {
            if(vuelos[i].isEmpty == 1)
            {
                *pId = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}
int buscarVuelos(eVuelos vuelos[], int tamVuelos, int id, int* pIndice){
    int todoOk = 0;
    if( vuelos && pIndice && tamVuelos > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamVuelos; i++)
        {
            if(vuelos[i].idVuelos == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaVuelo(eVuelos vuelos[],int tamVuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD, eAerolineas aerolineas[],int tamA,eTipo tipos[],int tamT, int* pProxId)
{
    int ok = 0;
    int indice;
    eVuelos nuevoVuelo;

    if(vuelos != NULL && tamVuelos > 0 && aviones != NULL && tamAvion > 0 && destinos != NULL && aerolineas != NULL && tipos != NULL && tamD > 0 &&  tamA > 0 && pProxId)
    {
        printf("*** ALTA VUELOS ***\n\n");
        buscarLibreVuelos(vuelos, tamVuelos, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevoVuelo.idVuelos = *pProxId;
            listarAviones(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
            if(utn_getNumeroInt(&nuevoVuelo.idAvion,"Ingrese id\n","ERROR (Rango->1,5)\n",1,5,2)==0
            && validarAviones(aviones, tamAvion, nuevoVuelo.idAvion)==1)
            {
                listarDestinos(destinos, tamD);
                if(utn_getNumeroInt(&nuevoVuelo.idDestino, "Ingrese Destino: \n","\nReingrese Opcion ('20000' a '20003')\n",20000,20003,2)==0
                && validarDestinos(destinos, tamD, nuevoVuelo.idDestino)==1 )
                {
                    while(!pidoValidoFecha(&nuevoVuelo.fecha))
                    {
                        if(pidoValidoFecha(&nuevoVuelo.fecha))
                        {
                            break;
                        }
                    }
                    nuevoVuelo.isEmpty = 0;
                    vuelos[indice] = nuevoVuelo;
                    (*pProxId)++;
                    ok = 1;
                }
                else
                    printf("No se ingreso el Vuelos por errores en el ingreso de datos\n");
            }
            else
                printf("No se ingreso el Vuelos por errores en el ingreso de datos\n");
        }
    }
    else
    {
        printf("No hay vuelos cargadas en el sistema\n");
    }
    return ok;
}

int listarVuelos(eVuelos vuelos[],int tamVuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD)
{
    int flag = 1;
    int ok = 0;
    if(vuelos && tamVuelos > 0 && aviones && tamAvion > 0 && destinos && tamD > 0)
    {
        printf("\n     ************ LISTADO DE VUELOS **************\n\n");
        printf("========================================================\n");
        printf("| ID VUELOS |  ID AVION  |    DESTINO    |    FECHA    |\n");
        printf("--------------------------------------------------------\n");

        for(int i = 0; i < tamVuelos; i++)
        {
            if(!vuelos[i].isEmpty)
            {
                mostrarVuelosFila(vuelos[i],aviones,tamAvion, destinos, tamD);
                flag = 0;
            }
        }
        printf("========================================================\n\n");
        if(flag)
        {
            printf("     No hay vuelos en el sistema\n");
        }
        ok = 1;
    }
    return ok;
}

void mostrarVuelosFila(eVuelos vuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD)
{
    char descDestinos[20];
    cargarDescripcionDestino(destinos, tamD, vuelos.idDestino, descDestinos);
    printf("|     %d     |     %d      |  %10s   | %2d/%2d/%4d  |\n",
           vuelos.idVuelos,
           vuelos.idAvion,
           descDestinos,
           vuelos.fecha.dia,
           vuelos.fecha.mes,
           vuelos.fecha.anio);
}

void mostrarVuelos(eVuelos vuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD)
{
    char descDestinos[20];
    printf("ID: %d\n", vuelos.idVuelos);
    printf("Id Aviones: %d\n", vuelos.idAvion);
    cargarDescripcionDestino(destinos, tamD, vuelos.idDestino, descDestinos);
    printf("ID DESTINO: %s\n", descDestinos);
    printf("FECHA: %d/%d/%d\n",vuelos.fecha.dia, vuelos.fecha.mes,vuelos.fecha.anio);

}

int hardcodearVuelos(eVuelos vuelos[], int tamVuelos, int cant, int* pId)
{
    int ok = 0;
    eVuelos listaV[5] =
    {
        {0, 1, 20000, {4,8,2022}},
        {0, 2, 20001, {2,9,2021}},
        {0, 3, 20002, {9,3,2019}},
        {0, 4, 20003, {4,8,2022}},
        {0, 2, 20001, {9,3,2019}}
    };
   if(vuelos && pId && tamVuelos > 0 && tamVuelos <= 5 && cant <= tamVuelos)
    {
        for(int i = 0; i < cant; i++)
        {
            vuelos[i] = listaV[i];
            vuelos[i].idVuelos = *pId;
            (*pId)++;
        }
        ok = 1;
    }
    return ok;
}

