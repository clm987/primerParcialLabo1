/*DESCRIPCION: IMPLEMENTACION DE FUNCIONES PARA EL MANEJO DE PRESTAMOS
 *AUTOR: CARLOS LOPEZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IOdata.h"
#include "ePrestamo.h"
#include "eCliente.h"

void setePrestamoStatus(ePrestamo* ePrestamoArray, int arrayPLength, int value)
{
	int i;
	for(i=0; i<arrayPLength; i++)
	{
		ePrestamoArray[i].isEmpty = value;
		ePrestamoArray[i].idCliente = 0;
	}

}

int findEmptyPlaceePrestamo(ePrestamo* ePrestamoArray,int arrayPLength, int value)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayPLength; i++)
    {
    	if(ePrestamoArray[i].isEmpty == value)
    	{
    		retCode = i;
    		//break;
    	}
    }
    return retCode;
}

int generateIdePrestamo()
{
    static int id=1;

    return id++;
}

int findePrestamoById(ePrestamo* ePrestamoArray,int arrayPLength, int id)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayPLength; i++)
    {
        if(ePrestamoArray[i].idPrestamo == id && ePrestamoArray[i].isEmpty == NON_EMPTY)
        {
        	retCode = i;
        }
    }
    return retCode;
}

int showListePrestamo(ePrestamo* ePrestamoArray, int arrayPLength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4)
{
	int retCode = -1;
	int i;
	int emptyPlaces = 0;

	for(i=0;i<arrayPLength;i++)
	{
		if(ePrestamoArray[i].isEmpty==EMPTY)
		{
			emptyPlaces ++;
			continue;
		}
		else
		{
		printf("%-20s|", fieldTitle1);
		printf("%-40f|", ePrestamoArray[i].importe);
		printf("%-20s|", fieldTitle2);
		printf("%-40d|", ePrestamoArray[i].cuotas);
		printf("%-10s|", fieldTitle3);
		printf("%-10d|", ePrestamoArray[i].estado);
		printf("%-5s|", fieldTitle4);
		printf("%-5d|", ePrestamoArray[i].idPrestamo);
		printf("\n");
		}
	}

	if(emptyPlaces < arrayPLength)
	{
		retCode = 0;
	}

	return retCode;
}

char getConfirmationePrestamo(char* message)
{
	char retA = 'n';

    do {
        printf("%s", message);
        fflush(stdin);
        scanf("%c", &retA);
        retA = tolower(retA);

    } while (retA != 's' && retA != 'n');

	return retA;
}

int checkIfEmptyePrestamo(ePrestamo* ePrestamoArray,int arrayPLength)
{
    int i;
    int retCode = -1;
    int countNonEmpty = 0;

    for(i = 0; i < arrayPLength; i++)
    {
    	if(ePrestamoArray[i].isEmpty == NON_EMPTY)
    	{
    		countNonEmpty++;
    	}
    }

    if(countNonEmpty > 0)
    {
    	retCode = 1;
    }
    return retCode;
}

void hardCodeFunctionPrestamo(ePrestamo* ePrestamoArray, int index, float importeTest, int cuotasTest, int estadoTest, int idPrestamoTest, int idClienteTest, int isEmptyTest)
{
	ePrestamoArray[index].importe = importeTest;
	ePrestamoArray[index].cuotas = cuotasTest;
	ePrestamoArray[index].estado = estadoTest;
	ePrestamoArray[index].idPrestamo = idPrestamoTest;
	ePrestamoArray[index].idCliente = idClienteTest;
	ePrestamoArray[index].isEmpty = isEmptyTest;

}
