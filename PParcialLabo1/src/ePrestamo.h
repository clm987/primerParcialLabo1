/*DESCRIPCION: PROTOTIPOS DE FUNCIONES PARA EL MANEJO DE PRESTAMOS
 *AUTOR: CARLOS LOPEZ
 */

#ifndef EPRESTAMO_H_
#define EPRESTAMO_H_

#define QTYPRESTAMO 50
#define ACTIVO 1
#define SALDADO 0
#define EMPTY 0
#define NON_EMPTY 1

// ESTRUCTURA DE DATOS PARA AGRUPAR LOS DATOS DE CLIENTES

typedef struct{
	float importe;
	int cuotas;
	int estado;
	int idPrestamo;
	int idCliente;
	int isEmpty;
}ePrestamo;

/**
 * \brief : Setea el array de prestaos en estado vacio (EMPTY = 0)
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param value: constante para setear el campo isEmpty.
 * \return : esta funcion no retorna nada.
 */
void setePrestamoStatus(ePrestamo* ePrestamoArray, int arrayPLength, int value);

/**
 * \brief : Encuentra una posicion vacia en el array de prestamos (con el campo isEmpty en EMPTY
 * \param ePrestamo* : puntero de array de prestamos
 * \param arrayPLength*: longitud del array de prestamos.
 * \param value: constante para setear el camnpo isEmpty en EMPTY
 * \return : retorna un entero en caso que se necesite controlar ejecucion
 */
int findEmptyPlaceePrestamo(ePrestamo* ePrestamoArray,int arrayPLength, int value);

/**
 * \brief : Genera el id incremental de prestamos y la devuelve
 * \return : devuelve un entero con el id generado
 */
int generateIdePrestamo();

/**
 * \brief :Ubica un prestamo por id en el array de prestamos
 * \param ePrestamo* : puntero de array de clientes
 * \param arrayPLength*: longitud del array de clientes
 * \param id: entero con la id de cliente
 * \return : retorna un entero con la posicion del cliente en el array de clientes
 */
int findePrestamoById(ePrestamo* ePrestamoArray,int arrayPLength, int id);


/**
 * \brief : Muestra el listado de prestamos
 * \param ePrestamo* : puntero de array de clientes
 * \param :arrayPLength longitud del array de clientes
 * \param fieldTitle1:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle2:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle3:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle4:puntero a char con mensaje a ser utilizado como titulo
 * \return :retorna un entero para control de ejecucion
 */
int showListePrestamo(ePrestamo* ePrestamoArray, int arrayPLength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4);

/**
 * \brief : recibe un puntero a char con un mensaje y pide confirmacion que es devuelta en un char
 * \param : *mensajes puntero a char con el mensaje que se mostrará al usuario.
 * \return : retorna un char con la respuesta del usuario
 */
char getConfirmationePrestamo(char* message);

/**
 * \brief : Permite modificar el estado de prestamo a ACTIVO o SALDADO en funcion del valor dado
 * \param ePrestamo* : puntero de array de clientes
 * \param arrayPLength: longitud del array de clientes
 * \param value: constante a asignar al estado del prestamo puede ser ACTIVO o SALDADO
 * \return : esta funcion no retorna nada.
 */
void setePrestamoEstado(ePrestamo* ePrestamoArray, int arrayPLength, int value);
/**
 * \brief : recorre el array de clientes para validar si esta vacio
 * \param ePrestamo* : puntero de array de clientes
 * \param arrayPLength: longitud del array de clientes
 * \return :retorna un entero para control de ejecucion
 */
int checkIfEmptyePrestamo(ePrestamo* ePrestamoArray,int arrayPLength);

#endif /* EPRESTAMO_H_ */
