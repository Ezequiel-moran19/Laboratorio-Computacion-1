#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

int criterio_Descendente(void* pElement1, void* pElement2);
void printLinkedList(LinkedList* Lista);

int main()
{
    setlocale(LC_ALL, "");
	int* element;
	int len;
    printf("     ___________________________________________________________________________________________ \n");
    printf("    |                                                                                           |\n");
    printf("    |                              ***TRABAJO PRACTICO NUMERO 4***                              |\n");
    printf("    |___________________________________________________________________________________________|\n\n");
	printf("\nll_newLinkedlist: Se crea una nueva lista de números.");
	LinkedList* ListaNumeros = ll_newLinkedList();
    printf("\n__________________________________________________________________________________________________________________\n");

	printf("\nll_add: Se agregan los números del 1 al 10.");
	for(int i=1;i<11;i++){
		int* number = (int*) malloc(sizeof(int));
		*number = i;
		ll_add(ListaNumeros, number);
	}
    printf("\n__________________________________________________________________________________________________________________\n");


	len = ll_len(ListaNumeros);
	printf("\nll_len: El tamaño de la lista es %d.", len);
    printf("\n__________________________________________________________________________________________________________________\n");


	printf("\nll_get: Se imprime la lista.\n");
	printf("Lista de Números: ");
	for(int i=0;i<len;i++){
		element = (int*) ll_get(ListaNumeros, i);
		printf("%d ", *element);
	}
    printf("\n__________________________________________________________________________________________________________________\n");


	int* numberAux = (int*) malloc(sizeof(int));
	*numberAux = 20;
	printf("\nll_set: Se reemplaza el elemento en índice 4 (Nro 5) por otro nuevo, de valor 20.");
	ll_set(ListaNumeros, 4, numberAux);
    printf("\n__________________________________________________________________________________________________________________\n");


	printf("\nll_remove: Se remueve el elemento en índice 7 (Nro 8).\n");
	ll_remove(ListaNumeros, 7);
	printf("Reimpresión de la lista con los cambios.\n");
	printf("Lista de Números: ");
	printLinkedList(ListaNumeros);
    printf("\n__________________________________________________________________________________________________________________\n");


	int index = ll_indexOf(ListaNumeros, numberAux);
	printf("\nll_indexOf: Indice del elemento 20 es: %d.", index);
    printf("\n__________________________________________________________________________________________________________________\n");


	printf("\nll_clone: Se realiza una copia de la lista.");
	LinkedList* ListaCopiada = ll_clone(ListaNumeros);
    printf("\n__________________________________________________________________________________________________________________\n");


	printf("\nll_pop: Se elimina el elemento en índice 3 de la lista original.\n");
	printf("ll_push: y se lo inserta en el índice 6 de la lista copiada mediante el método push.\n");
	int* popNumber = ll_pop(ListaNumeros, 3);
	ll_push(ListaCopiada, 6, popNumber);
	printf("Impresión de ambas listas con los cambios:\n");
	printf("Lista de Números: ");
	printLinkedList(ListaNumeros);
	printf("\nCopia de lista de Números: ");
	printLinkedList(ListaCopiada);
    printf("\n__________________________________________________________________________________________________________________\n");


	printf("\nll_contains: ¿La lista original contiene el elemento en índice 3? (nº4)");
    if(ll_contains(ListaNumeros, ll_get(ListaCopiada, 3)))
    {
        printf("\nSí lo contiene.");
    }
    else
    {
        printf("\nNo lo contiene.");
    }

	printf("\n\nll_containsAll: ¿La lista copiada contiene todos los elementos de la lista original?");
    if(ll_containsAll(ListaCopiada, ListaNumeros))
    {
        printf("\nSí los contiene.");
    }
    else
    {
        printf("\nNo los contiene.");
    }
    printf("\n__________________________________________________________________________________________________________________\n\n");

	printf("ll_sublist: Se recorta la lista original desde el índice 4 al 7 (nros 20 6 7 9)\n");
	LinkedList* ListaRecortada = ll_subList(ListaNumeros, 4, 7);
	printf("\nLista Original: ");
	printLinkedList(ListaNumeros);
	printf("\nLista Copiada: ");
	printLinkedList(ListaCopiada);
	printf("\nLista Recortada: ");
	printLinkedList(ListaRecortada);
	printf("\n__________________________________________________________________________________________________________________\n");

	printf("\nll_sort & ll_clear: Se ordena de mayor a menor la lista original, de menor a mayor la copiada y se limpia la lista recortada.");
	ll_sort(ListaNumeros, criterio_Descendente, 1);
	ll_sort(ListaCopiada, criterio_Descendente, 0);
	ll_clear(ListaRecortada);
    printf("\n__________________________________________________________________________________________________________________\n");

	printf("\n**Reimpresión de Listas**\n");
	printf("\nLista Original: ");
	printLinkedList(ListaNumeros);
	printf("\nLista Copiada: ");
	printLinkedList(ListaCopiada);
	printf("\nLista Recortada: ");
	printLinkedList(ListaRecortada);


	printf("\n\nll_isEmpty: \n");
	printf("La Lista Original");
	if(ll_isEmpty(ListaNumeros))
    {
        printf(" está vacía.\n");
    }
    else
    {
        printf(" no está vacía.\n");
    }

	printf("La Lista Copiada");
	if(ll_isEmpty(ListaCopiada))
    {
        printf(" está vacía.\n");
    }
    else
    {
        printf(" no está vacía.\n");
    }

	printf("La Lista Recortada");
    if(ll_isEmpty(ListaRecortada))
    {
        printf(" está vacía.\n");
    }
    else
    {
        printf(" no está vacía.\n");
    }
    printf("__________________________________________________________________________________________________________________\n");

	printf("\nll_deleteLinkedList: Se eliminan las listas creadas durante la demostración.");
	printf("\n__________________________________________________________________________________________________________________\n");
	ll_deleteLinkedList(ListaNumeros);
	ll_deleteLinkedList(ListaRecortada);
	ll_deleteLinkedList(ListaCopiada);
    system("pause");


//	system("cls");
//    startTesting(1);  // ll_newLinkedList
//    startTesting(2);  // ll_len
//    startTesting(3);  // getNode - test_getNode
//    startTesting(4);  // addNode - test_addNode
//    startTesting(5);  // ll_add
//    startTesting(6);  // ll_get
//    startTesting(7);  // ll_set
//    startTesting(8);  // ll_remove
//    startTesting(9);  // ll_clear
//    startTesting(10); // ll_deleteLinkedList
//    startTesting(11); // ll_indexOf
//    startTesting(12); // ll_isEmpty
//    startTesting(13); // ll_push
//    startTesting(14); // ll_pop
//    startTesting(15); // ll_contains
//    startTesting(16); // ll_containsAll
//    startTesting(17); // ll_subList
//    startTesting(18); // ll_clone
//    startTesting(19); // ll_sort

    return 0;
}

int criterio_Descendente(void* pE1, void* pE2){
	int* num1 = (int*) pE1;
	int* num2 = (int*) pE2;
	int ok = 0;
	if(*num1 > *num2)
	{
		ok = 1;
	}
	else if(*num1 < *num2)
	{
		ok = -1;
	}
	return ok;
}

void printLinkedList(LinkedList* Lista)
{
	int len = ll_len(Lista);
	int* number;

	for(int i=0;i<len;i++){
		number = (int*) ll_get(Lista, i);
		printf("%d ", *number);
	}
}


































