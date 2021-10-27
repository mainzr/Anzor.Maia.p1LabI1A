/*
 * color.h
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */

#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

#endif /* COLOR_H_ */
int mostrarColores(eColor colores[], int tamC);

int cargarDescripcionColor(eColor colores[], int tamC, int idColor, char descripcion[]);
