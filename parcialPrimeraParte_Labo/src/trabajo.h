/*
 * trabajo.h
 *
 *  Created on: 23 oct. 2021
 *      Author: MAIA
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"
#include "marcas.h"
#include "autos.h"
#include "color.h"
#include "fecha.h"
#include "cliente.h"

typedef struct {
	int id;
	int idPatente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajos;


#endif /* TRABAJO_H_ */

int inicializarTrabajo(eTrabajos trabajos[], int tamT);

int buscarLibreTrabajo(eTrabajos trabajos[], int tamT);

int altaTrabajos(eTrabajos trabajos[], int tamT, eAutos autos[], int tamA, eServicio servicios[], int tamS, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli, int* pId);

void mostrarTrabajo(eTrabajos unTrabajo, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS);
//int mostrarUnTrabajo(eTrabajos unTrabajo, eAutos autos[], int tamAuto, eServicio servicios[], int tamServ, eMarcas marcas[], int tamMarca, eColor colores[], int tamColores);

int mostrarTrabajos(eTrabajos trabajos[], int tamT, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eFecha fechas[], int tamF);

int informarTrabajosAutos(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli);

int informarSumaImportes(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli);

int informarServiciosAutos(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli);
