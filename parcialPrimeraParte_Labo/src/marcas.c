/*
 * marcas.c
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "marcas.h"
#include "color.h"
#include "servicio.h"
#include "autos.h"

int mostrarMarcas(eMarcas marcas[], int tamM){

	int ok = 0;

	if(marcas != NULL && tamM > 0)
	{

		printf("\n                    MARCAS\n");
		printf(" --------------------------------------------\n");
		printf("         ID             DESCRIPCIONES\n");
		printf("----------------------------------------------\n");


		for(int i = 0; i < tamM; i++)
		{
		 printf("        %d               %s \n", marcas[i].id, marcas[i].descripcion);

		}
		printf("\n\n");

		ok = 1;
	}


	return ok;
}

int cargarDescripcionMarca(eMarcas marcas[], int tamM, int idMarca, char descripcion[]){

	int excelente = 0;

	if(marcas != NULL && tamM > 0 && descripcion != NULL){

		for(int i = 0; i < tamM; i++){

			if(marcas[i].id == idMarca){
				strcpy(descripcion, marcas[i].descripcion);//ENCUENTRA LOCALIDAD QUE TIENE ID
				break;
			}
		}

		excelente = 1;
	}

	return excelente;

}



