
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_lib.h"
#include "rubro.h"
#include "articulo.h"

int menuPrincipal(){
	int opcion;
	if(utn_getNumeroInt(&opcion, "\n     *** Menu Principal *** \n\n"
    "1. Alta Articulo\n"
    "2. Modificar Articulo\n"
    "3. Baja Articulo\n"
    "4. Listar Articulos\n"
    "5. Listar Rubros\n"
    "6. Alta Ventas\n"
    "7. Listar Ventas\n"
    "8. Informes\n"
    "9. Salir\n"
    "Ingrese opcion: \n",
    "\nReingrese Opcion ('1' a '9')\n",1,9,2)==0){}
    return opcion;
}

void mostrarAtirculos(eArticulo art, eRubro vecR[],int tamR)
{
    char descripcion[20];
    if(cargarDescripcionRubro(vecR, tamR, art.rubroId, descripcion)==1)
    {
        printf("Id: %d\n", art.idArticulo);
        printf("Descripcion: %s\n", art.descripcion);
        printf("Medida: %.2f\n", art.medida);
        printf("Precio: %.2f\n", art.precio);
        printf("Rubro: %s\n", descripcion);
    }
}

void mostrarArticulosFila(eArticulo art, eRubro vecR[],int tamR)
{
    char descripcion[20];
    cargarDescripcionRubro(vecR, tamR, art.rubroId, descripcion);
    printf(" %4d        %10s        %.2f       $%.2f        %10s \n",
           art.idArticulo,
           art.descripcion,
           art.medida,
           art.precio,
           descripcion);
    printf("\n-----------------------------------------------------------------------\n");
}

