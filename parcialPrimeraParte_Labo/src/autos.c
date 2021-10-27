/*
 * autos.c
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
#include "autos.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


int inicializarAutos(eAutos autos[], int tamA)
{
	int ok = 0;

	if(autos != NULL && tamA > 0){
		for(int i = 0; i < tamA; i++){
			autos[i].isEmpty = 1;
		}
		ok = 1;
	}


	return ok;
}


int buscarLibreAutos(eAutos autos[], int tamA){
	int indice;



	if(autos != NULL && tamA > 0)
	{
		for(int i = 0; i < tamA; i++){

		   if(autos[i].isEmpty == 1){
			   indice = i;

			}
		}

	}
	return indice;
}




int altaAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli, int* pId){

	int ok = 0;
	int indice;
	eAutos auxAutos;


	if(autos != NULL && tamA > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC > 0  && clientes != NULL && tamCli > 0 && pId != NULL)
	{


		system("cls");

		//printf("------------------------------------------------------\n");
		printf(" \n              ***   ALTAS AUTOS ***\n\n");
		//printf("------------------------------------------------------\n\n");


		indice = buscarLibreAutos(autos, tamA);

		if(indice == -1) //no hay lugar
		{
			printf("No hay lugar\n");
		}
		else  //hay lugar
		{
			auxAutos.id = *pId;
			(*pId)++;

			//------------------------------ Se piden datos


			mostrarMarcas(marcas, tamM);
			getInteger(&auxAutos.idMarca, "Ingrese id de la marca: ", "Error...reingrese id: ", 1000, 1004);


			mostrarColores(colores, tamC);
		    getInteger(&auxAutos.idColor, "Ingrese id de la marca que desee: ", "Error...reingrese id: ", 5000, 5004);



			validarCaracter(&auxAutos.caja, "Ingrese caja que desea (automatica 'a' / manual 'm'): ", "Error...Reingrese opcion: ", 'm', 'a');
			auxAutos.caja = toupper(auxAutos.caja);

			mostrarClientes(clientes, tamCli);
			printf("Seleccione su id de cliente: ");
			scanf("%d", &auxAutos.idCliente);
			while(validarIdCliente(auxAutos.idCliente, clientes, tamCli) == 0)
			{
				printf("Error....reingrese opcion: ");
				scanf("%d", &auxAutos.idCliente);
			}

			auxAutos.isEmpty = 0;
			autos[indice] = auxAutos;

			printf("\n\n");
			printf("Auto dado de alta:\n");
			printf("-------------------------------------------------------------------------\n");
			mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCli);
			printf("-------------------------------------------------------------------------\n");

			ok = 1;

		}

	}

	return ok;
}



int buscarAutoId(eAutos autos[], int tam, int id){

	// SE NECESITA VARIABLE PARA VER SI SE ENCONTRO ID -> SI NO SE ENCONTRO DEVUELVE -1  -- SI SE ENCONTRO DEVUELVE EL INDICE

	int idEncontrada = -1;

	for(int i = 0; i < tam; i++){
		if(autos[i].isEmpty == 0 && autos[i].id == id){
			idEncontrada = i;
			break;
		}
	}
	return idEncontrada;
}


void mostrarAuto(eAutos unAuto, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{

	char descMarc[20];
	char desColores[20];
	char descNombre[20];


	cargarDescripcionMarca(marcas, tamM, unAuto.idMarca, descMarc);
	cargarDescripcionColor(colores, tamC, unAuto.idColor, desColores);
	cargarDescripcionCliente(clientes, tamClie, unAuto.idCliente, descNombre);


	printf("%5d            %-16s   %-17s    %-9c      %s \n\n",

			unAuto.id,
			desColores,
			descMarc,
			unAuto.caja,
			descNombre);
}

int mostrarAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli){

	int ok = 0;
	int flag = 1;

	if(autos != NULL && tamA > 0){
		printf("                      LISTADO DE AUTOS \n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    ID          COLORES            MARCA            TIPO CAJA         CLIENTE   \n");
		printf("------------------------------------------------------------------------------------\n");

		for(int i = 0; i < tamA; i++){

			if(autos[i].isEmpty == 0){

				mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCli); //RECORRO ARRAY, PREGUNTA SI ESTRUCUTURA ESTA VACIA, DE VECTOR LISTA LO PASA A FUNCION MOSTAR PERSONA
			    flag = 0;
			}
		}

		if(flag == 1)
		{
			printf("no hay autos para mostrar\n");
		}

		ok = 1;
	}

	return ok;
}


int modificarAuto(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli){

	    int ok = 0;
		int id;
		int indice;
		char confirma;
		int auxInt;

		if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
		{


			printf("------------------------------------------------------\n");
			printf("                 MODIFICAR AUTOS\n");
			printf("------------------------------------------------------\n\n");

			mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);

			printf("ingrese id: ");
			scanf("%d", &id);

			indice = buscarAutoId(autos, tamA, id);

			if(indice == -1){

				printf("no existe un auto con id: %d\n\n", id);

			}
			else
			{
				mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCli);

				validarCaracter(&confirma, "confirma modificacion? (s/n): ", "Error....reintentelo nuevamente: ", 's', 'n');

				if(confirma == 's'){

					switch(menModificar()){

					     case 1:

					    	 mostrarColores(colores, tamC);

					    	 getInteger(&auxInt, "\nIngrese id del nuevo color: ", "\nError...Reingrese id: ", 5000, 5004);
					    	 autos[indice].idColor = auxInt;

					    	 printf("\n\nLista de autos actualizada:\n");
					    	 mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCli);
					    	 break;

					     case 2:
					    	 mostrarMarcas(marcas, tamM);

					    	 getInteger(&auxInt, "\nIngrese id de la nueva marca: ", "\nError...Reingrese id: ", 1000, 1004);
					    	 autos[indice].idMarca = auxInt;

					    	 printf("\n\nLista de autos actualizada:\n");
					    	 mostrarAuto(autos[indice], marcas, tamM, colores, tamC, clientes, tamCli);
					    	 break;
					     default:
					    	 printf("Opcion invalida\n");
					    	 break;
					}

					ok = 1;
				}
				else
				{
					printf("se ha cancelado la modificacion\n");
				}
			}

		}


		return ok;
	}

int bajaAutos(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli){
	int ok = 0;
	int indice;
	char confirma;
	int id;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0){

		printf("--------------------------------------------------------------\n");
		printf("                        BAJA AUTOS                       \n");
		printf("--------------------------------------------------------------\n\n");

		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);

		printf("Ingrese el ID del auto que desea dar de baja: ");
		scanf("%d", &id);

		indice = buscarAutoId(autos, tamM, id);

		if(indice == -1)
		{
			printf("No se encontro un auto  con ID: %d... Reintentelo nuevamente.\n", id);
		}
		else
		{
			validarCaracter(&confirma, "¿Desea confirmar la baja este auto? (s/n): ", "Error....reintentelo nuevamente: ", 's', 'n');

			if(confirma == 's'){
				autos[indice].isEmpty = 1;
				ok = 1;
			}
			else
			{
				printf("\nSe ha cancela la baja...\n");
			}
		}

	}

	return ok;
}


int ordenarAutos(eAutos autos[], int tamA, eMarcas marca[], int tamM)
{
    int ok = 0;
    eAutos auxAuto;

    char descMarcaUno[20];
    char descMarcaDos[20];


    if(autos != NULL && tamA > 0 && marca != NULL)
    {
        for(int i = 0; i < tamA - 1; i++)
        {
            for(int j = i + 1; j < tamA; j++)
            {
                cargarDescripcionMarca(marca, tamM, autos[i].idMarca, descMarcaUno);
                cargarDescripcionMarca(marca, tamM, autos[j].idMarca, descMarcaDos);

                if((strcmp(descMarcaUno, descMarcaDos) > 0) || (strcmp(descMarcaUno, descMarcaDos) == 0 && autos[i].id > autos[j].id))
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }


            }
        }

        ok = 1;
    }
    return ok;
}


int informarColorAuto(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eCliente clientes[], int tamCli)
{
	int idColorElegido;
	int ok = 0;
	int flag = 1;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{
		mostrarColores(colores, tamC);
		getInteger(&idColorElegido, "Seleccione el id del color del auto que desea ver: ", "Error....reingrese opcion: ", 5000, 5004);


		printf("\n                INFORME AUTOS DEL MISMO COLOR \n");
		printf("--------------------------------------------------------------\n");
		printf("    ID          COLORES            MARCA         TIPO CAJA      \n");
		printf("---------------------------------------------------------------\n");

		for(int i = 0; i < tamA; i++){

			if(autos[i].isEmpty == 0 && idColorElegido == autos[i].idColor){

				mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
				flag = 0;
			}
		}
		if(flag == 1)
		{
			printf("\nNo hay autos para mostrar\n");
		}

		ok = 1;
	}


	return ok;
}

int informarMarcaAuto(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM, eCliente clientes[], int tamCli)
{
	int idMarcaElegido;
	int ok = 0;
	int flag = 1;

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
	{
		mostrarMarcas(marcas, tamM);
		getInteger(&idMarcaElegido, "Seleccione id de la marca del auto que desea ver: ", "Error....reingrese opcion: ", 1000, 1004);


		printf("\n                 INFORME AUTOS DE LA MISMA MARCA \n");
		printf("--------------------------------------------------------------\n");
		printf("    ID          COLORES            MARCA         TIPO CAJA      \n");
		printf("---------------------------------------------------------------\n");

		for(int i = 0; i < tamA; i++){

			if(autos[i].isEmpty == 0 && idMarcaElegido == autos[i].idMarca){

				mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
				flag = 0;
			}
		}
		if(flag == 1)
		{
			printf("\nNo hay autos para mostrar\n");
		}

		ok = 1;
	}

	return ok;
}


int informarMismaMarcaColor(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM)
{
	int ok = 0;
	int idColorElgido;
	int idMarcaElegida;
	int contador = 0;
	char descColor[20];
	char descMarca[20];

	if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0)
	{
		mostrarMarcas(marcas, tamM);
		getInteger(&idMarcaElegida, "Seleccione id de la marca del auto que desea ver: ", "Error....reingrese opcion: ", 1000, 1004);

		mostrarColores(colores, tamC);
		getInteger(&idColorElgido, "Seleccione id del color del auto que desea ver: ", "Error....reingrese opcion: ", 5000, 5004);

		for(int i = 0; i < tamA; i++)
		{

			if(autos[i].isEmpty == 0 && idMarcaElegida == autos[i].idMarca && idColorElgido == autos[i].idColor)
			{
				contador++;
			}
		}

		cargarDescripcionColor(colores, tamC, idColorElgido, descColor);
		cargarDescripcionMarca(marcas, tamM, idMarcaElegida, descMarca);

		printf("\nCantidad de autos de la marca '%s' y el color '%s' seleccionado: %d auto/s\n", descMarca, descColor, contador);

		ok = 1;
	}

	return ok;
}

int validarIdMarca( int id, eMarcas marcas[], int tamM )
{
    int esValido = 0;

    if (marcas != NULL && tamM > 0)
    {
        for (int i = 0; i < tamM; i++)
        {
            if (id == marcas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int mostrarAutosTodasCajas(eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli)
{

    int todoOk = 0;


    if (autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
    {
        for (int i = 0; i < tamA; i++)
        {
    		printf("\n\n             INFORME AUTOS POR CAJA: '%c'\n", autos[i].caja);

            mostrarAutosIdCaja(autos[i].caja, autos, tamA, marcas, tamM, colores, tamC, clientes, tamCli);
        }


    }

    return todoOk;

}
/*
int mostrarColores(eAutos autos[], int tamA){

	int ok = 0;

	if(autos != NULL && tamC > 0){

		printf("\n                   autos\n");
		printf(" ----------------------------------------------\n");
		printf("         ID              DESCRIPCIONES\n");
		printf(" -----------------------------------------------\n");


		for(int i = 0; i < tamC; i++)
		{
			printf("        %-10d             %s\n", colores[i].id, colores[i].nombreColor);

		}
		printf("\n\n");

		ok = 1;
	}


	return ok;
}*/

