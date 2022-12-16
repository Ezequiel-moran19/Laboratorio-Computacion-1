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
int ingresoEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int todoOK=-1;
    int numeroIngresado;

    if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
    {
       printf("%s", mensaje);
       fflush(stdin);
       scanf("%d", &numeroIngresado);

       while(numeroIngresado<min || numeroIngresado>max)
       {
          printf("%s", mensajeError);
          fflush(stdin);
          scanf("%d", &numeroIngresado);
       }

       *entero=numeroIngresado;
       todoOK=1;
    }

    return todoOK;
}

int validarNumero(char numero[])
{
    int todoOk = 1;
    int esNumero;

    if(numero != NULL)
    {
        for(int i = 0; i < strlen(numero) -1; i++)
        {
            esNumero = isdigit(numero[i]);
            if(esNumero == 0)
            {
                puts("Error no es un numero...\n");
                todoOk = 0;
                break;
            }
        }
    }

    return todoOk;
}

int convertirCharAInt(char num[], int* pNumero)
{
    int todoOk = 0;

    if(num != NULL && pNumero != NULL)
    {
        *pNumero = atoi(num);
        todoOk = 1;
    }
    return todoOk;
}

int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo)
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL && mensaje != NULL && minimo < maximo)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0 || stricmp(buffNum , "\n") == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAInt(buffNum, &numero))
        {
            if(numero < minimo || numero > maximo)
            {
                printf("Numero fuera de rango, NO GUARDADO! Reintente\n");
            }
            else
            {
                *pNumero = numero;
                todoOk = 1;
            }

        }
    }
    return todoOk;
}
int capitalString (char string[])
{

	int ok = 0;
	if( string != NULL)
	{
		for (int i = 0; string[i] != '\0'; i++)
		{
			string[i] = tolower(string[i]);
		}
		string [0] = toupper(string[0]);

		for (int i = 0; string[i] != '\0'; i++)
		{
			if (string[i] == ' ')
			{
				string[i+1] = toupper(string[i+1]);
			}
		}

		ok = 1;
	}
	return ok;
}
int quitarEnter (char string[], int max_string)
{

	int ok = 0;
	char aux[max_string];

	strncpy(aux, string, max_string);

	if(string != NULL && max_string > 0){

		for(int i = 0; i < max_string; i++){

			if(aux[i] == '\n'){

				aux[i] = '\0';
				strncpy(string, aux, max_string);
				ok = 1;

				break;
			}
		}

		if(!ok){

			printf("No se ha podido procesar la solicitud. Dato demasiado largo.\n");
		}
	}
	return ok;
}

int cargaString (char string[], int max_string, char* mensaje, char* mensajeError)
{
	int ok = 0;
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

					ok = 1;
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
	return ok;
}
