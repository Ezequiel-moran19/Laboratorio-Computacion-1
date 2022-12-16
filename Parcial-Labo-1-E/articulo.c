
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"
#include "articulo.h"

int menuPrincipal(){
	int opcion;
	printf("\n     *** Menu Principal *** \n\n");
	printf("1. Alta Articulo\n");
	printf("2. Modificar Articulo\n");
	printf("3. Baja Articulo\n");
	printf("4. Listar Articulos\n");
	printf("5. Listar Rubros\n");
	printf("6. Alta Ventas\n");
	printf("7. Listar Ventas\n");
	printf("8. Informes\n");
	printf("9. Salir\n");
	printf("Ingrese opcion: \n");
	fflush(stdin);
    scanf("%d", &opcion);

	return opcion;
}

void mostrarAtirculos(eArticulo art, eRubro vecR[],int tamR){
    char descripcion[20];
    if(cargarDescripcionRubro(vecR, tamR, art.rubroId, descripcion)==1){
       printf("Id: %d\n", art.idArticulo);
	   printf("Descripcion: %s\n", art.descripcion);
	   printf("Medida: %.2f\n", art.medida);
	   printf("Precio: %.2f\n", art.precio);
	   printf("Rubro: %s\n", descripcion);

    }
}

void mostrarArticulosFila(eArticulo art, eRubro vecR[],int tamR){
    char descripcion[20];
    cargarDescripcionRubro(vecR, tamR, art.rubroId, descripcion);
	printf(" %4d        %10s        %.2f       $%.2f        %10s \n",
    	art.idArticulo,
    	art.descripcion,
    	art.medida,
    	art.precio,
    	descripcion
        );
        printf("\n-----------------------------------------------------------------------\n");
}

