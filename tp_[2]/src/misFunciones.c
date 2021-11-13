#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "misFunciones.h"
#include "ArrayEmployees.h"

int menu(void)
{
	int opcion;

	system("clear");

	printf("\t~EMPLEADOS~\n");
	printf("===========================\n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. SALIR\n");
	printf("===========================\n");

	printf("\nElegir una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * @brief
 *
 * @param list Puntero a string
 * @param len Entero que indica el largo de la lista
 * @param pFlag Puntero entero a bandera
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido) - (0) si no lo hubo
 */
int myGets(char* list, int len, int* pFlag)
{
	int todoOk = -1;
	char bufferString[51];

	if(list != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				if(*pFlag == 0)
				{
					strncpy(list, bufferString, len);
				}
				else
				{
					strncpy(list, bufferString, len);
				}
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

/**
 * @brief
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param pFlag Puntero entero a bandera
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido) - (0) si no lo hubo
 */
int myGetsStruct(Employee* list, int len, int* pFlag)
{
	int todoOk = -1;
	char bufferString[51];

	if(list != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				if(*pFlag == 0)
				{
					strncpy(list->name, bufferString, len);
				}
				else
				{
					strncpy(list->lastName, bufferString, len);
				}
				todoOk = 0;
			}
		}
	}
	return todoOk;
}

/**
 * @brief Busca un espacio libre en la lista de empleados
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @return Retorna la posicion del primer espacio libre que encuentra - (-1) en caso de error
 * 		   (puntero NULL o largo invalido) o no hay espacios libres
 */
int buscarEspacioLibre(Employee* list, int len)
{
	int indice = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/**
 * @brief Pide los datos para dar de alta un empleado
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param listEmployee Puntero Employee* a una lista auxiliar de empleados
 * @param pId Puntero entero al id del empleado
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido) o no hay espacio
 * 		   en el sistema - (0) si no lo hubo
 */
int tomarDatos(Employee* list, int len, Employee* listEmployee, int* pId)
{
	int todoOk = -1;
	int flag_myGets = 0;
	int indice;
	int retornoFlotante;
	int retornoEntero;

	if(listEmployee != NULL && len > 0 && pId != NULL)
	{
		system("clear");
		printf("     ~Alta empleado~\n");
		printf("===========================\n");

		indice = buscarEspacioLibre(list, len);

		if(indice != -1)
		{
			listEmployee->id = (*pId)++;

			printf("Ingrese el nombre: ");
			myGetsStruct(listEmployee, sizeof(listEmployee->name), &flag_myGets);

			printf("Ingrese el apellido: ");
			flag_myGets = 1;
			myGetsStruct(listEmployee, sizeof(listEmployee->lastName), &flag_myGets);

			printf("Ingrese el salario: ");
			retornoFlotante = scanf("%f", &listEmployee->salary);

			if(validarFlotante(retornoFlotante, &listEmployee->salary) == -1)
			{
				printf("\nTe quedaste sin intentos. ");
				listEmployee->id = (*pId)--;
				return todoOk = -1;
			}

			printf("Ingrese el sector: ");
			retornoEntero = scanf("%d", &listEmployee->sector);

			if(validarEntero(retornoEntero, &listEmployee->sector) == -1)
			{
				printf("\nTe quedaste sin intentos. ");
				listEmployee->id = (*pId)--;
				return todoOk = -1;
			}

			if(addEmployee(list, len, listEmployee->id, listEmployee->name, listEmployee->lastName, listEmployee->salary, listEmployee->sector) == 0)
			{
				printf("\nAlta exitosa\n");
				todoOk = 0;
			}
		}
		else
		{
			printf("\nNo hay espacio en el sistema. ");
		}
	}
	return todoOk;
}

/**
 * @brief Imprime el menu de modificaciones y permite elegir una opcion
 *
 * @return Retorna la opcion elegida
 */
int menuModificacion(void)
{
    int opcion;

    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");
    printf("5- Salir\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/**
 * @brief Permite modificar un dato de un empleado mediante su id
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido), cancela confirmacion
 * 		   o el id ingresado no existe - (0) si no lo hubo
 */
int modificarEmpleado(Employee* list, int len)
{
	int todoOk = -1;
	int indice;
	int auxId;
	char confirmar;
	char auxNombre[51];
	char auxApellido[51];
	float auxSalario;
	int auxSector;
	int flag_myGets = 0;
	int retornoId;
	int retornoFlotante;
	int retornoEntero;

	if(list != NULL && len > 0)
	{
		system("clear");
		printf(" ~Modificar datos empleado~\n");
		printf("===========================\n");

		printEmployees(list, len);

		printf("\nIngrese el id del empleado que quiere modificar: ");
		retornoId = scanf("%d", &auxId);

		if(validarEntero(retornoId, &auxId) == -1)
			{
				printf("\nTe quedaste sin intentos. ");
				return todoOk = -1;
			}

		indice = findEmployeeById(list, len, auxId);

		if(indice != -1)
		{
			printf("\nSeguro que quiere modificar un dato de %s %s, id: %d? ('s' para confirmar): ",
					list[indice].name,
					list[indice].lastName,
					list[indice].id);
			__fpurge(stdin);
			scanf("%c", &confirmar);

			confirmar = tolower(confirmar);

			if(confirmar == 's')
			{
				switch(menuModificacion())
				{
					case 1:
						printf("Ingrese nuevo nombre: ");
						myGets(auxNombre, sizeof(auxNombre), &flag_myGets);
						strcpy(list[indice].name, auxNombre);
						break;
					case 2:
						printf("Ingrese nuevo apellido: ");
						flag_myGets = 1;
						myGets(auxApellido, sizeof(auxApellido), &flag_myGets);
						strcpy(list[indice].lastName, auxApellido);
						break;
					case 3:
						printf("Ingrese una nuevo salario: ");
						retornoFlotante = scanf("%f", &auxSalario);

						if(validarFlotante(retornoFlotante, &auxSalario) == -1)
						{
							printf("\nTe quedaste sin intentos. ");
							return todoOk = -1;
						}

						list[indice].salary = auxSalario;
						break;
					case 4:
						printf("Ingrese una nuevo sector: ");
						retornoEntero = scanf("%d", &auxSector);

						if(validarEntero(retornoEntero, &auxSector) == -1)
						{
							printf("\nTe quedaste sin intentos. ");
							return todoOk = -1;
						}

						list[indice].sector = auxSector;
						break;
				}
				todoOk = 0;
			}
			else
			{
				printf("\nSe ha cancelado la modificacion. ");
			}
		}
		else
		{
			printf("\nEl id ingresado no existe. ");
		}
	}
	return todoOk;
}

/**
 * @brief Calcula el total y promedio de los salarios
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param pSum Puntero flotante a variable suma del main
 * @param pProm	Puntero flotante a variable promedio del main
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido) - (0) si no lo hubo
 */
float totalYPromSalarios(Employee* list, int len, float* pSum, float* pProm)
{
	int todoOk = -1;
	int contador = 0;

	if(list != NULL && len > 0 && pSum != NULL && pProm != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				*pSum += list[i].salary;
				contador++;
			}
		}
		*pProm = *pSum / contador;

		todoOk = 0;
	}
	return todoOk;
}

/**
 * @brief Calcula cuantos empleados superan el salario promedio
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param pProm	Puntero flotante a variable promedio del main
 * @return Retorna la cantidad de empleados que cumplen esa condicion
 */
int salariosMayoresAlPromedio(Employee* list, int len, float* pProm)
{
	int contador = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].salary > *pProm)
		{
			contador++;
		}
	}
	return contador;
}

