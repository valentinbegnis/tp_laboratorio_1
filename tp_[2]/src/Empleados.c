/*
 ============================================================================
 Name        : Empleados.c
 Author      : Begnis Valentin
 Description : Trabajo Practico Numero 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "misFunciones.h"

#define TAM 1000

int main(void)
{
	setbuf(stdout, NULL);

	char seguir = 's';
	int empleadoId = 1000;
	int seCargoUnEmpleado = 0;
	float suma = 0;
	float promedio = 0;
	int empSalarioMayorProm;

	Employee lista[TAM];
	Employee auxEmployee;

	initEmployees(lista, TAM);

	do
	{
		switch(menu())
		{
			case 1:
				if(tomarDatos(lista, TAM, &auxEmployee, &empleadoId) == -1)
				{
					printf("Error\n");
				}
				else
				{
					seCargoUnEmpleado = 1;
				}
				break;
			case 2:
				if(seCargoUnEmpleado)
				{
					if(modificarEmpleado(lista, TAM) == 0)
					{
						printf("\nModificacion exitosa\n");
					}
					else
					{
						printf("Error\n");
					}
				}
				else
				{
					printf("Realice la carga de al menos un empleado para realizar esta accion\n");
				}
				break;
			case 3:
				if(seCargoUnEmpleado)
				{
					if(removeEmployee(lista, TAM, empleadoId) == 0)
					{
						 printf("\nBaja exitosa\n");
					}
					else
					{
						printf("Error\n");
					}
				}
				else
				{
					printf("Realice la carga de al menos un empleado para realizar esta accion\n");
				}
				break;
			case 4:
				if(seCargoUnEmpleado)
				{
					printf("\n1. Listado de los empleados ordenados\n   alfabéticamente por Apellido y Sector\n\n");

					sortEmployees(lista, TAM, UP);
					printEmployees(lista, TAM);

					printf("\n");

					totalYPromSalarios(lista, TAM, &suma, &promedio);
					empSalarioMayorProm = salariosMayoresAlPromedio(lista, TAM, &promedio);

					printf("2. \nTotal salarios: %.2f\n", suma);
					printf("Promedio salarios: %.2f\n", promedio);
					printf("Empleados que superan el salario promedio: %d\n", empSalarioMayorProm);

					suma = 0;
					promedio = 0;
				}
				else
				{
					printf("Realice la carga de al menos un empleado para realizar esta accion\n");
				}
				break;
			case 5:
				seguir = 'n';
				break;
			default:
				printf("Opcion invalida\n");
		}

		printf("\nPresione cualquier tecla para continuar... ");
		__fpurge(stdin);
		getchar();

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
