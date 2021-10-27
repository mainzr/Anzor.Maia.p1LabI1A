/*
 * cliente.h
 *
 *  Created on: 27 oct. 2021
 *      Author: MAIA
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int id;
	char nombre[20];
	char sexo;
	int isEmpty;
}eCliente;

#endif /* CLIENTE_H_ */

int inicializarCliente(eCliente clientes[], int tamCli);

int buscarLibreClientes(eCliente clientes[], int tamCli);

int altaClientes(eCliente clientes[], int tamClie, int* pId);

int cargarDescripcionCliente(eCliente clientes[], int tamCli, int idCliente, char descripcion[]);

void mostrarCliente(eCliente unCliente, int tamCli);

int mostrarClientes(eCliente clientes[], int tamCli);

int validarIdCliente( int id, eCliente clientes[], int tamCli );

int altaClientes(eCliente clientes[], int tamClie, int* pId);
