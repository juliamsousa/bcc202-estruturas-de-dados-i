#include <iostream>
#include "algoritmosOrdenacao.hpp"
using namespace std;

void bubbleSort (int* vetor, int tamanho)
{
	int aux;
	
	for (int i=0; i<tamanho-1; i++)
	{
		for (int j=1; j<tamanho-i; j++)
		{	
			if (vetor[j] < vetor[j-1])
			{
				aux = vetor[j];
				vetor[j] = vetor [j-1];
				vetor [j-1] = aux; 
			}
		}
	}
}

void selectionSort (int* vetor, int tamanho)
{
	int aux, min;
	
	for (int i=0; i<tamanho-1; i++)
	{
		min = i;
		
		for (int j=i+1; j<tamanho; j++)
			if (vetor[j]<vetor[min])
				min = j;
		
		aux = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = aux;	
	}
}

void insertionSort (int* vetor, int tamanho)
{
	int j, aux;
	
	for (int i=1; i<tamanho; i++)
	{
		aux = vetor[i];
		j = i-1;
		
		while (j>=0 && aux<vetor[j])
		{
			vetor[j+1] = vetor[j];
			j--;
		}
		
		vetor[j+1] = aux;
	}
}

void mergeSortIntercala (int* vetor, int esquerda, int meio, int direita)
{
	int i, j, k;
	
	int ta = meio-esquerda+1;
	int tb = direita-meio;
	
	int* a = new int [ta];
	int* b = new int [tb];
	
	for (i=0; i<ta; i++)
		a[i] = vetor[i+esquerda]; 
	for (i=0; i<tb; i++) 
		b[i] = vetor[i+meio+1];
	
	for (i=0, j=0, k=esquerda; k<=direita; k++)
	{
		if (i==ta)
			vetor[k] = b[j++];
		else
			if (j == tb)
				vetor[k] = a[i++];
			else
				if (a[i]<b[j])
					vetor[k] = a[i++];
				else
					vetor[k] = b[j++];
	}
	
	delete[] a;
	delete[] b;
}

void mergeSortOrdena (int* vetor, int esquerda, int direita)
{
	if (direita<=esquerda)
		return;
	
	int meio = (direita+esquerda)/2;
	
	mergeSortOrdena(vetor, esquerda, meio);
	mergeSortOrdena(vetor, meio+1, direita);
	mergeSortIntercala (vetor, esquerda, meio, direita);
	
	return;
}

void mergeSortRecursivo (int* vetor, int tamanho)
{
	mergeSortOrdena (vetor, 0, tamanho-1);
}

void mergeSortIterativo (int* vetor, int tamanho)
{
	int esquerda, direita;
	int n=1;
	
	while (n<tamanho)
	{
		esquerda =0;
		
		while (esquerda+n<tamanho)
		{
			direita = esquerda+2*n;
			
			if (direita>tamanho)
				direita = tamanho;
			
			mergeSortIntercala (vetor, esquerda, esquerda+n-1, direita-1);
			
			esquerda = esquerda+2*n; 
		}
		
		n*=2;
	}
}

void shellSort (int* vetor, int n)
{
	int i, j, h, aux;
	
	for (h=1; h<n; h = 3*h+1);
	
	do 
	{
		h = (h-1)/3;
		
		for (i=h; i<n; i++)
		{
			aux = vetor[i];
			j=i;
			
			while (vetor[j-h]>aux)
			{
				vetor[j] = vetor[j-h];
				j -= h;
				
				if(j<h)
					break;
				
			}
			
			vetor[j] = aux;
		}
	} while (h!=1);
}

void quickSortParticao (int* vetor, int esq, int dir, int* i, int* j)
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
		
		if (*i <= *j)
		{
			aux = vetor[*i];
			vetor[*i] = vetor[*j];
			vetor[*j] = aux;
			
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}

void quickSortOrdena (int* vetor, int esq, int dir)
{
	int i, j;
	
	quickSortParticao (vetor, esq, dir, &i, &j);
	
	if (esq < j) quickSortOrdena (vetor, esq, j);
	
	if (i < dir) quickSortOrdena (vetor, i, dir);
}

void quickSort (int* vetor, int n)
{
	quickSortOrdena (vetor, 0, n-1);
}
