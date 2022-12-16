
#ifndef CALCULOS_H_
#define CALCULOS_H_

 /**
    * \brief realiza una division
    * \return retorna el valor
    *
    */
int division(float* pResultado, int operador1, int operador2);

/**
 * \brief calcula la suma de todos los costos
 *
 * \param pN1 puntero a donde se carga el el numero
 * \param pN2 puntero a donde se carga el el numero
 * \param pN3 puntero a donde se carga el el numero
 */
float calcularCostos(float* pN1, float* pN2, float* pN3);

/** \brief permite al usuario cargar datos y cambia su valor inicial de la bandera al ingresar correctamente.
 *
 * \param pFlag int* puntero a entero
 * \return int retornaok = 1 si los datos fueron cargados.
 *
 */
int banderaMantenimiento(int* pFlag);

/** \brief permite al usuario cargar datos y cambia su valor inicial de la bandera al ingresar correctamente.
 *
 * \param pFlag int* puntero a entero
 * \param pFlag int* puntero a entero
 * \return int retornaok = 1 si los datos fueron cargados.
 *
 */
int banderaJugador(int* pFlagMantenimiento, int* pFlagJugador);

/** \brief permite al usuario cargar datos y cambia su valor inicial de la bandera al ingresar correctamente.
 *
 * \param pFlagM int* puntero a entero.
 * \param pFlagJ int* puntero a entero.
 * \param pFlagC int* puntero a entero.
 * \return int retorna ok = 1 si los datos fueron cargados correctamente.
 *
 */
int banderaCalcular( int* pFlagM, int* pFlagJ, int* pFlagC);

#endif /* CALCULOS_H_ */
