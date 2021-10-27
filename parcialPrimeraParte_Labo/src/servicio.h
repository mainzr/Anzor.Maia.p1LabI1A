/*
 * lavado.h
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */

#ifndef LAVADO_H_
#define LAVADO_H_

typedef struct
{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

#endif /* LAVADO_H_ */
int mostrarServicios(eServicio servicios[], int tamS);

int buscarServicioId(eServicio servicios[], int tamS, int id);

int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio, char descripcion[]);
