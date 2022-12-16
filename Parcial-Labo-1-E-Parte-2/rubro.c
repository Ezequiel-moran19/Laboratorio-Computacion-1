#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"

int cargarDescripcionRubro(eRubro rubros[], int tamR, int id, char desc[]){
    int ok = 0;
    int flag = 1;
    if(rubros && tamR > 0 && desc ){
         ok = 1;
         for(int i= 0; i < tamR; i++)
         {
            if( rubros[i].idRubro == id){
                strcpy( desc, rubros[i].descripcion);
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

int listarRubros(eRubro rubros[], int tamR){

 int todoOk = 0;
    if(rubros && tamR > 0 ){

        printf("\n   *** LISTADO DE RUBROS ***\n\n");

        printf("     ID       DESCRIPCION\n");
        printf("--------------------------\n");
         for(int i= 0; i < tamR; i++){

           printf("    %4d      %10s\n",
                  rubros[i].idRubro,
                  rubros[i].descripcion);
         }
    }
    return todoOk;
}

int buscarRubros(eRubro rubros[], int tamR, int id, int* pIndice){
    int todoOk = 0;
    if( rubros && pIndice && tamR > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamR; i++)
        {
            if(rubros[i].idRubro == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarRubros(eRubro rubros[], int tamR, int id){
 int esValido = 0;
 int indice;
     if (buscarRubros(rubros, tamR, id, &indice) == 1){
        if(indice != -1){
            esValido = 1;
        }
     }
 return esValido;
}
