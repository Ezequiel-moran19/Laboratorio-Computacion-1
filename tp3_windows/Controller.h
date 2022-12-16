/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, int* nextId);

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador);

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador);

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador);


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/** \brief Listar selecciones
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);


/** \brief Ordenar selecciones
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief Listar Convocados
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarConvocados(LinkedList* pArrayListJugador);

/** \brief Listar general
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayLisSeleccion LinkedList*
 * \return int
 *
 */
int controller_Listados(LinkedList* pArrayListJugador,LinkedList* pArrayLisSeleccion);


/** \brief Ordenar ambas estructuras
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarAmbasEstructuras(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/** \brief Listar selecciones disponibles para convocar
 *
 * \param pArrayLisSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSeleccionesDisponiblesAConvocar(LinkedList* pArrayListSeleccion);

/** \brief Convocar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_convocarJugadores (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);


/** \brief Quitar jugadores convocados
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_quitarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Funcion que contiene un menu con las opciones convocar y quitar
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_convocar_quitar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Genera un archivo binario
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_generarArchivoBinario(char *path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char *confe);

/** \brief Carga la lista de convocados en un archivo binario
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarYListarArchivoBinario(char *path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, char *confe);
