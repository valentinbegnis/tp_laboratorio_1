#include "misFunciones.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int pedirString(char string[], int len, int min)
{
	int todoOk = 0;
	char bufferString[100];

	if(string != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) >= min &&
					strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(string, bufferString, len);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

int esSoloLetras(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
		   return 0;
		}
		i++;
	}
	return 1;
}

int validarEntero(int ret, int* number)
{
	int todoOk = 0;

	if(number != NULL)
	{
		while(ret != 1)
		{
			printf("Error. Ingrese un valor numerico: ");
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
