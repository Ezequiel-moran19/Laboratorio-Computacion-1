
#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

//DEFINES OF THIS TEST
#define LENGTH 5


void lenTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void lenTestCase01(void)
{
    int r;
    LinkedList* list;

    list = ll_newLinkedList();
    list->size = 5;
    r = ll_len(list);
    utest_assertEqualsIntMsg(r,LENGTH,"\nError en el valor de retorno de <len> si los parametros son correctos\n la funcion retorna la cantidad de elementos de la lista\n");

}

void lenTestCase02(void)
{
    int r;
    LinkedList* list;
    list = ll_newLinkedList();
    r = ll_len(list);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <len> si los parametros son correctos \ny la lista esta vacia la funcion retorna 0\n");

}

void lenTestCase03(void)
{
    int r;

    r = ll_len(NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <len> si el puntero a la lista es NULL\n la funcion retorna -1\n");
}
