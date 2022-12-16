#include "fecha.h"
#include "destino.h"
#include "avion.h"
#include "tipo.h"
#include "aerolinea.h"

#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct{
	int idVuelos;
	int idAvion;
	int idDestino;
	eFecha fecha;
    int isEmpty;
}eVuelos;

#endif // VUELO_H_INCLUDED

/** \brief coloca todos los campos isEmpty del vector de vuelos en 1
 *
 * \param vuelos eVuelos vector de estructuras de vuelos
 * \param tamT int tamaño del vector de tipos
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarVuelos(eVuelos vuelos[], int tamVuelos);

/** \brief busca la primer estructura del array de vuelos q este vacia
 *
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param tamVuelos int tamaño del vector de vuelos
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibreVuelos(eVuelos vuelos[], int tamVuelos, int* pId);

/** \brief recibe un id y busca en q posicion del vector de vuelos se encuentra
 *
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param tamVuelos int tamaño del vector de vuelos
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarVuelos(eVuelos vuelos[], int tamVuelos, int id, int* pIndice);

/** \brief permite el ingreso de datos para dar de alta de un vuelos en el sistema
 *
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param tamVuelos int tamaño del vector de vuelos
 * \param destinos[] eDestino vector de estructuras de destino
 * \param tamD int tamaño del vector de destino
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de vuelos vacia
 *
 */
int altaVuelo(eVuelos vuelos[],int tamVuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD,eAerolineas aerolineas[],int tamA ,eTipo tipos[],int tamT, int* pProxId);

/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de vuelos
 *
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param tamVuelos int tamaño del vector de vuelos
 * \param destinos[] eDestino vector de estructuras de destino
 * \param tamD int tamaño del vector de destino
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarVuelos(eVuelos vuelos[],int tamVuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD);


/**
 *  \brief Imprime los dalos que se cargan en la estructura
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param destinos[] eDestino vector de estructuras de destino
 * \param tamD int tamaño del vector de destino
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param EL array de estructura
 *
*/
void mostrarVuelosFila(eVuelos vuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD);

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param destinos[] eDestino vector de estructuras de destino
 * \param tamD int tamaño del vector de destino
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param EL array de estructura
 *
*/
void mostrarVuelos(eVuelos vuelos, eAvion aviones[], int tamAvion, eDestino destinos[],int tamD);

/** \brief perimte realizar un alta forzada de datos en el array de vuelos
 *
 * \param vuelos[] eVuelos vector de estructuras de vuelos
 * \param tamVuelos int tamaño del vector de vuelos
 * \param cant int cantidad de vuelos q se desean dar de alta
 * \param pId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1
 *
 */
int hardcodearVuelos(eVuelos vuelos[], int tamVuelos, int cant, int* pId);
