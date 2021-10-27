/*
 * marcas.h
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */

#ifndef MARCAS_H_
#define MARCAS_H_

typedef struct {
	int id;
	char descripcion[20];
} eMarcas;

#endif /* MARCAS_H_ */

int mostrarMarcas(eMarcas marcas[], int tamM);

int cargarDescripcionMarca(eMarcas marcas[], int tamM, int idMarca, char descripcion[]);

//int listarMarcas(eMarcas marcas[], int tamM, int idMarca, char descripcion[]);
