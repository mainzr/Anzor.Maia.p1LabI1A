/*
 * hardcodeo.c
 *
 *  Created on: 23 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcodeo.h"
#include "autos.h"
#include "trabajo.h"
#include "cliente.h"




int IdMarca[10]={1000, 1001, 1000, 1003, 1003, 1002, 1001, 1002, 1000, 1002};

int color[10]={5004, 5005, 5000, 5003, 5004, 5002, 5005, 5002, 5000, 5001};

char caja[10] = {'a','m','m','a','m','a','m','m','m','a'};

int harcodearAutos(eAutos autos[], int tamA, int cantidadACargar, int* pIdAutos)
{
    int contador=-1;

    if(autos!=NULL && tamA>0 && cantidadACargar>=0 && cantidadACargar<=tamA && pIdAutos!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            autos[i].id= *pIdAutos;
            (*pIdAutos)++;
            autos[i].caja = caja[i];
            autos[i].idColor=color[i];
            autos[i].idMarca=IdMarca[i];
            autos[i].isEmpty=0;
            contador++;
        }
        //*pBanderaBici=1;
    }
    return contador;
}

int autos[15]={1,1,5,3,4,8,10,6,5,7,2,3,10,9,9};

int idsServicio[15]={20001,20002,20001,20000,20003,20003,20001,20000,20002,20003,20003,20001,20002,20000,20000};

eFecha fechas[15]={{27,12,1991},
                   {26,06,1996},
                   {22,02,2000},
                   {30,11,2001},
                   {03,12,2001},
                   {31,05,2000},
                   {12,10,1997},
                   {01,01,2003},
                   {10,01,2001},
                   {07,01,1995},
                   {13,01,1970},
                   {16,10,1964},
                   {27,03,1984},
                   {19,12,1976},
                   {20,8,2007}
                   };

int hardcodearTrabajos(eTrabajos trabajos[], int tamTrab, int cantidad, int* id)
{
    int contador=-1;

	if(trabajos!=NULL && tamTrab>0 && cantidad>=0 && cantidad<=tamTrab && id!=NULL)
	{
		contador=0;
		for(int i=0; i<cantidad; i++)
		{
			trabajos[i].id = *id;
			(*id)++;
            trabajos[i].idPatente = autos[i];
			trabajos[i].idServicio = idsServicio[i];
			trabajos[i].fecha = fechas[i];
			trabajos[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}

char sexo[11] = {'f','m','f','f','m','m','f','m','f','m'};

char nombres[11][20] = {"Maria", "Jose", "Yuno", "Sebastian", "Luz", "Lucia", "Nahue", "Bianca", "Lucas", "Gabi"};


int hardcodearClientes(eCliente clientes[], int tamClientes, int cant, int* pIdCliente)
{
    int contador=-1;
    if(clientes!=NULL && tamClientes>0 && pIdCliente!=NULL && cant>=0 && cant <=tamClientes)
    {

        for(int i=0; i < cant; i++)
        {
            clientes[i].id = *pIdCliente;
            (*pIdCliente)++;
            strcpy(clientes[i].nombre, nombres[i]);
            clientes[i].sexo = sexo[i];
            clientes[i].isEmpty=0;
            contador++;

        }
    }
    return contador;
}



