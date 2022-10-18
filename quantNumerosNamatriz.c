/*
Dada uma matriz MLINHAxCOLUNA, onde LINHA e
COLUNA são constantes, e uma linha L,
desenvolver uma função que retorne um vetor
de tamanho COLUNA contendo, em cada
posição, a quantidade de vezes que os
elementos da linha L encontram-se nas demais
linhas da matriz.
Exemplo:

	1 5 7 1 6
	6 2 1 4 7
M = 3 6 9 7 1
	2 4 5 7 4
	2 4 8 9 2
	L = 3 (ou seja, a 4a linha)
		Retornará o seguinte vetor:
	V = 3 2 1 3 2
	Ou seja:
	2 aparece 3x nas demais linhas
	4 aparece 2x nas demais linhas
	5 aparece 1x nas demais linhas
	7 aparece 3x nas demais linhas
	4 aparece 2x nas demais linhas
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 5
#define C 5
#define TRUE 1
#define FALSE 0


void exibir (float m[L][C]);
void preencherMatriz (float m[L][C]);
void exibirVetor (int vetor[], int tamanho);
int mtbuscar(float mat[L][C], int numero, int lin);
int matrizSoma(float matriz[L][C], int vetor[C], int linha);

void main ()
{
	float matriz[L][C];
	int vet[C], linha;
	
	preencherMatriz (matriz);
	exibir (matriz);
	
	printf("Entre em qual linha deve ser buscado: ");
	scanf ("%d", &linha);
	
	matrizSoma(matriz, vet, linha);
	
	exibirVetor (vet, C);
	
}
int matrizSoma(float matriz[L][C], int vetor[C], int linha)
{
    int i, j, h = 0;
    
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            if(i==linha)
            {
                vetor[h] = mtbuscar(matriz, matriz[i][j], linha);
                h++;
                
            }
        }
    }
}

int mtbuscar(float mat[L][C], int numero, int lin)
{
	int i, j, quant = 0;
	
	for(i = 0; i < L; i++)
	{
		for(j = 0; j < C; j++)
		{
			if(mat[i][j] == numero)
			{
				if(i != lin)
				{
					quant++;	
				}	
			}
		}
	}
	return quant;
}

void exibir (float m[L][C])
{
	
	int i, j;
	
	printf ("\nElementos da matriz:\n\n");
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%.1f ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}
void preencherMatriz (float m[L][C])
{
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			m[i][j] = rand () % 9;
		}
	}
}

void exibirVetor (int vetor[], int tamanho)
{
	
	int i;
	
	printf ("\n\nElementos do vetor: ");
	

	for (i=0;i<tamanho;i++)	
	{
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n\n");
}
