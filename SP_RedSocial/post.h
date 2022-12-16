#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

typedef struct
{
    int id;
    char user[300];
    int likes;
    int dislikes;
    int followers;
}ePost;

#endif // POST_H_INCLUDED

ePost* new_post();
ePost* new_Param(char* id,char* user, char* likes,char* dislikes,char* followers);
void post_delete(ePost* this);
//Setter
int s_setId(ePost* this,int id);
int s_setUser(ePost* this,char* user);
int s_setLikes(ePost* this,int likes);
int s_setDislikes(ePost* this,int dislikes);
int s_setFollowers(ePost* this,int followers);
//Getter
int g_getId(ePost* this,int* id);
int g_getUser(ePost* this,char* user);
int g_getLikes(ePost* this,int* likes);
int g_getDislikes(ePost* this,int* dislikes);
int g_getFollowers(ePost* this,int* followers);

void mostrar_Post(ePost* this);
int filtrar_masCantidadlikes(void* post);
int filtrar_masCantidadHaters(void* post);
