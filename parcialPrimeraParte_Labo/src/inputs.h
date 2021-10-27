/*
 * inputs.h
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include "autos.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"
#include "trabajo.h"

#endif /* INPUTS_H_ */
char menu();

int getInteger(int* number, char* message, char* errorMessage, int minNumber, int maxNumber);

int menModificar();

int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);

int subMenuInformes();

int informarMenu(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli);

