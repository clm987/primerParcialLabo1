/*DESCRIPCION: IMPLEMENTACION DE FUNCIONES PARA EL MANEJO DE CLIENTES
 *AUTOR: CARLOS LOPEZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IOdata.h"
#include "eCliente.h"


void seteClienteStatus(eCliente* eClienteArray,int arrayClenght,int value)
{
    int i;
    for(i = 0; i < arrayClenght; i++)
    {
    	eClienteArray[i].isEmpty = value;
    }
}

int findEmptyPlace(eCliente* eClienteArray,int arrayClenght, int value)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayClenght; i++)
    {
    	if(eClienteArray[i].isEmpty == value)
    	{
    		retCode = i;
    	}
    }
    return retCode;
}

int seteCliente(eCliente* eClienteArray, int arrayClenght)
{
	int retCode = -1;
	int index = findEmptyPlace(eClienteArray, QTYCLIENTE,EMPTY);

	if(index == -1)
	{
		showMessage("\nNo hay lugares disponibles.");
	}
	else
	{
		getAlphaString(eClienteArray[index].nombre, "\nIngrese el nombre: ", "\nError. El nombre solo debe contener letras.");
		getAlphaString(eClienteArray[index].apellido, "\nIngrese el apellido: ", "\nError. El apellido solo debe contener letras.");
		getAlphaNumericCuil(eClienteArray[index].cuil, "\nIngrese el nuevo CUIL: ","\nError.El CUIL solo puede contener guiones y numeros! Intente de nuevo: ");
		eClienteArray[index].ideCliente = generateIdeCliente();
		eClienteArray[index].isEmpty = NON_EMPTY;
		showMessage("\nAlta dada con exito!!");
		showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
		system("pause");
		retCode = 0;
	}

	return retCode;
}

void showeCliente(eCliente* eClienteArray, int index, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4)
{
	char pipe =' ';

	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle1);
	printf("%-40c|\n", pipe);
	printf("%-40s|\n", eClienteArray[index].nombre);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle2);
	printf("%-40c|\n", pipe);
	printf("%-40s|\n", eClienteArray[index].apellido);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle3);
	printf("%-40c|\n", pipe);
	printf("%-40s|\n", eClienteArray[index].cuil);
	printf("****************************************|\n");
	printf("%-40s|\n", fieldTitle4);
	printf("%-40c|\n", pipe);
	printf("%-40d|\n", eClienteArray[index].ideCliente);
	printf("****************************************|\n");
}

int generateIdeCliente()
{
    static int id=1;

    return id++;
}

int findeClienteById(eCliente* eClienteArray, int arrayCLength, int id)
{
    int i;
    int retCode = -1;
    for(i = 0; i < arrayCLength; i++)
    {
        if(eClienteArray[i].ideCliente == id && eClienteArray[i].isEmpty == NON_EMPTY)
        {
        	retCode = i;
        }
    }
    return retCode;
}


int modifyeCliente(eCliente* eClienteArray, int arrayCLength)
{
	int retCode = -1;
	int index;
	int option;
	int id;
	int members;
	char subMenu[] =
				"\n\n1 MODIFICAR NOMBRE\
				 \n\n2 MODIFICAR APELLIDO\
				 \n\n3 MODIFICAR CUIL\
				 \n\n4 SALIR\
				 \n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";
	members = showListeCliente(eClienteArray,arrayCLength,"NOMBRE", "APELLIDO","CUIL", "ID");

	if(members == -1)
	{
		showMessage("No hay clientes cargados aun!");
		system("pause");
	}else
	{

	getNaturalNumber(&id,"Ingrese el id del cliente a modificar: ","Error. El Id solo puede ser numerico",3);
	index = findeClienteById(eClienteArray,arrayCLength,id);

	while(index == -1)
	{
		showMessage("Debe ingresar ID valido. Intente nuevamente: ");
		showListeCliente(eClienteArray,arrayCLength,"NOMBRE", "APELLIDO","CUIL", "ID");
		getNaturalNumber(&id,"Ingrese el id del cliente a modificar: ","Error. El Id solo puede ser numerico",3);
		index = findeClienteById(eClienteArray,arrayCLength,id);
	}

	showeCliente(eClienteArray,index,"NOMBRE A MODIFICAR", "APELLIDO A MODIFICAR","CUIL A MODIFICAR", "ID");

	while(option != 4)
	{
	getValidOption(&option, subMenu,mensajeError,1,4,3);
		switch(option)
		{
		case 1:
			getAlphaString(eClienteArray[index].nombre, "\nIngrese el nuevo nombre: ", "\nError. El nombre solo debe contener letras.");
			showMessage("\n Los nuevos datos son: ");
			showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
			retCode = 1;
			fflush(stdin);
			system("pause");
		break;
		case 2:
			getAlphaString(eClienteArray[index].apellido, "\nIngrese el nuevo apellido: ", "\nError. El apellido solo debe contener letras.");
			showMessage("\n Los nuevos datos son: ");
			showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
			retCode = 1;
			fflush(stdin);
			system("pause");
		break;
		case 3:
			getAlphaNumericCuil(eClienteArray[index].cuil, "\nIngrese el nuevo CUIL: ","\nError.El CUIL solo puede contener guiones y numeros! Intente de nuevo: ");
			showMessage("\n Los nuevos datos son: ");
			showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
			retCode = 1;
			fflush(stdin);
			system("pause");
		break;
		case 4:
			break;
		}
	}

	}

	return retCode;
}

int showListeCliente(eCliente* eClienteArray, int arrayCLength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4)
{
	int retCode = -1;
	int i;
	int emptyPlaces = 0;

	for(i=0;i<arrayCLength;i++)
	{
		if(eClienteArray[i].isEmpty==EMPTY)
		{
			emptyPlaces ++;
			continue;
		}
		else
		{
		printf("%-20s|", fieldTitle1);
		printf("%-40s|", eClienteArray[i].nombre);
		printf("%-20s|", fieldTitle2);
		printf("%-40s|", eClienteArray[i].apellido);
		printf("%-10s|", fieldTitle3);
		printf("%-10s|", eClienteArray[i].cuil);
		printf("%-5s|", fieldTitle4);
		printf("%-5d|", eClienteArray[i].ideCliente);
		printf("\n");
		}
	}

	if(emptyPlaces < arrayCLength)
	{
		retCode = 0;
	}

	return retCode;
}


int deleteeClienteById(eCliente* eClienteArray,int arrayCLength, int id)
{
    int i;
    int retCode = -1;

    for(i = 0; i < arrayCLength; i++)
    {
        if(eClienteArray[i].ideCliente == id && eClienteArray[i].isEmpty == NON_EMPTY)
        {
        	eClienteArray[i].isEmpty = EMPTY;

        	retCode = 0;
        }
    }
    return retCode;
}

char getConfirmationeCliente(char* message)
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

int checkIfEmptyeCliente(eCliente* eClienteArray ,int arrayCLength)
{
    int i;
    int retCode = -1;
    int countNonEmpty = 0;
    for(i = 0; i < arrayCLength; i++)
    {
    	if(eClienteArray[i].isEmpty == NON_EMPTY)
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


