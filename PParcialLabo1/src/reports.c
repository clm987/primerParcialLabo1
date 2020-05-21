/*DESCRIPCION: IMPLEMENTACION DE FUNCIONES PARA EL MANEJO DE REPORTES
 *AUTOR: CARLOS LOPEZ
 */
#include "reports.h"

#define QTYCLIENTE 50
#define QTYPRESTAMO 50
#define EMPTY 0
#define NON_EMPTY 1


int showMaxPrestamosActivos(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength)
{
	int retCode = -1;
	int i;
	int members;
	int membersPrest;
	int index;
	int idMax;
	int max;
	int flagg = 0;
	int prestActivos = 0;

	members = checkIfEmptyeCliente(eClienteArray,arrayCLength);
	membersPrest = checkIfEmptyePrestamo(ePrestamoArray,arrayPLength);
	if(members == -1 || membersPrest == -1)
	{
		showMessage("No hay clientes con prestamos cargados aun");
		system("pause");
	}else
	{

		for(i=0; i<arrayCLength; i++)
		{
		prestActivos = countPrestamosActivosCliente(ePrestamoArray,arrayPLength,eClienteArray[i].ideCliente);
			if(i==0)
			{
				max = prestActivos;
				idMax = eClienteArray[i].ideCliente;
			}
			else if(prestActivos > max)
			{
				max = prestActivos;
				idMax = eClienteArray[i].ideCliente;
				flagg = 1;
			}
		}

	if(flagg == 0)
	{

		showMessage("Todos los clientes tienen la misma cantidad de Activos!");
		system("pause");
	}else
	{
	index = findeClienteById(eClienteArray,arrayCLength,idMax);
	showMessage("CLIENTE CON MAS PRESTAMOS ACTIVOS\n");
	showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
	system("pause");
	}

	retCode = 1;
	}

return retCode;
}


int countPrestamosActivosCliente(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente)
{
	int i;
	int countPresActivos = 0;

		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].idCliente == idCliente)
				{
					if(ePrestamoArray[i].estado == ACTIVO)
					{
						countPresActivos++;
					}
				}
			continue;
			}
		countPresActivos = -1;

		}
	return countPresActivos;
}

int showMaxPrestamosSaldados(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength)
{
	int retCode = -1;
	int i;
	int members;
	int index;
	int idMax;
	int max;
	int prestSaldados = 0;

	members = checkIfEmptyeCliente(eClienteArray,arrayCLength);
	if(members == -1)
	{
		showMessage("No hay clientes cargados aun");
		system("pause");
	}else
	{

		for(i=0; i<arrayCLength; i++)
		{
		prestSaldados = countPrestamosSaldadosCliente(ePrestamoArray,arrayPLength,eClienteArray[i].ideCliente);
			if(i==0)
			{
				max = prestSaldados;
				idMax = eClienteArray[i].ideCliente;
			}
			else if(prestSaldados > max)
			{
				max = prestSaldados;
				idMax = eClienteArray[i].ideCliente;
			}
		}

	index = findeClienteById(eClienteArray,arrayCLength,idMax);

	if(prestSaldados == -1)
	{
		showMessage("No se han saldado prestamos aun!\n");
		system("pause");
	}
	else
	{
		showMessage("CLIENTE CON MAS PRESTAMOS SALDADOS\n");
		showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
		system("pause");
	}
	retCode = 1;
	}

return retCode;
}

int countPrestamosSaldadosCliente(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente)
{
	int i;
	int countPresSaldados = 0;

		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].idCliente == idCliente)
				{
					if(ePrestamoArray[i].estado == SALDADO)
					{
						countPresSaldados++;
					}
				}
			continue;
			}
			countPresSaldados = -1;
		}
	return countPresSaldados;
}

int countPrestamosActivosGivenAmount(ePrestamo* ePrestamoArray,int arrayPLength, float amount)
{
	int i;
	int countPres = 0;
		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].estado == ACTIVO)
				{
					if((ePrestamoArray[i].importe) > amount)
					{
						countPres++;
					}

				}

			}
		continue;
		}
	return countPres;
}

void showCountPrestAmount(ePrestamo* ePrestamoArray, int arrayPLength)
{
	int contPrestamos = 0;
	int members;
	float limit;

	members = checkIfEmptyePrestamo(ePrestamoArray,arrayPLength);
	if(members == -1)
	{
		showMessage("No hay prestamos cargados aun");
		system("pause");
	}
	else
	{
		getFloatNumber(&limit, "\nIngrese el importe limite: ", "\nError. El importe solo debe contener numeros.",3);
		contPrestamos = countPrestamosActivosGivenAmount(ePrestamoArray,arrayPLength,limit);
		if(contPrestamos == 0)
		{
			showMessage("No hay prestamos por encima de ese monto");
			system("pause");
		}
		else
		{
			showMessage("CANTIDAD DE PRESTAMOS POR ENCIMA DE ESE MONTO");
			printf("**** %27d                              ****\n",contPrestamos);
			system("pause");
		}
	}
}


