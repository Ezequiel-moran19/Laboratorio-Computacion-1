#include "jugador.h"
#include "confederacion.h"
#include "menu.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/** \brief imprime en pantalla el menu de opciones de informes y permite al usuario ingresar una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformes();

/** \brief esta funcion realiza el llamado a las demas funciones cuando son solicitadas segun la opcion ingresada por el usuario en el menu
 *
 * \param Jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 al terminar de ejecutarse correctamente
 *
 */
int informes(eJugador jugadores[], int tamJ, eConfederacion confederaciones[],int tamC);

/** \brief Listade los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo encontrarlas con exito
 *
 */
int ordenarPorNombre(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/** \brief Muestra en forma de tabla las estructuras q no estan vacias del vector de jugadores
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarJugadores(eJugador jugadores[], int tamJ, eConfederacion confe[], int tamC);

/** \brief Muestra en forma de tabla las estructuras q no estan vacias del vector de confederaciones y sus jugadores
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listaConfederacionesJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[],int tamC);

/** \brief Acumula de los Salarios de los jugadores cargadas en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pSumaSalarios  Puntero a Float.
 * \param *cantidad  Puntero a entero.
 * \return int retorna 1 si pudo calcular el promedio
 *
 */
int sumaSalariosJugadores(eJugador jugadores[], int tamJ, float* pSumaSalarios, int* cantidad);

/** \brief Calcula el promedio de los Salarios de los jugadores cargadas en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pPromedio  Puntero a entero.
 * \return int retorna 1 si pudo calcular el promedio
 *
 */
int promedioSalarios(eJugador jugadores[], int tamJ, float* pPromedio);

/** \brief Recorre el vector de Jugador y cuenta los jugadores que se encuentran por encima del salario promedio
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \return int retorna 1 si pudo calcular el promedio
 *
 */
int cantidadJugadoresSalariosEncimaPromedio(eJugador jugadores[], int tamJ, int* pCantidad);

/** \brief Muestra el total, promedio y el que esta por encima del promedio de los Salarios de los jugadores cargadas en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \return int retorna 1 si pudo mostrar
 *
 */
int infoTotalSalarioJugadores( eJugador jugadores[], int tamJ);

/** \brief acumula de los Anios de contratos de los jugadores cargadas en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pSumaSalarios  Puntero a Float.
 * \param *cantidad  Puntero a entero.
 * \return int retorna 1 si pudo acumular
 *
 */
int acumuladorAniosDeContrato(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumulador[]);

/** \brief Calcula confederacion con mas anios de contrato de jugadores.
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pMaximo  Puntero a entero.
 * \param Array de enteros para acumular los contratos.
 * \return int retorna 1 si pudo encontrar en mayor contrato
 *
 */
int calcularMayorContrato(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int *pMaximo, int acumulador[]);

/** \brief Informa la confederacion con mas anios de contrato de jugadores cargados en el sistema.
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pPromedio  Puntero a entero.
 * \return int retorna 1 si mostrar los anio del contrato
 *
 */
void infoConfederacionMayorCantidadContratos(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/** \brief Recorre el vector de Jugador y cuenta los jugadores que se encuentran cargados
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param *pContador puntero a entero
 * \return int retorna 1 si pudo contar
 *
 */
int contadorJugadores(eJugador jugadores[], int tamJ, int *pContador);

/** \brief acumula de los Anios de contratos de los jugadores cargadas en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param Array de enteros para acumular jugadores por confederacion.
 * \return int retorna 1 si pudo acumular
 *
 */
int acumuladorJugadoresPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumulador[]);

/** \brief Calacula el porcentaje de los jugadores por confederaciones
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param porcentaje array de flotantes para acumular el porcentaje.
 * \param Array de enteros para acumular jugadores por confederacion.
 * \return int retorna 1 si pudo calcular el porcentaje
 *
 */
int calculatePorcentajeDeJugadoresPorConfederation(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, float porcentaje[], int acumuladorConfe[]);

/** \brief Informa el porcentaje de jugadores por confederacion cargados en el sistema.
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int retorna 1 si mostrar los porcentajes
 *
 */
void infoPorcentajeJugadoresPorConfederacion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/** \brief Calacula el maximo de los jugadores por region
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param Array de enteros para acumular jugadores por confederacion.
 * \param *pJugadorPorConfe puntero a entero
 * \return int retorna 1 si pudo calcular el porcentaje
 *
 */
int calcularMaximoDeJugadoresPorRegion(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC, int acumuladorConfe[], int *pJugadorPorConfe);

/** \brief Informa la region con mas jugadores por cargados en el sistema y los lista.
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int retorna 1 si mostrar las regiones
 *
 */
void infoRegionMasJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);


#endif /* INFORMES_H_ */
