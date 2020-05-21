/*DESCRIPCION: PROTOTIPOS DE FUNCIONES PARA EL MANEJO DE CLIENTES
 *AUTOR: CARLOS LOPEZ
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

#define QTYCLIENTE 50
#define EMPTY 0
#define NON_EMPTY 1

//Estructura de datos para agrupar datos de cada cliente.

typedef struct{
	char nombre[64];
	char apellido[64];
	char cuil[64];
	int ideCliente;
	int isEmpty;
}eCliente;

/**
 * \brief : Setea el array de clientes en estado vacio (EMPTY = 0)
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes.
 * \param value: constante para setear el camnpo isEmpty.
 * \return : esta funcion no retorna nada.
 */
void seteClienteStatus(eCliente* eClienteArray,int arrayClenght,int value);

/**
 * \brief : Encuentra una posicion vacia en el array de clientes (con el campo isEmpty en EMPTY
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes.
 * \param value: constante para setear el camnpo isEmpty en EMPTY
 * \return : retorna un entero en caso que se necesite controlar ejecucion
 */
int findEmptyPlace(eCliente* eClienteArray,int arrayClenght, int value);

/**
 * \brief : Da de alta a un cliente con los valores ingresados por el usuario
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes.
 * \return : retorna un entero en caso que se necesite controlar ejecucion
 */
int seteCliente(eCliente* eClienteArray, int arrayClenght);

/**
 * \brief : Genera el id incremental de clientes y la devuelve
 * \return : devuelve un entero con el id generado
 */
int generateIdeCliente();

/**
 * \brief : recibe un puntero a char con un mensaje y lo muestra con el formato estadarizado.
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \param fieldTitle1:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle2:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle3:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle4:puntero a char con mensaje a ser utilizado como titulo
 * \return : esta funcion no retorna nada.
 */
void showeCliente(eCliente* eClienteArray, int index, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4);

/**
 * \brief : Ubica un cliente por id en el array de clientes
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \param id: entero con la id de cliente
 * \return : retorna un entero con la posicion del cliente en el array de clientes
 */
int findeClienteById(eCliente* eClienteArray, int arrayCLength, int id);

/**
 * \brief :permite la modificacion de los datos del cliente
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \return : retorna un entero para control de ejecucion
 */
int modifyeCliente(eCliente* eClienteArray, int arrayCLength);

/**
 * \brief : recibe un puntero a char con un mensaje y lo muestra con el formato estadarizado.
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \param fieldTitle1:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle2:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle3:puntero a char con mensaje a ser utilizado como titulo
 * \param fieldTitle4:puntero a char con mensaje a ser utilizado como titulo
 * \return :retorna un entero para control de ejecucion
 */
int showListeCliente(eCliente* eClienteArray, int arrayCLength, char* fieldTitle1, char* fieldTitle2, char* fieldTitle3,char* fieldTitle4);

/**
 * \brief : recibe un puntero a char con un mensaje y lo muestra con el formato estadarizado.
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \param id: entero con la id de cliente
 * \return : retorna un entero para control de ejecucion
 */
int deleteeClienteById(eCliente* eClienteArray,int arrayCLength, int id);

/**
 * \brief : recibe un puntero a char con un mensaje y pide confirmacion que es devuelta en un char
 * \param : *mensajes puntero a char con el mensaje que se mostrar� al usuario.
 * \return : retorna un char con la respuesta del usuario
 */
char getConfirmationeCliente(char* message);

/**
 * \brief : recorre el array de clientes para validar si esta vacio
 * \param eCliente* : puntero de array de clientes
 * \param arrayClenght: longitud del array de clientes
 * \return :retorna un entero para control de ejecucion
 */
int checkIfEmptyeCliente(eCliente* eClienteArray ,int arrayCLength);

void hardCodeFunctionCliente(eCliente* eClienteArray, int index, char* apellidoTest, char* nombreTest, char* cuilTest, int ideClienteTest, int isEmptyTest);

#endif /* ECLIENTE_H_ */
