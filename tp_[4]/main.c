#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

int main()
{
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagGuardoArchivo = 0;
    int id;

    do{
        switch(menu())
        {
            case 1:
                if(ll_isEmpty(listaEmpleados) && !flagGuardoArchivo)
                {
                    if(!controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("Archivo cargado exitosamente\n");
                        id = controller_nextId(listaEmpleados);
                        id++;
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo\n");
                    }
                }
                else
                {
                    printf("Ya cargo un archivo\n");
                }
                break;
            case 2:
                if(ll_isEmpty(listaEmpleados) && !flagGuardoArchivo)
                {
                    if(!controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Archivo cargado exitosamente\n");
                        id = controller_nextId(listaEmpleados);
                        id++;
                    }
                    else
                    {
                        printf("Ocurrio un error al cargar el archivo\n");
                    }
                }
                else
                {
                    printf("Ya cargo un archivo\n");
                }
                break;
            case 3:
               if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_addEmployee(listaEmpleados, &id))
                    {
                        printf("\nAlta exitosa\n");
                    }
                    else
                    {
                        printf("Ocurrio un error al dar de alta un empleado\n");
                    }
                }
                else
                {
                    printf("Debe cargar un archivo primero\n");
                }
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados))
                {
                     if(!controller_editEmployee(listaEmpleados, &id))
                    {
                        printf("\nModificacion exitosa\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error al intentar modificar al empleado\n");
                    }
                }
                else
                {
                    printf("No hay empleados para modificar\n");
                }
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados))
                {
                     if(!controller_removeEmployee(listaEmpleados))
                    {
                        printf("\nBaja exitosa\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error al intentar dar de baja al empleado\n");
                    }
                }
                else
                {
                    printf("No hay empleados para dar de baja\n");
                }
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("\nOcurrio un error al mostrar los empleados\n");
                    }
                }
                else
                {
                    printf("No hay empleados para mostrar\n");
                }
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_sortEmployee(listaEmpleados))
                    {
                        printf("\nOrdenamiento exitoso\n");
                    }
                    else
                    {
                        printf("\nOcurrio un error al intentar ordenar los empleados\n");
                    }
                }
                else
                {
                    printf("No hay empleados para ordenar\n");
                }
                break;
           case 8:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_ListarRango(listaEmpleados))
                    {
                        printf("\nOcurrio un error al mostrar los empleados dentro de ese rango\n");
                    }
                }
                else
                {
                    printf("No hay empleados para mostrar\n");
                }
                break;
            case 9:
               if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsText("data.csv", listaEmpleados))
                    {
                        printf("Archivo guardado con exito\n");
                        flagGuardoArchivo = 1;
                    }
                    else
                    {
                        printf("No hay empleados para mostrar\n");
                    }
                }
                else
                {
                    printf("Debe cargar un archivo primero\n");
                }
                break;
            case 10:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsBinary("data.bin", listaEmpleados))
                    {
                        printf("Archivo guardado con exito\n");
                        flagGuardoArchivo = 1;
                    }
                    else
                    {
                        printf("Ocurrio un error al sobreescribir el archivo\n");
                    }
                }
                else
                {
                    printf("Debe cargar un archivo primero\n");
                }
                break;
            case 11:
                printf("Saliste\n");
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida\n");
        }

        printf("\nPresione cualquier tecla para continuar...");
        __fpurge(stdin);
        getchar();

    }while(seguir == 's');

    return 0;
}
