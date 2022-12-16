#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"
#include "articulo.h"
#include "venta.h"
#include "informes.h"

#define TAMA 5
#define TAMR 4
#define TAMV 5
#define NADA 0
#define ALTA 1

int main()
{
    char salir = 'n';
    int proxIdA = 1;
    int proxIdV = 2000;
    int queHizo = NADA;

    eArticulo listaA[TAMA];
    eRubro listaR[TAMR] =
    {
        {1000, "ELECTRONICA"},
        {1001, "BLANCO"},
        {1002, "AUDIO"},
        {1003, "VIDEO"}
    };

    eVenta listaV[TAMV];

    inicializarArticulos(listaA, TAMA);
    inicializarVenta(listaV, TAMV);

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(!altaArticulos(listaA, TAMA,listaR, TAMR,&proxIdA))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("Alta realizado con exito!!!\n");
            }
            queHizo = ALTA;
            break;
        case 2:
            if(queHizo == ALTA)
            {
                modificarArticulos(listaA, TAMA, listaR, TAMR);
            }
            else
            {
                printf("Para modificar un campo primero debe dar de alta un articulo \n");
            }
            break;
        case 3:
            if(queHizo == ALTA)
            {
                bajaArticulos(listaA, TAMA, listaR, TAMR);
            }
            else
            {
                printf("Para modificar un campo primero debe dar de alta un articulo \n");
            }
            break;
        case 4:
            if(queHizo == ALTA)
            {
                listarArticulos(listaA, TAMA, listaR, TAMR);
            }
            else
            {
                printf("Para lista Articulos debe dar de alta al menos uno \n");
            }
            break;
        case 5:
            listarRubros(listaR, TAMR);
            break;
        case 6:
            if(queHizo == ALTA)
            {
                if(!altaVenta(listaV, TAMV, listaA, TAMA, listaR, TAMR, &proxIdV))
                {
                    printf("No se pudo realizar el Alta\n");
                }
                else
                {
                    printf("Alta realizado con exito!!!\n");
                }
            }
            else
            {
                printf("Para dar de alta una venta debe dar de alta al menos un articulo \n");
            }
            break;
        case 7:
            listarVentas(listaV, TAMV, listaA, TAMA);
            break;
        case 8:
            informes(listaA, TAMA, listaV, TAMV,  listaR, TAMR);
            break;
        case 9:
            confirmarSalida(&salir);
            break;
        default:
            printf("La opcion ingresada no es valida\n");
            break;
        }
        system("pause");
    }
    while(salir != 's');

    return 0;
}


