#include "fecha.h"
#include "articulo.h"
#include "rubro.h"

#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct{
  int idVenta;
  int articuloId;
  int cantidad;
  float precioTotal;
  eFecha fecha;
  int isEmpty;
}eVenta;

#endif // VENTA_H_INCLUDED

/** \brief coloca todos los campos isEmpty del vector de ventas en 1
 *
 * \param venta eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarVenta(eVenta venta[], int tamV);

/** \brief busca la primer estructura del array de ventas q este vacias
 *
 * \param venta[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de venta
 * \param pId int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibreVenta(eVenta venta[], int tamV, int* pId);

/** \brief permite el ingreso de datos para dar de alta de un ventas en el sistema
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param eArticulo[] eRubro vector de estructuras de rubros
 * \param tamA int tamaño del vector de Articulos
 * \param rubros[] eRubro vector de estructuras de rubros
 * \param tamR int tamaño del vector de Rubros
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de ventas vacia
 *
 */
int altaVenta(eVenta venta[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR, int* pProxId);

/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de ventas
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param articulos[] eArticulo vector de estructuras de rubros
 * \param tamA int tamaño del vector de Articulos
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarVentas(eVenta venta[], int tamV, eArticulo articulos[], int tamA);

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param articulos[] eArticulo array de estructuras de Articulos
 * \param tamA int taamaño del array de Articulos
 * \param idA int idA a buscar
 * \param descArticulo[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarArticulo(char descArticulo[],eArticulo articulos[],int tamA,int idA);

/**
 *  \brief Imprime los dalos que se cargan en la estructura en filas
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param articulos[] eArticulo array de estructuras de Articulos
 * \param tamA int taamaño del array de Articulos
 * \param EL array de estructura
 *
*/
void mostrarVentasFila(eVenta venta, eArticulo articulos[], int tamA);

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param articulos[] eArticulo array de estructuras de Articulos
 * \param tamA int taamaño del array de Articulos
 * \param EL array de estructura
 *
*/
void mostrarVentas(eVenta venta, eArticulo articulos[], int tamA);

/** \brief perimte realizar un alta forzada de datos en el array de Ventas
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param cant int cantidad de motos q se desean dar de alta
 * \param pId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1 si pudo realizar las altas solicitadas
 *
 */
int hardcodearVentas(eVenta venta[], int tamV, int cant, int* pId);