int inicializarArticulos(eArticulo articulos[], int tamA)
{
    int ok = 0;
    if( articulos  && tamA > 0)
    {
        for(int i=0; i < tamA; i++)
        {
            articulos[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}

int buscarLibre(eArticulo articulos[], int tamA, int* pIndex)
{
    int ok = 0;
    if( articulos != NULL && pIndex != NULL && tamA > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tamA; i++)
        {
            if(articulos[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int buscarArticulo(eArticulo articulos[], int tamA, int id, int* pIndex)
{
    int ok = 0;
    if( articulos && pIndex && tamA > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamA; i++)
        {
            if( !articulos[i].isEmpty  && articulos[i].idArticulo == id)
            {
                *pIndex = i;
                break;
            }
        }
        ok = 1;
    }
    return ok;
}

int listarArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR)
{
    int flag = 1;
    int ok = 0;
    if(articulos && tamA > 0 && rubros && tamR > 0)
    {
        printf("\n                        *** LISTADO DE PRODUCTOS *** \n\n");
        printf("    ID         DESCRIPCION    MEDIDA       PRECIO              RUBRO \n");
        printf("-----------------------------------------------------------------------\n");
        ordenarRubroDescripcion(articulos, tamA);
        for(int i = 0; i < tamA; i++)
        {
            if(!articulos[i].isEmpty)
            {
                mostrarArticulosFila(articulos[i],rubros,tamR);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay productos en el sistema\n");
        }
        ok = 1;
    }
    return ok;
}

int ordenarRubroDescripcion(eArticulo articulos[], int tamA)
{
    int ok=0;
    eArticulo auxArt;
    if(articulos && tamA > 0)
    {
        for(int i=0; i<tamA-1; i++)
        {
            for(int j=i+1; j<tamA; j++)
            {
                if(articulos[i].rubroId > articulos[j].rubroId)
                {
                    auxArt=articulos[i];
                    articulos[i]=articulos[j];
                    articulos[j]=auxArt;
                }
                else if (articulos[i].rubroId == articulos[j].rubroId &&
                         strcmp(articulos[i].descripcion,articulos[j].descripcion) > 0)
                {
                    auxArt=articulos[i];
                    articulos[i]=articulos[j];
                    articulos[j]=auxArt;
                }
            }
        }
        ok=1;
    }
    return ok;
}

int hardcodearAticulos(eArticulo articulos[], int tamA, int cant, int* pId)
{
    int ok = 0;
    eArticulo listaA[5] =
    {
        {0, "Negro",1.80,1000,1001},
        {0,"Blanco",1.50,2500,1002},
        {0, "Grande",1.75,3100,1003},
        {0, "Chico",2.50,4800,1004},
        {0, "Mediano",1.15,2000,1005}
    };

    if(articulos && pId && tamA > 0 && tamA <= 5 && cant <= tamA)
    {
        for(int i = 0; i < cant; i++)
        {
            articulos[i] = listaA[i];
            articulos[i].idArticulo = *pId;
            (*pId)++;
        }
        ok = 1;
    }
    return ok;
}

int validarArticulo(eArticulo articulos[], int tamA, int id)
{
    int esValido = 0;
    int indice;

    if (buscarArticulo(articulos, tamA, id, &indice )== 1 )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int altaArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR, int* pProxId)
{
    int ok = 0;
    int indice;
    eArticulo nuevoArt;

    if( articulos && pProxId && tamA > 0 && rubros && tamR > 0 )
    {
        printf("    *** ALTA ARTICULOS ***\n\n");
        buscarLibre(articulos, tamA, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoArt.idArticulo = *pProxId;
            if(utn_getString(nuevoArt.descripcion,"Ingrese Nombre\n","ERROR (Rango->0,20)\n",0,20,2)==0&&
               utn_getNumeroFloat(&nuevoArt.medida, "Ingrese Medida: \n","\nReingrese Opcion ('1' a '300')\n",1,300,2)==0 &&
               utn_getNumeroFloat(&nuevoArt.precio, "Ingrese Precio: \n","\nReingrese Opcion ('1' a '1000000')\n",1,1000000,2)==0)
            {
                listarRubros(rubros, tamR);
                if(utn_getNumeroInt(&nuevoArt.rubroId, "Ingrese Rubro: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1003,2)==0)
                {
                    nuevoArt.isEmpty = 0;
                    articulos[indice] = nuevoArt;
                    (*pProxId)++;
                    ok = 1;
                }
                else
                    printf("No se ingreso el Articulos por errores en el ingreso de datos\n");

            }
            else
                printf("No se ingreso el Articulos por errores en el ingreso de datos\n");
        }
    }
    return ok;
}

int bajaArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR)
{
    int ok = 0;
    int id;
    int indice;
    char confirma;

    if( articulos && tamA > 0 && rubros && tamR > 0)
    {
        printf("\n                     ******* BAJA DE ARTICULOS *******\n");
        listarArticulos(articulos, tamA, rubros, tamR);
        if(utn_getNumeroInt(&id, "Ingrese Articulo: \n","\nReingrese Opcion ('1' a '5')\n",1,5,2)==0)
        {
            if(buscarArticulo(articulos, tamA, id, &indice))
            {
                if(indice == -1)
                {
                    printf("No existe un aticulo con id: %d en el sistema\n", id);
                }
                else
                {
                    mostrarAtirculos(articulos[indice], rubros, tamR);
                    if(utn_getCharacter(&confirma,"Confirma baja? [s/n]: \n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                    {
                        articulos[indice].isEmpty = 1;
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
    }
    return ok;
}

int modificarArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR)
{
    int ok = 0;
    int id;
    int indice;
    char salir = 'n';
    char confirma;
    eArticulo auxArt;

    if( articulos && tamA > 0 && rubros && tamR > 0)
    {
        listarArticulos(articulos, tamA, rubros, tamR);
        if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,5)\n",0,5,2)==0)
        {
            if( buscarArticulo(articulos, tamA, id, &indice))
            {
                if(indice == -1)
                {
                    printf("No existe un articulo con id: %d en el sistema\n", id);
                }
                else
                {
                    mostrarAtirculos(articulos[indice], rubros, tamR);
                    if(utn_getCharacter(&confirma,"Confirma el Articulo seleccionado? [s/n]\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
                    {
                        do
                        {
                            switch(menuModificacion())
                            {
                            case 1:
                                if(utn_getNumeroFloat(&auxArt.medida, "Ingrese Medida: \n","\nReingrese Opcion ('1' a '300')\n",1,300,2)==0)
                                {
                                    articulos[indice].medida = auxArt.medida;
                                    printf("Medida modificado!!!\n");
                                }
                                else
                                    printf("\nNo se modificaron datos\n");
                                break;
                            case 2:
                                if(utn_getNumeroFloat(&auxArt.precio, "Ingrese Precio: \n","\nReingrese Opcion ('1' a '1000000')\n",1,1000000,2)==0)
                                {
                                    articulos[indice].precio = auxArt.precio;
                                    printf("Precio modificado!!!\n");
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
    }
    return ok;
}

int menuModificacion(){
  int opcion;
  if(utn_getNumeroInt(&opcion,
    "Ingrese opcion:\n 1-Medida\n 2-Precio\n 3-Salir\n",
    "ERROR (Rango 1->3)",1,3,2)==0){}
   return opcion;
}
