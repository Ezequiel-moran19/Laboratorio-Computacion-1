

#ifndef RUBRO_H_INCLUDED
#define RUBRO_H_INCLUDED

typedef struct{
    int idRubro;
	char descripcion[30];
}eRubro;

#endif // RUBRO_H_INCLUDED


 /** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param vecRubro[] eRubro array de estructuras de rubro
 * \param tamR int taamaño del array de rubro
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionRubro(eRubro vecRubro[], int tamR, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de rubro
 *
 * \param vecRubro[] eRubro array de estructuras de rubro
 * \param tamR int taamaño del array de rubro
 * \return int devuelve 1 si pudo listar los rubros
 *
 */
int listarRubros(eRubro vecRubro[], int tamR);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de rubro
 *
 * \param vecRubro[] eRubro array de estructuras de rubro
 * \param tamR int taamaño del array de rubro
 * \param id int id ingresado
 * \param pIndice int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarRubros(eRubro vecRubro[], int tamR, int id, int* pIndice);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param vecRubro[] eRubro array de estructuras de rubro
 * \param tamR int taamaño del array de rubro
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarRubros(eRubro vecRubro[], int tamR, int id);
