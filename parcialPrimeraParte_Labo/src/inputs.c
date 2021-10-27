/*
 * inputs.c
 *
 *  Created on: 20 oct. 2021
 *      Author: MAIA
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
#include "trabajo.h"

char menu()
{
	char opcion;

	system("cls");

	printf("\n---------------------------------------------------------\n");
	printf("                     *** ABM AUTOS ***                 \n");
	printf("----------------------------------------------------------\n");
	printf("  A. ALTA CLIENTE\n");
	printf("  B. ALTA AUTOS\n");
	printf("  C. MODIFICAR AUTOS\n");
	printf("  D. BAJA AUTOS\n");
	printf("  E. LISTAR AUTOS (POR MARCA Y PATENTE)\n");
	printf("  F. LISTAR MARCAS\n");
	printf("  G. LISTAR COLORES\n");
	printf("  H. LISTAR SERVICIOS\n");
	printf("  I. ALTA TRABAJO\n");
	printf("  J. LISTAR TRABAJOS\n");
	printf("  K. INFORMES\n");
	printf("  L. SALIR\n\n");



	printf("\nIngrese opcion: ");
	scanf("%c", &opcion);
	opcion = toupper(opcion);

	return opcion;
}


int menModificar(){

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE MODIFICACIONES                      \n");
	printf("---------------------------------------------------------------------\n\n");

	printf(" 1. Color.\n");
	printf(" 2. Modelo\n");

	getInteger(&option, "\nIngrese la opcion que desee modificar: ", "Error...Reingrese opcion: ", 1, 2);


	return option;
}

int getInteger(int* number, char* message, char* errorMessage, int minNumber, int maxNumber)
{
	int error = -1;
	int auxInt;

	if(message != NULL && errorMessage != NULL )
	{
		printf("%s", message);
		scanf("%d", &auxInt);

		while(auxInt < minNumber || auxInt > maxNumber)
		{
			printf("%s", errorMessage);
			scanf("%d", &auxInt);
		}

		*number = auxInt;

		error = 0;
	}

    return error;
}


int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos)
{
    int todoOk=0;
    char respuesta;

    if(mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c",&respuesta);

        while(respuesta != opcionUno && respuesta != opcionDos )
        {
                printf("%s", mensajeError);
                fflush(stdin);
                scanf("%c",&respuesta);

        }

        *charAValidar = respuesta;
        todoOk=1;
    }
    return todoOk;
}


int subMenuInformes(){

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE INFORMES                    \n");
	printf("---------------------------------------------------------------------\n\n");

	printf("  1. INFORMAR AUTOS DEL MISMO COLOR.\n");
	printf("  2. INFORMAR AUTOS DE MISMA MARCA\n");
	printf("  3. INFORMAR AUTO MAS VIEJO\n");
	printf("  4. INFORMAR AUTOS POR CAJA\n");
	printf("  5. INFORMAR CANTIDAD DE AUTOS CON MISMA MARCA Y COLOR\n");
	printf("  6. INFORMAR MARCA DE AUTO MAS ELEGIDA POR CLIENTES\n");
	printf("  7. INFORMAR TRABAJOS HECHOS A UN AUTO\n");
	printf("  8. INFORMAR SUMA DE IMPORTES DE UN AUTO\n");
	printf("  9. INFORMAR SERVICIO REALIZADO A AUTOS Y FECHA\n");
	printf(" 10. INFORMAR SERVICIOS REALIZADOS EN UNA FECHA\n\n");



	printf("Ingrese la opcion que desee modificar: ");
	scanf("%d", &option);

	return option;
}

int informarMenu(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli)
{
	int ok = 0;

	switch(subMenuInformes())
	{
	    case 1:
			informarColorAuto(autos, tamA, colores, tamC, marcas, tamM, clientes, tamCli);
			break;
	    case 2:
			informarMarcaAuto(autos, tamA, colores, tamC, marcas, tamM, clientes, tamCli);
			break;
	    case 3:

	    	break;
	    case 4:
			//mostrarAutosTodasCajas(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);
			mostrarAutosTodasCajas(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);

			break;
	    case 5:
			informarMismaMarcaColor(autos, tamA, colores, tamC, marcas, tamM);

			break;
	    case 6:
			informarMarcaMasElegida(autos, tamA, colores, tamC, marcas, tamM);
			break;
	    case 7:
			informarTrabajosAutos(autos, tamA, colores, tamC, marcas, tamM, trabajos, tamT, servicios, tamS, fechas, tamF, clientes, tamCli);
			break;
	    case 8:
	    	informarSumaImportes(autos, tamA, colores, tamC, marcas, tamM, trabajos, tamT, servicios, tamS, fechas, tamF, clientes, tamCli);
	    	break;
	    case 9:
	    	informarServiciosAutos(autos, tamA, colores, tamC, marcas, tamM, trabajos, tamT, servicios, tamS, fechas, tamF, clientes, tamCli);
	    	break;
	    case 10:
	    	break;

	    default:
	    	printf("Error...opcion invalida.\n");
	    	break;
	}
	ok = 1;


	return ok;
}



