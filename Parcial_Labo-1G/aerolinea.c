#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "aerolinea.h"

int cargarDescripcionAerolineas(eAerolineas aerolineas[], int tamA, int id, char desc[]){
    int ok = 0;
    int flag = 1;
    if(aerolineas && tamA > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamA; i++)
         {
            if( aerolineas[i].idAerolineas == id){
                strcpy( desc, aerolineas[i].descripcion);
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

int listarAerolineas(eAerolineas aerolineas[], int tamA)
{

 int todoOk = 0;
    if(aerolineas != NULL && tamA > 0 ){

        printf("\n*** LISTADO DE AEROLINEAS ***\n\n");
        printf("=========================\n");
        printf("|    ID     |  NOMBRE   |\n");
        printf("-------------------------\n");
         for(int i= 0; i < tamA; i++)
        {
           printf("|    %4d   |%10s |\n",
           aerolineas[i].idAerolineas, aerolineas[i].descripcion);
         }
        printf("=========================\n");
    }
    return todoOk;
}


int buscarAerolineas(eAerolineas aerolineas[], int tamA, int id, int* pIndice){
    int todoOk = 0;
    if( aerolineas && pIndice && tamA > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamA; i++)
        {
            if(aerolineas[i].idAerolineas == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarAerolineas(eAerolineas aerolineas[], int tamA, int id){
 int esValido = 0;
 int indice;
     if (buscarAerolineas(aerolineas, tamA, id, &indice))
     {
        if(indice != -1){
            esValido = 1;
        }
     }
 return esValido;
}





