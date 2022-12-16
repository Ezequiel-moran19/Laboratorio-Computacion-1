#ifndef MENU_H_
#define MENU_H_

/** \brief Muestra la barra de menu
 *
 * \param *pHosp  puntero a float del valor a recibir
 * \param *pCom   puntero a float del valor a recibir
 * \param *pTransp  puntero a float del valor a recibir
 * \param *pA  puntero a entero que muestra la cantidad de arquero
 * \param *pD  puntero a entero que muestra la cantidad de defensor
 * \param *pM  puntero a entero que muestra la cantidad de mediocampista
 * \param *pDel puntero a entero que muestra la cantidad de delanteros
 * \return int retorna la opcion ingresada por el usuario.
 *
 */
int menuPrincipal(float* pHosp, float* pCom, float* pTransp, int* pA, int* pD, int* pM, int* pDel);

/** \brief muestra las opciones de Confederaciones y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int subMenuConfederaciones();

/** \brief Carga la opcion de la liga y cuanta las liga.
 *
 * \param *p1  puntero a entero liga AFC
 * \param *p2  puntero a entero liga CAF
 * \param *p3  puntero a entero liga Concacaf
 * \param *p4  puntero a entero liga Conmebol
 * \param *p5  puntero a entero liga Uefa
 * \param *p6  puntero a entero liga Ofc
 * \return ok = 1 si pudo cargar
 *
 */
int cargarLiga(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6);

/** \brief muestra el resultado
 *
 * \param *pL1 puntero a float liga AFC
 * \param *pL2 puntero a float liga CAF
 * \param *pL3 puntero a float liga Concacaf
 * \param *p4 puntero a float liga Conmebol
 * \param *p5 puntero a float liga Uefa
 * \param *p6 puntero a float liga Ofc
 * \return ok = 1 si pudo mostrar
 *
 */
int mostrarPomedios(float* pL1, float* pL2, float* pL3, float* pL4, float* pL5, float* pL6);

/** \brief cambia el estado de las banderas segun el ingreso de datos.
 *
 * \param *pFlagM  puntero a entero.
 * \param *pFlagJ  puntero a entero.
 * \param *pFlagC  puntero a entero.
 * \return int retorna 1 si los datos fueron cargados correctamente.
 *
 */
int informarResultados(int* pFlagM, int* pFlagJ, int* pFlagC);


#endif /* MENU_H_ */
