/*
 * color.c
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

#include "color.h"

int mostrarColores(eColor colores[], int tamC){

	int ok = 0;

	if(colores != NULL && tamC > 0){

		printf("\n                   COLORES\n");
		printf(" ----------------------------------------------\n");
		printf("         ID              DESCRIPCIONES\n");
		printf(" -----------------------------------------------\n");


		for(int i = 0; i < tamC; i++)
		{
			printf("        %-10d             %s\n", colores[i].id, colores[i].nombreColor);

		}
		printf("\n\n");

		ok = 1;
	}


	return ok;
}




int cargarDescripcionColor(eColor colores[], int tamC, int idColor, char descripcion[]){

	int excelente = 0;

	if(colores != NULL && tamC > 0 && descripcion != NULL){

		for(int i = 0; i < tamC; i++){

			if(colores[i].id == idColor){
				strcpy(descripcion, colores[i].nombreColor);//ENCUENTRA LOCALIDAD QUE TIENE ID
				break;
			}
		}

		excelente = 1;
	}

	return excelente;

}


