#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "confederacion.h"
#include "menu.h"

int cargarConfederacion(eConfederacion confederaciones[], int tamC, int id, char desc[]){
    int ok = 0;
    int flag = 1;
    if(confederaciones && tamC > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamC; i++)
         {
            if( confederaciones[i].id == id){
                strcpy( desc, confederaciones[i].nombre);
                flag = 0;
                break;
            }
         }
         if(flag){
            ok = -1;
         }
    }
    return ok;
}

int listarConfederaciones(eConfederacion confederaciones[], int tamC)
{
    int ok = 0;
    if(confederaciones && tamC > 0){

        printf("\n   *** LISTADO DE CONFEDERACIONES ***\n\n");
        printf("===============================================================\n");
        printf("| ID   |    NOMBRE   |     REGION             | ANIO CREACION |\n");
        printf("---------------------------------------------------------------\n");
         for(int i= 0; i < tamC; i++){

           printf("| %d  |%10s   |%22s  |      %4d     |\n",
                  confederaciones[i].id,
                  confederaciones[i].nombre,
                  confederaciones[i].region,
                  confederaciones[i].anioCreacion);
         }
    }
    printf("===============================================================\n");
    return ok;
}

int buscarConfederadion(eConfederacion confederaciones[], int tamC, int id, int* pIndice){
    int todoOk = 0;
    if( confederaciones && pIndice && tamC > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamC; i++)
        {
            if(confederaciones[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarConfederacion(eConfederacion confederacion[], int tamC)
{
    int ok = 0;
    if( confederacion && tamC > 0)
    {
        for(int i=0; i < tamC; i++)
        {
        	confederacion[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibre(eConfederacion confederaciones[], int tamC, int* pIndice)
{
    int ok = 0;
    if( confederaciones != NULL && pIndice != NULL && tamC > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tamC; i++)
        {
            if(confederaciones[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

void mostrarConfederacion(eConfederacion confederaciones)
{
	printf("ID: %d\n",  confederaciones.id);
	printf("NOMBRE: %s\n", confederaciones.nombre);
	printf("REGION: %s\n", confederaciones.region);
	printf("ANIO DE CREACION: %d\n",confederaciones.anioCreacion);
}

int altaConfederacion(eConfederacion confederaciones[], int tamC,int* pProxId)
{
    int ok = 0;
    int indice;
    eConfederacion nConfederaciones;

    if(confederaciones != NULL  && pProxId != NULL  && tamC > 0)
    {
        printf(" ______________________________________________________________________________ \n");
		printf("|                                                                              |\n");
		printf("|                             *** ALTA CONFEDERCIONES***                       |\n");
		printf("|______________________________________________________________________________|\n\n");
		buscarLibre(confederaciones, tamC, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	nConfederaciones.id = *pProxId;
            if(utn_getString(nConfederaciones.nombre,"Ingrese Nombre\n","ERROR (Rango->0,20)\n",1,50,2)==0
            && utn_getString(nConfederaciones.region,"Ingrese posicion\nArquero - Defensor - Mediocampista - Delantero\n","ERROR (Rango->0,20)\n",1,50,2)==0
            && utn_getNumeroInt(&nConfederaciones.anioCreacion,"Ingrese numero de camiseta\n","ERROR (Rango->1900,2000)\n",1900,2000,2)==0 )
            {
            	nConfederaciones.isEmpty = 0;
            	confederaciones[indice] = nConfederaciones;
                (*pProxId)++;
                 ok = 1;
            }
            else
                printf("No se ingreso la Confederacion por errores en el ingreso de datos\n");
        }
    }
    return ok;
}

int bajafederacion(eConfederacion confederaciones[], int tamC)
{
    int ok = 0;
    int id;
    int indice;
    char confirma;

    if(confederaciones != NULL && tamC > 0)
    {
    	printf(" ______________________________________________________________________________ \n");
		printf("|                                                                              |\n");
		printf("|                             ***BAJA CONFEDERACION***                         |\n");
		printf("|______________________________________________________________________________|\n\n");
        listarConfederaciones(confederaciones, tamC);
        if(utn_getNumeroInt(&id, "Ingrese Confederacion: \n","\nReingrese Opcion ('100' a '1000')\n",100,1000,2)==0)
        {
            if(buscarConfederadion(confederaciones, tamC, id, &indice) && indice == -1)
            {
                printf("No existe un Confederacion con id: %d en el sistema\n", id);
            }
            else
            {
            	mostrarConfederacion(confederaciones[indice]);
                if(utn_getCharacter(&confirma,"Confirma baja? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                {
                    confederaciones[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                    ok = 1;
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }
            }
        }else
            printf("No se pudo dar de baja la confederacion por errores en el ingreso de datos\n");
    }
    return ok;
}

int modificarfederacion(eConfederacion confederaciones[], int tamC)
{
    int ok = 0;
    int id;
    int indice;
    char salir = 'n';
    char confirma;
    eConfederacion nConfederaciones;

    if(confederaciones != NULL && tamC > 0)
    {
    	printf(" ___________________________________________________________________________________ \n");
		printf("|                                                                                   |\n");
		printf("|                             ***MODIFICAR CONFEDERCION***                          |\n");
		printf("|___________________________________________________________________________________|\n\n");
		listarConfederaciones(confederaciones, tamC);
        if(utn_getNumeroInt(&id,"Ingrese id\n","\nReingrese Opcion ('100' a '1000')\n",100,1000,2)==0
        && buscarConfederadion(confederaciones, tamC, id, &indice)
        && indice == -1 )
        {
            printf("No existe un confederacion con id: %d en el sistema\n", id);
        }
        else
        {
        	mostrarConfederacion(confederaciones[indice]);
            if(utn_getCharacter(&confirma,"Confirma el Jugador seleccionado? [s/n]\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
            {
                do
                {
                    switch(menuModificacionConfe())
                    {
                    case 1:
                        if(utn_getString(nConfederaciones.nombre,"Ingrese Nombre\n","ERROR (Rango->0,50)\n",0,50,2)==0)
                        {
                            strcpy(confederaciones[indice].nombre, nConfederaciones.nombre);
                            printf("Nombre modificado!!!\n");
                        }
                        break;
                    case 2:
                        if(utn_getString(nConfederaciones.region,"Ingrese posicion\n","ERROR (Rango->0,20)\n",0,50,2)==0)
                        {
                        	 strcpy(confederaciones[indice].region, nConfederaciones.region);
                            printf("Region modificada!!!\n");
                        }
                        break;
                    case 3:
                        if(utn_getNumeroInt(&nConfederaciones.anioCreacion,"Ingrese numero de anio de creacion\n","ERROR (Rango->1900,2000)\n",1900,2000,2)==0)
                        {
                        	confederaciones[indice].anioCreacion = nConfederaciones.anioCreacion;
                            printf("Anio de creacion modificado!!!\n");
                        }
                        else
                            printf("\nNo se modificaron datos\n");
                        break;

                    case 4:
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

