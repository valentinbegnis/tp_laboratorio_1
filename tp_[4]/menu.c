#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int menu()
{
    int opcion;

    system("clear");

    printf("-----------------------------------------------------------------------------\n");
    printf("------------------------------Sistema empleados------------------------------\n");
    printf("-----------------------------------------------------------------------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Listar empleados dentro de un rango\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("10. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("11. Salir\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuModificaciones()
{
    int opcion;

    printf("\n1. Modificar nombre\n");
    printf("2. Modificar cantidad de horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Modificar indice\n");
    printf("5. Salir\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuOrdenamiento()
{
    int opcion;

    printf("\n1. Ordenamiento por ID\n");
    printf("2. Ordenamiento por nombre\n");
    printf("3. Ordenamiento por horas trabajadas\n");
    printf("4. Ordenamiento por sueldo\n");
    printf("5. Cancelar ordenamiento\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuCriterio()
{
    int opcion;

    printf("1. Criterio ascendente\n");
    printf("0. Criteio descendente\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuIndice()
{
    int opcion;

    printf("\n1. Agregar empleado al final de la lista\n");
    printf("2. Agregar empleado en indice a eleccion\n");

    printf("\nElegir una opcion: ");
    __fpurge(stdin);
    scanf("%d", &opcion);

    return opcion;
}

