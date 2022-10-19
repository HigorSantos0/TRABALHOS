/*
Considere um vetor que armazene alguns
dados coletados de um grupo de pessoas em
uma pesquisa, a saber: nome, gênero, idade e
altura.

Desenvolver uma função que receba os
parâmetros gênero, faixa de idade (idade inicial
e idade final) e faixa de altura (altura inferior e
altura superior) e retorne a quantidade de
pessoas que atendem aos filtros por ele
representados.

Nota: caso o gênero especificado seja igual a
M, serão considerados os homens que
estiverem nas faixas de idade e altura
especificadas; o mesmo ocorrerá com as
mulheres, quando o gênero for F. Porém, se o
gênero contiver qualquer valor diferente de M
ou F, todas as pessoas que atenderem aos
filtros de idade e altura serão contabilizadas.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 3

typedef struct{
	
	char nome[50];
	char genero;
	int idade;
	float altura;
	
}Tpessoa;

int leituraDados(Tpessoa vetor[], int tamanho);
int funcaoMediaDados(Tpessoa vetor[], char gen, int tamanho, int idadeInicial, int idadeFinal, float alturaInicial, float alturaFinalint,int  *quantHomens, int *quantMulheres);

void main()
{
	Tpessoa vetor[TAM];
	char gener;
	int idadeI, idadeF;
	float alturaI, alturaF;
	int quantDH, quantDM;
	int resp;
	
	leituraDados(vetor, TAM);
	
	
	printf("Qual genero deseja buscar? M ou F: ");
	fflush(stdin);
	scanf("%c", &gener);
	
	printf("Qual faixa de idade deseja buscar? ");
	scanf("%d %d", &idadeI, &idadeF);
		
	printf("Qual faixa de altura deseja buscar? ");
	scanf("%f %f", &alturaI, &alturaF);
	
	resp = funcaoMediaDados(vetor, gener, TAM, idadeI, idadeF, alturaI, alturaF,&quantDH, &quantDM);
	
	printf("QUantidade de homens buscados: %d\n", quantDH);
	
	printf("QUantidade de mulheres buscados: %d\n", quantDM);
	
}
int funcaoMediaDados(Tpessoa vetor[], char gen, int tamanho, int idadeInicial, int idadeFinal, float alturaInicial, float alturaFinal, int *quantHomens, int *quantMulheres)
{
	int i, quantH = 0, quantM = 0;
	
	
	for(i = 0; i < tamanho; i++)
	{
			
		if(gen == 'm')
		{
			if(vetor[i].idade >= idadeInicial && vetor[i].idade <= idadeFinal)
			{
				if(vetor[i].altura >= alturaInicial && vetor[i].altura <= alturaFinal)
				{
					quantH++;	
				}			
			}
			
		}
		
		if(gen == 'f')
		{
			if(vetor[i].idade >= idadeInicial && vetor[i].idade <= idadeFinal)
			{
				if(vetor[i].altura >= alturaInicial && vetor[i].altura <= alturaFinal)
				{
					quantM++;		
				}
			}
		}
		if(gen != 'm' && gen != 'f')
		{
			if(vetor[i].idade >= idadeInicial && vetor[i].idade <= idadeFinal)
			{
				if(vetor[i].altura >= alturaInicial && vetor[i].altura <= alturaFinal)
				{
					quantH++;	
				}			
			}
			
			if(vetor[i].idade >= idadeInicial && vetor[i].idade <= idadeFinal)
			{
				if(vetor[i].altura >= alturaInicial && vetor[i].altura <= alturaFinal)
				{
					quantM++;		
				}
			}
		}
		
	}
	
	*quantHomens = quantH;
	*quantMulheres = quantM;
}

int leituraDados(Tpessoa vetor[], int tamanho)
{
	int i, cont = 0;
	
	for(i = 0; i < tamanho; i++)
	{
			
		
		printf("Entre com seu nome: ");
		fflush(stdin);
		gets(vetor[i].nome);
		
		printf("Entre com o seu genero M ou F: ");
		fflush(stdin);
		scanf("%c", &vetor[i].genero);
		
		printf("Entre com a sua idade: ");
		scanf("%d", &vetor[i].idade);
		
		printf("Entre com a sua altura ");
		scanf("%f", &vetor[i].altura);
		
		printf("\n");
		
	}
}

