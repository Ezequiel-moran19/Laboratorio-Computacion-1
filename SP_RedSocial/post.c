#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "UTN_lib.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "post.h"

ePost* new_post()
{
    ePost* nuevoPost = NULL;
	nuevoPost = (ePost*) malloc(sizeof(ePost));

    if(nuevoPost != NULL)
    {
    	nuevoPost->id = 0;
        strcpy(nuevoPost->user, "");
        nuevoPost->likes = 0;
        nuevoPost->dislikes = 0;
        nuevoPost->followers = 0;
    }
    return nuevoPost;
}
ePost* new_Param(char* id,char* user, char* likes,char* dislikes,char* followers)
{
    ePost* nuevoPost;
	nuevoPost = NULL;
	nuevoPost = new_post();

    if(nuevoPost != NULL)
    {
        s_setId(nuevoPost,atoi(id));
        s_setUser(nuevoPost,user);
        s_setLikes(nuevoPost,atoi(likes));
        s_setDislikes(nuevoPost,atoi(dislikes));
        s_setFollowers(nuevoPost,atoi(followers));
    }
    return nuevoPost;
}

void post_delete(ePost* this)
{
    if(this != NULL)
	{
    	free(this);
	}
}
//Setter
int s_setId(ePost* this,int id)
{
    int ok=0;

    if(this !=NULL && id>=0 && id<= 50000)
    {
        this->id=id;
        ok =1;
    }
    return ok;
}

int s_setUser(ePost* this,char* user)
{
    int ok=0;

    if(this != NULL && user!=NULL)
    {
        strcpy(this->user,user);
        ok =1;
    }
    return ok;
}

int s_setLikes(ePost* this,int likes)
{
    int ok=0;

    if(this !=NULL && likes>=0 && likes<= 50000)
    {
        this->likes=likes;
        ok =1;
    }
    return ok;
}

int s_setDislikes(ePost* this,int dislikes)
{
    int ok=0;

    if(this !=NULL && dislikes>=0 && dislikes<= 50000)
    {
        this->dislikes=dislikes;
        ok =1;
    }
    return ok;
}

int s_setFollowers(ePost* this,int followers)
{
    int ok=0;

    if(this !=NULL && followers>=0 && followers<= 50000)
    {
        this->followers=followers;
        ok =1;
    }
    return ok;
}
//Getter
int g_getId(ePost* this,int* id)
{
    int ok = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        ok = 1;
    }
    return ok;
}

int g_getUser(ePost* this,char* user)
{

    int ok = 0;
    if (this != NULL && user != NULL )
    {
        strcpy(user, this->user);
        ok = 1;
    }
    return ok;
}

int g_getLikes(ePost* this,int* likes)
{

    int ok = 0;
    if (this != NULL && likes != NULL)
    {
        *likes = this->likes;
        ok = 1;
    }
    return ok;
}

int g_getDislikes(ePost* this,int* dislikes)
{
    int ok = 0;
    if (this != NULL && dislikes != NULL)
    {
        *dislikes = this->dislikes;
        ok = 1;
    }
    return ok;
}

int g_getFollowers(ePost* this,int* followers)
{

    int ok = 0;
    if (this != NULL && followers != NULL)
    {
        *followers = this->followers;
        ok = 1;
    }
    return ok;

}

void mostrar_Post(ePost* this)
{
    int id;
    char user[50];
    int likes;
    int dislikes;
    int followers;
    if(this != NULL)
    {
        if( g_getId( this, &id )
        &&  g_getUser( this, user )
        &&  g_getLikes( this, &likes)
        &&  g_getDislikes(this, &dislikes)
        &&  g_getFollowers(this,&followers))
        {
            printf ("|   %-7d    %-15s          %-8d                %-6d              %-6d     |\n", id, user, likes, dislikes,followers);
            printf ("|______________________________________________________________________________________________|\n");
        }
    }
}

int filtrar_masCantidadlikes(void* post)
{
    int ok = 0;
    ePost* pPost = NULL;
    if (post != NULL)
    {
        pPost = (ePost*) post;
        if(pPost->likes > 4000)
        {
            printf("%d\n\n", pPost->likes);
            ok = 1;
        }
    }
    return ok;
}

int filtrar_masCantidadHaters(void* post)
{
    int ok = 0;
    ePost* pPost = NULL;
    if (post != NULL)
    {
        pPost=(ePost*) post;
        if(pPost->likes < pPost->dislikes)
        {
            ok = 1;
        }
    }
    return ok;
}

