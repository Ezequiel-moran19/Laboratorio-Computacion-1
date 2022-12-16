#include "confederacion.h"

#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct{
    int id;
    char nombre[50];
    char posicion[50];
    int numeroCamiseta;
    int idConfederacion;
    float salario;
    int aniosContrato;
    int isEmpty;
}eJugador;

#endif /* JUGADOR_H_ */

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *  \param jugadores eJugador vector de estructuras de jugadores
 *  \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 *  \param tamC int tamaño del vector de confederaciones
 *  \param EL array de estructura
 *
*/
void mostrarJugadores(eJugador jugadores, eConfederacion confederaciones[],int tamC);

/**
 *  \brief Imprime los dalos que se cargan en la estructura
 *  \param jugadores eJugador vector de estructuras de jugadores
 *  \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 *  \param tamC int tamaño del vector de confederaciones
 *  \param EL array de estructura
 *
*/
void mostrarJugadoresFila(eJugador jugadores, eConfederacion confederaciones[],int tamC);

/** \brief coloca todos los campos isEmpty del vector de jugadores en 1
 *
 * \param jugadores eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarJugador(eJugador jugadores[], int tamJ);

/** \brief busca la primer estructura del array de jugadores q este vacia
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLugarLibre(eJugador jugadores[], int tamJ, int* pIndex);

/** \brief recibe un id y busca en q posicion del vector de jugadores se encuentra
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarJugador(eJugador jugadores[], int tamJ, int id, int* pIndex);

int hardcodearJugadores(eJugador jugadores[], int tamJ, int cant, int* pId);

/** \brief permite el ingreso de datos para dar de alta de un jugadores en el sistema
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \param pProxId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de jugadores vacia
 *
 */
int altaJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC,int* idx);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajaJugador(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param jugadores[] eJugador vector de estructuras de jugadores
 * \param tamJ int tamaño del vector de jugadores
 * \param confederaciones[] eConfederacion vector de estructuras de confederaciones
 * \param tamC int tamaño del vector de confederaciones
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarJugadores(eJugador jugadores[], int tamJ, eConfederacion confederaciones[], int tamC);



