#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    Employee* auxEmployee;
    char buffer[4][200];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        do{
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3])) == 4)
            {
                auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxEmployee != NULL)
                {
                    if(ll_add(pArrayListEmployee, auxEmployee))
                    {
                        employee_delete(auxEmployee);
                        break;
                    }
                    else
                    {
                        fallo = 0;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }
    return fallo;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int fallo = 1;
    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do{
            auxEmployee = employee_new();

            if(auxEmployee != NULL)
            {
                if(fread(auxEmployee, sizeof(Employee), 1, pFile))
                {
                    ll_add(pArrayListEmployee, auxEmployee);
                    fallo = 0;
                }
            }
        }while(!feof(pFile));
    }
    return fallo;
}
