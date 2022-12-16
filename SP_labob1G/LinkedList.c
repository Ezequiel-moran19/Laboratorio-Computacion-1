#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
       {
          this->size = 0;
          this->pFirstNode = NULL;
       }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
        nodo = this->pFirstNode;

        while(nodeIndex > 0)
        {
        	nodo = nodo->pNextNode;
        	nodeIndex--;
        }
	}
    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* nodoDelantero = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
	   nuevoNodo = (Node*) malloc(sizeof(Node));
	   if(nuevoNodo != NULL)
	   {
		   nuevoNodo->pElement = pElement;

		  if(nodeIndex == 0)
		  {
			  nuevoNodo->pNextNode = this->pFirstNode;
			  this->pFirstNode = nuevoNodo;
		  }
		  else
		  {
			  nodoDelantero = getNode(this, nodeIndex -1);
			  nuevoNodo->pNextNode = nodoDelantero->pNextNode;
			  nodoDelantero->pNextNode = nuevoNodo;
		  }
		  this->size++;
		  returnAux = 0;
	   }
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    return  addNode(this, ll_len(this), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
   	{
    	returnAux = getNode(this, index)->pElement;
   	}
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(index >= 0 && index < ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodo = NULL;
    Node* nodoAdelante = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
	{
    	if(index == 0)
    	{
		     nodo = this->pFirstNode;
	 	     this->pFirstNode = nodo->pNextNode;
		}
	    else
	    {
	    	nodoAdelante = getNode(this, index -1);
	    	nodo = nodoAdelante->pNextNode;
	    	nodoAdelante->pNextNode = nodo->pNextNode;
	    }
    	free(nodo);
    	this->size--;
    	returnAux = 0;
	}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	while(this->pFirstNode != NULL)
    	{
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
       if(!ll_clear(this))
       {
           free(this);
           returnAux = 0;
       }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        int tam = ll_len(this);
        for(int i=0; i<tam; i++)
        {
            if(pElement == ll_get(this, i) )
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 1;
        if( ll_len(this) )
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    returnAux = addNode(this, index, pElement);
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this, index);
    ll_remove(this, index);

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) >= 0 )
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElemento = NULL;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;

        int tam = ll_len(this2);

        for(int i=0; i<tam; i++)
        {
            auxElemento = ll_get(this2, i);
            if( !ll_contains(this, auxElemento) )
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from >= 0 && to <= ll_len(this) && to > from)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {

            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i) );   // ll_get() me devuelve el elemento de la lista en la posicion i, para usarlo en la funcion ll_add
            }
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
	int estaOrdenado;
	int len;
	void *auxElement = NULL;
	void *auxElementDos = NULL;
	int retornoPFunc;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		len = ll_len(this);
		do
		{
			estaOrdenado = 1;
			len--;
			for (int i = 0; i < len; i++)
			{
				auxElement = ll_get(this, i);
				auxElementDos = ll_get(this, i + 1);
				retornoPFunc = pFunc(auxElement, auxElementDos);
				if ((retornoPFunc > 0 && order == 1) || (retornoPFunc > 0 && order == 0))
				{
					ll_set(this, i, auxElementDos);
					ll_set(this, i + 1, auxElement);
					estaOrdenado = 0;
				}
			}

		} while (estaOrdenado == 0);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista Filtrada) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* filterList = NULL;
    void* elemento = NULL;
    int tam;

    if(this != NULL && pFunc != NULL)
    {
        filterList = ll_newLinkedList();

        if(filterList != NULL)
        {
            tam = ll_len(this);

            for(int i=0; i<tam; i++)
            {
                elemento = ll_get(this, i);

                if( pFunc(elemento) )
                {
                    ll_add(filterList, elemento);
                }
            }
        }
    }

    return filterList;
}


LinkedList* ll_map(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* mapList = NULL;
    void* elemento = NULL;
    int tam;

    if(this != NULL && pFunc != NULL)
    {
        mapList = ll_newLinkedList();

        if(mapList != NULL)
        {
            tam = ll_len(this);

            for(int i=0; i<tam; i++)
            {
                elemento = ll_get(this, i);
                if( pFunc(elemento) )
                {
                    ll_add(mapList, elemento);
                }
            }
        }
    }
    return mapList;
}

/// @brief ll_count		CUENTA ELEMENTOS DE LA LISTA SEGUN FUNCION CRITERIO.
///
/// @param this			PUNTERO TIPO LINKEDLIST.
/// @param pFunc	    PUNTERO FUNCION CRITERIO.
/// @return				RETORNA 0 SINO CONTO NADA.
/// 					RETORNA CONTADOR/ACUMULADOR DE ELEMENTOS CONTADOS.
int ll_count(LinkedList *this, int (*pFunc)(void*))
{
	int returnLl_count = 0;
	int lenList;
	void *auxElement;
	if (this != NULL && pFunc != NULL)
	{
		lenList = ll_len(this);  //INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1
		if (lenList > 0)
		{
			for (int i = 0; i < lenList; i++)
			{
				auxElement = ll_get(this, i);

				if (auxElement != NULL)
				{
					returnLl_count += pFunc(auxElement);
				}
			}
		}
	}
	return returnLl_count;
}
