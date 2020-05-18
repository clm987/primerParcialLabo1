/*
 ============================================================================
 Name        : PParcialLabo1.c
 Author      : CARLOS LOPEZ
 Description : ABM DE CLIENTES Y PRESTAMOS CON INFORMES
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "IOdata.h"
#include "eCliente.h"
#include "ePrestamo.h"
#include "linkerStructure.h"
#include "reports.h"

int main(void)
{
	eCliente eClienteArray[QTYCLIENTE];
	seteClienteStatus(eClienteArray, QTYCLIENTE,EMPTY);

	ePrestamo ePrestamoArray[QTYPRESTAMO];
	setePrestamoStatus(ePrestamoArray, QTYPRESTAMO, EMPTY);

	int option = 0;
	int option1 = 0;
	int flagg = 0;
	char menuDeOpciones[] =
						"\n\n1 ALTA DE CLIENTE\
						\n\n2 MODIFICACION CLIENTE\
						\n\n3 BAJA CLIENTE\
						\n\n4 ALTA PRESTAMO\
						\n\n5 SALDAR PRESTAMO\
						\n\n6 REANUDAR PRESTAMO\
						\n\n7 MOSTRAR LISTADO CLIENTES CON PRESTAMOS ACTIVOS\
						\n\n8 MOSTRAR LISTADO PRESTAMOS ACTIVOS IDENTIFICADOS POR CUIL DE CLIENTE\
						\n\n9 CLIENTE CON MAS PRESTAMOS ACTIVOS Y CLIENTE CON MAS PRESTAMOS SALDADOS\
						\n\n10 CANTIDAD DE PRESTAMOS ACTIVOS POR SOBRE UN MONTO LIMITE\
						\n\n11 SALIR\
						\n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";
	char SubmenuDeOpciones[] =
							"\n\n1 CLIENTE CON MAS PRESTAMOS ACTIVOS\
							\n\n2 CLIENTE CON MAS PRESTAMOS SALDADOS\
							\n\n Ingrese una opcion: ";
		char SunMenumensajeError[] = "Error. Debe ingresar un opcion valida";


				while(option != 11)
				{
					system("cls");
					getValidOption(&option, menuDeOpciones,mensajeError,1,11,3);

					switch (option)
					{
					case 1:
						 seteCliente(eClienteArray,QTYCLIENTE);
						 flagg = 1;
						break;
					case 2:
						modifyeCliente(eClienteArray,QTYCLIENTE);
						break;
					case 3:
						deleteMembereCliente(eClienteArray,QTYCLIENTE,ePrestamoArray, QTYPRESTAMO);
						break;
					case 4:
						if(flagg == 1)
						{
						setePrestamo(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						}else
						{
							showMessage("Aun no se han dado de alta clientes");
							system("pause");
						}

						break;
					case 5:
						modifyePrestamo(ePrestamoArray, QTYPRESTAMO, eClienteArray, QTYCLIENTE,5);
						break;
					case 6:
						modifyePrestamo(ePrestamoArray, QTYPRESTAMO, eClienteArray, QTYCLIENTE,6);
						break;
					case 7:
						showListeClientePrestamosActivos(eClienteArray,QTYCLIENTE,ePrestamoArray,QTYPRESTAMO);
						break;
					case 8:
						showListePrestamoActivo(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE,"IMPORTE","CUOTAS","ESTADO","ID","CUIL");
						break;
					case 9:
						getValidOption(&option1, SubmenuDeOpciones,SunMenumensajeError,1,2,3);
						if(option1 == 1)
						{
						showMaxPrestamosActivos(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						}
						if(option1 == 2)
						{
						showMaxPrestamosSaldados(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						}
						break;
					case 10:
						showCountPrestAmount(ePrestamoArray,QTYPRESTAMO);
						break;
					case 11:
						break;
					}
				}
	return 0;
}
