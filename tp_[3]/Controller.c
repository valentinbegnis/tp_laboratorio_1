#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "misFunciones.h"
#include "menu.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    FILE* txtFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        txtFile = fopen(path, "r");

        if(txtFile != NULL)
        {
            fallo = parser_EmployeeFromText(txtFile, pArrayListEmployee);
            fclose(txtFile);
        }
    }
    return fallo;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    FILE* binFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        binFile = fopen(path, "rb");

        if(binFile != NULL)
        {
            fallo = parser_EmployeeFromBinary(binFile, pArrayListEmployee);
            fclose(binFile);
        }
    }
    return fallo;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int fallo = 1;
    Employee* auxEmployee;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int retorno;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("-------------------Alta empleados---------------------\n");
        printf("------------------------------------------------------\n");

        auxEmployee = employee_new();

        if(auxEmployee != NULL)
        {
            employee_setId(auxEmployee, *pId);
            (*pId)++;

            printf("\nIngrese el nombre: ");
            pedirString(nombre, 128, 2);
            employee_setNombre(auxEmployee, nombre);

            printf("Ingrese las horas trabajadas: ");
            retorno = scanf("%d", &horasTrabajadas);
            validarEntero(retorno, &horasTrabajadas);
            employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

            printf("Ingrese el sueldo: ");
            retorno = scanf("%d", &sueldo);
            validarEntero(retorno, &sueldo);
            employee_setSueldo(auxEmployee, sueldo);

            ll_add(pArrayListEmployee, auxEmployee);

            fallo = 0;
        }
    }

    return fallo;
}

/** \brief Busca la posicion del empleado en base a un ID recibido por parametro
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int controller_getIndexById(LinkedList* pArrayListEmployee, int id)
{
    int idEmployee = -1;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL)
            {
                employee_getId(auxEmployee, &idEmployee);
                if(idEmployee == id)
                {
                    idEmployee = i;
                    break;
                }
            }
        }
    }
    return idEmployee;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    Employee* auxEmployee;
    int idIndice;
    int retorno;
    int opcion;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("-------------------Modificar empleado-----------------\n");
        printf("------------------------------------------------------\n");
        printf("\nIngrese el ID del empleado que desea modificar: ");
        retorno = scanf("%d", &idIndice);
        validarEntero(retorno, &idIndice);

        idIndice = controller_getIndexById(pArrayListEmployee, idIndice);
        auxEmployee = ll_get(pArrayListEmployee, idIndice);

        if(auxEmployee != NULL)
        {
            opcion = menuModificaciones();

            switch(opcion)
            {
                case 1:
                    printf("\nIngrese un nuevo nombre: ");
                    pedirString(nombre, 128, 2);
                    employee_setNombre(auxEmployee, nombre);
                    break;
                case 2:
                    printf("\nIngrese la nueva cantidad de horas trabajadas: ");
                    retorno = scanf("%d", &horasTrabajadas);
                    validarEntero(retorno, &horasTrabajadas);
                    employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
                    break;
                case 3:
                    printf("\nIngrese el nuevo sueldo: ");
                    retorno = scanf("%d", &sueldo);
                    validarEntero(retorno, &sueldo);
                    employee_setSueldo(auxEmployee, sueldo);
                    break;
                case 4:
                    printf("\nModificacion cancelada\n");
                    break;
                default:
                    printf("Debe ingresar una opcion valida\n");
            }

            if(opcion > 0 && opcion < 4)
            {
                fallo = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado es invalido\n");
        }
    }
    return fallo;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    Employee* auxEmployee;
    int idIndice;
    int retorno;

    char nombre[128];
    int id;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID del empleado que desea dar de baja: ");
        retorno = scanf("%d", &idIndice);
        validarEntero(retorno, &idIndice);

        idIndice = controller_getIndexById(pArrayListEmployee, idIndice);
        auxEmployee = ll_get(pArrayListEmployee, idIndice);

        if(auxEmployee != NULL)
        {
            if(!ll_remove(pArrayListEmployee, idIndice))
            {
                employee_getNombre(auxEmployee, nombre);
                employee_getId(auxEmployee, &id);

                printf("Diste de baja a %s, id: %d\n", nombre, id);

                fallo = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado es invalido\n");
        }
    }
    return fallo;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    int tam = ll_len(pArrayListEmployee);
    Employee* employee = NULL;

    if(pArrayListEmployee != NULL && tam > 0)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("------------------Listado de empleados----------------\n");
        printf("------------------------------------------------------\n");
        printf("  ID          Nombre       Horas trabajadas   Sueldo  \n");

        for(int i = 0; i < tam; i++)
        {
            employee = ll_get(pArrayListEmployee, i);
            employee_mostrarUno(employee);
        }

        fallo = 0;
    }
    return fallo;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    int opcion;
    int criterio;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("------------------Ordenar empleados-------------------\n");
        printf("------------------------------------------------------\n");

        opcion = menuOrdenamiento();

        switch(opcion)
        {
            case 1:
                criterio = menuCriterio();

                if(criterio == 1)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortId, 1);
                }
                else if(criterio == 2)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortId, 0);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 2:
                criterio = menuCriterio();

                if(criterio == 1)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortName, 1);
                }
                else if(criterio == 2)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortName, 0);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 3:
                criterio = menuCriterio();

                if(criterio == 1)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortHours, 1);
                }
                else if(criterio == 2)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortHours, 0);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 4:
                criterio = menuCriterio();

                if(criterio == 1)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortSalary, 1);
                }
                else if(criterio == 2)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(pArrayListEmployee, employee_sortSalary, 0);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 5:
                printf("\nOrdenamiento cancelado\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

        if(opcion > 0 && opcion < 5)
        {
            fallo = 0;
        }
    }
    return fallo;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    FILE* txtFile;
    Employee* employee;
    int id;
    char nombre[128];
    int sueldo;
    int horas;
    int tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		txtFile = fopen(path, "w");
		employee = employee_new();

		if(txtFile != NULL && employee != NULL)
		{
            fprintf(txtFile, "id,nombre,horasTrabajadas,sueldo\n");

            for(int i = 0; i < tam; i++)
            {
                employee = ll_get(pArrayListEmployee, i);
                if(employee != NULL)
                {
                    employee_getId(employee, &id);
                    employee_getNombre(employee, nombre);
                    employee_getHorasTrabajadas(employee, &horas);
                    employee_getSueldo(employee, &sueldo);

                    fprintf(txtFile,"%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                    fallo = 0;
                }
            }
            fclose(txtFile);
        }
	}
    return fallo;
}

/** \brief Guarda los datos de los empleados en un archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
	Employee* employee;
	FILE* binFile;
	int tam = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL)
	{
		binFile = fopen(path, "wb");
		employee = employee_new();

		if(employee != NULL)
		{
            for(int i = 0; i < tam; i++)
            {
                employee = ll_get(pArrayListEmployee, i);
                fwrite(employee, sizeof(Employee), 1, binFile);
            }
            fallo = 0;
		}
		fclose(binFile);
	}
	return fallo;
}

/** \brief Busca el ID mas grande y lo retorna.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_nextId(LinkedList* pArrayListEmployee)
{
    int id = 0;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        auxEmployee = ll_get(pArrayListEmployee, tam - 1);
        employee_getId(auxEmployee, &id);
    }

    return id;
}
