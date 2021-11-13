#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @fn int menu(float*, float*, int, int)
 * @brief Muestra el menu de opciones
 *
 * @param x Recibe primer operando
 * @param y	Recibe segundo operando
 * @param flagRecibidaDeUno Bandera para actualizar primer operando
 * @param flagRecibidaDeDos Bandera para actualizar segundo operando
 * @return Opcion elegida
 */
int menu(float*, float*, int, int);
/**
 * @fn int pedirOperando(float*)
 * @brief Llama la funcion validarEntrada
 *
 * @param Direccion de memoria del operando
 * @return Evalua el correcto funcionamiento de la funcion
 */
int pedirOperando(float*);
/**
 * @fn float validarEntrada(float*)
 * @brief Pide un operando al usuario y valida que sea un numero
 *
 * @param entradaAValidar Entrada a validar
 * @return Operando
 */
float validarEntrada(float*);
/**
 * @fn int calcularOperaciones(float*, float*, float*, float*, int*, float*, float*, unsigned long int*, unsigned long int*, int*, int*)
 * @brief Llama a las funciones de calculo
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @param resSuma Resultado de la suma
 * @param resResta Resultado de la resta
 * @param sePudoDividir Evalua si se pudo efectuar la division
 * @param resDividir Resultado de la division
 * @param resMultiplicacion Resultado de la multiplicacion
 * @param resFactorialUno Resultado factorial del primer operando
 * @param resFactorialDos Resultado factorial del segundo operando
 * @param sePudoHacerFactUno Evalua si se pudo calcular el factorial del primer operando
 * @param sePudoHacerFactDos Evalua si se pudo calcular el factorial del segundo operando
 * @return Evalua el correcto funcionamiento de la funcion
 */
int calcularOperaciones(float*, float*, float*, float*, int*, float*, float*, unsigned long int*, unsigned long int*, int*, int*);
/**
 * @fn int informeResultados(float*, float*, float*, float*, int*, float*, float*, unsigned long int*, unsigned long int*, int*, int*)
 * @brief Muestra los resultados de todas las operaciones
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @param resSuma Resultado de la suma
 * @param resResta Resultado de la resta
 * @param sePudoDividir Evalua si se pudo efectuar la division
 * @param resDividir Resultado de la division
 * @param resMultiplicacion Resultado de la multiplicacion
 * @param resFactorialUno Resultado factorial del primer operando
 * @param resFactorialDos Resultado factorial del segundo operando
 * @param sePudoHacerFactUno Evalua si se pudo calcular el factorial del primer operando
 * @param sePudoHacerFactDos Evalua si se pudo calcular el factorial del segundo operando
 * @return Evalua el correcto funcionamiento de la funcion
 */
int informeResultados(float*, float*, float*, float*, int*, float*, float*, unsigned long int*, unsigned long int*, int*, int*);
/**
 * @fn float suma(float, float)
 * @brief Realiza la suma de los operandos
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @return Resultado de la suma
 */
float suma(float, float);
/**
 * @fn float resta(float, float)
 * @brief Realiza la resta de los operandos
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @return Resultado de la resta
 */
float resta(float, float);
/**
 * @fn int dividir(float, float, float*)
 * @brief Realiza la division de los operandos
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @param resDividir Resultado de la division
 * @return Evalua el correcto funcionamiento de la funcion
 */
int dividir(float, float, float*);
/**
 * @fn float multiplicar(float, float)
 * @brief Realiza la multiplicacion de los operandos
 *
 * @param x Primer operando
 * @param y Segundo operando
 * @return Resultado de la multiplicacion
 */
float multiplicar(float, float);
/**
 * @fn int factorial(float, unsigned long int*)
 * @brief Realiza el factorial del operando que recibe por parametro
 *
 * @param z Operando
 * @param resFactorial Resultado de factorial
 * @return Evalua el correcto funcionamiento de la funcion
 */
int factorial(float, unsigned long int*);

#endif /* FUNCIONES_H_ */
