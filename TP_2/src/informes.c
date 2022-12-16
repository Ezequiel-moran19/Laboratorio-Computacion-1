#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN_lib.h"
#include "informes.h"


int informes(eJugador jugadores[], int tamJ, eConfederacion confederaciones[],int tamC)
{
    char salir = 'n';
    int ok = 0;
    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
        do
        {
            switch(menuInformes())
            {
            case 1:
                listarJugadores(jugadores, tamJ, confederaciones, tamC);
                break;
            case 2:
                listaConfederacionesJugadores(jugadores, tamJ, confederaciones, tamC);
                break;
            case 3:
            	infoTotalSalarioJugadores(jugadores, tamJ);
                break;
            case 4:
            	infoConfederacionMayorCantidadContratos(jugadores, tamJ, confederaciones, tamC);
                break;
            case 5:
            	infoPorcentajeJugadoresPorConfederacion(jugadores, tamJ, confederaciones, tamC);
                break;
            case 6:
            	infoRegionMasJugadores(jugadores, tamJ, confederaciones, tamC);
                break;
            case 7:
                confirmarSalida(&salir);
                break;
            }
             system("pause");
        }
        while(salir != 's');
       ok=1;
    }
   return ok;
}

// INFORME NRO 1
int ordenarPorNombre(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
	int ok = 0;
	char confeDesc1[50];
    char confeDesc2[50];
	eJugador auxJugadores;

	if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
	{
		for (int i = 0; i < tamJ - 1; i++)
		{
			for (int j = i + 1; j < tamJ; j++)
			{
				if(!jugadores[i].isEmpty
				&& cargarConfederacion(confederaciones, tamC, jugadores[i].idConfederacion, confeDesc1) == 1
				&& cargarConfederacion(confederaciones, tamC, jugadores[i].idConfederacion, confeDesc2) == 1)
				{
					if ((stricmp(confeDesc1, confeDesc2)) < 0 || (stricmp(confeDesc1, confeDesc2) == 0 && (stricmp(jugadores[i].nombre, jugadores[j].nombre)) > 0))
					{
						auxJugadores = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = auxJugadores;
					}
					ok = 1;
				}
			}
		}
	}
	return ok;
}

int listarJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
    int flag = 1;
    int ok = 0;
    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
        printf("\n                        *** LISTADO DE JUGADORES *** \n\n");
        printf("===============================================================================================================\n");
        printf("| ID |       NOMBRE         |    POSICION   | Nro CAMISETA |    SUELDO    | CONFEDERACION | ANiOS de CONTRARO |\n");
        printf("---------------------------------------------------------------------------------------------------------------\n");
        ordenarPorNombre(jugadores, tamJ, confederaciones, tamC);
        for(int i = 0; i < tamJ; i++)
        {
            if( !jugadores[i].isEmpty)
            {
                mostrarJugadoresFila(jugadores[i],confederaciones,tamC);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay jugadores en el sistema\n");
        }
        ok = 1;
    }
         printf("===============================================================================================================\n");
    return ok;
}

// INFORME NRO 2
int listaConfederacionesJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[],int tamC)
{
    int ok = 0;
    int flag;

    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
        printf("\n                   ******* LISTADO DE CONFEDERACIONES CON SUS JUGADORES *******\n");
        printf("      =====================================================================================\n\n");

        for(int i=0; i < tamC; i++)
        {
            printf("\nCONFEDERACION:%s\n", confederaciones[i].nombre);
            printf("===============================================================================================================\n");
            printf("| ID |       NOMBRE         |    POSICION   | Nro CAMISETA |    SUELDO    | CONFEDERACION | ANiOS de CONTRARO |\n");
            printf("---------------------------------------------------------------------------------------------------------------\n");
            flag = 1;

            for(int j = 0; j < tamJ; j++)
            {
                if( !jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
                {
                    mostrarJugadoresFila(jugadores[j], confederaciones, tamC);
                    flag = 0;
                }
            }
            printf("===============================================================================================================\n");
            if(flag)
            {
                printf("No hay jugadores en esta confederacion: %s\n\n", confederaciones[i].nombre);
            }
        }
        ok = 1;
    }
    return ok;
}

// INFORME NRO 3
int sumaSalariosJugadores(eJugador jugadores[], int tamJ, float* pSumaSalarios, int* cantidad)
{
    int ok = 0;
    if( jugadores != NULL && pSumaSalarios != NULL && cantidad != NULL && tamJ > 0)
    {
    	for(int i = 0; i < tamJ; i++){

    		if(jugadores[i].isEmpty == 0){

    			*pSumaSalarios += jugadores[i].salario;
    			*cantidad += 1;
    			ok = 1;
    		}
    	}
    }
    return ok;
}

