
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
    int isEmpty;
}eConfederacion;


#endif /* CONFEDERACION_H_ */

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarConfederacion(eConfederacion confederaciones[], int tamC, int id, char desc[]);

/** \brief imprime en pantalla en forma de tabla las estructuras de confederaciones
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo listar las confederaciones
 *
 */
int listarConfederaciones(eConfederacion confederaciones[], int tamC);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int buscarConfederadion(eConfederacion confederaciones[], int tamC, int id, int* pIndice);


/** \brief coloca todos los campos isEmpty del vector de confederacion en 1
 *
 * \param confederacion[] eConfederacion vector de estructuras de jugadores
 * \param tamC int tamaño del vector de jugadores
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarConfederacion(eConfederacion confederacion[], int tamC);

/** \brief busca la primer estructura del array de condeferacion q este vacia
 *
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibre(eConfederacion confederaciones[], int tamC, int* pIndice);

void mostrarConfederacion(eConfederacion confederaciones);

/** \brief permite el ingreso de datos para dar de alta de un confederaciones en el sistema
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de jugadores vacia
 *
 */
int altaConfederacion(eConfederacion confederaciones[], int tamC,int* pProxId);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajafederacion(eConfederacion confederaciones[], int tamC);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarfederacion(eConfederacion confederaciones[], int tamC);


