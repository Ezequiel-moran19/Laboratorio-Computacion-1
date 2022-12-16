
#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST

#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void deleteLinkedListTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void deleteLinkedListTestCase01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_deleteLinkedList(list);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <deleteLinkedList> si los parametros son correctos es 0\n");
}


void deleteLinkedListTestCase02(void)
{
    int r;
    r = ll_deleteLinkedList(NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <deleteLinkedList> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}




