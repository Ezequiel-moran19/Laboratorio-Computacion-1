#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "UTN_lib.h"

int menuPrincipal()
{
	int opcion;

	if(utn_getNumeroInt(&opcion,
			" _______________________________________________________________________ \n"
			"|                                                                       |\n"
			"|                           **MENU PRINCIPAL**                          |\n"
			"|_______________________________________________________________________|\n"
			"|                                                                       |\n"
			"|1-CARGA DE ARCHIVOS DE JUGADORES Y SELECCIONES data.csv (modo texto).  |\n"
			"|2-ALTA DE JUGADOR.                                                     |\n"
			"|3-MODIFICACIÓN DE JUGADOR.                                             |\n"
			"|4-BAJA DE JUGADOR.                                                     |\n"
			"|5-LISTADOS.                                                            |\n"
			"|6-CONVOCAR JUGADORES.                                                  |\n"
			"|7-ORDENAR Y LISTAR.                                                    |\n"
			"|8-GENERAR ARCHIVO BINARIO.                                             |\n"
			"|9-CARGAR ARCHIVO BINARIO.                                              |\n"
			"|10-GUARDAR ARCHIVOS.                                                   |\n"
			"|11-SALIR.                                                              |\n"
			"|_______________________________________________________________________|\n"
			"Ingrse una opcion:",
            "\nReingrese Opcion ('1' a '11')\n",1,11,2)==0){}

	return opcion;
}
int menuModificaciones()
{
	int opcion;

		if(utn_getNumeroInt(&opcion,
				" _______________________________________________ \n"
				"|                                               |\n"
				"|          **MENU DE MODIFICACIONES**           |\n"
				"|_______________________________________________|\n"
				"|                                               |\n"
				"|1-MODIFICAR NOMBRE.                            |\n"
				"|2-MODIFICAR EDAD.                              |\n"
				"|3-MODIFICAR POSICION.                          |\n"
				"|4-MODIFICAR NACIONALIDAD.                      |\n"
				"|5-SALIR.                                       |\n"
				"|_______________________________________________|\n"
				"Ingrse una opcion:",
	     "\nReingrese Opcion ('1' a '5')\n",1,5,2)==0){}

	return opcion;
}

int menuModificarSeleciones()
{
	int opcion;
	if(utn_getNumeroInt(&opcion,
			" _______________________________________________ \n"
			"|                                               |\n"
			"|          **MENU DE MODIFICACIONES**           |\n"
			"|_______________________________________________|\n"
			"|                                               |\n"
			"|1-MODIFICAR PAIS.                              |\n"
			"|2-MODIFICAR CONFEDERACION.                     |\n"
			"|3-MODIFICAR CONVOCADOS.                        |\n"
			"|4-SALIR.                                       |\n"
			"|_______________________________________________|\n"
			"Ingrse una opcion:",
	 "\nReingrese Opcion ('1' a '4')\n",1,4,2)==0){}
	return opcion;
}

int menuPcionesOrdenamiento()
{
	int opcion;
	if(utn_getNumeroInt(&opcion,
			" _______________________________________________ \n"
			"|                                               |\n"
			"|           **MENU DE ORDENAMIENTO**            |\n"
			"|_______________________________________________|\n"
			"|                                               |\n"
			"|1-ORDENAMIENTO POR NACIONALIDAD.               |\n"
			"|2-ORDENAMIENTO POR CONFEDERACION.              |\n"
			"|3-ORDENAMIENTO POR EDAD..                      |\n"
			"|4-ORDENAMIENTO POR NOMBRE..                    |\n"
			"|5-SALIR.                                       |\n"
			"|_______________________________________________|\n"
			"Ingrse una opcion:",
			 "\nReingrese Opcion ('1' a '5')\n",1,5,2)==0){}

	return opcion;
}

int menuListados()
{
	int opcion;

		if(utn_getNumeroInt(&opcion,
		" _______________________________________________ \n"
		"|                                               |\n"
		"|          **MENU DE LISTADOS**                 |\n"
		"|_______________________________________________|\n"
		"|                                               |\n"
		"|1-LISTAR JUGADORES.                            |\n"
		"|2-LISTAR SELECCIONES.                          |\n"
		"|3-LISTAAR CONVOCADOS.                          |\n"
		"|4-SALIR.                                       |\n"
		"|_______________________________________________|\n"
		"Ingrse una opcion:",
	     "\nReingrese Opcion ('1' a '4')\n",1,4,2)==0){}

	return opcion;
}

