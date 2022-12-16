#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "jugador.h"
#include "menu.h"
#include "informes.h"

void mostrarJugadores(eJugador jugadores, eConfederacion confederaciones[],int tamC)
{
    char descripcion[50];
    if(cargarConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcion)==1)
    {
        printf("ID: %d\n",  jugadores.id);
        printf("NOMBRE: %s\n", jugadores.nombre);
        printf("POSICION: %s\n", jugadores.posicion);
        printf("Nro CAMISETA: %d\n",jugadores.numeroCamiseta);
        printf("SALARIO: %.2f\n", jugadores.salario);
        printf("CONFEDERACION: %s\n", descripcion);
        printf("ANIOS DE CONTRATO: %d\n",jugadores.aniosContrato);
    }
}

void mostrarJugadoresFila(eJugador jugadores, eConfederacion confederaciones[],int tamC)
{
    char descripcion[50];
    cargarConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcion);
        printf("| %d  |%20s  |%14s |    %4d      | %10.2f   | %10s    |        %d          |\n",
           jugadores.id,
           jugadores.nombre,
           jugadores.posicion,
           jugadores.numeroCamiseta,
           jugadores.salario,
           descripcion,
           jugadores.aniosContrato );
}

int inicializarJugador(eJugador jugadores[], int tamJ)
{
    int ok = 0;
    if( jugadores && tamJ > 0)
    {
        for(int i=0; i < tamJ; i++)
        {
            jugadores[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLugarLibre(eJugador jugadores[], int tamJ, int* pIndex)
{
    int ok = 0;
    if( jugadores != NULL && pIndex != NULL && tamJ > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamJ; i++)
        {
            if(jugadores[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int buscarJugador(eJugador jugadores[], int tamJ, int id, int* pIndex)
{
    int ok = 0;
    if( jugadores != NULL && pIndex != NULL && tamJ > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamJ; i++)
        {
            if( !jugadores[i].isEmpty  && jugadores[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int hardcodearJugadores(eJugador jugadores[], int tamJ, int cant, int* pId)
{
    int ok = 0;
    eJugador lista[15] =
    {
       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4},
	   {2,"Juan Musso","ARQUERO",12,100,80000,2},
	   {3,"Leo Messi","DELANTERO",10,100,80000,4},
	   {4,"Almirez Ali","DELANTERO",9,100,55000,1},
	   {5,"Harry Maguire","DEFENSOR",2,101,70000,4},
	   {6,"Eric Dier","DEFENSOR",3,101,60000,2},
	   {7,"Harry Kane","DELANTERO",10,101,3000,2},
	   {8,"Alfred Gomis","ARQUERO",1,101,9000,1},
	   {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1},
	   {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4},
	   {11,"Tecatito","DELANTERO",11,104,100000,3},
	   {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2},
	   {13,"Bamba Dieng ","DELANTERO",9,103,100000,2},
	   {14,"Demba Seck","DELANTERO",11,103,6000,2},
	   {15,"Tarek Salman","DEFENSOR",6,102,78000,5}

    };

    if(jugadores != NULL && pId  != NULL && tamJ > 0 && tamJ <= 15 && cant <= tamJ)
    {
        for(int i = 0; i < cant; i++)
        {
            jugadores[i] = lista[i];
            jugadores[i].id = *pId;
            (*pId)++;
        }
        ok = 1;
    }
    return ok;
}

int altaJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC,int* pProxId)
{
    int ok = 0;
    int indice;
    eJugador nJugador;

    if(jugadores != NULL  && confederaciones != NULL  && pProxId != NULL  && tamJ > 0 && tamC > 0)
    {
    	printf(" ______________________________________________________________________________ \n");
		printf("|                                                                              |\n");
		printf("|                             ***ALTA JUGADOR***                               |\n");
		printf("|______________________________________________________________________________|\n\n");

        buscarLugarLibre(jugadores, tamJ, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nJugador.id = *pProxId;
            if(cargaString(nJugador.nombre, 50,"Ingrese Nombre\n","ERROR (Rango->0,50)\n")
            && cargaString(nJugador.posicion,50,"Ingrese una de estas cuantro opciones\nArquero - Defensor - Mediocampista - Delantero\n","ERROR (Rango->0,50)\n")
            && utn_getNumeroInt(&nJugador.numeroCamiseta,"Ingrese numero de camiseta\n","ERROR (Rango->1,99)\n",1,50,2)==0 )
            {

                listarConfederaciones(confederaciones, tamC);
                if(utn_getNumeroInt(&nJugador.idConfederacion,"Ingrese id de confederacion\n","ERROR (Rango->100,105)\n",100,105,2)==0)
                {
                	if(utn_getNumeroFloat(&nJugador.salario, "Ingrese Precio: \n","\nReingrese Opcion ('1' a '1000000')\n",1,10000000,2)==0
					&& utn_getNumeroInt(&nJugador.aniosContrato,"Ingrese años de contrato\n","ERROR (Rango->1,99)\n",1,50,2)==0 )
					{
					   nJugador.isEmpty = 0;
					   jugadores[indice] = nJugador;
					   (*pProxId)++;
					   ok = 1;
					}
                    else
						printf("No se ingreso el Jugadores por errores en el ingreso de datos\n");
				}
			}
			else
				printf("No se ingreso el Jugadores por errores en el ingreso de datos\n");
        }
    }
    return ok;
}

int bajaJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
    int ok = 0;
    int id;
    int indice;
    char confirma;

    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
    	printf(" ______________________________________________________________________________ \n");
		printf("|                                                                              |\n");
		printf("|                             ***BAJA JUGADOR***                               |\n");
		printf("|______________________________________________________________________________|\n\n");

        listarJugadores(jugadores, tamJ, confederaciones, tamC);
        if(utn_getNumeroInt(&id, "Ingrese Jugador: \n","\nReingrese Opcion ('1' a '3000')\n",1,3000,2)==0)
        {
            if(buscarJugador(jugadores, tamJ, id, &indice) && indice == -1)
            {
                printf("No existe un jugadores con id: %d en el sistema\n", id);
            }
            else
            {
                mostrarJugadores(jugadores[indice], confederaciones, tamC);
                if(utn_getCharacter(&confirma,"Confirma baja? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                {
                    jugadores[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                    ok = 1;
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }
            }
        }else
            printf("No se pudo dar de baja al Jugadores por errores en el ingreso de datos\n");
    }
    return ok;
}

int modificarJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC)
{
    int ok = 0;
    int id;
    int indice;
    char salir = 'n';
    char confirma;
    eJugador nJugador;

    if(jugadores != NULL && tamJ > 0 && confederaciones != NULL && tamC > 0)
    {
    	printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                             ***MODIFICAR JUGADOR***                               |\n");
		printf("|___________________________________________________________________________________|\n\n");
        listarJugadores(jugadores, tamJ, confederaciones, tamC);
        if(utn_getNumeroInt(&id,"Ingrese id\n","\nReingrese Opcion ('1' a '3000')\n",1,3000,2)==0
        && buscarJugador(jugadores, tamJ, id, &indice)
        && indice == -1 )
        {
            printf("No existe un articulo con id: %d en el sistema\n", id);
        }
        else
        {
            mostrarJugadores(jugadores[indice], confederaciones, tamC);
            if(utn_getCharacter(&confirma,"Confirma el Jugador seleccionado? [s/n]\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
            {
                do
                {
                    switch(menuModificacion())
                    {
                    case 1:
                        if(utn_getString(nJugador.nombre,"Ingrese Nombre\n","ERROR (Rango->0,50)\n",0,50,2)==0)
                        {
                            strcpy(jugadores[indice].nombre, nJugador.nombre);
                            printf("Nombre modificado!!!\n");
                        }
                        break;
                    case 2:
                        if(utn_getString(nJugador.posicion,"Ingrese posicion\n","ERROR (Rango->0,20)\n",0,50,2)==0)
                        {
                            strcpy(jugadores[indice].posicion, nJugador.posicion);
                            printf("Posicion modificada!!!\n");
                        }
                        break;
                    case 3:
                        if(utn_getNumeroInt(&nJugador.numeroCamiseta,"Ingrese numero de camiseta\n","ERROR (Rango->1,99)\n",1,50,2)==0)
                        {
                            jugadores[indice].numeroCamiseta = nJugador.numeroCamiseta;
                            printf("Nro de camiseta modificado!!!\n");
                        }
                        else
                            printf("\nNo se modificaron datos\n");
                        break;
                    case 4:
                        listarConfederaciones(confederaciones, tamC);
                        if(utn_getNumeroInt(&nJugador.idConfederacion,"Ingrese id de confederacion\n","ERROR (Rango->100,105)\n",100,105,2)==0)
                        {
                            jugadores[indice].idConfederacion = nJugador.idConfederacion;
                            printf("Confederacion modificadA!!!\n");
                        }
                        break;
                    case 5:
                        if(utn_getNumeroFloat(&nJugador.salario, "Ingrese Precio: \n","\nReingrese Opcion ('1' a '1000000')\n",1,10000000,2)==0)
                        {
                            jugadores[indice].salario = nJugador.salario;
                            printf("Salario modificado!!!\n");
                        }
                        break;
                    case 6:
                        if(utn_getNumeroInt(&nJugador.aniosContrato,"Ingrese años de contrato\n","ERROR (Rango->1,99)\n",1,50,2)==0)
                        {
                            jugadores[indice].aniosContrato = nJugador.aniosContrato;
                            printf("Anios de contrato modificado!!!\n");
                        }
                        break;
                    case 7:
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
            ok = 1;
        }
    }
    return ok;
}

