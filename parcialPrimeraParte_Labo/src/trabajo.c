/*
 * trabajo.c
 *
 *  Created on: 23 oct. 2021
 *      Author: MAIA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"
#include "marcas.h"
#include "autos.h"
#include "color.h"
#include "fecha.h"
#include "trabajo.h"
#include "inputs.h"
#include "cliente.h"

int inicializarTrabajo(eTrabajos trabajos[], int tamT)
{
	int ok = 0;

	if(trabajos != NULL && tamT > 0){
		for(int i = 0; i < tamT; i++){
			trabajos[i].isEmpty = 1;
		}
		ok = 1;
	}


	return ok;
}

int buscarLibreTrabajo(eTrabajos trabajos[], int tamT){
	//int ok = 0;
	int indice = -1;


	if(trabajos != NULL && tamT > 0)
	{
		for(int i = 0; i < tamT; i++){

		   if(trabajos[i].isEmpty == 1){
			   indice = i;
              break;
			}
		}

	}
	return indice;
}




void mostrarTrabajo(eTrabajos unTrabajo, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS)
{
	int indiceAuto;
	char descMarc[20];
	char desColores[20];
	int indiceServicio;
	char descServicio[20];


	if(autos != NULL && tamA > 0 && marcas != NULL  && tamM > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0)
	{
		indiceAuto = buscarAutoId(autos, tamA, unTrabajo.idPatente); //posicion de auto
		indiceServicio = buscarServicioId(servicios, tamS, unTrabajo.idServicio);


		cargarDescripcionMarca(marcas, tamM, autos[indiceAuto].idMarca, descMarc);
		cargarDescripcionColor(colores, tamC, autos[indiceAuto].idColor, desColores);

		cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descServicio);


		printf("%10d       %-5d  %-9s     %-15s     %-10c    %-10d    %-10s    %-10d       %d/%d/%d  ",
				unTrabajo.id,

				autos[indiceAuto].id, desColores, descMarc, autos[indiceAuto].caja,

				servicios[indiceServicio].id, descServicio, servicios[indiceServicio].precio,

				unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);

	}


}


int mostrarTrabajos(eTrabajos trabajos[], int tamT, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eFecha fechas[], int tamF)
{

	int ok = 0;
	int flag = 1;

	if(trabajos != NULL && tamT > 0 && autos != NULL && tamA > 0 && marcas != NULL  && tamM > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && fechas != NULL && tamF > 0)
	{

		printf("                                                           LISTADO TRABAJO \n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n");
		printf("             |                  AUTOS                   |                 SERVICIOS                |       FECHAS\n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n");
		printf(" ID TRABAJO  |  ID      COLORES     MARCA    TIPO CAJA  |   ID        DESCRIPCION       PRECIO     |   DIA / MES / AÑO \n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n\n");

		for(int i = 0; i < tamT; i++){

			if(trabajos[i].isEmpty == 0){
				mostrarTrabajo(trabajos[i], autos, tamA, marcas, tamM, colores, tamC, servicios, tamS);
			    flag = 0;
			}
			printf("\n\n");
		}

		if(flag == 1)
		{
			printf("no hay trabajos para mostrar\n");
		}

		ok = 1;
	}

	return ok;
}




int altaTrabajos(eTrabajos trabajos[], int tamT, eAutos autos[], int tamA, eServicio servicios[], int tamS, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli, int* pId)
{
	int ok = 0;
	int indice;
	int indiceId;
	eTrabajos auxTrabajos;


	if(trabajos != NULL && tamA > 0 && autos != NULL && tamA> 0 && servicios != NULL && tamS > 0 && pId != NULL && clientes != NULL && tamCli > 0)
	{


		system("cls");

		printf("------------------------------------------------------\n");
		printf("               ***   ALTAS TRABAJOS ***\n");
		printf("------------------------------------------------------\n\n");


		indice = buscarLibreTrabajo(trabajos, tamT);

		if(indice == -1) //no hay lugar
		{
			printf("No hay lugar\n");
		}
		else  //hay lugar
		{
			auxTrabajos.id = *pId;
			(*pId)++;

			//------------------------------ Se piden datos:

			mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);
			printf("Ingrese id (patente) del auto que desee: ");
			scanf("%d", &auxTrabajos.idPatente);

			indiceId = buscarAutoId(autos, tamA, auxTrabajos.idPatente);

			if(indiceId == -1)
			{
				printf("error...no existe un auto con id: %d\n\n", auxTrabajos.idPatente);

			}
			else
			{
				mostrarServicios(servicios, tamS);
			    getInteger(&auxTrabajos.idServicio, "Ingrese id del servicio que desee: ", "Error...reingrese id: ", 20000, 20003);


				printf("Ingrese fecha deseada: ");
				validarFecha(&auxTrabajos.fecha);



				auxTrabajos.isEmpty = 0; //SE ACTUALIZA PORQUE TYA NO ESTA VACIO
				trabajos[indice] = auxTrabajos;

				printf("\n\n");
				printf("Trabajo dado de alta:\n\n");
				mostrarTrabajo(trabajos[indice], autos, tamA, marcas, tamM, colores, tamC, servicios, tamS);
				printf("\n");

				ok = 1;
			}

		}

	}

	return ok;
}


int informarTrabajosAutos(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli)
{
	int ok = 0;
	int idElegida;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{
		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);

		printf("Elija id del auto que desee ver los trabajos hechos: ");
		scanf("%d", &idElegida);

		printf("\n                                                   LISTADO TRABAJO \n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n");
		printf("             |                  AUTOS                   |                 SERVICIOS                |       FECHAS\n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n");
		printf(" ID TRABAJO  |  ID      COLORES     MARCA    TIPO CAJA  |   ID        DESCRIPCION       PRECIO     |   DIA / MES / AÑO \n");
		printf("-------------|------------------------------------------|------------------------------------------|------------------------------\n\n");


		for(int i = 0; i < tamA; i++)
		{
			if(autos[i].isEmpty == 0 && autos[i].id == idElegida)
			{
				mostrarTrabajo(trabajos[i], autos, tamA, marcas, tamM, colores, tamC, servicios, tamS);
			}
		}
		printf("\n\n");

		ok = 1;
	}



	return ok;
}


int informarSumaImportes(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli)
{
	int ok = 0;
	int idElegido;
	int acumulador = 0;
	int indice;
	int indiceServ;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{
		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);

		printf("Ingrese id del auto que desee saber importes total: ");
		scanf("%d", &idElegido);

		indice = buscarAutoId(autos, tamA, idElegido);


		for(int i = 0; i < tamT; i++)
		{
			if(autos[indice].isEmpty == 0  && trabajos[i].isEmpty == 0)
			{
				if( autos[indice].id == idElegido && trabajos[i].idPatente == idElegido)
				{
					indiceServ = buscarServicioId(servicios, tamS, trabajos[i].idServicio);

					acumulador += servicios[indiceServ].precio;
				}

			}

		}
		printf("\nTotal de importes hechos a este auto: %d\n", acumulador);
		ok = 1;
	}


	return ok;
}


int informarServiciosAutos(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli)
{
	int ok = 0;
	int idElegido;
	int indice;
	int indiceAuto;
	int flag = 0;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{
		mostrarServicios(servicios, tamS);

		printf("Ingrese id del servicio : ");
		scanf("%d", &idElegido);

		//indice = buscarAutoId(autos, tamA, idElegido);
		indice = buscarServicioId(servicios, tamS, idElegido);


		for(int i = 0; i < tamT; i++)
		{

				if( servicios[indice].id == idElegido && trabajos[i].idServicio == idElegido)
				{
					indiceAuto = buscarAutoId(autos, tamA, trabajos[i].idServicio);
					//indiceServ = buscarServicioId(servicios, tamS, trabajos[i].idServicio);
					mostrarTrabajos(trabajos, tamT, autos, tamA, marcas, tamM, colores, tamC, servicios, tamS, fechas, tamF);
					flag = 1;
				}



		}
		if(flag == 0)
		{
			printf("-----------------------------------------------------\n");
			printf("\nNo hay autos que se hayan realizado ese servicio...\n");
			printf("-----------------------------------------------------\n");

		}

		ok = 1;
	}


	return ok;
}
/*
int informarServiciosFecha(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eTrabajos trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fechas[], int tamF, eCliente clientes[], int tamCli)
{
	int ok = 0;
	int idElegido;
	int indice;
	int indiceAuto;
	int flag = 0;
	int fecha;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{

		print("Ingrese la fecha que desee saber los servicios realizados: ");
		validarFecha(&fecha);

		//indice = buscarAutoId(autos, tamA, idElegido);
		//indice = buscarServicioId(servicios, tamS, idElegido);
		indice = buscarServicioIdFecha(trabajos, tamT, fecha);

		for(int i = 0; i < tamT; i++)
		{
				if( servicios[i].id == indice && trabajos[i].fecha == fecha)
				{
					indiceAuto = buscarAutoId(autos, tamA, trabajos[i].idServicio);
					//indiceServ = buscarServicioId(servicios, tamS, trabajos[i].idServicio);
					mostrarTrabajos(trabajos, tamT, autos, tamA, marcas, tamM, colores, tamC, servicios, tamS, fechas, tamF);
					flag = 1;
				}

		}
		if(flag == 0)
		{
			printf("-----------------------------------------------------\n");
			printf("No hay autos que se hayan realizado este servicio...\n");
			printf("-----------------------------------------------------\n");

		}

		ok = 1;
	}


	return ok;
}

int buscarServicioIdFecha(eTrabajos trabajos[], int tamT, int fecha){

	// SE NECESITA VARIABLE PARA VER SI SE ENCONTRO ID -> SI NO SE ENCONTRO DEVUELVE -1  -- SI SE ENCONTRO DEVUELVE EL INDICE

	int idEncontrada = -1;

	for(int i = 0; i < tamT; i++){
		if( trabajos[i].fecha == fecha){
			idEncontrada = i;
			break;
		}
	}
	return idEncontrada;
}
*/
