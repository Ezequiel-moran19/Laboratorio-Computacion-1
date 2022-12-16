#include "UTN_lib.h"
#include "rubro.h"
#include "articulo.h"
#include "venta.h"
#include "fecha.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuInformes();

/** \brief muestra un menu con los informes requeridos
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \return int retorna 1 si pudo realizar los llamados
 *
 */
void informes(eArticulo articulos[],int tamA,eVenta ventas[],int tamV, eRubro rubros[],int tamR);

/** \brief Muestra los articulos de un rubro ingresados por el usuarios
 *
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \return int retorna 1 si pudo realizar los llamados
 *
 */
int mostrarArtRubro(eArticulo articulos[], int tamA, eRubro rubros[],int tamR);

/** \brief perimte al usuario ingresar una fecha y muestra todos las ventas que se hicieron en esa fecha
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \return int retorna 1 si pudo mostrar las ventas por fecha
 *
 */
int mostrarVentasFechas(eVenta ventas[], int tamV, eArticulo articulos[],int tamA);

/** \brief muestra el importe total de la suma de los importes de cada venta realizada por un id de Articulo
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \return int devuelve 1 si pudo calcular e informar el total
 *
 */
int totalImportesVentas(eVenta ventas[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR);

/** \brief muestra el importe total de la suma de los importes de cada venta realizada por un id de rubro en una fecha seleccionada
 *
 * \param ventas[] eVenta vector de estructuras de ventas
 * \param tamV int tamaño del vector de ventas
 * \param articulos[] eArticulo vector de estructuras de articulos
 * \param tamA int tamaño del vector de articulos
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \return int devuelve 1 si pudo calcular e informar el total
 *
 */
int totalImportesVentasRubro(eVenta ventas[], int tamV, eArticulo articulos[], int tamA, eRubro rubros[], int tamR);

#endif // INFORMES_H_INCLUDED

