#include <iostream>
#include <ctime>
#include <time.h>
#include "shellquick.hpp"
using namespace std;

void shellSort (int* vetor, int n, int* comparacoes, int* trocas, double* tempo)
{
	int i, j, h, aux;
	
	clock_t tinicial = clock();
	
	for (h=1; h<n; h = 3*h+1);
	
	do 
	{
		h = (h-1)/3;
		
		for (i=h; i<n; i++)
		{
			aux = vetor[i];
			j=i;
			
			*comparacoes++;
			
			while (vetor[j-h]>aux)
			{
				*trocas++;
				
				vetor[j] = vetor[j-h];
				j -= h;
				
				if(j<h)
					break;
				
			}
			
			vetor[j] = aux;
		}
	} while (h!=1);
	
	clock_t tfinal = clock();
	
	*tempo = (tfinal - tinicial)/(double)CLOCKS_PER_SEC;
}

void quickSortParticao (int* vetor, int esq, int dir, int* i, int* j, int* comparacoes, int* trocas)
{
	int pivo, aux;
	*i = esq;
	*j = dir;
	
	pivo = vetor[(*i+*j)/2];
	
	do
	{
		while (!(pivo <= vetor[*i]))
			(*i)++;
		
		while (pivo < vetor[*j])
			(*j)--;
		
		*comparacoes++;
		
		if (*i <= *j)
		{
			*trocas++;
			
			aux = vetor[*i];
			vetor[*i] = vetor[*j];
			vetor[*j] = aux;
			
			(*i)++;
			(*j)--;
		}
		
	} while (*i <= *j);
}

void quickSortOrdena (int* vetor, int esq, int dir, int* comparacoes, int* trocas, double* tempo)
{
	int i, j;
	clock_t tinicial = clock();
	
	quickSortParticao (vetor, esq, dir, &i, &j, comparacoes, trocas);
	
	if (esq < j) quickSortOrdena (vetor, esq, j, comparacoes, trocas, tempo);
	
	if (i < dir) quickSortOrdena (vetor, i, dir, comparacoes, trocas, tempo);
	
	clock_t tfinal = clock();
	
	*tempo = (tfinal - tinicial)/(double)CLOCKS_PER_SEC;
}

void quickSort (int* vetor, int n, int* comparacoes, int* trocas, double* tempo)
{
	quickSortOrdena (vetor, 0, n-1, comparacoes, trocas, tempo);
}
