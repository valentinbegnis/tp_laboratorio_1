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
    int indice;

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

            switch(menuIndice())
            {
                case 1:
                    ll_add(pArrayListEmployee, auxEmployee);
                    break;
                case 2:
                    printf("Ingrese el indice: ");
                    __fpurge(stdin);
                    scanf("%d", &indice);

                    while(indice < 0 || indice >= ll_len(pArrayListEmployee))
                    {
                        printf("Ingrese un indice correcto (de 0 a %d): ", ll_len(pArrayListEmployee) - 1);
                        scanf("%d", &indice);
                    }

                    ll_push(pArrayListEmployee, indice, auxEmployee);
                    break;
                default:
                    printf("Opcion invalida\n");
            }

            if(ll_contains(pArrayListEmployee, auxEmployee))
            {
                printf("\nEl siguiente empleado fue dado de alta:\n");
                printf("  ID          Nombre       Horas trabajadas   Sueldo  \n");
                employee_mostrarUno(auxEmployee);
                fallo = 0;
            }
            else
            {
                printf("Hubo un error dando de alta al empleado\n\n");
            }
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
    Employee* auxEmployee = NULL;
    Employee* auxEmployee2 = NULL;
    int idIndice;
    int retorno;
    int opcion;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int indice;
    char confirma;
    int flag = 1;

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
                    printf("\nIngrese un nuevo indice: ");
                    __fpurge(stdin);
                    scanf("%d", &indice);

                    while(indice < 0 || indice >= ll_len(pArrayListEmployee))
                    {
                        printf("Ingrese un indice correcto (de 0 a %d): ", ll_len(pArrayListEmployee) - 1);
                        scanf("%d", &indice);
                    }

                    printf("Se sobreescribiran los datos del siguiente empleado en el indice %d\n", indice);
                    printf("  ID          Nombre       Horas trabajadas   Sueldo  \n");

                    auxEmployee2 = ll_get(pArrayListEmployee, indice);
                    employee_mostrarUno(auxEmployee2);

                    printf("\n\"s\" para confirmar - Cualquier otra tecla para cancelar: ");
                    __fpurge(stdin);
                    scanf("%c", &confirma);

                    if(confirma == 's')
                    {
                        ll_set(pArrayListEmployee, indice, auxEmployee);
                        flag = 0;
                    }
                    break;
                case 5:
                    printf("\nModificacion cancelada\n");
                    break;
                default:
                    printf("Debe ingresar una opcion valida\n");
            }

            if(opcion > 0 && opcion < 5 && !flag)
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
    Employee* auxEmployee = NULL;
    int idIndice;
    int retorno;
    int indice;
    char confirma;
    char nombre[128];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID del empleado que desea dar de baja: ");
        retorno = scanf("%d", &idIndice);
        validarEntero(retorno, &idIndice);

        idIndice = controller_getIndexById(pArrayListEmployee, idIndice);
        auxEmployee = ll_get(pArrayListEmployee, idIndice);

        if(auxEmployee != NULL)
        {
            indice = ll_indexOf(pArrayListEmployee, auxEmployee);

            printf("\nDara de baja al siguiente empleado:\n");
            printf("  ID          Nombre       Horas trabajadas   Sueldo  \n");
            employee_mostrarUno(auxEmployee);

            printf("\nPresione \"s\" para confirmar: ");
            __fpurge(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                auxEmployee = ll_pop(pArrayListEmployee, indice);
            }

            if(ll_contains(pArrayListEmployee, auxEmployee))
            {
                printf("\nError, el empleado no fue eliminado\n");
            }
            else
            {
                employee_getNombre(auxEmployee, nombre);
                printf("\nDiste de baja a %s\n", nombre);
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
    char confirma;
    LinkedList* auxLista = NULL;
    LinkedList* copia = NULL;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("------------------Ordenar empleados-------------------\n");
        printf("------------------------------------------------------\n");

        printf("\nDesea ordenar la lista original o quiere crear una copia?\n");
        printf("(\"o\" para ordenar la original - Cualquier otra tecla para una copia): ");
        __fpurge(stdin);
        scanf("%c", &confirma);

        if(confirma != 'o')
        {
            copia = ll_clone(pArrayListEmployee);
            if(ll_containsAll(copia, pArrayListEmployee))
            {
                auxLista = copia;
            }
            else
            {
                printf("\nError al crear la copia, se usara la lista original\n");
                auxLista = pArrayListEmployee;
            }
        }
        else
        {
            auxLista = pArrayListEmployee;
        }

        opcion = menuOrdenamiento();

        switch(opcion)
        {
            case 1:
                criterio = menuCriterio();

                if(criterio == 1 || criterio == 0)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(auxLista, employee_sortId, criterio);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 2:
                criterio = menuCriterio();

                if(criterio == 1 || criterio == 0)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(auxLista, employee_sortName, criterio);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 3:
                criterio = menuCriterio();

                if(criterio == 1 || criterio == 0)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(auxLista, employee_sortHours, criterio);
                }
                else
                {
                    printf("Criterio invalido\n");
                }
                break;
            case 4:
                criterio = menuCriterio();

                if(criterio == 1 || criterio == 0)
                {
                    printf("\nRealizando ordenamiento...\n");
                    ll_sort(auxLista, employee_sortSalary, criterio);
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
            if(confirma != 'o')
            {
                controller_ListEmployee(auxLista);
                ll_deleteLinkedList(auxLista);
            }
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

/** \brief Lista los empleados dentro de un rango
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListarRango(LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    LinkedList* cloneArray = NULL;
    int from;
    int to;
    int retorno;

    if(pArrayListEmployee != NULL)
    {
        system("clear");
        printf("------------------------------------------------------\n");
        printf("------------------Listar en un rango------------------\n");
        printf("------------------------------------------------------\n");

        printf("\nIngrese el indice desde el que quiere empezar a listar: ");
        retorno = scanf("%d", &from);
        validarEntero(retorno, &from);

        while(from < 0 || from >= ll_len(pArrayListEmployee))
        {
            printf("\nIngrese un indice correcto: ");
            retorno = scanf("%d", &from);
            validarEntero(retorno, &from);
        }

        printf("\nIngrese el indice hasta el que quiere a listar: ");
        retorno = scanf("%d", &to);
        validarEntero(retorno, &to);

        while(from > to || to >= ll_len(pArrayListEmployee))
        {
            printf("\nIngrese un indice correcto: ");
            retorno = scanf("%d", &to);
            validarEntero(retorno, &to);
        }

        cloneArray = ll_subList(pArrayListEmployee, from, to);
        if(cloneArray != NULL)
        {
            controller_ListEmployee(cloneArray);
            fallo = 0;
        }
    }
    return fallo;
}
