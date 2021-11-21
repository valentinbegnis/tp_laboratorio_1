#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

/** \ brief Permite ingresar un string y valida su largo
 *\ param string campo donde se cargara el string
 *\ param len largo maximo del string
 *\ param min largo minimo del string
 *\ return 0 si hubo error, 1 si no lo hubo
 */
int pedirString(char string[], int len, int min);

/** \ brief Valida que el dato ingresado sea un string
 *\ param str a validar
 *\ return 0 si no lo es, 1 si lo es
 */
int esSoloLetras(char str[]);

/** \ brief Valida que el dato ingresado sea un numero
 *\ param ret Entero retorno del scanf
 *\ param number Direccion de memoria del numero a validar
 *\ return 0 si no lo es, 1 si lo es
 */
int validarEntero(int ret, int* number);

#endif // MISFUNCIONES_H_INCLUDED
