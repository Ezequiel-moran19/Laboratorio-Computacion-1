#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"

int cargarDescripcionRubro(eRubro vecR[], int tamR, int id, char desc[]){

    int ok = 0;
    int flag = 1;
    if(vecR != NULL && tamR > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamR; i++){

            if( vecR[i].idRubro == id){
                strcpy( desc, vecR[i].descripcion);
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

int listarRubros(eRubro vecR[], int tamR){

 int todoOk = 0;
    if(vecR != NULL && tamR > 0 ){

        printf("\n   *** Listado de Rubros ***\n\n");

        printf("     id       descripcion\n");
        printf("--------------------------\n");
         for(int i= 0; i < tamR; i++){

           printf("    %4d      %10s\n",
                  vecR[i].idRubro,
                  vecR[i].descripcion);
         }
    }
    return todoOk;
}

int buscarRubros(eRubro vecR[], int tamR, int id, int* pIndice)
{
    int todoOk = 0;
    if( vecR != NULL && pIndice && tamR > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamR; i++)
        {
            if(vecR[i].idRubro == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarRubros(eRubro vecR[], int tamR, int id){
 int esValido = 0;
 int indice;

 if (buscarRubros(vecR, tamR, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}