int showMaxPrestamosAlta(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength)
{
	int retCode = -1;
	int i;
	int members;
	int membersPrest;
	int index;
	int idMax;
	int max;
	int flagg = 0;
	int prestamosAlta = 0;

	members = checkIfEmptyeCliente(eClienteArray,arrayCLength);
	membersPrest = checkIfEmptyePrestamo(ePrestamoArray,arrayPLength);
	if(members == -1 || membersPrest == -1)
	{
		showMessage("No hay clientes con prestamos cargados aun");
		system("pause");
	}else
	{

		for(i=0; i<arrayCLength; i++)
		{
			prestamosAlta = countPrestamosAlta(ePrestamoArray,arrayPLength,eClienteArray[i].ideCliente);
			if(i==0)
			{
				max = prestamosAlta;
				idMax = eClienteArray[i].ideCliente;
			}
			else if(prestamosAlta > max)
			{
				max = prestamosAlta;
				idMax = eClienteArray[i].ideCliente;
				flagg = 1;
			}
		}

	if(flagg == 0)
	{

		showMessage("Todos los clientes tienen la misma cantidad de Prestamos!");
		system("pause");
	}else
	{
	index = findeClienteById(eClienteArray,arrayCLength,idMax);
	showMessage("CLIENTE CON MAS PRESTAMOS ACTIVOS\n");
	showeCliente(eClienteArray,index,"NOMBRE", "APELLIDO","CUIL", "ID");
	system("pause");
	}

	retCode = 1;
	}

return retCode;
}

int countPrestamosAlta(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente)
{
	int i;
	int countPresAlta = 0;

		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].idCliente == idCliente)
				{
						countPresAlta++;
				}
			continue;
			}
			countPresAlta = -1;

		}
	return countPresAlta;
}


int showMaxPrestamos12Cuotas(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength)
{
	int retCode = -1;
	int members;
	int membersPrest;
	int prestamos12saldados = 0;

	members = checkIfEmptyeCliente(eClienteArray,arrayCLength);
	membersPrest = checkIfEmptyePrestamo(ePrestamoArray,arrayPLength);
	if(members == -1 || membersPrest == -1)
	{
		showMessage("No hay clientes con prestamos cargados aun");
		system("pause");
	}else
	{
			prestamos12saldados = countPrestamosSaldados12(ePrestamoArray,arrayPLength);
			if(prestamos12saldados ==0)
			{
				showMessage("No hay prestamos de 12 cuotas saldados aun");
				system("pause");
			}
			else
			{
				showMessage("CANTIDAD DE PRESTAMOS 12 SALDADOS");
				printf("**** %27d                              ****\n",prestamos12saldados);
				retCode = 1;
				system("pause");
			}
	}


return retCode;
}

int countPrestamosSaldados12(ePrestamo* ePrestamoArray,int arrayPLength)
{
	int i;
	int countPres = 0;
		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].estado == SALDADO)
				{
					if((ePrestamoArray[i].cuotas) == 12)
					{
						countPres++;
					}

				}

			}
		continue;
		}
	return countPres;
}


void showCountPrestCuotas(ePrestamo* ePrestamoArray, int arrayPLength)
{
	int contPrestamos = 0;
	int members;
	int cuotas;

	members = checkIfEmptyePrestamo(ePrestamoArray,arrayPLength);
	if(members == -1)
	{
		showMessage("No hay prestamos cargados aun");
		system("pause");
	}
	else
	{
		getNaturalNumber(&cuotas, "\nIngrese las cuotas: ","\nError.Las cuotas solo pueden contener numeros",3);
		contPrestamos = countPrestamosActivosPorCuotas(ePrestamoArray,arrayPLength,cuotas);
		if(contPrestamos == 0)
		{
			showMessage("No hay prestamos activos con ese numero de cuotas");
			system("pause");
		}
		else
		{
			showMessage("CANTIDAD DE PRESTAMOS ACTIVOS CON ESE NUMERO DE CUOTAS");
			printf("**** %27d                              ****\n",contPrestamos);
			system("pause");
		}
	}
}

int countPrestamosActivosPorCuotas(ePrestamo* ePrestamoArray,int arrayPLength, int cuotas)
{
	int i;
	int countPres = 0;
		for(i=0; i<arrayPLength; i++)
		{
			if(ePrestamoArray[i].isEmpty == NON_EMPTY)
			{
				if(ePrestamoArray[i].estado == ACTIVO)
				{
					if((ePrestamoArray[i].cuotas) == cuotas)
					{
						countPres++;
					}

				}

			}
		continue;
		}
	return countPres;
}
