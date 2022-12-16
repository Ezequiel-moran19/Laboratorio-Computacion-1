#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief Carga las post desde el archivo post.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayList);

/** \brief Guarda los datos de las (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_guardarPostModoTexto(char* path, LinkedList* pArrayList);

/** \brief Listar posteos
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_imprimirLista(LinkedList* pArrayList);

/** \brief Asigna Estadisticas de likes de manera random
 *
 * \param post void*
 * \return 1 si pudo realizar la asignacion
 */
void* asignarEstadisticaLikes(void* post);

/** \brief Asigna Estadisticas de Dislikes de manera random
 *
 * \param post void*
 * \return 1 si pudo realizar la asignacion
 */
void* asignarEstadisticaDislikes(void* post);

/** \brief Asigna Estadisticas de flollowers de manera random
 *
 * \param post void*
 * \return 1 si pudo realizar la asignacion
 */
void* asignarEstadisticaFlollwers(void* post);

int controller_map(LinkedList* pArrayList);
int controller_filtrarPorLikes(LinkedList* pArrayList);
int controller_filtrarPorHeaters(LinkedList* pArrayList);
int compararFollow(void* a,void* b);
int controller_ordenarPost(LinkedList* pArrayList);
int controller_mostrarMasPopular(LinkedList* pArrayList);

#endif // CONTROLLER_H_INCLUDED
