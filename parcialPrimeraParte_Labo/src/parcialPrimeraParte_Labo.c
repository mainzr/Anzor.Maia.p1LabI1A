/*
 ============================================================================
 Name        : parcialPrimeraParte_Labo.c
 Author      : MAIA MARIA LUZ ANZOR
 Version     :
 Copyright   :
 Description : Parcial 1 Labo
 ============================================================================
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
#include "hardcodeo.h"
#include "trabajo.h"
#include "fecha.h"
#include "cliente.h"



#define TAM_M 5
#define TAM_A 10
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10
#define TAM_F 10
#define TAM_CLI 5

int main(void) {
	setbuf(stdout, NULL);

	char seguir='s';
	eAutos autos[TAM_A];
	eTrabajos trabajos[TAM_T];
	eFecha fechas[TAM_F];
	eCliente clientes[TAM_CLI];
	int nextIdAutos = 1;
	int nextIdTrab = 1;
	int nextIdClie = 0;

	eMarcas marcas[TAM_M] = {
				{1000, "renault"},
				{1001, "ford"},
				{1002, "fiat"},
				{1003, "chevrolet"},
				{1004, "peugeot"}
	};


	 eColor colores[TAM_C] = {
	 			{5000, "Negro"},
	 			{5001, "Blanco"},
	 			{5002, "Rojo"},
	 			{5003, "Gris"},
	 			{5004, "Azul"}
	 	};

	 eServicio servicios[] = {
	 			{20000, "Lavado", 450,},
	 			{20001, "Pulido", 500,},
	 			{20002, "Encerado", 600,},
	 			{20003, "Completo", 900}
	 	};



	if(!inicializarAutos(autos, TAM_A))
	{
		printf("ocurrio problema al inicializar\n");
	}

	if(!inicializarTrabajo(trabajos, TAM_T))
	{
		printf("ocurrio problema al inicializar\n");
	}

	if(!inicializarCliente(clientes, TAM_CLI))
	{
		printf("ocurrio problema al inicializar\n");
	}

    //harcodearAutos(autos, TAM_A, 5, &nextIdAutos);
	//hardcodearTrabajos(trabajos, TAM_T, 5, &nextIdTrab);
	//hardcodearClientes(clientes, TAM_CLI, 5, &nextIdClie);

	do
	{
		system("cls");
		switch(menu())
		{
		    case  'A':
				if(altaClientes(clientes, TAM_CLI, &nextIdClie))
				{
					printf("\nAlta exitosa\n");

				}
				else
				{
					printf("\nError al dar de alta.\n");
				}
		    	break;
			case 'B':
					if(altaAutos(autos, TAM_A, marcas, TAM_M, colores, TAM_C, clientes, TAM_CLI, &nextIdAutos))
					{
						printf("\nAlta exitosa\n");
					}
					else
					{
						printf("\nError al dar de alta.\n");
					}

				break;

			case'C':
					if(!modificarAuto(autos, TAM_A, marcas, TAM_M, colores, TAM_C, clientes, TAM_CLI))
					{
						printf("\nError al modificar\n");
					}
					else
					{
						printf("\nMoficacion exitosa!\n");
					}

				break;
			case 'D':
					if(!bajaAutos(autos, TAM_A, marcas, TAM_M, colores, TAM_C, clientes, TAM_CLI))
					{
						printf("\nError al dar de baja\n");
					}
					else
					{
						printf("\nBaja exitosa!\n");
					}


				break;

			case 'E':
				ordenarAutos(autos, TAM_A, marcas, TAM_M);
				mostrarAutos(autos, TAM_A, marcas, TAM_M, colores, TAM_C, clientes, TAM_CLI);
				break;

			case 'F':
				mostrarMarcas(marcas, TAM_M);

				break;
			case 'G':
				mostrarColores(colores, TAM_C);

				break;
			case 'H':
				mostrarServicios(servicios, TAM_S);
				break;
			case 'I':
				if(!altaTrabajos(trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M, colores, TAM_C, clientes, TAM_CLI, &nextIdTrab))
				{
					printf("\nError al dar de alta de trabajo.\n");

				}
				else
				{
					printf("\nAlta exitosa de trabajo\n");
				}
				break;
			case 'J':
				mostrarTrabajos(trabajos, TAM_T, autos, TAM_A, marcas, TAM_M, colores, TAM_C, servicios, TAM_S, fechas, TAM_F);
				break;
			case 'K':
				informarMenu(autos, TAM_A, colores, TAM_C, marcas, TAM_M, trabajos, TAM_T, servicios, TAM_S, fechas, TAM_F, clientes, TAM_CLI);
				break;
			case 'L':
				validarCaracter(&seguir, "¿Seguro que desea salir? (s/n): ", "Error...reingrese opcion: ", 's', 'n');
				seguir = 'n';
				break;
			default:
				printf("\nError...opcion incorrecta.\n");
		}
		system("pause");

	}while(seguir == 's');



	return EXIT_SUCCESS;
}
