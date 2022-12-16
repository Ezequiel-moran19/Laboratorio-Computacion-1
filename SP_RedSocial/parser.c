#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
    int ok = 0;
    char id[100];
	char user[100];
	char likes[100];
	char dislikes[100];
	char followers[100];
	char falsaLectura[1000];
	ePost* pPost;

	fscanf(pFile, "%s", falsaLectura);
	while(!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, user, likes, dislikes, followers);

		pPost = new_Param(id, user, likes, dislikes, followers);

		if(pPost == NULL)
		{
			printf("falló la carga del id: %s\n", id);
		}
		ll_add(pArrayList, pPost);
		ok = 1;
	}
	printf("\n Guardado!!!\n");
    return ok;
}
