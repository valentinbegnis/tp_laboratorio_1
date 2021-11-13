/*
 ============================================================================
 Author      : Valentin Begnis
 Description : Trabajo Práctico N°1
 ============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);

    char seguir = 's';
    float a, b;
    float resultadoSuma, resultadoResta, resultadoDividir, resultadoMultiplicacion;
    unsigned long int resultadoFactorialUno, resultadoFactorialDos;

    int pidioPrimerOperando = 0, pidioSegundoOperando = 0;
    int realizoCalculos = 0;
    int informoResultados = 0;
    int divisionExitosa = 0;
    int factorialExitosoUno = 0, factorialExitosoDos = 0;

    do
    {
        switch(menu(&a, &b, pidioPrimerOperando, pidioSegundoOperando))
        {
            case 1:
                if(pidioPrimerOperando == 1)
                {
                    printf("Ya ingresaste este dato\n");
                }
                else
                {
                    pidioPrimerOperando = 1;
                    pedirOperando(&a);
                }
                break;
            case 2:
                if(pidioSegundoOperando == 1)
                {
                    printf("Ya ingresaste este dato\n");
                }
                else
                {
                    pidioSegundoOperando = 1;
                    pedirOperando(&b);
                }
                break;
            case 3:
                if(pidioPrimerOperando == 1 && pidioSegundoOperando == 1 && realizoCalculos == 0)
                {
                    calcularOperaciones(&a, &b, &resultadoSuma, &resultadoResta, &divisionExitosa, &resultadoDividir, &resultadoMultiplicacion, &resultadoFactorialUno, &resultadoFactorialDos, &factorialExitosoUno, &factorialExitosoDos);
                    printf("Operaciones realizadas\n");
                    realizoCalculos = 1;
                    informoResultados = 1;
                }
                else if(realizoCalculos == 1)
                {
                    printf("Ya realizaste los calculos\n");
                }
                else if(pidioPrimerOperando == 0 && pidioSegundoOperando == 0)
                {
                    printf("Debe pedir ambos operandos para proceder\n");
                }
                else if(pidioPrimerOperando == 0)
                {
                    printf("Debe pedir el primer operando para proceder\n");
                }
                else if(pidioSegundoOperando == 0)
                {
                    printf("Debe pedir el segundo operando para proceder\n");
                }

                break;
            case 4:
                if(realizoCalculos == 1 && informoResultados == 1)
                {
                    informeResultados(&a, &b, &resultadoSuma, &resultadoResta, &divisionExitosa, &resultadoDividir, &resultadoMultiplicacion, &resultadoFactorialUno, &resultadoFactorialDos, &factorialExitosoUno, &factorialExitosoDos);
                    pidioPrimerOperando = 0;
                    pidioSegundoOperando = 0;
                    realizoCalculos = 0;
                    informoResultados = 0;
                }
                else if(realizoCalculos == 0)
                {
                    printf("No se pueden informar los resultados sin primero hacer los calculos...\n");
                }
                break;
            case 5:
                printf("Saliste\n");
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

        printf("\nPresione cualquier tecla para continuar...");
        __fpurge(stdin);
        getchar();

    }while(seguir == 's');

    return EXIT_SUCCESS;
}
