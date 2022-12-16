#ifndef UTN_LIB_H_INCLUDED
#define UTN_LIB_H_INCLUDED

/**
 * \brief Solicita un numero entero al usuario, lo verifica y devuelve el resultado
 *
 * \param pResultado: puntero a donde se carga el resultado
 * \param mensaje: texto que pide ingreso de numero
 * \param mensajeError: texto de error
 * \param minimo: minimo valor
 * \param maximo: maximo valor
 * \param reintentos: cant. de reintentos para el ingreso
 * \return
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Solicita un numero flotante al usuario, lo verifica y devuelve el resultado
 *
 * \param pResultado: puntero a donde se carga el resultado
 * \param mensaje: texto que pide ingreso de numero
 * \param mensajeError: texto de error
 * \param minimo: minimo valor
 * \param maximo: maximo valor
 * \param reintentos: cant. de reintentos para el ingreso
 * \return
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief Solicita un caracter al usuario, la verifica y devuelve el resultado
 *
 * \param pResultado: puntero a donde se carga el resultado
 * \param mensaje: texto que pide ingreso de caracter
 * \param mensajeError: texto de error
 * \param minimo: minimo caracter valido
 * \param maximo: maximo caracter valido
 * \param reintentos: cant. de reintentos para el ingreso
 * \return
 */
int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/**
 * \brief Solicita una cadena al usuario, lo verifica y devuelve el resultado
 *
 * \param pResultado: puntero a donde se carga el resultado
 * \param mensaje: texto que pide ingreso de caracter
 * \param mensajeError: texto de error
 * \param minimo: minimo cantidad de caracteres validos
 * \param maximo: maxima cantidad de caracteres (tama�o del vector)
 * \param reintentos: cant. de reintentos para el ingreso
 * \return
 */
int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Calcula el mayor de dos enteros
 *
 * \param pResultado puntero a donde se carga el resultado
 * \param num1 primer numero entero a comparar
 * \param num2 segundo numero entero a comparar
 * \return retorna 0 si son iguales, 1 si encontro un mayor y -1 si hubo un error
 */
int calcularMayor (int *pResultado, int num1, int num2);

/**
 * \brief Calcula el menor de dos enteros
 *
 * \param pResultado puntero a donde se carga el resultado
 * \param num1 primer numero entero a comparar
 * \param num2 segundo numero entero a comparar
 * \return retorna 0 si son iguales, 1 si encontro un mayor y -1 si hubo un error
 */
int calcularMenor (int *pResultado, int num1, int num2);

/** \brief valida que los datos ingresdaos por el ususario sean caracteres
 *
 * \param letras[] char cadena de caracteres
 * \return int devuelve 1 si todos los datos en la cadena con caracteres
 *
 */
int validarLetras(char letras[]);
/** \brief permite el ingreso de cadenas de caracteres al usuario
 *
 * \param cadena[] char cadena de caraceteres
 * \param tam int tama�o de la cadena de caracteres
 * \param mensaje[] char mensaje con el nombred el dato q se pedira ingresar al usuario
 * \return int devuelve 1 si pudo pedir y cargar los datos en el sistema
 *
 */
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);
/** \brief permite al usuario confirmar la salida del programa
 *
 * \param x char* direccion de memoria de char para confirmar salida
 * \return void
 *
 */
void confirmarSalida(char* x);

#endif // UTN_LIB_H_INCLUDED
