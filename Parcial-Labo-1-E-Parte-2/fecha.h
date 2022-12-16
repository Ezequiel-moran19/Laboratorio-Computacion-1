#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#endif // FECHA_H_INCLUDED

/** \brief valida si el anio ingresado es valido dentro de un rango
 *
 * \param anio int
 * \return int retorna 1 si es valido
 *
 */
int validoAnio(int anio);

/** \brief valida si un a�o ingresado corresponde a a�o bisiesto
 *
 * \param anio int
 * \return int retorna 1 si el a�o es valido, 2 si es bisiesto, 0 si es invalido
 *
 */
int validoAnioBisiesto(int anio);

/** \brief valida si el numero ingresado como mes es valido
 *
 * \param mes int
 * \return int retorna 1 si es valido
 *
 */
int validoMes(int mes);

/** \brief valida si el numero ingresado como dia es valido en el rango de 1 a 31
 *
 * \param int dia
 * \return retorna 1 si es valido
 *
 */
int validoDia(int dia);

/** \brief valida si el numero ingresado en dia y mes concuerdan segun la cantidad de dias q tiene cada mes
 *
 * \param mes int
 * \param dia int
 * \param anio int
 * \return int devuelve 1 cuando todo es valido
 *
 */
int validoDiaMes(int mes, int dia, int anio);

/** \brief pide al usuario el ingreso de una fecha y la valida
 *
 * \param fecha eFecha* puntero a una estructura de fecha donde guardar los datos ingresados por el usuario
 * \return int devuelve 1 si la fecha es valida y se puede cargar en una estructura de fecha
 *
 */
int pidoValidoFecha(eFecha* fecha);
