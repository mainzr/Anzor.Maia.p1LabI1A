/*
 * fecha.h
 *
 *  Created on: 23 oct. 2021
 *      Author: MAIA
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct {
	int dia;
	int mes;
	int anio;
}eFecha;

#endif /* FECHA_H_ */

int validarFecha(eFecha* unaFecha);