int mostrarAutosIdCaja(char caja, eAutos autos[], int tamA, eMarcas marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCli)
{
    int ok = 0;
    int flag = 1;
    char descCaja[20];
    //char descCaja2[20];


    if (autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCli > 0)
    {

		printf("--------------------------------------------------------------\n");
		printf("    ID          COLORES            MARCA         TIPO CAJA      \n");
		printf("---------------------------------------------------------------\n");

        for (int i = 0; i < tamA; i++)
        {     //cargarDescripcionCaja(autos, tamA, caja, descCaja2);


            if (autos[i].isEmpty == 0 && autos[i].caja == caja )
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCli);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            //cargarDescripcionMarca(marcas, tamM, caja, descMarca);
            //cargarDescripcionCaja(autos, tamA, caja, descCaja);
            printf("No hay autos caja: '%s'.\n", descCaja);

        }
        ok = 1;
    }
    return ok;
}


int informarMarcaMasElegida(eAutos autos[], int tamA, eColor colores[], int tamC, eMarcas marcas[], int tamM)
{
    int ok = 0;
    int contadores[5] = {0};
    int marcasMasCantidad;

    if(autos != NULL && tamA > 0 && colores != NULL && tamC > 0 && marcas != NULL && tamM > 0)
    {
        system("cls");
		printf("------------------------\n");
		printf("  MARCAS MAS ELEGIDAS:   \n");
		printf("------------------------\n");

        for(int i = 0; i < tamM; i++)
        {
            for(int j = 0; j < tamA; j++)
            {
                if(autos[j].isEmpty == 0 &&  autos[j].idMarca == marcas[i].id)
                {
                    contadores[i]++;
                }
            }
        }

        for(int i = 0; i < tamM; i++)
        {
            if(i == 0 || marcasMasCantidad < contadores[i])
            {
                marcasMasCantidad = contadores[i];
            }
        }

        for(int i = 0; i < tamM; i++)
        {
            if(contadores[i] == marcasMasCantidad)
            {
                printf(" %5s\n", marcas[i].descripcion);
            }
        }
        printf("\n\n");

        ok = 1;
    }
    return ok;
}

/*
int cargarDescripcionCaja(eAutos autos[], int tamA, char caja, char descripcion[]){

	int excelente = 0;

	if(autos != NULL && tamA > 0 && descripcion != NULL){

		for(int i = 0; i < tamA; i++){

			if(autos[i].id == caja){
				if(autos->caja == 'A')
				{
				 strcpy(descripcion, "Automatico");//ENCUENTRA LOCALIDAD QUE TIENE ID
				  break;
				}
				else
				{
				 if(autos->caja == 'M')
				 {
				 strcpy(descripcion, "Manual");//ENCUENTRA LOCALIDAD QUE TIENE ID

				 }
				}

			}
		}

		excelente = 1;
	}

	return excelente;

}*/

