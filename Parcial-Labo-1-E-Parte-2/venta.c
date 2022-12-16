#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "venta.h"

int inicializarVenta(eVenta ventas[], int tamV)
{
    int ok = 0;
    if(ventas && tamV > 0)
    {
        for(int i = 0; i < tamV; i++)
        {
            ventas[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibreVenta(eVenta ventas[], int tamV, int* pId)
{
    int ok = 0;
    if(ventas && pId && tamV > 0 )
    {
        *pId = -1;
        for(int i = 0; i < tamV; i++)
        {
            if(ventas[i].isEmpty == 1)
            {
                *pId = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int altaVenta(eVenta ventas[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR, int* pProxId)
{
    int ok = 0;
    int indice;
    int idArt;
    eVenta nuevaVenta;
    eFecha auxFecha;

    if(ventas && tamV > 0 && articulos && tamA > 0 && rubros && tamR > 0 && pProxId)
    {
        printf("*** ALTA VENTAS ***\n\n");
        buscarLibreVenta(ventas, tamV, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevaVenta.idVenta = *pProxId;
            listarArticulos(articulos, tamA, rubros, tamR);
            if(utn_getNumeroInt(&idArt,"Ingrese id\n","ERROR (Rango->0,5)\n",1,100,2)==0)
            {
                while(validarArticulo(articulos, tamA, idArt) == 0)
                {
                    printf("El Id ingresado no se encuentra en el sistema \n");
                    listarArticulos(articulos, tamA, rubros, tamR);
                    if(utn_getNumeroInt(&idArt,"Ingrese id\n","ERROR (Rango->0,5)\n",1,100,2)==0)
                    {
                        validarArticulo(articulos, tamA, idArt);
                    }
                }
            }
            if(utn_getNumeroInt(&nuevaVenta.cantidad, "Ingrese cantidad: \n","\nReingrese Opcion ('1' a '1000')\n",1,1000,2)==0
                    && utn_getNumeroFloat(&nuevaVenta.precioTotal, "Ingrese Precio: \n","\nReingrese Opcion ('1' a '1000000')\n",1,1000000,2)==0)
            {
                while(!pidoValidoFecha(&auxFecha))
                {
                    if(pidoValidoFecha(&auxFecha))
                    {
                        break;
                    }
                }
                nuevaVenta.isEmpty = 0;
                nuevaVenta.articuloId = idArt;
                nuevaVenta.fecha = auxFecha;
                ventas[indice] = nuevaVenta;
                (*pProxId)++;
                ok = 1;
            }
        }
    }
    else
    {
        printf("No hay ventas cargadas en el sistema\n");
    }
    return ok;
}

int listarVentas(eVenta venta[], int tamV, eArticulo articulos[], int tamA)
{
    int flag = 1;
    int ok = 0;
    if(venta && tamV > 0 && articulos && tamA > 0)
    {
        printf("******************  VENTAS  ********************\n\n");
        printf(" ID     ID ARTICULO       CANTIDAD       PRECIO TOTAL        DESCRIPCION      FECHA \n");
        printf("-------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i < tamV; i++)
        {
            if(!venta[i].isEmpty)
            {
                mostrarVentasFila(venta[i],articulos,tamA);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay productos en el sistema\n");
        }
        ok = 1;
    }
    return ok;
}

int cargarArticulo(char descArticulo[],eArticulo articulos[],int tamA,int idA)
{
    int ok=-1;
    int size;
    if(descArticulo)
    {
        ok=0;
        for(int i=0; i<tamA; i++)
        {
            if(articulos[i].idArticulo==idA)
            {
                size=sizeof(articulos[i].descripcion);
                strncpy(descArticulo, articulos[i].descripcion, size);
                ok=1;
            }
        }
    }
    return ok;
}

void mostrarVentasFila(eVenta venta, eArticulo articulos[], int tamA)
{
    char descArt[20];
    cargarArticulo(descArt, articulos, tamA, venta.articuloId);
    printf("%4d     %4d                %d             $%.2f         %10s        %02d/%02d/%4d \n",
           venta.idVenta,
           venta.articuloId,
           venta.cantidad,
           venta.precioTotal,
           descArt,
           venta.fecha.dia,
           venta.fecha.mes,
           venta.fecha.anio);
}

void mostrarVentas(eVenta venta, eArticulo articulos[], int tamA)
{
    char descArt[20];
    printf("\nId: %d\n", venta.idVenta);
    printf("Id Articulo: %d\n", venta.articuloId);
    printf("Cantidad: %d\n", venta.cantidad);
    printf("Precio Total: %.2f\n", venta.precioTotal);
    cargarArticulo(descArt, articulos, tamA, venta.articuloId);
    printf("Decripcion: %s\n", descArt);
    printf("Fecha: %d/%d/%d\n", venta.fecha.dia, venta.fecha.mes, venta.fecha.anio);

}

int hardcodearVentas(eVenta venta[], int tamV, int cant, int* pId)
{
    int ok = 0;
    eVenta ventas[5] =
    {
        {0, 1, 2,1000, {4,8,2022}},
        {0, 2, 1,3000, {2,9,2021}},
        {0, 3, 1,4500, {9,3,2019}},
        {0, 1, 2,5000, {4,8,2022}},
        {0, 3, 3,2000, {9,3,2019}}
    };
    if(venta && pId && tamV > 0 && cant <= tamV)
    {
        for(int i = 0; i < cant; i++)
        {
            venta[i] = ventas[i];
            venta[i].idVenta = *pId;
            (*pId)++;
        }
        ok = 1;
    }
    return ok;
}

