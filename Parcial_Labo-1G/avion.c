#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "avion.h"
//#include "tipo.h"
//#include "aerolinea.h"

int menuPrincipal()
{
    int opcion;
    if(utn_getNumeroInt(&opcion, "\n     *** Menu Principal *** \n\n"
      "1. Alta Avion\n"
      "2. Modificar Avion\n"
      "3. Baja Avion\n"
      "4. Listar Aviones\n"
      "5. Listar Aerolineas\n"
      "6. Listar Tipos\n"
      "7. Listar Destinos\n"
      "8. Alta Vuelos\n"
      "9. Listar Vuelos\n"
      "10. Informes\n"
      "11. Salir\n"
      "Ingrese opcion: \n",
      "\nReingrese Opcion ('1' a '11')\n",1,11,2)==0) {}
    return opcion;
}

void mostrarAvion(eAvion aviones, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT)
{
    char descA[20];
    char descT[20];
    if(cargarDescripcionTipo(tipos, tamT, aviones.idTipo, descT) == 1
    && cargarDescripcionAerolineas(aerolineas, tamA, aviones.idAerolinea, descA)== 1)
    {
        printf("ID: %d\n",  aviones.id);
        cargarDescripcionAerolineas(aerolineas, tamA, aviones.idAerolinea, descA);
        printf("AEROLINEA: %s\n", descA);
        cargarDescripcionTipo(tipos, tamT, aviones.idTipo, descT);
        printf("TIPO: %s\n", descT);
        printf("CAPACIDAD: %d\n", aviones.capacidad);
    }

}

void mostrarAvionesFila(eAvion aviones, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT)
{
    char descA[20];
    char descT[20];
     cargarDescripcionTipo(tipos, tamT, aviones.idTipo, descT);
     cargarDescripcionAerolineas(aerolineas, tamA, aviones.idAerolinea, descA);

           printf("| %d |%12s |%10s |   %4d   |\n",
           aviones.id,
           descA,
           descT,
          aviones.capacidad);

}

