/*
 * fecha.c
 *
 *  Created on: 23 oct. 2021
 *      Author: MAIA
 */

#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarFecha(eFecha* unaFecha)
{
    int ok = 0;

    printf("ingrese dia: ");
    scanf("%d", &unaFecha->dia);

    printf("Ingrese mes: ");
    scanf("%d", &unaFecha->mes);

    printf("Ingrese anio (1950 - 2021): ");
    scanf("%d", &unaFecha->anio);

    while(ok == 0)
    {
        if(unaFecha->anio >= 1950 && unaFecha->anio <= 2021)
        {
            if(unaFecha->mes >= 1 && unaFecha->mes <= 12)
            {
                switch(unaFecha->mes)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(unaFecha->dia <1 || unaFecha->dia > 31)
                        {

                            printf("error...Dia invalido para este mes...reintentelo nuevamente...\n");

                            printf("ingrese dia (1 - 31): ");
                            scanf("%d", &unaFecha->dia);

                            printf("Ingrese mes (1 - 12): ");
                            scanf("%d", &unaFecha->mes);

                            printf("Ingrese anio (1950 - 2021): ");
                            scanf("%d", &unaFecha->anio);

                        }
                        else
                        {
                            ok = 1;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(unaFecha->dia < 1 || unaFecha->dia > 30)
                        {

                            printf("error...Dia invalido para este mes...reintentelo nuevamente...\n");

                            printf("ingrese dia (1 - 30): ");
                            scanf("%d", &unaFecha->dia);

                            printf("Ingrese mes (1 - 12): ");
                            scanf("%d", &unaFecha->mes);

                            printf("Ingrese anio (1950 - 2021): ");
                            scanf("%d", &unaFecha->anio);
                        }
                        else
                        {
                            ok = 1;
                        }
                        break;
                    case 2:
                        if(unaFecha->anio%4==0 || (unaFecha->anio%100 != 0 && unaFecha->anio%400 ==0 ))
                        {
                            if(unaFecha->dia < 1 || unaFecha->dia > 29)
                            {
                                printf("error...Dia invalido para este mes...reintentelo nuevamente...\n");

                                printf("ingrese dia (1 - 29): ");
                                scanf("%d", &unaFecha->dia);

                                printf("Ingrese mes (1 - 12): ");
                                scanf("%d", &unaFecha->mes);

                                printf("Ingrese anio (1950 - 2021): ");
                                scanf("%d", &unaFecha->anio);
                            }
                            else
                            {
                                ok = 1;
                            }
                        }
                        else
                        {
                            if(unaFecha->dia < 1 || unaFecha->dia > 28)
                            {
                                printf("error...Dia invalido para este mes...reintentelo nuevamente...\n");

                                printf("ingrese dia (1 - 28): ");
                                scanf("%d", &unaFecha->dia);

                                printf("Ingrese mes (1 - 12): ");
                                scanf("%d", &unaFecha->mes);

                                printf("Ingrese anio (1950 - 2021): ");
                                scanf("%d", &unaFecha->anio);
                            }
                            else
                            {
                                ok = 1;
                            }
                        }
                        break;
                }
            }
            else
            {
                printf("error...mes invalido...reintentelo nuevamente...\n");

                printf("ingrese dia: ");
                scanf("%d", &unaFecha->dia);

                printf("Ingrese mes: ");
                scanf("%d", &unaFecha->mes);

                printf("Ingrese anio: ");
                scanf("%d", &unaFecha->anio);
            }
        }
        else
        {
            printf("error...anio invalido...reintentelo nuevamente...\n");

            printf("ingrese dia: ");
            scanf("%d", &unaFecha->dia);

            printf("Ingrese mes: ");
            scanf("%d", &unaFecha->mes);

            printf("Ingrese anio: ");
            scanf("%d", &unaFecha->anio);
        }
    }

    return ok;
}


