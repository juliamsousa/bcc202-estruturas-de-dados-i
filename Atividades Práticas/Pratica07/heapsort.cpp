#include <iostream>
#include <ctime>
using namespace std;

void heapRefaz (int *v, int esq, int dir, int* comp, int* trocas, double* tempo) 
{
	int i = esq;
	int j = i*2 + 1; // j = prim eiro filho de i
	
	int aux = v[i]; // aux = no i (pai de j)

	while (j<=dir) 
	{
		*comp++;
		if (j<dir && v[j]<v[j+ 1])
			j++; // j recebe o outro filho de i
	
		*comp++;
		if (aux>=v[j])
			break; // heap foi refeito corretam ente
		
		*trocas++;
		v[i] = v[j];
		
		i = j;
		j = i*2 + 1; // j = prim eiro filho de i
	}
	
	v[i] = aux;
}

void heapConstroi (int *v, int n, int* comp, int* trocas, double* tempo) 
{
	int esq = (n/2)-1;

	while (esq >= 0) 
	{
		heapRefaz (v, esq, n-1, comp, trocas, tempo);
		esq--;
	}
}

void heapSort (int *v, int n, int* comp, int* trocas, double* tempo) 
{
	int aux;
	
	clock_t tinicial = clock();
	
	heapConstroi (v, n, comp, trocas, tempo);
	
	while (n>1) 
	{
		aux = v[n-1];
	
		v[n-1] = v[0];
		v[0] = aux;
	
		n--;
	
		heapRefaz (v, 0, n-1, comp, trocas, tempo); // refaz o heap
	}
	
	clock_t tfinal = clock();
	
	*tempo = (tfinal - tinicial)/(double)CLOCKS_PER_SEC;
}



