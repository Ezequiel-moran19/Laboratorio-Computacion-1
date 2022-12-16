#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(eTipo tipos[], int tamT, int id, char desc[]){
    int ok = 0;
    int flag = 1;
    if(tipos && tamT > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamT; i++)
         {
            if( tipos[i].idTipo == id){
                strcpy( desc, tipos[i].descripcion);
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

int listarTipos(eTipo tipos[], int tamT){

 int ok = 0;
    if(tipos != NULL && tamT > 0 ){

        printf("\n  *** LISTADO DE TIPOS ***\n\n");
        printf("=============================\n");
        printf("|    ID     |  DESCRIPCION  |\n");
        printf("-----------------------------\n");
         for(int i= 0; i < tamT; i++){

           printf("|    %4d   |  %10s   |\n",
                  tipos[i].idTipo,
                  tipos[i].descripcion);
         }
       printf("=============================\n");
       ok=1;
    }
    return ok;
}

int buscarTipos(eTipo tipos[], int tamT, int id, int* pIndice){
    int ok = 0;
    if( tipos && pIndice && tamT > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamT; i++)
        {
            if(tipos[i].idTipo == id)
            {
                *pIndice = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int validarTipos(eTipo tipos[], int tamT, int id){
 int esValido = 0;
 int indice;
     if (buscarTipos(tipos, tamT, id, &indice) == 1){
        if(indice != -1){
            esValido = 1;
        }
     }
 return esValido;
}
