#ifndef MISFUNCIONES_H_
#define MISFUNCIONES_H_

#include "ArrayEmployees.h"

int menu(void);
int myGets(char* list, int len, int* pFlag);
int myGetsStruct(Employee* list, int len, int* pFlag);
int buscarEspacioLibre(Employee* list, int len);
int tomarDatos(Employee* list, int len, Employee* listEmployee, int* pId);
int menuModificacion(void);
int modificarEmpleado(Employee* list, int len);
float totalYPromSalarios(Employee* list, int len, float* pSum, float* pProm);
int salariosMayoresAlPromedio(Employee* list, int len, float* pProm);
int validarFlotante(int ret, float* number);
int validarEntero(int ret, int* number);


#endif /* MISFUNCIONES_H_ */


