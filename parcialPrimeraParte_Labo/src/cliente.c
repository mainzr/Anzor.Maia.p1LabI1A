/*
 * cliente.c
 *
 *  Created on: 27 oct. 2021
 *      Author: MAIA
 */

#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int inicializarCliente(eCliente clientes[], int tamCli)
{
	int ok = 0;

	if(clientes != NULL && tamCli > 0){
		for(int i = 0; i < tamCli; i++){
			clientes[i].isEmpty = 1;
		}
		ok = 1;
	}


	return ok;
}


int buscarLibreClientes(eCliente clientes[], int tamCli){
	int indice;



	if(clientes != NULL && tamCli > 0)
	{
		for(int i = 0; i < tamCli; i++){

		   if(clientes[i].isEmpty == 1){
			   indice = i;

			}
		}

	}
	return indice;
}


int cargarDescripcionCliente(eCliente clientes[], int tamCli, int idCliente, char descripcion[]){

	int ok = 0;

	if(clientes != NULL && tamCli > 0 && descripcion != NULL){

		for(int i = 0; i < tamCli; i++){

			if(clientes[i].id == idCliente){
				strcpy(descripcion, clientes[i].nombre);//ENCUENTRA LOCALIDAD QUE TIENE ID
				break;
			}
		}

		ok = 1;
	}

	return ok;

}

void mostrarCliente(eCliente unCliente, int tamCli)
{


	printf("%5d         %-10s        %-5c \n\n",

			unCliente.id,
			unCliente.nombre,
			unCliente.sexo);
}

int mostrarClientes(eCliente clientes[], int tamCli){

	int ok = 0;
	int flag = 1;

	if(clientes != NULL && tamCli > 0){
		printf("\n          LISTADO DE CLIENTES \n");
		printf("--------------------------------------------\n");
		printf("    ID          NOMBRE            SEXO           \n");
		printf("--------------------------------------------\n");

		for(int i = 0; i < tamCli; i++){

			if(clientes[i].isEmpty == 0)
			{
				mostrarCliente(clientes[i], tamCli);
			    flag = 0;
			}
		}

		if(flag == 1)
		{
			printf("no hay clientes para mostrar\n");
		}

		ok = 1;
	}

	return ok;
}

int validarIdCliente( int id, eCliente clientes[], int tamCli )
{
    int esValido = 0;

    if (clientes != NULL && tamCli > 0)
    {
        for (int i = 0; i < tamCli; i++)
        {
            if (id == clientes[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int altaClientes(eCliente clientes[], int tamClie, int* pId){

	int ok = 0;
	int indice;
	eCliente auxClientes;


	if(clientes != NULL && tamClie > 0  && pId != NULL)
	{
		system("cls");

		//printf("------------------------------------------------------\n");
		printf(" \n              ***   ALTAS CLIENTES ***\n\n");
		//printf("------------------------------------------------------\n\n");


		indice = buscarLibreClientes(clientes, tamClie);

		if(indice == -1) //no hay lugar
		{
			printf("No hay lugar\n");
		}
		else  //hay lugar
		{
			auxClientes.id = *pId;
			(*pId)++;

			//------------------------------ Se piden datos:

			printf("Ingrese su nombre: ");
			fflush(stdin);
			gets(auxClientes.nombre);

			validarCaracter(&auxClientes.sexo, "Ingrese sexo 'femenino' (f), 'masculino' (m): ", "Error...reingrese sexo: ", 'f', 'm');



			auxClientes.isEmpty = 0;
			clientes[indice] = auxClientes;

			printf("\n\n");
			printf("Cliente dado de alta:\n");

			ok = 1;

		}

	}

	return ok;
}


