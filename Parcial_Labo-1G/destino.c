#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "destino.h"

int cargarDescripcionDestino(eDestino destinos[], int tamD, int id, char desc[]){
    int ok = 0;
    int flag = 1;
    if(destinos && tamD > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamD; i++)
         {
            if( destinos[i].idDestino == id){
                strcpy( desc, destinos[i].descripcion);
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

int listarDestinos(eDestino destinos[], int tamD){

 int todoOk = 0;
    if(destinos && tamD > 0 ){

        printf("\n*** LISTADO DE DESTINOS ***\n\n");
        printf("===============================================\n");
        printf("|     ID     |  DESCRIPCION  |     PRECIO     |\n");
        printf("-----------------------------------------------\n");
         for(int i= 0; i < tamD; i++){

           printf("|    %4d   |  %10s   |   $%10.2f  |\n",
                  destinos[i].idDestino,
                  destinos[i].descripcion,
                  destinos[i].precio);
         }
       printf("===============================================\n");
    }
    return todoOk;
}

int buscarDestinos(eDestino destinos[], int tamD, int id, int* pIndice){
    int todoOk = 0;
    if( destinos && tamD > 0  )
    {
        *pIndice = -1;
        for(int i=0; i < tamD; i++)
        {
            if(destinos[i].idDestino == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarDestinos(eDestino destinos[], int tamD, int id){
 int esValido = 0;
 int indice;
     if (buscarDestinos(destinos, tamD, id, &indice) == 1){
        if(indice != -1){
            esValido = 1;
        }
     }
 return esValido;
}
