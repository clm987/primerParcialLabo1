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

	//DATOS HARCODEO DE CLIENTES

	hardCodeFunctionCliente(eClienteArray,0,"CARLOS","LOPEZ","20-35415147-5",1,NON_EMPTY);
	hardCodeFunctionCliente(eClienteArray,1,"JUAN","PEREZ","20-27415147-5",2,NON_EMPTY);
	hardCodeFunctionCliente(eClienteArray,2,"MIGUEL","GONZALEZ","36-35415147-5",3,NON_EMPTY);
	hardCodeFunctionCliente(eClienteArray,3,"ANDRE","MORENO","33-35415147-5",4,NON_EMPTY);

	//DATOS HARCODEO DE PRESTAMOS

	hardCodeFunctionPrestamo(ePrestamoArray,0,30000,12,1,1,1,NON_EMPTY);
	hardCodeFunctionPrestamo(ePrestamoArray,1,50000,22,1,2,2,NON_EMPTY);
	hardCodeFunctionPrestamo(ePrestamoArray,2,15000,24,1,3,3,NON_EMPTY);
	hardCodeFunctionPrestamo(ePrestamoArray,3,25000,10,1,4,4,NON_EMPTY);
	hardCodeFunctionPrestamo(ePrestamoArray,4,75000,24,1,5,4,NON_EMPTY);


	int option = 0;
	int option1 = 0;
	int option2 = 0;
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
						\n\n9 INFORMES DE CLIENTES\
						\n\n10 INFORMES DE PRESTAMOS\
						\n\n11 SALIR\
						\n\n Ingrese una opcion: ";
	char mensajeError[] = "Error. Debe ingresar un opcion valida";
	char SubmenuDeOpciones[] =
							"\n\n1 CLIENTE CON MAS PRESTAMOS ACTIVOS\
							\n\n2 CLIENTE CON MAS PRESTAMOS SALDADOS\
							\n\n3 CLIENTE CON MAS PRESTAMOS DADOS DE ALTA\
							\n\n Ingrese una opcion: ";
	char SunMenumensajeError[] = "Error. Debe ingresar un opcion valida";
	char SubmenuDeOpcionesPrestamos[] =
								"\n\n1 PRESTAMOS POR SOBRE UN MONTO\
								\n\n2  PRESTAMOS DE 12 CUOTAS SALDADOS\
								\n\n3  PRESTAMOS POR CANTIDAD DE CUOTAS\
								\n\n Ingrese una opcion: ";
	char SunMenumensajeErrorPrestamos[] = "Error. Debe ingresar un opcion valida";


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
						showMessage("OPCIONES DE REPORTE DE CLIENTES");
						getValidOption(&option1, SubmenuDeOpciones,SunMenumensajeError,1,3,3);
						switch(option1)
						{
						case 1:
						showMaxPrestamosActivos(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						break;
						case 2:
						showMaxPrestamosSaldados(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						break;
						case 3:
						showMaxPrestamosAlta(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						break;
						}
						break;
					case 10:
						showMessage("OPCIONES DE REPORTE DE PRESTAMOS");
						getValidOption(&option2, SubmenuDeOpcionesPrestamos,SunMenumensajeErrorPrestamos,1,3,3);
						switch(option2)
						{
						case 1:
						showCountPrestAmount(ePrestamoArray,QTYPRESTAMO);
						break;
						case 2:
						showMaxPrestamos12Cuotas(ePrestamoArray,QTYPRESTAMO,eClienteArray,QTYCLIENTE);
						break;
						case 3:
							showCountPrestCuotas(ePrestamoArray,QTYPRESTAMO);
						break;
						}
						break;
					case 11:
						break;
					}
				}
	return 0;
}
