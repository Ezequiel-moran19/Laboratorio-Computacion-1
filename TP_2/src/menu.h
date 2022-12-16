
#ifndef MENU_H_
#define MENU_H_

/** \brief imprime en pantalla el menu de opciones de informes y permite al usuario ingresar una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuPrincipal();

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuModificacion();

/** \brief muestra las opciones del menu Informesy permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuInformes();

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuModificacionConfe();

int banderaAlta(int* pFlag);

int banderaInformes(int* pFlagA, int* pFlagI);

#endif /* MENU_H_ */
