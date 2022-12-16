#include "UTN_lib.h"
#include "aerolinea.h"
#include "tipo.h"
#include "vuelo.h"
#include "avion.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief imprime en pantalla el menu de opciones de informes y permite al usuario ingresar una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformes();

/** \brief esta funcion realiza el llamado a las demas funciones cuando son solicitadas segun la opcion ingresada por el usuario en el menu
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \return int devuelve 1 al terminar de ejecutarse correctamente
 *
 */
int informes(eAvion aviones[],int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT);

/** \brief esta funcion muestra los Aviones des una Aerolinea que ingresa el usuario
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \return int devuelve 1 si se muestra
 *
 */
int mostrarAvionesDeAerolinea(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT);

/** \brief esta funcion muestra los Aviones des un Tipo que ingresa el usuario
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamanio del array de tipos
 * \return int devuelve 1 si se muestra
 *
 */
int mostrarAvionesTipos(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT);

/** \brief calcula el promedio de los Aviones de las Aerolinea cargadas en el sistema
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \return int retorna 1 si pudo calcular el promedio
 *
 */
int promedioAvionesJet(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA);

/** \brief muestra un listado de los aviones separados por aerolínea
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarAvionesPorAerolinea(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT);

/** \brief Informa la o las aerolíneas que pueden transportar mas pasajeros
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \return int devuelve 1 si pudo encontrala con exito
 *
 */
int aerolineasMasPasajeros(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[], int tamT);

/** \brief Muestra la aerolínea con menor cantidad de aviones
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \return int devuelve 1 si pudo encontrarlas con exito
 *
 */
int aerolineaMenorCantidadAviones(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA);


#endif // INFORMES_H_INCLUDED