int inicializarArticulos(eArticulo vecA[], int tamA){
    int ok = 0;
    if( vecA != NULL && tamA > 0)
    {
        for(int i=0; i < tamA; i++)
        {
            vecA[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibre(eArticulo vecA[], int tamA, int* pIndex){
    int ok = 0;
    if( vecA != NULL && pIndex != NULL && tamA > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamA; i++)
        {
            if(vecA[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int buscarArticulo(eArticulo vecA[], int tamA, int id, int* pIndex){
    int ok = 0;
    if( vecA != NULL && pIndex != NULL && tamA > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamA; i++)
        {
            if( !vecA[i].isEmpty  && vecA[i].idArticulo == id)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int listarArticulos(eArticulo vecA[], int tamA , eRubro vecR[], int tamR){
    int flag = 1;
    int ok = 0;
    if(vecA != NULL && tamA > 0 && vecR != NULL && tamR > 0){

        printf("\n                        *** Listado de Productos *** \n\n");
        printf("  id           descripcion    medida       precio            rubro \n");
        printf("-----------------------------------------------------------------------\n");
        for(int i = 0; i < tamA; i++){
          if(!vecA[i].isEmpty){
             mostrarArticulosFila(vecA[i],vecR,tamR);
             flag = 0;
          }
        }
        if(flag){
            printf("     No hay productos en el sistema\n");
        }
        ok = 1;
    }
    return ok;
}

int hardcodearAticulos(eArticulo vecA[], int tamA, int cant, int* pId){
	int ok = 0;
   eArticulo articulos[5] =
    {   {0, "Negro" ,1.80,1000,1001,0},
        {0,"Blanco" ,1.50,2500,1002,0},
        {0, "Grande" ,1.75,3100,1003,0},
        {0, "Chico" ,2.50,4800,1004,0}
         };

   if(vecA != NULL && pId && tamA > 0 && tamA <= 5 && cant <= tamA){
	    for(int i = 0; i < cant; i++){
	    	vecA[i] = articulos[i];
	    	vecA[i].idArticulo = *pId;
	    	(*pId)++;
	    }
	  ok = 1;
   }
   return ok;
}

int validarArticulo(eArticulo vecA[], int tamA, int id){
    int esValido = 0;
    int indice;

    if (buscarArticulo(vecA, tamA, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int altaArticulos(eArticulo vecA[], int tamA, eRubro vecR[], int tamR, int* pProxId){
    int ok = 0;
    int indice;
    int idR;
    float auxPrecio;
    float auxMedida;
    eArticulo nuevoArt;

    if( vecA != NULL && pProxId && tamA > 0 && vecR != NULL && tamR > 0 )
    {

        printf("    *** Alta Articulos ***\n\n");
        buscarLibre(vecA, tamA, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoArt.idArticulo = *pProxId;

            pidoValidoLetras(nuevoArt.descripcion, tamA, "");

            printf("Ingrese medida: ");
            scanf("%f", &auxMedida);
            while( auxMedida < 0 )
            {
                printf("Medida invalido. Reingrese Medida mayor a 0: ");
                scanf("%f", &auxMedida);

            }
            nuevoArt.medida = auxMedida;

            printf("Ingrese precio: ");
            scanf("%f", &auxPrecio);
            while( auxPrecio < 0 )
            {
                printf("Precio invalido. Reingrese precio mayor a 0: ");
                scanf("%f", &auxPrecio);

            }
            nuevoArt.precio = auxPrecio;

            listarRubros(vecR, tamR);
            printf("Ingrese rubro: ");
            scanf("%d", &idR);
            while( !validarRubros(vecR,tamR, idR) )
            {
                printf("Id invalido. Reingrese id rubro: ");
                scanf("%d", &idR);

            }
              nuevoArt.rubroId = idR;

              nuevoArt.isEmpty = 0;

              vecA[indice] = nuevoArt;

              (*pProxId)++;

                ok = 1;
          }
        }
    return ok;
}

int bajaArticulos(eArticulo vecA[], int tamA, eRubro vecR[], int tamR){
    int ok = 0;
	int indice;
	int id;
	char confirma;

	if( vecA != NULL && tamA > 0 && vecR != NULL && tamR > 0)
	{
		listarArticulos(vecA, tamA, vecR, tamR);
		printf("Ingrese id: ");
		scanf("%d", &id);

		if (buscarArticulo(vecA, tamA, id, &indice)){

			if(indice == -1)
			{
				printf("No existe un aticulo con id: %d en el sistema\n", id);
			}
			else
			{
				mostrarAtirculos(vecA[indice], vecR, tamR);
				printf("Confirma baja? [s/n]: ");
				fflush(stdin);
				scanf("%c", &confirma);

				if(confirma == 's' || confirma == 'S')
				{
					vecA[indice].isEmpty = 1;
					printf("Baja exitosa!!!\n");
					ok = 1;
				}
				else
				{
					printf("Baja cancelada por el usuario\n");
				}
            }
            ok=1;
		}
    }
	return ok;
}

int modificarArticulos(eArticulo vecA[], int tamA, eRubro vecR[], int tamR){
    int ok = 0;
    int indice;
    int id;
    float precio;
    float medida;

    if( vecA != NULL && tamA > 0 && vecR != NULL && tamR > 0)
    {
        listarArticulos(vecA, tamA, vecR, tamR);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarArticulo(vecA, tamA, id, &indice))
        {

           if(indice == -1)
           {
                printf("No existe un articulo con id: %d en el sistema\n", id);
           }
           else
           {
                switch(menuModificarArticulos()){
                    case 1:
                        printf("Ingrese medida: ");
                        scanf("%f", &medida);
                        while( medida < 0 )
                        {
                            printf("Medida invalido. Reingrese Medida mayor a 0: ");
                            scanf("%f", &medida);

                        }
                        vecA[indice].medida = medida;
                        printf("Tipo modificado!!!");
                        break;
                    case 2:
                        printf("Ingrese nuevo precio: ");
                        scanf("%f", &precio);
                        while( precio < 0 )
                        {
                            printf("Precio invalido. Reingrese precio mayor a 0: ");
                            scanf("%f", &precio);
                        }
                        vecA[indice].precio = precio;
                        printf("Precio modificado!!!");
                        break;
                  }
            }
          ok = 1;
        }
    }
    return ok;
}

int menuModificarArticulos(){
	int opcion;
	printf("     *** Campo a modificar ***\n\n");
	printf("1. Medida\n");
	printf("2. Precio\n");
	printf("3. Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	return opcion;
}

