#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

typedef struct{
    int idAerolineas;
	char descripcion[30];
}eAerolineas;

#endif // AEROLINEA_H_INCLUDED

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param aerolineas[] eAerolineas array de estructuras de aerolineas
 * \param tamA int taamaño del array de aerolineas
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionAerolineas(eAerolineas aerolineas[], int tamA, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de aerolineas
 *
 * \param aerolineas[] eAerolineas array de estructuras de aerolineas
 * \param tamA int taamaño del array de aerolineas
 * \return int devuelve 1 si pudo listar los rubross
 *
 */
int listarAerolineas(eAerolineas aerolineas[], int tamA);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de tipos
 *
 * \param aerolineas[] eAerolineas array de estructuras de aerolineas
 * \param tamA int taamaño del array de aerolineas
 * \param id int id ingresado
 * \param pIndice int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarAerolineas(eAerolineas aerolineas[], int tamA, int id, int* pIndice);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param aerolineas[] eAerolineas array de estructuras de aerolineas
 * \param tamA int taamaño del array de aerolineas
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarAerolineas(eAerolineas aerolineas[], int tamA, int id);
