#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct{
    int idDestino;
	char descripcion[25];
	float precio;
}eDestino;

#endif // DESTINO_H_INCLUDED

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param destinos[] eDestino array de estructuras de destinos
 * \param tamT int taamaño del array de destinos
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionDestino(eDestino destinos[], int tamD, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de destinos
 *
 * \param destinos[] eDestino array de estructuras de destinos
 * \param tamT int taamaño del array de destinos
 * \return int devuelve 1 si pudo listar los destinos
 *
 */
int listarDestinos(eDestino destinos[], int tamD);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de tipos
 *
 * \param destinos[] eDestino array de estructuras de destinos
 * \param tamT int taamaño del array de destinos
 * \param id int id ingresado
 * \param pIndice int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarDestinos(eDestino destinos[], int tamD, int id, int* pIndice);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param destinos[] eDestino array de estructuras de destinos
 * \param tamT int taamaño del array de destinos
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarDestinos(eDestino destinos[], int tamD, int id);
