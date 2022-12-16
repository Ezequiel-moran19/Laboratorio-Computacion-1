#include <stdio.h>
#include <stdlib.h>
#include "UTN_lib.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "informe.h"

#define TAMAV 5
#define TAMA 5
#define TAMT 4
#define TAMD 4
#define TAMVU 5

int main()
{
    char salir = 'n';
    int proxIdAvion = 1;
    int proxIdVuelos = 1;
    eAvion aviones[TAMAV];
    eVuelos vuelos[TAMVU];
    eAerolineas aerolineas[TAMA] =
    {
        {1000, "Lan"},
        {1001, "Iberia"},
        {1002, "Norwegian"},
        {1003, "American"},
        {1004, "Austral"}
    };

    eTipo tipos[TAMT] =
    {
        {5000, "Jet"},
        {5001, "Helice"},
        {5002, "Planeador"},
        {5003, "Carga"}
    };

    eDestino destinos[TAMD] =
    {
        {20000, "Calafate", 22250},
        {20001, "Miami", 103000},
        {20002, "Milan", 84400},
        {20003, "Amsterdam", 95600}
    };

   inicializarAvion(aviones, TAMAV);
   inicializarVuelos(vuelos, TAMVU);
   hardcodearAviones(aviones, TAMAV, 3, &proxIdAvion);
   hardcodearVuelos(vuelos, TAMVU, 3, &proxIdVuelos);
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(!altaAavio(aviones, TAMAV ,aerolineas, TAMA, tipos, TAMT, &proxIdAvion))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("Alta realizado con exito!!!\n");
            }
            break;
        case 2:
            modificarAvion(aviones, TAMAV, aerolineas, TAMA, tipos, TAMT);
            break;
        case 3:
            bajaAvion(aviones, TAMAV, aerolineas, TAMA, tipos, TAMT);
            break;
        case 4:
            listarAviones(aviones, TAMAV, aerolineas, TAMA, tipos, TAMT);
            break;
        case 5:
            listarAerolineas(aerolineas, TAMA);
            break;
        case 6:
            listarTipos(tipos, TAMT);
            break;
        case 7:
            listarDestinos(destinos, TAMD);
            break;
        case 8:
            if(!altaVuelo(vuelos, TAMVU, aviones, TAMAV, destinos, TAMD, aerolineas, TAMA, tipos, TAMT, &proxIdVuelos))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("Alta realizado con exito!!!\n");
            }
            break;
        case 9:
            listarVuelos(vuelos, TAMVU, aviones, TAMAV, destinos, TAMD);
            break;
        case 10:
            informes(aviones, TAMAV, aerolineas, TAMA, tipos, TAMT);
            break;
        case 11:
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

