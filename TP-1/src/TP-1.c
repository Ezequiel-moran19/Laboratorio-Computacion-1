#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "menu.h"
#include "calculos.h"

#define ARQ 2
#define DEF 8
#define MED 8
#define DEL 4

int main()
{
	setbuf(stdout,NULL);
    char salir = 'n';
    char carga;
    int contJugadoresTotal = 0;
    float costoHospedaje=0;
    float costoComida = 0;
    float costoTransporte=0;
    float acumCostoHospedaje = 0;
    float acumCostoComida = 0;
    float acumCostoTransporte = 0;
    int puesto;
    int numeroCamiseta;
    int cantArqueros = 0;
    int cantDefensores = 0;
    int cantMediocampistas= 0;
    int cantDelanteros =0;
    float proAfc;
    float proCaf;
    float proConcacaf;
    float proConmebol;
    float proUefa;
    float proOfc;
    int jugadoresLigaAfc = 0;
    int jugadoresLigaCaf = 0;
    int jugadoresLigaConcacaf = 0;
    int jugadoresLigaConmebol = 0;
    int jugadoresLigaUefa = 0;
    int jugadoresLigaOfc = 0;
    float costoTotalConAumento;
    float costoTotalSinAumento;
    float aumento =0.35;
    float costoMasIncremento;
    int flagM = 0;
    int flagJ = 0;
    int flagC = 0;

    do
    {
        switch(menuPrincipal(&acumCostoHospedaje, &acumCostoComida, &acumCostoTransporte, &cantArqueros, &cantDefensores, &cantMediocampistas, &cantDelanteros))
        {
			case 1:
				if(utn_getNumeroFloat(&costoHospedaje, "Ingrese el costo del hospedaje: \n","\nReingrese Opcion ('1' a '1000000')\n",1,100000000,5)==0
				&& utn_getNumeroFloat(&costoComida, "Ingrese el costo de comida: \n","\nReingrese Opcion ('1' a '1000000')\n",1,100000000,5)==0
				&& utn_getNumeroFloat(&costoTransporte, "Ingrese el costo del transporte: \n","\nReingrese Opcion ('1' a '1000000')\n",1,100000000,5)==0
				&& utn_getCharacter(&carga,"Confirma Carga? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && carga=='s')
				{
					acumCostoHospedaje += costoHospedaje;
					acumCostoComida += costoComida;
					acumCostoTransporte += costoTransporte;
				}
				else
				{
					printf("Error datos mal cargados.\n");
				}
				banderaMantenimiento(&flagM);
				break;

			case 2:
				if(flagM == 1
				&& utn_getNumeroInt(&puesto, "Posicion del jugador:\n1- Arquero,\n2- Defensor,\n3- Mediocampista,\n4- Delantero\n", "Error, numero mayor a 1 y menor a 100\n",1,22,2)==0)
				{
					switch(puesto)
					{
						case 1:
							if(cantArqueros == ARQ)
							{
								printf("Cantidad maxima de arqueros por equipo 2.\n");
							}
							else
							{
								cargarLiga(&jugadoresLigaAfc, &jugadoresLigaCaf, &jugadoresLigaConcacaf, &jugadoresLigaConmebol, &jugadoresLigaUefa, &jugadoresLigaOfc);
								if(utn_getNumeroInt(&numeroCamiseta, "Ingrese numero de camiseta del 1 al 100\n", "Error, numero mayor a 1 y menor a 100\n",1,100,2)==0
								&& utn_getCharacter(&carga,"Confirma Carga? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && carga=='s')
								{
									  cantArqueros++;
									  contJugadoresTotal++;
									  banderaJugador( &flagM, &flagJ);
								}
								else
								{
									printf("Error en la carga de datos, intentos terminados.\n");
								}
							}
							break;
						case 2:
							if(cantDefensores == DEF)
							{
								printf("no se puede agregar mas defensores. Maximo permitido 8.\n");
			 				}
							else
							{
								cargarLiga(&jugadoresLigaAfc, &jugadoresLigaCaf, &jugadoresLigaConcacaf, &jugadoresLigaConmebol, &jugadoresLigaUefa, &jugadoresLigaOfc);
								if(utn_getNumeroInt(&numeroCamiseta, "Ingrese numero de camiseta del 1 al 100\n", "Error, numero mayor a 1 y menor a 100\n",1,100,2)==0
								&& utn_getCharacter(&carga,"Confirma Carga? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && carga=='s')
								{
									  cantDefensores++;
									  contJugadoresTotal++;
									  banderaJugador( &flagM, &flagJ);
								}
								else
								{
									printf("Error datos mal cargados.\n");
								}
							}
							break;
						case 3:
							if(cantMediocampistas==MED)
							{
								printf("Cantidad maxima de Mediocampistas por equipo 8.\n");
							}
							else
							{
								cargarLiga(&jugadoresLigaAfc, &jugadoresLigaCaf, &jugadoresLigaConcacaf, &jugadoresLigaConmebol, &jugadoresLigaUefa, &jugadoresLigaOfc);
								if(utn_getNumeroInt(&numeroCamiseta, "Ingrese numero de camiseta del 1 al 100\n", "Error, numero mayor a 1 y menor a 100\n",1,100,2)==0)
								{
									cantMediocampistas++;

									contJugadoresTotal++;
									banderaJugador( &flagM, &flagJ);
								}
								else
								{
									printf("Error datos mal cargados.\n");
								}
							}
							break;
						case 4:
							if(cantDelanteros == DEL)
							{
								printf("Cantidad maxima de Delanteros por equipo 4.\n");
							}
							else
							{
								cargarLiga(&jugadoresLigaAfc, &jugadoresLigaCaf, &jugadoresLigaConcacaf, &jugadoresLigaConmebol, &jugadoresLigaUefa, &jugadoresLigaOfc);
								if(utn_getNumeroInt(&numeroCamiseta, "Ingrese numero de camiseta del 1 al 100\n", "Error, numero mayor a 1 y menor a 100\n",1,100,2)==0)
								{
									cantDelanteros++;
									contJugadoresTotal++;
									banderaJugador( &flagM, &flagJ);
								}
								else
								{
									printf("Error datos mal cargados.\n");
								}
							}
							break;
					    }
					}
					else
					{
						banderaJugador(&flagJ, &flagM);
					}
				break;

			case 3:
				if(flagJ ==1)
				{
					costoTotalSinAumento = calcularCostos(&acumCostoHospedaje, &acumCostoComida, &acumCostoTransporte);
					costoMasIncremento = costoTotalSinAumento * aumento;
					costoTotalConAumento = costoTotalSinAumento + costoMasIncremento;
					division(&proAfc, jugadoresLigaAfc, contJugadoresTotal);
					division(&proCaf, jugadoresLigaCaf, contJugadoresTotal);
					division(&proConcacaf, jugadoresLigaConcacaf, contJugadoresTotal);
					division(&proConmebol, jugadoresLigaConmebol, contJugadoresTotal);
					division(&proUefa, jugadoresLigaUefa, contJugadoresTotal);
					division(&proOfc, jugadoresLigaOfc, contJugadoresTotal);
					banderaCalcular(&flagM, &flagJ, &flagC);
				}
				else
				{
					banderaCalcular(&flagM, &flagJ, &flagC);
				}
				break;

			case 4:
				if(flagC == 1)
				{
					mostrarPomedios(&proAfc, &proCaf, &proConcacaf, &proConmebol,&proUefa, &proOfc);
					if(jugadoresLigaUefa > jugadoresLigaAfc && jugadoresLigaUefa > jugadoresLigaCaf
					&& jugadoresLigaUefa > jugadoresLigaConcacaf && jugadoresLigaUefa > jugadoresLigaConmebol
					&& jugadoresLigaUefa > jugadoresLigaOfc)
					{
						printf("\nTOTAL COSTO DE MANTTEMIENTO $%.2f \nSE APLICA UN AUMENTO DE $%.2f\nNUEVO VALOR: $%.2f \n",costoTotalSinAumento, costoMasIncremento, costoTotalConAumento);
					}
					else
					{
						printf("TOTAL COSTO DE MANTENIMIENTO $%.2f\n",costoTotalSinAumento);
					}
					informarResultados(&flagM, &flagJ, &flagC);
				}
				else
				{
					informarResultados(&flagM, &flagJ, &flagC);
				}
				break;

			case 5:
				  confirmarSalida(&salir);
				break;
			}
        system("pause");
    } while(salir != 's');
    return 0;
}



