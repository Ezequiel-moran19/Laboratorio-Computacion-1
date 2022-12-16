
#include <stdio.h>
#include <stdlib.h>
#include "UTN_lib.h"
#include "jugador.h"
#include "confederacion.h"
#include "informes.h"
#include "menu.h"

#define TAMC 6
#define TAMJ 3000

int main()
{
	setbuf(stdout,NULL);
    char salir = 'n';
    int proxIdJugador = 1;
    int flagAlta = 0;
    int flagInfo = 0;

    eJugador jugadores[TAMJ];
    eConfederacion confederaciones[TAMC] =
    {
        {100, "CONMEBOL", "SUDAMERICA",1916},
        {101, "UEFA", "EUROPA",1954},
        {102, "AFC", "ASIA",1955},
        {103, "CAF", "AFRICA",1957},
        {104, "CONCACAF", "NORTE Y CENTRO AMERICA",1961},
        {105, "OFC", "OCEANIA",1966}
    };

    inicializarJugador(jugadores, TAMJ);
    inicializarConfederacion(confederaciones, TAMC);
   // hardcodearJugadores(jugadores, TAMJ, 15, &proxIdJugador);Testeos realizados con exitos

    do
    {
        switch(menuPrincipal())
        {
        case 1:
             if(!altaJugador(jugadores, TAMJ, confederaciones, TAMC, &proxIdJugador))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("Alta realizado con exito!!!\n");
            }
             banderaAlta(&flagAlta);
            break;
        case 2:
              bajaJugador(jugadores, TAMJ, confederaciones, TAMC);
            break;
        case 3:
              modificarJugadores(jugadores, TAMJ, confederaciones, TAMC);
            break;
        case 4:
        	if(flagAlta == 1)
         	{
        		informes(jugadores, TAMJ, confederaciones, TAMC);
        	    banderaInformes( &flagAlta, &flagInfo);
        	}
        	else
			{
				printf("Antes de ingresar a informes debe dar de alta al menos a un jugador\n");
			}
            break;
        case 5:
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
