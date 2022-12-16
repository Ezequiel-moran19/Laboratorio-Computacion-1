
#include "rubro.h"

#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

typedef struct{
	int idArticulo;
	char descripcion[30];
	float medida;
	float precio;
	int rubroId;
    int isEmpty;
}eArticulo;

#endif // ARTICULO_H_INCLUDED

/** \brief imprime en pantalla el menu con las opciones y permite al usuario el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuPrincipal();

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *  \param EL array de estructura
 *
*/
void mostrarAtirculos(eArticulo art, eRubro vecR[],int tamR);

/**
 *  \brief Imprime los dalos que se cargan en la estructura en filas
 *  \param EL array de estructura
 *
*/
void mostrarArticulosFila(eArticulo art, eRubro vecR[],int tamR);

/** \brief coloca todos los campos isEmpty del vector de articulo en 1
 *
 * \param vecA eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarArticulos(eArticulo articulos[], int tamA);

/** \brief busca la primer estructura del array de articulo q este vacia
 *
 * \param articulos[] eArticulo vector de estructuras de Articulo
 * \param tamA int tamaño del vector de Articulo
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibre(eArticulo articulos[], int tamA, int* pIndex);

/** \brief recibe un id y busca en q posicion del vector de Articulo se encuentra
 *
 * \param vecA[] eArticulo vector de estructuras de Articulo
 * \param tamA int tamaño del vector de Articulo
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarArticulo(eArticulo articulos[], int tamA, int id, int* pIndex);

/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de articulo
 *
 * \param articulos[] eArticulo vector de estructuras de Articulo
 * \param tamA int tamaño del vector de Articulo
 * \param vecR[] eRubro vector de estructuras de rubros
 * \param tamR int tamaño del vector de Rubros
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarArticulos(eArticulo articulos[], int tamA , eRubro rubros[], int tamR);

int ordenarRubroDescripcion(eArticulo articulos[], int tamA);

/** \brief perimte realizar un alta forzada de datos en el array de articulos
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param cant int cantidad de motos q se desean dar de alta
 * \param pNextId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1 si pudo realizar las altas solicitadas
 *
 */
int hardcodearAticulos(eArticulo articulos[], int tamA, int cant, int* pId);

/** \brief recibe un id y valida si es un id presente en el vector de articulos
 *
 * \param articulos[] eArticulo vector de estructuras de Articulos
 * \param tamA int tamaño del vector de Articulos
 * \param id int id ingresado por el usuario
 * \return int devuelve 1 si es valido, -1 si es invalido
 *
 */
int validarArticulo(eArticulo articulos[], int tamA, int id);

/** \brief permite el ingreso de datos para dar de alta de un Articulo en el sistema
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param rubros[] eRubro vector de estructuras de rubros
 * \param tamR int tamaño del vector de Rubros
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de articulos vacia
 *
 */
int altaArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR, int* pProxId);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulo
 * \param rubros[] eRubro vector de estructuras de rubros
 * \param tamR int tamaño del vector de Rubros
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajaArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param rubros[] eRubro vector de estructuras de rubros
 * \param tamR int tamaño del vector de Rubros
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarArticulos(eArticulo articulos[], int tamA, eRubro rubros[], int tamR);

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */

int menuModificacion();



