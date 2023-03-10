/*
 * UTN_SebaLib.c
 *
 *  Created on: 13 may. 2022
 *      Author: Sebastian Migliorisi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado
 * 			en cadena un maximo de 'longitud-1' caracteres
 *
 * \param cadena puntero al espacio de memoria donde se copiara la cadena
 * \param longitud define el tama�o de la cadena
 * \return retorna 0 si se obtiene una cadena y 1 si no
 */

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';
	return 0;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 *
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 si la cadena es numerica y 0 si no lo es
 */
static int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0, cPunto=0;
	if(cadena[0]=='-')
		i++;
	for( ; cadena[i]!='\0'; i++)
	{
		if(cadena[i]<'0' || cadena[i]>'9')
		{
			if(cadena[i]=='.' && cPunto==0)
				cPunto=1;
			else
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Convierte una cadena de caracteres en numero entero
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 si se obtiene un numero entero y 1 si no
 */
static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}

/**
 * \brief Convierte una cadena de caracteres en numero flotante
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara la funcion
 * \return Retorna 0 si se obtiene un numero flotante y 1 si no
 */

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atof(buffer);
	}
	return retorno;
}

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo>=0 &&  minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);
			//fflush(stdin);
			//scanf("%c", &buffer);
			if(myGets(buffer,sizeof(buffer))==0 && strlen(buffer)==1 && buffer[0]>=minimo && buffer[0]<=maximo)
			{
				*pResultado=buffer[0];
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}

int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo>=0 && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s", mensaje);

			if(myGets(buffer,sizeof(buffer))==0 && strnlen(buffer,4096)>=minimo && strnlen(buffer,4096)<=maximo)
			{
				strncpy(pResultado,buffer,maximo);
				pResultado[maximo] = '\0';
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}


int calcularMayor (int *pResultado, int num1, int num2)
{
	int retorno=-1;

	if(pResultado!=NULL)
	{
		if(num1==num2)
			retorno=0;
		else if(num1>num2)
			*pResultado=num1;
		else
			*pResultado=num2;
	}
	return retorno;
}


int calcularMenor (int *pResultado, int num1, int num2)
{
	int retorno=-1;

	if(pResultado!=NULL)
	{
		if(num1==num2)
			retorno=0;
		else if(num1>num2)
			*pResultado=num1;
		else
			*pResultado=num2;
	}
	return retorno;
}


int validarLetras(char letras[])
{
    int todoOk = 1;
    int esLetra;

    if(letras != NULL)
    {
        for(int i = 0; i < strlen(letras) -1; i++)
        {
            esLetra = isalpha(letras[i]);
            if(esLetra == 0)
            {
              todoOk = 0;
              break;
            }
        }
    }

    return todoOk;
}

int pidoValidoLetras(char cadena[], int tam, char mensaje[])
{
    int todoOk = 0;
    char buffer[100];

    if(cadena != NULL && mensaje != NULL && tam > 0)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, tam, stdin);

        while(validarLetras(buffer) == 0 || stricmp(buffer , "\n") == 0)
        {
            printf("Ingreso invalido.\nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, tam, stdin);
        }

        strcpy(cadena, buffer);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            todoOk = 1;
        }
    }
    return todoOk;
}

void confirmarSalida(char* x)
{
    printf("Confirma que desea salir?: [s/n]");
    fflush(stdin);
    scanf("%c",x);
}
