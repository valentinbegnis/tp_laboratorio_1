#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "Funciones.h"

int menu(float* x, float* y, int flagRecibidaDeUno, int flagRecibidaDeDos)
{
    int opcion;
    system("clear");

    if(x != NULL && y != NULL)
    {
        printf("\tCalculadora\t\n\n");
        if(flagRecibidaDeUno == 0 && flagRecibidaDeDos == 0)
        {
            printf("1.Ingrese un numero(A=x)\n");
            printf("2.Ingrese un numero(B=y)\n");
        }
        else if(flagRecibidaDeUno == 1 && flagRecibidaDeDos == 0)
        {
            printf("1.Ingrese un numero(A=%.2f)\n", *x);
            printf("2.Ingrese un numero(B=y)\n");
        }
        else if(flagRecibidaDeUno == 0 && flagRecibidaDeDos == 1)
        {
            printf("1.Ingrese un numero(A=x)\n");
            printf("2.Ingrese un numero(B=%.2f)\n", *y);
        }
        else
        {
            printf("1.Ingrese un numero(A=%.2f)\n", *x);
            printf("2.Ingrese un numero(B=%.2f)\n", *y);
        }

        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");

        printf("\nIngrese una opcion: ");
        __fpurge(stdin);
        scanf("%d", &opcion);
        printf("\n");
    }
    return opcion;
}

int pedirOperando(float* numero)
{
    int todoOk = 0;
    if(numero != NULL)
    {
        validarEntrada(numero);
        todoOk = 1;
    }
    return todoOk;
}

float validarEntrada(float *entradaAValidar)
{
    int esNumero;
    if(entradaAValidar != NULL)
    {
        printf("Ingrese un operando: ");
        __fpurge(stdin);
        esNumero = scanf("%f", entradaAValidar);
        while(!esNumero)
        {
            printf("\nError, tiene que ser un numero: ");
            __fpurge(stdin);
            esNumero = scanf("%f", entradaAValidar);
        }
    }
    return *entradaAValidar;
}
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
int calcularOperaciones(float* x, float* y, float* resSuma, float* resResta, int* sePudoDividir, float* resDividir, float* resMultiplicacion, unsigned long int* resFactorialUno, unsigned long int* resFactorialDos, int* sePudoHacerFactUno, int* sePudoHacerFactDos)
{
    int todoOk = 0;
    if(x != NULL && y != NULL && resSuma != NULL && resResta != NULL && sePudoDividir != NULL && resDividir != NULL && resMultiplicacion != NULL && resFactorialUno != NULL && resFactorialDos != NULL && sePudoHacerFactUno != NULL && sePudoHacerFactDos != NULL)
    {
        *resSuma = suma(*x, *y);
        *resResta = resta(*x, *y);
        *sePudoDividir = dividir(*x, *y, resDividir);
        *resMultiplicacion = multiplicar(*x, *y);
        *sePudoHacerFactUno = factorial(*x, resFactorialUno);
        *sePudoHacerFactDos = factorial(*y, resFactorialDos);
        todoOk = 1;
    }
    return todoOk;
}

int informeResultados(float* x, float* y, float* resSuma, float* resResta, int* sePudoDividir, float* resDividir, float* resMultiplicacion, unsigned long int* resFactorialUno, unsigned long int* resFactorialDos, int* sePudoHacerFactUno, int* sePudoHacerFactDos)
{
    int todoOk = 0;
    if(x != NULL && y != NULL && resSuma != NULL && resResta != NULL && sePudoDividir != NULL && resDividir != NULL && resMultiplicacion != NULL && resFactorialUno != NULL && resFactorialDos != NULL && sePudoHacerFactUno != NULL && sePudoHacerFactDos != NULL)
    {
        printf("Resultado suma: %.2f\n", *resSuma);
        printf("Resultado resta: %.2f\n", *resResta);

        if(*sePudoDividir == 1)
        {
            printf("Resultado de la division: %.2f\n", *resDividir);
        }
        else
        {
            printf("No se pudo efectuar la division\n");
        }

        printf("Resultado de la multiplicacion: %.2f\n", *resMultiplicacion);

        if(*sePudoHacerFactUno == 1 && *sePudoHacerFactDos == 1)
        {
            printf("Resultado del factorial de %.2f es: %lu ", *x, *resFactorialUno);
            printf("y el factorial de %.2f es: %lu\n", *y, *resFactorialDos);
        }
        else if(*sePudoHacerFactUno == 1 && *sePudoHacerFactDos == 0)
        {
            printf("Resultado del factorial de %.2f es: %lu ", *x, *resFactorialUno);
            printf("y el factorial de %.2f no se puede calcular\n", *y);
        }
        else if(*sePudoHacerFactUno == 0 && *sePudoHacerFactDos == 1)
        {
            printf("No se puede calcular el factorial de %.2f ", *x);
            printf("y el factorial de %.2f es: %lu\n", *y, *resFactorialDos);
        }
        else if(*sePudoHacerFactUno == 0 && *sePudoHacerFactDos == 0)
        {
            printf("No se pueden calcular los factoriales\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

float suma(float x, float y)
{
    float sumar;
    sumar = x + y;

    return sumar;
}

float resta(float x, float y)
{
    float restar;
    restar = x - y;

    return restar;
}

int dividir(float x, float y, float* resDividir)
{
    int todoOk = 0;
    if(resDividir != NULL)
    {
        if(y != 0)
        {
            *resDividir = x / y;
            todoOk = 1;
        }
    }
    return todoOk;
}

float multiplicar(float x, float y)
{
    float multiplicacion;
    multiplicacion = x * y;

    return multiplicacion;
}

int factorial(float z, unsigned long int* resFactorial)
{
    int todoOk = 0;
    int numEntero;
    float numero;

    numEntero = z;
    numero = numEntero;

    *resFactorial = 1;

    if(resFactorial != NULL)
    {
        if(numero > 0 && numero < 13)
        {
            if(z == numero)
            {
                for(int i = *resFactorial; i <= numero; i++)
                {
                    *resFactorial *= i;
                }
                todoOk = 1;
            }
        }
        else if(numero == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
