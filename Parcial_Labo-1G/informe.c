#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informe.h"

int menuInformes(){
  int opcion;
  if(utn_getNumeroInt(&opcion, "\n***** Menu de Informes *****\n\n"
   "1. Mostrar aviones de la aerolinea seleccionada\n"
   "2. Mostrar aviones de un tipo \n"
   "3. Promedio de aviones jet sobre el total de aviones de una aerolinea\n"
   "4. listado de los aviones separados por aerolinea\n"
   "5. aerolineas que pueden transportar mas pasajeros\n"
   "6. Mostrar la aerolinea con menor cantidad de aviones\n"
   "7-     Salir\n",
    "\nReingrese Opcion ('1' a '7')\n",1,7,2)==0){}
   return opcion;
}

int informes(eAvion aviones[],int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT)
{
    char salir = 'n';
    int ok = 0;
    if(aviones != NULL && aerolineas != NULL  && tipos != NULL && tamAvion > 0 && tamA > 0 &&  tamT > 0 )
    {
        do
        {
            switch(menuInformes())
            {
            case 1:
                mostrarAvionesDeAerolinea(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
                break;
            case 2:
                mostrarAvionesTipos(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
                break;
            case 3:
                promedioAvionesJet(aviones, tamAvion, aerolineas, tamA);
                break;
            case 4:
                listarAvionesPorAerolinea(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
                break;
            case 5:
                aerolineasMasPasajeros(aviones, tamAvion, aerolineas, tamA, tipos, tamT);
                break;
            case 6:
                aerolineaMenorCantidadAviones(aviones, tamAvion, aerolineas, tamA);
                break;
            case 7:
                confirmarSalida(&salir);
                break;
            }
        }
        while(salir != 's');
        ok=1;
    }
    return ok;

}

int mostrarAvionesDeAerolinea(eAvion aviones[], int tamAvion, eAerolineas aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int ok = 0;
    int flag = 1;
    int idAerolinea;
    char descripcion[20];

    if(aviones != NULL && aerolineas != NULL  && tipos != NULL && tamAvion > 0 && tamA > 0 &&  tamT > 0 )
    {
        printf("**** INFORMES AVIONES DE UNA AEROLINEA ****\n");
        printf("---------------------------------------------\n\n");
        listarAerolineas(aerolineas, tamA);
        if(utn_getNumeroInt(&idAerolinea, "Ingrese Aerolinea: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1004,2)==0
        && validarAerolineas(aerolineas, tamA, idAerolinea)==1)
        {
            printf("\n*** LISTA DE AVIONES DE UNA AEROLINEA ***\n\n");
            printf("==========================================\n");
            printf("| ID|   AEROLINEA |    TIPO   | CAPACIDAD|\n");
            printf("------------------------------------------\n");
            for(int i=0; i < tamAvion; i++)
            {
                if(aviones[i].isEmpty == 0 && aviones[i].idAerolinea==idAerolinea)
                {
                    mostrarAvionesFila(aviones[i],aerolineas,tamA, tipos, tamT);
                    flag=0;
                }
            }
            printf("==========================================\n");
            cargarDescripcionAerolineas(aerolineas, tamA, idAerolinea, descripcion);
            if(flag)
            {
                printf("\n No hay aviones en la aerolinea %s \n\n", descripcion);
            }
        }
        else
            printf("\nNo se ingresaron Aerolineas por errores en el ingreso de datos\n");
        ok=1;
    }
    return ok;
}

int mostrarAvionesTipos(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT)
{
    int ok = 0;
    int flag = 1;
    int idTipo;
    char descripcion[50];

    if(aviones != NULL && aerolineas != NULL  && tipos != NULL && tamAvion > 0 && tamA > 0 &&  tamT > 0 )
    {
        printf("   *** INFORMES AVIONES DE UN TIPO ***\n");
        printf("=========================================\n\n");
        listarTipos(tipos, tamT);
        if(utn_getNumeroInt(&idTipo, "Ingrese Tipo: \n","\nReingrese Opcion ('5000' a '5003')\n",5000,5003,2)==0
        && validarTipos(tipos, tamT, idTipo)==1)
        {
            printf("\n******* LISTA DE AVIONES DE UN TIPO *******\n");
            printf("==========================================\n");
            printf("| ID|   AEROLINEA |    TIPO   | CAPACIDAD|\n");
            printf("------------------------------------------\n");
            for(int i=0; i < tamAvion; i++)
            {
                if(aviones[i].isEmpty == 0 &&  aviones[i].idTipo==idTipo)
                {
                    mostrarAvionesFila(aviones[i], aerolineas, tamAvion, tipos, tamT);
                    flag=0;
                }
            }
            printf("==========================================\n");
            cargarDescripcionTipo(tipos, tamT, idTipo, descripcion);
            if(flag)
            {
                printf("\nNo hay aviones del tipo jet: %s\n\n",descripcion);
            }
        }
        else
            printf("\nNo se ingresaron Tipos por errores en el ingreso de datos\n");

        ok = 1;
    }
    return ok;
}

int promedioAvionesJet(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA)
{
    int ok = 0;
    int idAerolinea;
    float porcentaje;
    int contadorAviones = 0;
    int contador = 0;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 )
    {
        printf("\n***** PORCENTAJE DE AVIONES JET POR TOTAL AVIONES ****\n");
        listarAerolineas(aerolineas, tamA);
        if(utn_getNumeroInt(&idAerolinea, "Ingrese Aerolinea: \n","\nReingrese Opcion ('1000' a '1003')\n",1000,1004,2)==0
        && validarAerolineas(aerolineas, tamA, idAerolinea)==1)
        {
            for(int i = 0; i < tamAvion; i++)
            {
                if(aviones[i].idAerolinea == idAerolinea)
                {
                    contadorAviones++;
                    if( aviones[i].isEmpty == 0 && aviones[i].idTipo == 5000)
                    {
                        contador++;
                    }
                }
            }
            if (contadorAviones == 0)
            {
                printf("\nNo se encontraron aviones en la aerolinea\n");
            }
            else
            {
                porcentaje = (contador * 100) / contadorAviones;
                printf("\nPorcentaje de aviones tipo Jet: %.2f\n", porcentaje);
            }
        }
        else
            printf("\nNo se ingresaron Aerolineas por errores en el ingreso de datos\n");
        ok = 1;
    }

    return ok;
}


int listarAvionesPorAerolinea(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT)
{
    int ok = 0;
    int flag;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 && tipos != NULL && tamT > 0 )
    {
        printf("\n                   ******* LISTADO DE AVIONES DE UNA AEROLILEA *******\n");
        printf("      =====================================================================================\n\n");

        for(int i=0; i < tamA; i++)
        {
            printf("\nAEROLINEA: %s\n", aerolineas[i].descripcion);
            printf("==========================================\n");
            printf("| ID|   AEROLINEA |    TIPO   | CAPACIDAD|\n");
            printf("------------------------------------------\n");
            flag = 1;

            for(int j = 0; j < tamAvion; j++)
            {
                if( !aviones[j].isEmpty && aviones[j].idAerolinea == aerolineas[i].idAerolineas)
                {
                    mostrarAvionesFila(aviones[j],aerolineas,tamA, tipos, tamT);
                    flag = 0;
                }
            }
            printf("==========================================\n");
            if(flag)
            {
                printf("No hay aviones en esta aerolinea: %s\n\n",aerolineas[i].descripcion);
            }
        }
        ok = 1;
    }
    return ok;
}

int aerolineasMasPasajeros(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int mayorCarga;
    int flag = 1;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 )
    {
        printf("\n***  AEROLINEAS/AS QUE PUEDEN TRANSPORTAR MAS PASAJEROS ***\n\n");

        for(int i=0; i < tamAvion; i++)
        {
            if( !aviones[i].isEmpty && ( flag || aviones[i].capacidad > mayorCarga))
            {
                mayorCarga = aviones[i].capacidad;
                flag = 0;
            }
        }

        if(flag)
        {
            printf("No hay aviones registrados en el sistema\n\n");
        }
        else
        {
            printf("CAPACIDAD: %d \n", mayorCarga);

            for(int i=0; i < tamAvion; i++)
            {
                if(!aviones[i].isEmpty && aviones[i].capacidad == mayorCarga)
                {
                    printf("AEROLINEA: %s\n", aerolineas[i].descripcion);
                }
            }
            printf("\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int aerolineaMenorCantidadAviones(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA)
{
    int ok = 0;
    int contador[]= {0, 0, 0, 0, 0};
    int menor;

    if(aviones != NULL && tamAvion > 0 && aerolineas != NULL && tamA > 0 )
    {
        printf("\n***** AEROLINEA CON  MENOR CANTIDAD DE AVIONES *****\n");
        for(int i = 0; i < tamA; i++)
        {
            for(int j = 0; j < tamAvion; j++)
            {
                if(aviones[j].isEmpty == 0 && aviones[j].idAerolinea == aerolineas[i].idAerolineas)
                {
                    contador[i]++;
                }
            }
        }
        for(int i = 0; i < tamA; i++)
        {
            if(i==0 || contador[i] < menor)
            {
                menor = contador[i];
            }
        }
        for(int i = 0; i < tamA; i++)
        {
            if(contador[i] == menor )
            {
                printf("\n  =============================");
                printf("\n  |AEROLINEA:    %10s   |\n", aerolineas[i].descripcion);
                printf("  |CANTIDAD DE AVIONES: %d     |\n", contador[i]);
                printf("  =============================\n");
            }
        }
        ok = 1;
    }
    return ok;
}
