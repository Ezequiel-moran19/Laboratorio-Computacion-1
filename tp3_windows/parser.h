
#ifndef PARSER_H_
#define PARSER_H_


#endif /* PARSER_H_ */


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