int promedioSalarios(eJugador jugadores[], int tamJ, float* pPromedio)
{
    int ok = 0;
    float sumaSalarios = 0;
    int cantidad = 0;

    if( jugadores != NULL && pPromedio != NULL && tamJ > 0)
    {
    	if(sumaSalariosJugadores(jugadores, tamJ, &sumaSalarios, &cantidad))
    	{
    		*pPromedio = sumaSalarios/cantidad;
    		ok = 1;
    	}
    }
    return ok;
}

int cantidadJugadoresSalariosEncimaPromedio(eJugador jugadores[], int tamJ, int* pCantidad)
{
    int ok = 0;
    int contador = 0;
    float pasajePromedio;

    if( jugadores != NULL && pCantidad != NULL && tamJ > 0)
    {
    	if(promedioSalarios(jugadores, tamJ, &pasajePromedio))
    	{
			for(int i = 0; i < tamJ; i++){

				if(jugadores[i].isEmpty == 0 && jugadores[i].salario > pasajePromedio){

					contador += 1;
					ok = 1;
				}
			}
    	}
    	if(contador){

    		*pCantidad = contador;
    	}
    }
    return ok;
}

int infoTotalSalarioJugadores( eJugador jugadores[], int tamJ)
{

	int ok = 0;
	float sumaSalarios = 0;
	int cantidad = 0;
	float promedio = 0;
	int cantSobrePromedio = 0;

	if( jugadores != NULL && tamJ > 0)
	{
		if (sumaSalariosJugadores(jugadores, tamJ, &sumaSalarios, &cantidad))
		{
			printf("\n--------------------------------------------------------------------------------------\n");
			printf("Total de salarios: $%.2f \n", sumaSalarios);
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("\n--------------------------------------------------------------------------------------\n");
			printf("Total de salarios: No hay suficientes datos.\n");
			printf("\n--------------------------------------------------------------------------------------\n");
		}

		if(promedioSalarios(jugadores, tamJ, &promedio))
		{
			printf("Promedio de salarios: $%.2f \n", promedio);
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("Promedio de salarios: No hay suficientes datos.\n");
			printf("\n--------------------------------------------------------------------------------------\n");
		}

		if(cantidadJugadoresSalariosEncimaPromedio(jugadores, tamJ, &cantSobrePromedio))
		{
			printf("Cantidad de Jugadores con salarios por encima del Promedio: %d\n", cantSobrePromedio);
			printf("\n--------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("Cantidad de Jugadores con salarios por encima del Promedio: No hay suficientes datos.\n");
			printf("\n--------------------------------------------------------------------------------------\n");
		}

		ok = 1;

	}
	return ok;
}

// INFORME NRO 4
int acumuladorAniosDeContrato(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumulador[])
{
	int ok = 0;
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0 && acumulador != NULL)
	{
		for (int i = 0; i < tamC; i++)
		{
			acumulador[i] = 0;
			for (int j = 0; j < tamJ; j++)
			{
				if (!jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					acumulador[i] += jugadores[j].aniosContrato;
					ok = 1;
				}
			}
		}
	}
	return ok;
}

int calcularMayorContrato(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int *pMaximo, int acumulador[])
{
	int ok = 0;
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && confederaciones > 0 && pMaximo != NULL && acumulador != NULL
	&& acumuladorAniosDeContrato(jugadores, tamJ, confederaciones, tamC, acumulador) == 1)
	{
		*pMaximo = 0;
		for (int i = 0; i < tamC; i++)
		{
			if (i == 0 || acumulador[i] > *pMaximo)
			{
				*pMaximo = acumulador[i];
				ok = 1;
			}
		}
	}
	return ok;
}

void infoConfederacionMayorCantidadContratos(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
	int maximo;
	int acumulador[tamC];
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0
	&& calcularMayorContrato(jugadores, tamJ, confederaciones, tamC, &maximo, acumulador) == 1)
	{
		for (int i = 0; i < tamC; i++)
		{
			if (acumulador[i] == maximo)
			{
				printf("\nLA CONFEDERACION CON MAS ANIOS DE CONTRATO ES %s, CUENTA CON %d ANIOS DE CONTRATO EN TOTAL\n", confederaciones[i].nombre, maximo);
				printf("===============================================================================================================\n");
				printf("| ID |       NOMBRE         |    POSICION   | Nro CAMISETA |    SUELDO    | CONFEDERACION | ANiOS de CONTRARO |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n");
				for (int j = 0; j < tamC; j++)
				{
					if (!jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
					{
						mostrarJugadoresFila(jugadores[j], confederaciones, tamC);
					}
				}
			}
		}
		printf("===============================================================================================================\n");
	}
}