/**
 * @brief Valida si el usuario ingresa un flotante y concede tres intentos para ingresarlo
 *
 * @param ret Retorno del scanf
 * @param number Puntero a flotante
 *
 * @return Retorna (-1) si hubo un error (puntero NULL o intentos agotados) - (0) si no lo hubo
 */
int validarFlotante(int ret, float* number)
{
	int todoOk = -1;
	int intento = 3;

	if(number != NULL)
	{
		while(ret != 1 && intento > 0)
		{
			printf("\n  ·Tienes %d intentos\n", intento);
			printf("Ingrese un valor numerico: ");
			__fpurge(stdin);
			ret = scanf("%f", number);

			intento--;
		}
		if(ret == 1)
		{
			todoOk = 0;
		}
	}
	return todoOk;
}

/**
 * @brief Valida si el usuario ingresa un entero y concede tres intentos para ingresarlo
 *
 * @param ret Retorno del scanf
 * @param number Puntero a entero
 *
 * @return Retorna (-1) si hubo un error (puntero NULL o intentos agotados) - (0) si no lo hubo
 */
int validarEntero(int ret, int* number)
{
	int todoOk = 0;

	if(number != NULL)
	{
		while(ret != 1)
		{
			printf("Ingrese un valor numerico: ");
			__fpurge(stdin);
			ret = scanf("%d", number);
		}
		if(ret == 1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

