/*
Desenvolver uma função que, dada uma string
s, determine se todos os seus caracteres são
distintos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int stringDistintos(char s[]);

void main()
{
	char s[20];
	int resp;
	
	printf("Entre com a string: ");
	fflush(stdin);
	gets(s);
	
	resp = stringDistintos(s);
	
	if(resp == TRUE)
	{
		printf("String distinta");
	}
	else
		{
			printf("String nao distinta");
		}
	
}


int stringDistintos(char string[])
{
	int i, j, cont = 0, retorno, quant;
	
	quant = strlen(string);
	
	for(i = 0; string[i] ; i++)
	{
		retorno = TRUE;
		
		for(j = 0; j < i; j++)
		{
			if(string[i] == string[j])
			{
				retorno = FALSE;
				break;
			}		
		}
		if(retorno == TRUE)
		{
			cont++;
		}
		
	}
	if(cont == quant)
	{
		return TRUE;	
	}
	
}





