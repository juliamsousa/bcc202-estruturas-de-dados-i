#include <iostream>
#include "funcoesElementoVetor.hpp"
using namespace std;

int menorElementoIterativo (int* vetor, int n)
{
	int menor = vetor[0];
	
	for (int i=0; i<n; i++)
		if (vetor[i]<menor)
			menor = vetor[i];
	
	return menor;
}

int menorElementoRecursiva (int* vetor, int n)
{	
	int menor;
	
	if (n == 1)
		return vetor[0];
	else
		menor = menorElementoRecursiva(vetor, n-1);
	
	if (menor<vetor[n-1])
		return menor;
	else
		return vetor[n-1];
}


