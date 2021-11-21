#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* newEmpleado = (Employee*) malloc(sizeof(Employee));

    if(newEmpleado != NULL)
    {
        newEmpleado->id = 0;
        strcpy(newEmpleado->nombre, "0");
        newEmpleado->horasTrabajadas = 0;
        newEmpleado->sueldo = 0;
    }

    return newEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmpleado = employee_new();

    if(newEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if((employee_setId(newEmpleado, atoi(idStr))
            || employee_setNombre(newEmpleado, nombreStr)
            || employee_setHorasTrabajadas(newEmpleado, atoi(horasTrabajadasStr))
            || employee_setSueldo(newEmpleado, atoi(sueldoStr))))
        {
            employee_delete(newEmpleado);
            newEmpleado = NULL;
        }
    }
    return newEmpleado;
}

void employee_delete(Employee* thisEmployee)
{
    if(thisEmployee != NULL)
    {
        free(thisEmployee);
    }
}

int employee_setId(Employee* thisEmployee, int id)
{
    int fallo = 1;

    if(thisEmployee != NULL && id > 0)
    {
        thisEmployee->id = id;
        fallo = 0;
    }
    return fallo;
}

int employee_getId(Employee* thisEmployee, int* id)
{
    int fallo = 1;

    if(thisEmployee != NULL && id != NULL)
    {
        *id = thisEmployee->id;
        fallo = 0;
    }
    return fallo;
}

int employee_setNombre(Employee* thisEmployee, char* nombre)
{
    int fallo = 1;

    if(thisEmployee != NULL && nombre != NULL)
    {
        if(strlen(nombre) > 1 && strlen(nombre) < 128)
        {
            strcpy(thisEmployee->nombre, nombre);
            fallo = 0;
        }
    }
    return fallo;
}

int employee_getNombre(Employee* thisEmployee, char* nombre)
{
    int fallo = 1;

    if(thisEmployee != NULL && nombre != NULL)
    {
        strcpy(nombre, thisEmployee->nombre);
        fallo = 0;
    }
    return fallo;
}

int employee_setHorasTrabajadas(Employee* thisEmployee, int horasTrabajadas)
{
    int fallo = 1;

    if(thisEmployee != NULL && horasTrabajadas > 0)
    {
        thisEmployee->horasTrabajadas = horasTrabajadas;
        fallo = 0;
    }
    return fallo;
}

int employee_getHorasTrabajadas(Employee* thisEmployee, int* horasTrabajadas)
{
   int fallo = 1;

    if(thisEmployee != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas =  thisEmployee->horasTrabajadas;
        fallo = 0;
    }
    return fallo;
}

int employee_setSueldo(Employee* thisEmployee, int sueldo)
{
    int fallo = 1;

    if(thisEmployee != NULL && sueldo > 0)
    {
        thisEmployee->sueldo = sueldo;
        fallo = 0;
    }
    return fallo;
}

int employee_getSueldo(Employee* thisEmployee, int* sueldo)
{
    int fallo = 1;

    if(thisEmployee != NULL && sueldo != NULL)
    {
        *sueldo = thisEmployee->sueldo;
        fallo = 0;
    }
    return fallo;
}

void employee_mostrarUno(Employee* thisEmployee)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(thisEmployee != NULL)
    {
        employee_getId(thisEmployee, &id);
        employee_getNombre(thisEmployee, nombre);
        employee_getHorasTrabajadas(thisEmployee, &horasTrabajadas);
        employee_getSueldo(thisEmployee, &sueldo);

        printf("%4d%15s              %3d         %6d\n", id, nombre, horasTrabajadas, sueldo);
    }
}

int employee_sortId(void* employeeUno, void* employeeDos)
{
	int criterio = 0;
	int idEmployeeUno;
	int idEmployeeDos;

	Employee* auxEmployeeUno = (Employee*) employeeUno;
	Employee* auxEmployeeDos = (Employee*) employeeDos;

	if(employeeUno != NULL && employeeDos != NULL)
	{
		employee_getId(auxEmployeeUno, &idEmployeeUno);
		employee_getId(auxEmployeeDos, &idEmployeeDos);

		if(idEmployeeUno > idEmployeeDos)
        {
			criterio = 1;
		}
		else if(idEmployeeUno < idEmployeeDos)
		{
            criterio = -1;
        }
	}
	return criterio;
}

int employee_sortName(void* employeeUno, void* employeeDos)
{
    int criterio = 0;
    char nombreUno[128];
    char nombreDos[128];

    Employee* auxEmployeeUno = (Employee*) employeeUno;
    Employee* auxEmployeeDos = (Employee*) employeeDos;


    if(employeeUno != NULL && employeeDos != NULL)
    {
        employee_getNombre(auxEmployeeUno, nombreUno);
		employee_getNombre(auxEmployeeDos, nombreDos);

        if(strcmp(nombreUno, nombreDos) > 0)
		{
			criterio = 1;
		}
		else if(strcmp(nombreUno, nombreDos) < 0)
        {
            criterio = -1;
        }
    }
    return criterio;
}

int employee_sortHours(void* employeeUno, void* employeeDos)
{
	int criterio = 0;
    int horasUno;
	int horasDos;

	Employee* auxEmployeeUno=(Employee*) employeeUno;
	Employee* auxEmployeeDos=(Employee*) employeeDos;

	if(employeeUno != NULL && employeeDos != NULL)
	{
		employee_getHorasTrabajadas(auxEmployeeUno, &horasUno);
		employee_getHorasTrabajadas(auxEmployeeDos, &horasDos);

        if(horasUno > horasDos)
        {
            criterio = 1 ;
        }
        else if(horasUno < horasDos)
        {
            criterio = -1;
        }
	}
	return criterio;
}

int employee_sortSalary(void* employeeUno, void* employeeDos)
{
	int criterio = 0;
	int sueldoUno;
	int sueldoDos;

	Employee* auxEmployeeUno=(Employee*) employeeUno;
	Employee* auxEmployeeDos=(Employee*) employeeDos;

	if(employeeUno != NULL && employeeDos != NULL)
	{
		employee_getSueldo(auxEmployeeUno, &sueldoUno);
		employee_getSueldo(auxEmployeeDos, &sueldoDos);

        if(sueldoUno > sueldoDos)
        {
            criterio = 1;
        }
        else if(sueldoUno < sueldoDos)
        {
            criterio = -1;
        }
	}
	return criterio;
}