// INFORME NRO 5
int contadorJugadores(eJugador jugadores[], int tamJ, int *pContador)
{
	int ok = 0;
	if (jugadores != NULL && tamJ > 0 && pContador != NULL)
	{
		*pContador = 0;
		for (int i = 0; i < tamJ; i++)
		{
			if(!jugadores[i].isEmpty)
			{
				(*pContador)++;
				ok = 1;
			}
		}
	}
	return ok;
}

int acumuladorJugadoresPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumulador[])
{
	int ok = 0;
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0 && acumulador != NULL)
	{
		for (int i = 0; i < tamC; i++)
		{
			acumulador[i] = 0;
			for (int j = 0; j < tamJ; j++)
			{
				if (!jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					acumulador[i]++;
					ok = 1;
				}
			}
		}
	}
	return ok;
}

int calculatePorcentajeDeJugadoresPorConfederation(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, float porcentaje[], int acumuladorConfe[])
{
	int ok = 0;
	int contador;
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0 && porcentaje != NULL && acumuladorConfe != NULL
    && acumuladorJugadoresPorConfederacion(jugadores, tamJ, confederaciones, tamC, acumuladorConfe) == 1
    && contadorJugadores(jugadores, tamJ, &contador) == 1)
    {
		for (int i = 0; i < tamC; i++)
		{
		   porcentaje[i] = 0;
		   if (contador > 0)
		   {
				porcentaje[i] = (float) acumuladorConfe[i] / contador * 100;
				ok = 1;
		   }
		}
	 }
	return ok;
}

void infoPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
	float porcentaje[tamC];
	int acum[tamC];
	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0
	&& calculatePorcentajeDeJugadoresPorConfederation(jugadores, tamJ, confederaciones, tamC, porcentaje, acum)==1)
	{
		for (int i = 0; i < tamC; i++)
		{
			printf("\nLA CONFEDERACION %s, CUENTA CON UN %%%.2f DE JUGADORES\n",confederaciones[i].nombre, porcentaje[i]);
			printf("===============================================================================================================\n");
			printf("| ID |       NOMBRE         |    POSICION   | Nro CAMISETA |    SUELDO    | CONFEDERACION | ANiOS de CONTRARO |\n");
			printf("---------------------------------------------------------------------------------------------------------------\n");

			for (int j = 0; j < tamJ; j++)
			{
				if (!jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					mostrarJugadoresFila(jugadores[j], confederaciones, tamC);
				}
			}
			printf("===============================================================================================================\n");
		}
	}
}

// INFORME NRO 6
int calcularMaximoDeJugadoresPorRegion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumuladorConfe[], int *pJugadorPorConfe)
{

	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0 && acumuladorConfe != NULL
    && acumuladorJugadoresPorConfederacion(jugadores, tamJ, confederaciones, tamC, acumuladorConfe) == 1)
	{
		for (int i = 0; i < tamC; i++)
		{
			if (i == 0 || acumuladorConfe[i] > *pJugadorPorConfe)
			{
				*pJugadorPorConfe = acumuladorConfe[i];
			}
		}
	}
	return 0;
}

void infoRegionMasJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
	int maximo;
	int acumulador[tamC];

	if (jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0
	&& calcularMaximoDeJugadoresPorRegion(jugadores, tamJ, confederaciones, tamC, acumulador, &maximo) == 0)
	{
	    for (int i = 0; i < tamC; i++)
		{
			if (acumulador[i] == maximo)
			{
				printf("\nLA CONFEDERACION: %s, PERTENECIENTE A LA REGION: %s, ES LA QUE CUENTA CON MAYOR CANTIDAD DE JUGADORES.\n\n", confederaciones[i].nombre, confederaciones[i].region);
				printf("===============================================================================================================\n");
				printf("| ID |       NOMBRE         |    POSICION   | Nro CAMISETA |    SUELDO    | CONFEDERACION | ANiOS de CONTRARO |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n");
				for (int j = 0; j < tamJ; j++)
				{
					if (!jugadores[j].isEmpty && jugadores[j].idConfederacion == confederaciones[i].id)
					{
						mostrarJugadoresFila(jugadores[j], confederaciones, tamC);
					}
				}
			}
		}
		printf("===============================================================================================================\n");
	}
}