int inicializarAvion(eAvion aviones[], int tamAvion)
{
    int ok = 0;
    if(aviones != NULL && tamAvion > 0)
    {
        for(int i=0; i < tamAvion; i++)
        {
            aviones[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibre(eAvion aviones[], int tamAvion, int* pIndex)
{
    int ok = 0;
    if(aviones != NULL && pIndex != NULL && tamAvion > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamAvion; i++)
        {
            if(aviones[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int buscarAvion(eAvion aviones[], int tamAvion, int id, int* pIndex)
{
    int ok = 0;
    if( aviones != NULL && pIndex != NULL && tamAvion > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamAvion; i++)
        {
            if(aviones[i].isEmpty == 0 && aviones[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int validarAviones(eAvion aviones[], int tamAvion, int id)
{
    int esValido = 0;
    int indice;

    if (buscarAvion(aviones, tamAvion, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}


int ordenarAvioneId(eAvion aviones[], int tamAvion)
{
	int ok = 0;
	eAvion auxAvion;

	if( aviones != NULL && tamAvion > 0)
	{
		for(int i=0; i < tamAvion - 1; i++)
		{
			for(int j= i+1; j < tamAvion; j++)
			{
				if(aviones[i].id > aviones[j].id)
				{
					auxAvion = aviones[i];
					aviones[i] = aviones[j];
					aviones[j] = auxAvion;
				}
			}
		}
		ok = 1;
	}
	return ok;
}
int listarAviones(eAvion aviones[], int tamAvion, eAerolineas aerolineas[], int tamA, eTipo tipos[],int tamT)
{
    int flag = 1;
    int ok = 0;
    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0)
    {
        printf("\n          *** LISTADO DE AVIONES *** \n\n");

        printf("==========================================\n");
        printf("| ID|   AEROLINEA |    TIPO   | CAPACIDAD|\n");
        printf("------------------------------------------\n");
        ordenarAvioneId(aviones, tamAvion);
        for(int i = 0; i < tamAvion; i++)
        {
            if( !aviones[i].isEmpty)
            {
                mostrarAvionesFila(aviones[i],aerolineas,tamA, tipos, tamT);
                flag = 0;
            }
        }
        printf("==========================================\n");
        if(flag)
        {
            printf("     No hay Aviones en el sistema\n");
        }
        ok = 1;
    }
    return ok;
}

int hardcodearAviones(eAvion aviones[], int tamAvion, int cant, int* pId)
{
    int ok = 0;
    eAvion listaA[5] =
    {
        {1, 1000, 5000, 30,0},
        {2, 1001, 5000, 85,0},
        {3, 1002, 5002, 75,0},
        {4, 1003, 5003, 80,0},
        {5, 1004, 5002, 120,0}
    };

    if( aviones != NULL && tamAvion > 0 && tamAvion <= 5 && cant <= tamAvion)
    {
        for(int i = 0; i < cant; i++)
        {
             aviones[i] = listaA[i];
             aviones[i].id = *pId;
            (*pId)++;
        }
        ok = 1;
    }
    return ok;
}

int altaAavio(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT, int* pProxId)
{
    int ok = 0;
    int indice;
    eAvion nuevoAvion;

    if(pProxId != NULL && aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 )
    {
        printf("    *** ALTA AVION ***\n\n");
        buscarLibre(aviones, tamAvion, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoAvion.id = *pProxId;
            listarAerolineas(aerolineas, tamA);
            if(utn_getNumeroInt(&nuevoAvion.idAerolinea, "Ingrese Aerolinea: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1004,2)==0
                    && validarAerolineas(aerolineas,tamA, nuevoAvion.idAerolinea)==1)
            {
                listarTipos(tipos, tamT);
                if(utn_getNumeroInt(&nuevoAvion.idTipo, "Ingrese Tipo: \n","\nReingrese Opcion ('5000' a '1003')\n",5000,5003,2)==0
                        && validarTipos(tipos,tamT, nuevoAvion.idTipo)==1
                        && utn_getNumeroInt(&nuevoAvion.capacidad, "Ingrese Capacidad: \n","\nReingrese Opcion ('30' a '300')\n",30,300,2)==0)
                {
                    nuevoAvion.isEmpty = 0;
                    aviones[indice] = nuevoAvion;
                    (*pProxId)++;
                    ok = 1;
                }
                else
                    printf("No se ingresaron Aviones por errores en el ingreso de datos\n");

            }
            else
                printf("No se ingreso el Aviones por errores en el ingreso de datos\n");
        }
    }
    else
    {
        printf("No hay aviones cargadas en el sistema\n");
    }
    return ok;
}

int bajaAvion(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT)
{
    int ok = 0;
    int id;
    int indice;
    char confirma;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 )
    {
        printf("\n        ******* BAJA DE AVIONES *******\n");
        listarAviones(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
        if(utn_getNumeroInt(&id, "Ingrese Avion: \n","\nReingrese Opcion ('1' a '5')\n",1,5,2)==0)
        {
            if(buscarAvion(aviones, tamAvion, id, &indice) && indice == -1)
            {
                printf("No existe un avion con id: %d en el sistema\n", id);
            }
            else
            {
                mostrarAvion(aviones[indice], aerolineas, tamAvion, tipos, tamT);
                if(utn_getCharacter(&confirma,"Confirma baja? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                {
                    aviones[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                    ok = 1;
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }
            }
        }
    }
    return ok;
}

int modificarAvion(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT)
{
    int ok = 0;
    int id;
    int indice;
    char salir = 'n';
    char confirma;
    eAvion auxAvion;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 )
    {
        listarAviones(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
        if(utn_getNumeroInt(&id,"Ingrese id  del Avion\n","ERROR (Rango->0,5)\n",1,5,2)==0)
        {
            if(buscarAvion(aviones, tamAvion, id, &indice) && indice == -1)
            {
                printf("No existe un Avion con id: %d en el sistema\n", id);
            }
            else
            {
                mostrarAvion(aviones[indice], aerolineas, tamAvion, tipos, tamT);
                if(utn_getCharacter(&confirma,"Confirma el Avion seleccionado? [s/n]\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                {
                    do
                    {
                        switch(menuModificacion())
                        {
                        case 1:
                            listarTipos(tipos, tamT);
                            if(utn_getNumeroInt(&auxAvion.idTipo, "Ingrese Tipo: \n","\nReingrese Opcion ('5000' a '1003')\n",5000,5003,2)==0
                                    && validarTipos(tipos,tamT, auxAvion.idTipo)==1)
                            {
                                aviones[indice].idTipo = auxAvion.idTipo;
                                printf("Tipo modificado!!!\n");
                            }
                            else
                                printf("\nNo se modificaron datos\n");
                            break;
                        case 2:
                            listarAviones(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
                            if(utn_getNumeroInt(&auxAvion.capacidad, "Ingrese Capacidad: \n","\nReingrese Opcion ('30' a '300')\n",30,300,2)==0)
                            {
                                aviones[indice].capacidad = auxAvion.capacidad;
                                printf("Capacidad modificado!!!\n");
                            }
                            else
                                printf("\nNo se modificaron datos\n");
                            break;
                        case 3:
                            confirmarSalida(&salir);
                            break;
                        }

                    }
                    while(salir != 's');
                }
                else
                {
                    printf("Modificacion cancelada por el usuario\n");
                }
            }
            ok = 1;
        }
    }
    return ok;
}

int menuModificacion()
{
    int opcion;
    if(utn_getNumeroInt(&opcion,
    "Ingrese opcion:\n 1-Tipo\n 2-Capacidad\n 3-Salir\n",
    "ERROR (Rango 1->3)",1,3,2)==0) {}
    return opcion;
}