int menuOpcionesPuestos(int* jug)
{

  int opcion;
  if(utn_getNumeroInt(&opcion,
    " _________________________ \n"
	"|                         |\n"
	"|         PUESTOS         |\n"
	"|_________________________|\n"
	"|                         |\n"
	"|1-Portero                |\n"
	"|2-Defensa Central        |\n"
	"|3-Lateral izquierdo      |\n"
	"|4-Lateral derecho        |\n"
    "|5-Pivote                 |\n"
    "|6-Mediocentro            |\n"
    "|7-Mediocentro ofensivo   |\n"
	"|8-Extremo izquiero       |\n"
	"|9-Extremo derecho        |\n"
	"|10-Mediapunta            |\n"
    "|11-Delantero centro      |\n"
	"|_________________________|\n"
    "Ingrse una opcion:",
    "ERROR (Rango 1->11)",1,11,2)==0){}
   return opcion;
}

int menuOpcionNacionalidades(int* jug)
{

  int opcion;
  if(utn_getNumeroInt(&opcion,
    " _________________________ \n"
	"|                         |\n"
	"|     NACIONALIDADES      |\n"
	"|_________________________|\n"
	"|                         |\n"
	"|1-Aleman                 |\n"
	"|2-Arabe                  |\n"
	"|3-Argentino              |\n"
	"|4-Austriaco              |\n"
    "|5-Belga.                 |\n"
    "|6-Brasilero              |\n"
    "|7-Canadiense             |\n"
	"|8-Camerunes              |\n"
	"|9-Sud Coreano            |\n"
	"|10-Costarricense         |\n"
    "|11-Croata                |\n"
	"|12-Dinamarques           |\n"
    "|13-Ecuatoriano           |\n"
	"|14-Espaniol              |\n"
	"|15-Estadounidense        |\n"
	"|16-Frances               |\n"
	"|17-Gales                 |\n"
	"|18-Ghanes                |\n"
    "|19-Ingles                |\n"
	"|20-Irani                 |\n"
	"|21-Japones.              |\n"
	"|22-Marroqui              |\n"
    "|23-Mexicano.             |\n"
    "|24-Nerlandes             |\n"
    "|25-Polaco.               |\n"
	"|26-Portugues             |\n"
    "|27-Qatari.               |\n"
    "|28-Senegales             |\n"
	"|29-Serbio                |\n"
    "|30-Suizo                 |\n"
    "|31-Tunecino.             |\n"
    "|32-Uruguayo              |\n"
	"|_________________________|\n"
    "Ingrse una opcion:",
    "ERROR (Rango 1->32)",1,32,2)==0){}
   return opcion;
}

int menuPuntoSeis()
{
    int opcion;
    if(utn_getNumeroInt(&opcion,
	" _________________________________ \n"
	"|                                 |\n"
	"|    MENU DE CONVOCA Y QUITAR     |\n"
	"|_________________________________|\n"
	"|                                 |\n"
	"|1-Convocar jugadores             |\n"
	"|2-Quitar jugadores.              |\n"
	"|3-SALIR.                         |\n"
	"|_________________________________|\n"
	"Ingrse una opcion:", "\nReingrese Opcion ('1' a '4')\n",1,4,2)==0){}

    return opcion;

}

int menuOpcionesConfes()
{

  int opcion;
  if(utn_getNumeroInt(&opcion,
    " _________________________ \n"
	"|                         |\n"
	"|    Confederaciones      |\n"
	"|_________________________|\n"
	"|                         |\n"
	"|1-CAF                    |\n"
	"|2-AFC                    |\n"
	"|3-CONMEBOL               |\n"
	"|4-CONCACAF               |\n"
    "|5-UEFA                   |\n"
	"|_________________________|\n"
    "Ingrse una opcion:",
    "ERROR (Rango 1->5)",1,5,2)==0){}
   return opcion;
}
