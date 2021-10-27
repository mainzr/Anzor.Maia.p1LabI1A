/*
 * lavado.c
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */
#include  "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"

int mostrarServicios(eServicio servicios[], int tamS){

	int ok = 0;

	if(servicios != NULL && tamS > 0){

		printf("\n                         SERVICIOS\n");
		printf(" --------------------------------------------------------------------\n");
		printf("          ID                DESCRIPCIONES           PRECIO\n");
		printf(" --------------------------------------------------------------------\n");


		for(int i = 0; i < tamS; i++)
		{
			printf("        %d               %-12s         %d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);

		}
		printf("\n\n");

		ok = 1;
	}


	return ok;
}

int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio, char descripcion[]){

	int ok = 0;

	if(servicios != NULL && tamS > 0 && descripcion != NULL){

		for(int i = 0; i < tamS; i++){

			if(servicios[i].id == idServicio){
				strcpy(descripcion, servicios[i].descripcion);
				break;
			}
		}

		ok = 1;
	}

	return ok;

}

int buscarServicioId(eServicio servicios[], int tamS, int id){

	// SE NECESITA VARIABLE PARA VER SI SE ENCONTRO ID -> SI NO SE ENCONTRO DEVUELVE -1  -- SI SE ENCONTRO DEVUELVE EL INDICE

	int idEncontrada = -1;

	for(int i = 0; i < tamS; i++){
		if( servicios[i].id == id){
			idEncontrada = i;
			break;
		}
	}
	return idEncontrada;
}
