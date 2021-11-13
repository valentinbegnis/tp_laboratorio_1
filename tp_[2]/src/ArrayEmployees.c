#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "misFunciones.h"

/**
 * @brief Recorre la lista de empleados inicializando el campo isEmpty en TRUE en todas sus posiciones,
 * 		  asi indica que se encuentras vacias
 *
 * @param list Puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @return Retorna (-1) si hubo un error (puntero NULL o largo invalido) - (0) si no lo hubo
 */
int initEmployees(Employee* list, int len)
{
	int todoOk = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		todoOk = 0;
	}
	return todoOk;
}

/**
 * @brief Agrega los valores recibidos como parametro en la primera posicion libre
 * 		  de la lista de empleados
 *
 * @param list puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param id Entero que indica el id del empleado
 * @param name String con el nombre del empleado
 * @param lastName String con el apellido del empleado
 * @param salary Flotante con el sueldo del empleado
 * @param sector Entero cnn el sector del empleado
 * @return Retorna (-1) si hubo error (puntero NULL, largo invalido) o no hay espacio disponible -
 * 		   (0) si no lo hubo
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int todoOk = -1;
	int indice = buscarEspacioLibre(list, len);

	if(list != NULL && len > 0 && name != NULL && lastName != NULL)
	{
		if(indice != -1)
		{
			list[indice].id = id;

			strcpy(list[indice].name, name);
			strcpy(list[indice].lastName, lastName);

			list[indice].salary = salary;
			list[indice].sector = sector;
			list[indice].isEmpty = FALSE;

			todoOk = 0;
		}
	}
	return todoOk;
}
/**
 * @brief Busca un empleado recibiendo su id como parametro de busqueda
 *
 * @param list puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param id Entero que indica el id del empleado
 * @return Retorna la posicion del empleado si lo encuentra - (-1) en caso de error
 * 		   (puntero NULL o largo invalido) o empleado no encontrado
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int indice = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/**
 * @brief Recibe el id de un empleado por parametro y lo elimina cambiando su campo isEmpty a TRUE
 *
 * @param list puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param id Entero que indica el id del empleado
 * @return Retorna (-1) si hubo error (puntero NULL, largo invalido) o no encuentra al empleado -
 * 		   (0) si no lo hubo
 */
int removeEmployee(Employee* list, int len, int id)
{
	int todoOk = -1;
	int indice;
	int auxId;
	char confirmar;

	if(list != NULL && len > 0)
	{
		system("clear");
		printf("      ~Baja empleado~\n");
		printf("===========================\n");

		printEmployees(list, len);

		printf("\nIngrese el id del empleado que quiere dar de baja: ");
		scanf("%d", &auxId);

		indice = findEmployeeById(list, len, auxId);

		if(indice != -1)
		{
			printf("Seguro que quiere dar de baja a %s %s, id: %d? ('s' para confirmar): ",
					list[indice].name,
					list[indice].lastName,
					list[indice].id);
			__fpurge(stdin);
			scanf("%c", &confirmar);

			confirmar = tolower(confirmar);

			if(confirmar == 's')
			{
				list[indice].isEmpty = TRUE;
				todoOk = 0;
			}
			else
			{
				printf("\nSe ha cancelado la baja. ");
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
 * @brief Ordena la lista de empleados por apellido y sector de forma ascendente o descendente
 * 		  segun lo indique el parametro order
 *
 * @param list puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @param order UP (1) indica orden ascendente, DOWN (0) ascendente
 * @return Retorna (-1) si hubo error (puntero NULL, largo invalido) - (0) si no lo hubo
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int todoOk = -1;
	Employee auxSort;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(order == UP)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0 ||
						(strcmp(list[i].lastName, list[j].lastName) == 0 &&
						list[i].sector > list[j].sector))
					{
						auxSort = list[i];
						list[i] = list[j];
						list[j] = auxSort;
					}
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0 ||
						(strcmp(list[i].lastName, list[j].lastName) == 0 &&
						list[i].sector < list[j].sector))
					{
						auxSort = list[i];
						list[i] = list[j];
						list[j] = auxSort;
					}
				}
			}
		}
		todoOk = 0;
	}
	return todoOk;
}

/**
 * @brief Imprime la lista de empleados de forma encolumnada
 *
 * @param list puntero Employee* a la lista de empleados
 * @param len Entero que indica el largo de la lista
 * @return Retorna (-1) si hubo error (puntero NULL, largo invalido) - (0) si no lo hubo
 */
int printEmployees(Employee* list, int len)
{
	int todoOk = -1;

	if(list != NULL && len > 0)
	{
		printf("\t\t   ~Lista empleados~\n");
		printf("=========================================================\n");
		printf("  ID\t       Nombre\t   Apellido     Salario\t  Sector\n");
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty)
			printf(" %d     %10s    %10s   %10.2f   %4d\n",
					list[i].id,
					list[i].name,
					list[i].lastName,
					list[i].salary,
					list[i].sector
					);
		}
		todoOk = 0;
	}
	return todoOk;
}
