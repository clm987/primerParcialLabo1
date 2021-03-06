/*DESCRIPCION: PROTOTIPOS DE FUNCIONES PARA EL MANEJO DE REPORTES
 *AUTOR: CARLOS LOPEZ
 */

#ifndef REPORTS_H_
#define REPORTS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eCliente.h"
#include "ePrestamo.h"
#include "IOdata.h"

/**
 * \brief :  encuentra el cliente con mayor cantidad de prestamos saldados
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param idCliente: entero con el id de cliente
 * \return : retorna en contador de prestamos saldados
 */
int countPrestamosSaldadosCliente(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente);

/**
 * \brief : muestra el cliente con mayor cantidad de prestamos saldados
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param eCliente* : puntero de array de prestamos
 * \param arrayCLength: longitud del array de prestamos.
 * \return : retorna un entero en caso que se necesite controlar ejecucion
 */
int showMaxPrestamosSaldados(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength);

/**
 * \brief :  encuentra el cliente con mayor cantidad de prestamos activos
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param idCliente: entero con el id de cliente
 * \return : retorna en contador de prestamos activos
 */
int countPrestamosActivosCliente(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente);

/**
 * \brief : muestra el cliente con mayor cantidad de prestamos activos
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param eCliente* : puntero de array de prestamos
 * \param arrayCLength: longitud del array de prestamos.
 * \return : retorna un entero en caso que se necesite controlar ejecucion
 */
int showMaxPrestamosActivos(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength);

/**
 * \brief : cuenta la cantidad de prestamos por encima de un monto determinado por el usuario
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param amount:float con el monto limite estipulado
 * \return : retorna en contador de prestamos por encima del limite estipulado por el usuario
 */
int countPrestamosActivosGivenAmount(ePrestamo* ePrestamoArray,int arrayPLength, float amount);

/**
 * \brief : muestra la cantidad de prestamos por encima de un monto determinado por el usuario
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos..
 * \return : no retorna nada
 */
void showCountPrestAmount(ePrestamo* ePrestamoArray, int arrayPLength);

int showMaxPrestamosAlta(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength);

int countPrestamosAlta(ePrestamo* ePrestamoArray,int arrayPLength,int idCliente);

int showMaxPrestamos12Cuotas(ePrestamo* ePrestamoArray, int arrayPLength, eCliente* eClienteArray, int arrayCLength);

int countPrestamosSaldados12(ePrestamo* ePrestamoArray,int arrayPLength);

int countPrestamosActivosPorCuotas(ePrestamo* ePrestamoArray,int arrayPLength, int cuotas);

void showCountPrestCuotas(ePrestamo* ePrestamoArray, int arrayPLength);


#endif /* REPORTS_H_ */
