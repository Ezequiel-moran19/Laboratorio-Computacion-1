#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int idTipo;
	char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param tipos[] eTipo array de estructuras de tipos
 * \param tamT int taamaño del array de tipos
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tamT, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de tipos
 *
 * \param tipos[] eTipo array de estructuras de tipos
 * \param tamT int taamaño del array de tipos
 * \return int devuelve 1 si pudo listar los tipos
 *
 */
int listarTipos(eTipo tipos[], int tamT);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de tipos
 *
 * \param tipos[] eTipo array de estructuras de tipos
 * \param tamT int taamaño del array de tipos
 * \param id int id ingresado
 * \param pIndice int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarTipos(eTipo tipos[], int tamT, int id, int* pIndice);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param tipos[] eTipo array de estructuras de tipos
 * \param tamT int taamaño del array de tipos
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarTipos(eTipo tipos[], int tamT, int id);
