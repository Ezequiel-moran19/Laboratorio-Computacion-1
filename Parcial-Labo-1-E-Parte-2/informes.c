#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

int menuInformes(){
  int opcion;
  if(utn_getNumeroInt(&opcion, "\n***** Menu de Informes *****\n\n"
    "1. Mostrar articulos de un rubro seleccionado\n"
    "2. Mostrar todas las ventas efectuadas en una fecha seleccionada\n"
    "3. Informar importe total de las ventas realizadas de un articulo seleccionado\n"
    "4. Informar importe total de todas las ventas de un rubro en una fecha seleccionada\n"
    "5-     Salir\n",
    "\nReingrese Opcion ('1' a '5')\n",1,5,2)==0){}
   return opcion;
}

void informes(eArticulo articulos[],int tamA,eVenta ventas[],int tamV, eRubro rubros[],int tamR)
{
    char salir = 'n';
    do
    {
        switch(menuInformes())
        {
        case 1:
            mostrarArtRubro(articulos, tamA, rubros, tamR);
            break;
        case 2:
            mostrarVentasFechas(ventas, tamV, articulos, tamA);
            break;
        case 3:
            totalImportesVentas(ventas,tamV, articulos, tamA, rubros, tamR);
            break;
        case 4:
            totalImportesVentasRubro(ventas, tamV, articulos, tamA, rubros, tamR);
            break;
        case 5:
            confirmarSalida(&salir);
            break;
        }
    }
    while(salir != 's');

}

int mostrarArtRubro(eArticulo articulos[], int tamA, eRubro rubros[],int tamR)
{
    int ok = 0;
    int idRubro;
    int flag=1;
    if(articulos && rubros && tamA > 0 && tamR > 0)
    {
        listarRubros(rubros, tamR);
        if(utn_getNumeroInt(&idRubro, "Ingrese rubro: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1003,2)==0)
        {
            printf("\n       ******* LISTA DE ARTICULOS    *******\n");
            printf("    ID          DESCRIPCION     MEDIDA     PRECIO\n\n");
            for(int i=0; i<tamA; i++)
            {
                if (articulos[i].isEmpty==0 && articulos[i].rubroId == idRubro)
                {
                    printf(" %4d        %10s          %.2f      $%.2f \n",
                           articulos[i].idArticulo,
                           articulos[i].descripcion,
                           articulos[i].medida,
                           articulos[i].precio);
                    flag=0;
                }
            }
        }
        if(flag)
        {
            printf("\n******* No hay articulos que listar *******\n\n");
        }
        ok = 1;
    }
    return ok;
}

int mostrarVentasFechas(eVenta ventas[], int tamV, eArticulo articulos[],int tamA)
{
    int ok = 0;
    eFecha auxFecha;
    int flag=1;
    if(ventas && articulos && tamV > 0 && tamA > 0)
    {
        listarVentas(ventas, tamV, articulos, tamA);
        printf("\n");
        while(!pidoValidoFecha(&auxFecha))
        {
            if(pidoValidoFecha(&auxFecha))
            {
                break;
            }
        }
        printf("\nVentas realizadas en la fecha: %2d/%2d/%d\n",auxFecha.dia, auxFecha.mes, auxFecha.anio);
        printf("\n Id    CANTIDAD     PRECIO \n");
        printf("------------------------------\n");
        for(int i=0; i<tamV; i++)
        {
            if (ventas[i].fecha.dia == auxFecha.dia
                    &&  ventas[i].fecha.mes == auxFecha.mes
                    &&  ventas[i].fecha.anio == auxFecha.anio)
            {
                printf(" %d    %d          $%0.2f\n",
                       ventas[i].idVenta,
                       ventas[i].cantidad,
                       ventas[i].precioTotal);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No se realizaron ventas en esa fecha\n");
        }
        ok = 1;
    }
    return ok;
}

int totalImportesVentas(eVenta ventas[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR)
{
    int ok = 0;
    int idArticulo;
    int cant = 0;
    float total = 0;

    if(articulos && ventas && rubros && tamV > 0 && tamA > 0 && tamR > 0)
    {
        printf("   *** TOTAL IMPORTE VENTA ***\n");
        printf("----------------------------------------------------\n");
        listarArticulos(articulos, tamA, rubros, tamR);
        if(utn_getNumeroInt(&idArticulo,"Ingrese id: ","ERROR (Rango->0,5)\n",1,100,2)==0)
        {
            while(validarArticulo(articulos, tamA, idArticulo) == 0)
            {
                printf("El Id ingresado no se encuentra en el sistema \n");
                listarArticulos(articulos, tamA, rubros, tamR);
                if(utn_getNumeroInt(&idArticulo,"Ingrese id: ","ERROR (Rango->0,5)\n",1,100,2)==0)
                {
                    validarArticulo(articulos, tamA, idArticulo);
                }
            }
        }
        for(int i = 0; i < tamV; i++)
        {
            if( !ventas[i].isEmpty && ventas[i].articuloId == idArticulo)
            {
                for(int j = 0; j < tamA; j++)
                {
                    if(ventas[i].articuloId == articulos[j].idArticulo)
                    {
                        cant=ventas[i].cantidad * ventas[i].precioTotal;
                        total += cant;
                    }
                }
            }
        }
        printf("El importe total de ventas del Articulo %d es $%.2f\n\n", idArticulo,total);

        ok = 1;
    }
    return ok;
}

int totalImportesVentasRubro(eVenta ventas[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR)
{
    int ok = 0;
    int idRubro;
    eFecha auxFecha;
    int cant = 0;
    float total = 0;
    int flag=1;

    if(articulos && ventas && rubros && tamV > 0 && tamA > 0 && tamR > 0)
    {
        listarRubros(rubros, tamR);
        if(utn_getNumeroInt(&idRubro, "Ingrese rubro: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1003,2)==0)
        {
            listarVentas(ventas, tamV, articulos, tamA);
            printf("\n");
            while(!pidoValidoFecha(&auxFecha))
            {
                if(pidoValidoFecha(&auxFecha))
                {
                    break;
                }
            }
            printf("\nLa fecha selecionada es: %2d/%2d/%d\n",auxFecha.dia, auxFecha.mes, auxFecha.anio);

            for(int i = 0; i < tamV; i++)
            {
                if(ventas[i].isEmpty
                        && ventas[i].fecha.dia == auxFecha.dia
                        && ventas[i].fecha.mes == auxFecha.mes
                        && ventas[i].fecha.anio == auxFecha.anio)
                {
                    for(int j = 0; j < tamR; j++)
                    {
                        if(ventas[i].articuloId == articulos[j].idArticulo && ventas[i].articuloId == idRubro)
                        {
                            cant=ventas[i].cantidad * ventas[i].precioTotal;
                            total += cant;
                            flag=0;
                        }
                    }
                }
            }
        }
        if(!flag)
        {
            printf("No se realizaron ventas en esa fecha\n");
        }
        else
        {
            printf("El importe total de todas las ventas de un rubro %d en una fecha es: $%.2f\n\n",idRubro,total);
        }

        ok = 1;
    }

    return ok;
}


