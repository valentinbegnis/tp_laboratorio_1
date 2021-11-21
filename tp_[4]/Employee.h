#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Inicializa un nuevo empleado
 * \return Employee* Dirección de memoria del empleado en cuestion
 */
Employee* employee_new();

/** \brief Asigna valores hardcodeados a un empleado
 * \param idStr char* Cadena de caracteres del ID
 * \param nombreStr char* Cadena de caracteres del nombre
 * \param horasTrabajadasStr char* Cadena de caracteres de las horas trabajadas
 * \param sueldoStr char* Cadena de caracteres del sueldo
 * \return Employee* Dirección de memoria del empleado en cuestion
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Hace un free al empleado pasado por parametro
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \return void
 */
void employee_delete(Employee* thisEmployee);

/** \brief Setea un ID a un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param id int ID a setear
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_setId(Employee* thisEmployee, int id);

/** \brief Obtiene el ID de un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param id int* Puntero a entero del ID
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_getId(Employee* thisEmployee, int* id);

/** \brief Setea un nombre a un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param nombre char*
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_setNombre(Employee* thisEmployee,char* nombre);

/** \brief Obtiene el nombre de un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param nombre char* Puntero a char del nombre
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_getNombre(Employee* thisEmployee,char* nombre);

/** \brief Setea las horas trabajadas a un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param horasTrabajadas int
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_setHorasTrabajadas(Employee* thisEmployee, int horasTrabajadas);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_getHorasTrabajadas(Employee* thisEmployee, int* horasTrabajadas);

/** \brief Setea un sueldo a un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param sueldo int
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_setSueldo(Employee* thisEmployee, int sueldo);

/** \brief Obtiene las horas trabajadas de un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \param id int* Puntero a entero de las horas trabajadas
 * \return int 1 si fallo, 0 si no fallo
 */
int employee_getSueldo(Employee* thisEmployee, int* sueldo);

/** \brief Muestra un empleado
 * \param thisEmployee Employee* Puntero a estructura Employee
 * \return void
 */
void employee_mostrarUno(Employee* thisEmployee);

/** \brief Compara los ID
 * \param employeeUno void* Puntero a void del empleado uno
 * \param employeeDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int employee_sortId(void* employeeUno, void* employeeDos);

/** \brief Compara los nombres
 * \param employeeUno void* Puntero a void del empleado uno
 * \param employeeDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int employee_sortName(void* employeeUno, void* employeeDos);

/** \brief Compara las horas trabajadas
 * \param employeeUno void* Puntero a void del empleado uno
 * \param employeeDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int employee_sortHours(void* employeeUno, void* employeeDos);

/** \brief Compara los sueldos
 * \param employeeUno void* Puntero a void del empleado uno
 * \param employeeDos void* Puntero a void del empleado dos
 * \return int -1 si el orden es descendente, 1 si es ascendente, 0 si hubo un error
 */
int employee_sortSalary(void* employeeUno, void* employeeDos);

#endif // employee_H_INCLUDED

#endif // EMPLOYEE_H_INCLUDED
