/*
 * autos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
 */

#ifndef AUTOS_H_
#define AUTOS_H_

#include "color.h"
#include "marcas.h"
#include "cliente.h"


typedef struct{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int idCliente;
	int isEmpty;
}eAutos;

#endif /* AUTOS_H_ */

int inicializarAutos(eAutos autos[], int tamA);

int buscarLibre(eAutos autos[], int tam);

int altaAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli, int* pId);

int buscarAutoId(eAutos autos[], int tam, int id);

void mostrarAuto(eAutos unAuto, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClie);


int mostrarAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);

int modificarAuto(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);

int bajaAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);

int ordenarAutos(eAutos autos[], int tamA, eMarcas marca[], int tamM);

int cargarDescripcionAuto( char opcionElegida[]);


int informarColorAuto(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eCliente clientes[], int tamCli);

int informarColorAuto(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eCliente clientes[], int tamCli);

int informarMarcaAuto(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eCliente clientes[], int tamCli);

int informarMismaMarcaColor(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM);

int validarIdMarca( int id, eMarcas marcas[], int tamM );

int mostrarAutosTodasCajas(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);

int mostrarAutosIdCaja(char caja, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli);

//int cargarDescripcionCaja(eAutos autos[], int tamA, char caja, char descripcion[]);

int informarMarcaMasElegida(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM);

int cargarDescripcionCaja(eAutos autos[], int tamA, char caja, char descripcion[]);
