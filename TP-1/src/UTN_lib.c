#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN_lib.h"

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

int capitalString (char string[]){

		int retorno = 0;

		if( string != NULL){

			for (int i = 0; string[i] != '\0'; i++){


					string[i] = tolower(string[i]);
			}

			string [0] = toupper(string[0]);

			for (int i = 0; string[i] != '\0'; i++){

				if (string[i] == ' '){

					string[i+1] = toupper(string[i+1]);
				}
			}

			retorno = 1;
		}
	return retorno;
}
int quitarEnter (char string[], int max_string){

	int retorno = 0;
	char aux[max_string];

	strncpy(aux, string, max_string);

	if(string != NULL && max_string > 0){

		for(int i = 0; i < max_string; i++){

			if(aux[i] == '\n'){

				aux[i] = '\0';
				strncpy(string, aux, max_string);
				retorno = 1;

				break;
			}
		}

		if(!retorno){

			printf("No se ha podido procesar la solicitud. Dato demasiado largo.\n");
		}
	}
	return retorno;
}

int cargaString (char string[], int max_string, char* mensaje, char* mensajeError){
	int retorno = 0;
	int reintentos = 3;
	int flag = 0;
	char aux[max_string];
	if(string != NULL && max_string > 0){

		do{
			printf("%s", mensaje);
			fflush(stdin);
			fgets(aux, max_string, stdin);

			if(quitarEnter(aux, max_string)){

				flag = 0;

				for(int i = 0; aux[i] != '\0'; i++){

					if(i != 0 && aux[i] == ' '){

						continue;

					}

					if(!isalpha(aux[i])){

						flag = 1;
						reintentos --;
						printf("%s", mensajeError);
						break;
					}
				}

				if(!flag){

					retorno = 1;
					capitalString (aux);
					strncpy(string, aux, max_string);
					break;
				}

			}

		}while(reintentos > 0);

	}

	if (!reintentos){

		printf("\nNo se ha podido ingresar el dato.");
	}
	return retorno;
}

void confirmarSalida(char* x)
{
    printf("Confirma que desea salir?: [s/n]");
    fflush(stdin);
    scanf("%c",x);
}

