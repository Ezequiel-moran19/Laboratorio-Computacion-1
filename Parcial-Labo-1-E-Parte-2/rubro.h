
#ifndef RUBRO_H_INCLUDED
#define RUBRO_H_INCLUDED

typedef struct{
    int idRubro;
	char descripcion[30];
}eRubro;

#endif // RUBRO_H_INCLUDED

 /** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionRubro(eRubro rubros[], int tamR, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de rubros
 *
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \return int devuelve 1 si pudo listar los rubross
 *
 */
int listarRubros(eRubro rubros[], int tamR);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de rubros
 *
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \param id int id ingresado
 * \param pIndice int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarRubros(eRubro rubros[], int tamR, int id, int* pIndice);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param rubros[] eRubro array de estructuras de rubros
 * \param tamR int taamaño del array de rubros
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarRubros(eRubro rubros[], int tamR, int id);
