#include "tipo.h"
#include "aerolinea.h"

#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

typedef struct{
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
    int isEmpty;
}eAvion;

#endif // AVION_H_INCLUDED
/** \brief imprime en pantalla el menu con las opciones y permite al usuario el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuPrincipal();

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *  \param aviones eAvion vector de estructuras de aviones
 *  \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 *  \param tamA int tamaño del vector de aerolineas
 *  \param tipos[] eTipo vector de estructuras de tipos
 *  \param tamT int tamaño del vector de tipos
 *  \param EL array de estructura
 *
*/
void mostrarAvion(eAvion aviones, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT);

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *  \param aviones eAvion vector de estructuras de aviones
 *  \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 *  \param tamA int tamaño del vector de aerolineas
 *  \param tipos[] eTipo vector de estructuras de tipos
 *  \param tamT int tamaño del vector de tipos
 *  \param EL array de estructura
 *
*/
void mostrarAvionesFila(eAvion aviones, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT);

/** \brief coloca todos los campos isEmpty del vector de aviones en 1
 *
 * \param aviones eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarAvion(eAvion aviones[], int tamAvion);

/** \brief busca la primer estructura del array de aviones q este vacia
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibre(eAvion aviones[], int tamAvion, int* pIndex);

/** \brief recibe un id y busca en q posicion del vector de aviones se encuentra
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarAvion(eAvion aviones[], int tamAvion, int id, int* pIndex);

int ordenarAvioneId(eAvion aviones[], int tamAvion);

/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de aviones
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
int listarAviones(eAvion aviones[], int tamAvion, eAerolineas aerolineas[], int tamA, eTipo tipos[],int tamT);

/** \brief perimte realizar un alta forzada de datos en el array de aviones
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param cant int cantidad de motos q se desean dar de alta
 * \param pNextId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1 si pudo realizar las altas solicitadas
 *
 */
int hardcodearAviones(eAvion aviones[], int tamAvion, int cant, int* pId);

/** \brief permite el ingreso de datos para dar de alta de un aviones en el sistema
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de aviones vacia
 *
 */
int altaAavio(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT, int* pProxId);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajaAvion(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param aerolineas[] eAerolineas vector de estructuras de aerolineas
 * \param tamA int tamaño del vector de aerolineas
 * \param tipos[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarAvion(eAvion aviones[], int tamAvion, eAerolineas aerolineas[],int tamA, eTipo tipos[],int tamT);

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuModificacion();

/** \brief recibe un id y valida si es un id presente en el vector de aviones
 *
 * \param aviones[] eAvion vector de estructuras de aviones
 * \param tamAvion int tamaño del vector de aviones
 * \param id int id ingresado por el usuario
 * \return int devuelve 1 si es valido, -1 si es invalido
 *
 */
int validarAviones(eAvion aviones[], int tamAvion, int id);

