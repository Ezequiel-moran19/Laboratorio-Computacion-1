
#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INCLUDE LIBRARY TO TEST
#include "../../inc/LinkedList.h"


void newTestSetup(void)
{
	utest_print("Setup...\r\n");

}

void newTestCase01(void)
{
    LinkedList* lista = ll_newLinkedList();
    utest_assertNotNullMsg(lista,"\nExiste un error. El valor de retorno no puede ser NULL\n");
}



